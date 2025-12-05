#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

class vec2 {
    public:
        double e[2];

        vec2() : e{0, 0} {}
        vec2(double x, double y) : e{x, y} {}

        double x() { return e[0]; }
        double y() { return e[1]; }

        double operator[](int i) const { 
            return e[i]; 
        }

        double& operator[](int i) { 
            return e[i]; 
        }

        vec2 operator-() {
            return vec2(-e[0], -e[1]);
        }

        vec2& operator+=(vec2 v) {
            e[0] += v[0];
            e[1] += v[1];
            return *this;
        }

        vec2& operator*=(float t) {
            e[0] *= t;
            e[1] *= t;
            return *this;
        }

        vec2& operator/=(float t) {
            return *this *= 1/t;
        }
        
        double lengthSquared() const {
            return e[0]*e[0] + e[1]*e[1];
        }

        double length() const {
            return std::sqrt(lengthSquared());
        }
    };

    using point2 = vec2;

    inline std::ostream& operator<<(std::ostream& out, const vec2& v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }
    
    inline vec2 operator+(const vec2& u, const vec2& v) {
        return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
    }

    inline vec2 operator-(const vec2& u, const vec2& v) {
        return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
    }

    inline vec2 operator*(const vec2& u, const vec2& v) {
        return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
    }


    inline vec2 operator*(const vec2& v, double t) {
        return vec2(t * v.e[0], t * v.e[1]);
    }

        inline vec2 operator*(double t, const vec2& v) {
            return v * t;
    }

    inline vec2 operator/(const vec2& u, const vec2& v) {
        return vec2(u.e[0] / v.e[0], u.e[1] / v.e[1]);
    }

    inline vec2 operator/(const vec2& v, double t) {
        return v * (1/t);
    }

    inline double dot(const vec2& u, const vec2& v) {
        return u.e[0] * v.e[0]
            +  u.e[1] * v.e[1];
    }

    inline vec2 normalize(const vec2& v) {
    return v / v.length();
}

#endif