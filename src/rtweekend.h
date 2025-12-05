#ifndef RTWEEKEND_H
#define RTWEEKEND_H

//Headers
#include "mathHeaders/ray.h"
#include "mathHeaders/vec2.h"

//Includes
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

//Usings
using std::make_shared;
using std::shared_ptr;

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Utility Funcs
inline double toRadians(double degrees) {
    return degrees * pi / 180.0;
}

#endif

//#include "rtweekend.h"