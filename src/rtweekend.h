#ifndef RTWEEKEND_H
#define RTWEEKEND_H

//General Headers
#include "mathHeaders/ray.h"
#include "mathHeaders/vec2.h"
#include "mathHeaders/interval.h"

//General Includes
#include <cmath>
#include <iostream>
#include <memory>
#include <random>

//Usings
using std::make_shared;
using std::shared_ptr;

//Constants
const double epsilon = std::numeric_limits<double>::epsilon();
const double pi = 3.1415926535897932385;

//Utility Funcs
inline double toRadians(double degrees) {
    return degrees * pi / 180.0;
}

inline double randomDouble() {
    //Random double in [0,1)
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double randomDouble(double min, double max) {
    //Random double in [min,max)
    return min + (max - min) * randomDouble();
}

#endif

//#include "rtweekend.h"