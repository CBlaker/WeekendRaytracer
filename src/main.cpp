#include "color.h"
#include "vec2.h"
#include "ray.h"

#include <iostream>
#include <fstream>

double hitSphere(const ray& r, const point3& center, float rad) {
    vec3 CminQ = center - r.origin();
    float a = r.direction().lengthSquared();
    float h = dot(r.direction(), CminQ);
    float c = CminQ.lengthSquared() - rad*rad;
    float discriminant = h*h - a*c;
    if (discriminant < 0) {
        return -1;
    } else {
        return (h - std::sqrt(discriminant)) / a;
    }
}

color rayCol(const ray& r) {
    point3 spherePos = point3(0.0, 0.0, 2.0);
    double t = hitSphere(r, spherePos, 0.5);
    point3 hitPos = r.rayAt(t);
    if (t > 0) {
        vec3 N = normalize(hitPos - spherePos);
        return 0.5 * (N + vec3(1.0, 1.0, 1.0));
    }

    vec3 unit_direction = normalize(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {

    //Set output file to write binary
    std::ofstream file("../output.ppm", std::ios::binary);

    //Define Render Resolution and Aspect ratio
    vec2 res = vec2(400, 225);
    float aspect = res.x() / res.y();

    //Viewport Properties
    float viewportScale = 1.0;
    vec2 viewportDim = vec2(viewportScale * aspect, viewportScale);

    //Camera Properties
    float focalLength = 1.0;
    point3 camPos = point3(0.0, 0.0, 0.0);

    //Viewport UV Vectors
    vec3 viewU = vec3(viewportDim.x(), 0.0, 0.0);
    vec3 viewV = vec3(0.0, -viewportDim.y(), 0.0);

    //Pixel Difference Vectors
    vec3 pixDU = viewU / res.x();
    vec3 pixDV = viewV / res.y();

    //Finding the center of the top left pixel of our viewport
    vec3 viewUpLeft = camPos + vec3(0.0, 0.0, focalLength) - viewU/2.0 - viewV/2.0;
    vec3 pix00Pos = viewUpLeft + 0.5 * (pixDU + pixDV);

    //Specify ASCII Colorm, Img Width and Height, and then max color
    file << "P3\n" << res.x() << ' ' << res.y() << "\n255\n";

    //Loop through pixels per horizontal line
    for (int j=0; j < res.y(); j++) {
        std::clog << "\rScanlines Remaining: " << (res.y() - j) << std::flush;
        for (int i=0; i < res.x(); i++) {

            vec2 pixCoord = vec2(double(i), double(j));

            vec3 rayOrg = pix00Pos + (pixCoord.x() * pixDU) + (pixCoord.y() * pixDV);
            vec3 rayDir = normalize(rayOrg - camPos);

            ray r(rayOrg, rayDir);

            //Normalize from -1 to 1, reduce stretching
            //vec2 uv = (pixelCoord / res);
            //uv = (uv * 2.0 - vec2(1.0, 1.0)) * aspect;
            
            //Output final color per pixel and write to file
            color outputCol = rayCol(r);
            writeCol(file, outputCol);
        }
    }

    std::clog << "\rRender Complete          ";
}