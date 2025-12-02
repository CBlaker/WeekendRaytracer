#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
#include <fstream>

using color = vec3;

void writeCol(std::ofstream& out, color& uvCol) {

            auto r = uvCol.x();
            auto g = uvCol.y();
            auto b = uvCol.z();

            //0-1 UV Coord to 0-255 RGB Colorspace
            int rByte = int(255 * r);
            int gByte = int(255 * g);
            int bByte = int(255 * b);
                        
            out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif