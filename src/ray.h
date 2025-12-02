#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {}

        ray(const point3& origin, const vec3& direction) : org(origin), dir(direction) {}

        
        const point3& origin() { return org; }
        const point3& direction() { return dir; }

        point3 rayAt(double t) {
            return org + t*dir;
        }

    private:
        point3 org;
        vec3 dir;

};

#endif