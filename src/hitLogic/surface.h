#ifndef HITSURFACE_H
#define HITSURFACE_H

#include "../rtweekend.h"

class hitInfo {
    public:
        point3 hitPos;
        vec3 normal;
        double t;
        bool frontFace;

        void setFaceNormal(const ray& r, const vec3& outNormal) {
            frontFace = dot(r.direction(), outNormal) < 0;
            normal = frontFace ? outNormal : -outNormal;
        }
};



class surface {
    public:
        virtual ~surface() {}

        virtual bool hit(const ray& r, double tMin, double tMax, hitInfo& info) const = 0;
};

#endif