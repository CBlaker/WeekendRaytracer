#ifndef SURFACES_H
#define SURFACES_H

#include "surface.h"

class sphere : public surface {
    public:
        sphere(const point3& spherePos, double sphereRad) : center(spherePos), radius(std::fmax(0, sphereRad)) {}

        bool hit(const ray& r, interval hitRange, hitInfo& info) const override {
            vec3 CminQ = center - r.origin();
            float a = r.direction().lengthSquared();
            float h = dot(r.direction(), CminQ);
            float c = CminQ.lengthSquared() - radius*radius;

            float discriminant = h*h - a*c;
            if (discriminant < 0) { return false; }

            float sqrtd = std::sqrt(discriminant);

            float root = (h - sqrtd) / a;
            if (!hitRange.surrounds(root)) {
                root = (h + sqrtd) / a;
                if (!hitRange.surrounds(root)) { return false; }
            }
        
            info.t = root;
            info.hitPos = r.rayAt(info.t);
            vec3 outNormal = (info.hitPos - center) / radius;
            info.setFaceNormal(r, outNormal);

            return true;
        }
    

    private:
        point3 center;
        double radius;
};

#endif