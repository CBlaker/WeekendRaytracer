#include "color.h"
#include "vec2.h"
#include "ray.h"

#include <iostream>
#include <fstream>

int main() {

    //Set output file to write binary
    std::ofstream file("../output.ppm", std::ios::binary);

    //Define Render Resolution and Aspect ratio
    vec2 res = vec2(400, 225);
    float aspect = res.x() / res.y();

    float uvScale = 1.0;

    //Specify ASCII Colorm, Img Width and Height, and then max color
    file << "P3\n" << res.x() << ' ' << res.y() << "\n255\n";

    //Loop through pixels per horizontal line
    for (int j=0; j < res.y(); j++) {
        std::clog << "\rScanlines Remaining: " << (res.y() - j) << std::flush;
        for (int i=0; i < res.x(); i++) {
            
            vec2 pixelCoord = vec2(double(i), double(j));

            //Normalize from 0 - 1
            vec2 uv = (pixelCoord / res);

            //Normalize from -1 to 1, reduce stretching
            //uv = (uv * 2.0 - vec2(1.0, 1.0)) * aspect;
            
            
            //Output final color per pixel and write to file
            color outputCol = color(uv.x(), uv.y(), 0.0);
            writeCol(file, outputCol);
        }
    }

    std::clog << "\rRender Complete          ";
}