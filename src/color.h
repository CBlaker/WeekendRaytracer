#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using color = vec3;

void writeCol(std::ofstream& out, color& col) {

            auto r = std::clamp(col.x(), 0.0, 1.0);
            auto g = std::clamp(col.y(), 0.0, 1.0);
            auto b = std::clamp(col.z(), 0.0, 1.0);

            //0-1 UV Coord to 0-255 RGB Colorspace
            int rByte = int(255 * r);
            int gByte = int(255 * g);
            int bByte = int(255 * b);
            
            //Output as "Red Green Blue" for ppm file
            out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif