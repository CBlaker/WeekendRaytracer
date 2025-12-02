#include "color.h"

#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("output.ppm", std::ios::binary);

    int imgHeight = 256;
    int imgWidth = 256;

    //Specify ASCII Colorm, Img Width and Height, and then max color
    file << "P3\n" << imgHeight << ' ' << imgWidth << "\n255\n";

    for (int j=0; j < imgHeight; j++) {
        std::clog << "\rScanlines Remaining: " << (imgHeight - j) << std::flush;
        for (int i=0; i < imgWidth; i++) {
            
            auto outputCol = color(double(i) / imgWidth, double(j) / imgHeight, 0.0);
            writeCol(file, outputCol);
        }
    }

    std::clog << "\rRender Complete          ";
}

// cmake --build build; build/Debug/raytracer.exe