#ifndef COLOR_H
#define COLOR_H


#include "mathHeaders/vec3.h"

#include <fstream>

using color = vec3;

void writeCol(std::ofstream& out, const color& col) {
    static const interval colorRange(0.0, 1.0);

    auto r = col.x();
    auto g = col.y();
    auto b = col.z();

    //0-1 UV Coord to 0-255 RGB Colorspace
    int rByte = int(255 * colorRange.clamp(r));
    int gByte = int(255 * colorRange.clamp(g));
    int bByte = int(255 * colorRange.clamp(b));
    
    //Output as "Red Green Blue" for ppm file
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif