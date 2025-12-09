#include "camera.h"
#include "hitLogic/objects.h"

int main() {

    surfaceList world;

    world.add(make_shared<sphere>(point3(0, 0, 3), 1.0));
    world.add(make_shared<sphere>(point3(-1, -0.5, 2.5), 0.5));
    world.add(make_shared<sphere>(point3(1, 0.5, 2), 0.3));
    
    world.add(make_shared<sphere>(point3(0,-101, 3), 100));

    camera cam;

    cam.file = std::ofstream("../output.ppm", std::ios::binary);
    //cam.res = vec2(1920, 1080);

    cam.camPos = point3(0.0, 0.0, 0.0);
    cam.camScale = 1.0;
    cam.focalLength = 1.0;

    cam.sampleNum = 100;
    cam.sampleScatter = 2.0;

    cam.render(world);
}