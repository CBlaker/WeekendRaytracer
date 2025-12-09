#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

#include "color.h"
#include "hitLogic/hitList.h"
#include "hitLogic/objects.h"

class camera {
    public:
        //Render Properties
        std::ofstream file;
        vec2 res = vec2(400, 225);

        //Camera Properties
        point3 camPos = point3(0.0, 0.0, 0.0);
        double camScale = 1.0;
        double focalLength = 1.0;

        //Ray Properties
        int sampleNum = 10;
        double sampleScatter = 1.0;

        void render(const surface& world) {
            double aspect = double(res.x()) / double(res.y());
            double sampleScale = 1/double(sampleNum);

            uvScale = 1/res * vec2(aspect, -1.0) * camScale;
            uvTranslate = vec2(-0.5 * aspect, 0.5) * camScale;
            
            //Specify ASCII Colorm, Img Width and Height, and then max color
            file << "P3\n" << res.x() << ' ' << res.y() << "\n255\n";

            //Loop through pixels per horizontal line
            for (int j=0; j < res.y(); j++) {
                std::clog << "\rScanlines Remaining: " << (res.y() - j) << std::flush;
                for (int i=0; i < res.x(); i++) {

                    vec2 pixCoord = vec2(double(i), double(j));
                    vec2 uv = pixCoord * uvScale + uvTranslate;
                    
                    color pixCol(0, 0, 0);

                    for (int sample=0; sample < sampleNum; sample++) {
                        ray r = getCamRay(uv);
                        pixCol += rayCol(r, world);
                    }
                    writeCol(file, pixCol * sampleScale);
                }
            }

            std::clog << "\rRender Complete          ";
        }
    
    private:
        vec2 uvScale;
        vec2 uvTranslate;

        ray getCamRay(vec2 uv) {
            vec2 uvSample = uv + (vec2(randomDouble(), randomDouble()) * uvScale * sampleScatter);
            vec3 samplePos = vec3(uvSample.x(), uvSample.y(), focalLength);

            vec3 rayOrg = camPos;
            vec3 rayDir = samplePos - camPos;

            return ray(rayOrg, rayDir);
        }

        //Ray Color Function
        color rayCol(const ray& r, const surface& world) const {
            hitInfo info;
                if (world.hit(r, interval(epsilon, infinity), info)) {
                    return 0.5 * (info.normal + color(1,1,1));
                }

                vec3 unitDir = normalize(r.direction());
                auto a = 0.5*(unitDir.y() + 1.0);
                return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
        }
};

#endif