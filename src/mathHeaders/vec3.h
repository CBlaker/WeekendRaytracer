#ifndef VEC3_H
#define VEC3_H

#include "../utility.h"

#include <cmath>
#include <iostream>

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {}
        vec3(double x, double y, double z) : e{x, y, z} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        double operator[](int i) const { 
            return e[i]; 
        }

        double& operator[](int i) { 
            return e[i]; 
        }

        vec3 operator-() const {
            return vec3(-e[0], -e[1], -e[2]);
        }

        vec3& operator+=(vec3 v) {
            e[0] += v[0];
            e[1] += v[1];
            e[2] += v[2];
            return *this;
        }

        vec3& operator*=(float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(float t) {
            return *this *= 1/t;
        }
        
        double lengthSquared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const {
            return std::sqrt(lengthSquared());
        }

        static vec3 random() {
            return vec3(randomDouble(), randomDouble(), randomDouble());
        }

        static vec3 random(interval range) {
            return vec3(randomDouble(range), randomDouble(range), randomDouble(range));
        }

        static vec3 random(interval rangeX, interval rangeY, interval rangeZ) {
            return vec3(randomDouble(rangeX), randomDouble(rangeY), randomDouble(rangeZ));
        }
    };

    using point3 = vec3;

    inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }
    
    inline vec3 operator+(const vec3& u, const vec3& v) {
        return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    inline vec3 operator-(const vec3& u, const vec3& v) {
        return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    inline vec3 operator*(const vec3& u, const vec3& v) {
        return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }


    inline vec3 operator*(const vec3& v, double t) {
        return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
    }

        inline vec3 operator*(double t, const vec3& v) {
            return v * t;
    }

    inline vec3 operator/(const vec3& u, const vec3& v) {
        return vec3(u.e[0] / v.e[0], u.e[1] / v.e[1], u.e[2] / v.e[2]);
    }

    inline vec3 operator/(const vec3& v, double t) {
        return v * (1/t);
    }

    inline vec3 operator/(double t, const vec3& v) {
        return vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
    }
    
    inline double dot(const vec3& u, const vec3& v) {
        return u.e[0] * v.e[0]
            +  u.e[1] * v.e[1]
            +  u.e[2] * v.e[2];
    }
    
    inline vec3 cross(const vec3& u, const vec3& v) {
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
    }

    inline vec3 normalize(const vec3& v) {
    return v / v.length();
    }

    inline vec3 randomDivergent(const vec3& normal, float divergence) {
        return normalize(vec3::random(
            interval(normal.x() - divergence, normal.x() + divergence),
            interval(normal.y() - divergence, normal.y() + divergence),
            interval(normal.z() - divergence, normal.z() + divergence)
        ));
    }

    inline vec3 reflect(const vec3& view, const vec3& normal) {
        return view - 2*dot(view,normal)*normal;
    }

#endif