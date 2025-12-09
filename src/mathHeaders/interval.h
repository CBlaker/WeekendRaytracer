#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits>

const double infinity = std::numeric_limits<double>::infinity();

class interval {
    public:
        double min, max;
        
        interval() : min(-infinity), max(+infinity) {}

        interval(double minVal, double maxVal) : min(minVal), max(maxVal) {}

        double size() const {
            return max - min;
        }

        bool constrains(double x) const {
            return min <= x && x <= max;
        }

        bool surrounds(double x) const {
            return min < x && x < max;
        }

        double clamp(double x) const {
            if (x < min) return min;
            if (x > max) return max;
            return x;
        }

        static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif