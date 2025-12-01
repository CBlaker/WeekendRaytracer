#include <iostream>

int main() {
    int imgWidth = 256;
    int imgHeight = 256;

    //Specify ASCII Colorm, Img Width and Height, and then max color
    std::cout << "P3\n" << imgWidth << ' ' << imgHeight << "\n255\n";

    for (int i=0; i < imgHeight; i++) {
        for (int j = 0; j < imgWidth; j++) {

            std::cout << "0" << ' ' << "0" << ' ' << "255" << '\n';
        }
    }
}

// cmake --build build; build/Debug/raytracer.exe > image.ppm