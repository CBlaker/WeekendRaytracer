#ifndef HITLIST_H
#define HITLIST_H

#include "surface.h"
#include <vector>


class surfaceList : public surface {
    public: 
        std::vector<shared_ptr<surface>> objects;

        surfaceList() {}
        surfaceList(shared_ptr<surface> object) { add(object); }

        void clear() { objects.clear(); }

        void add(shared_ptr<surface> object) {
            objects.push_back(object);
        }

        bool hit(const ray& r, interval hitRange, hitInfo& info) const override {
            hitInfo tempInfo;
            bool hitAny = false;
            double closest = hitRange.max;

            for (const shared_ptr<surface>& object : objects) {
                if (object->hit(r, interval(hitRange.min, closest), tempInfo)) {
                    hitAny = true;
                    closest = tempInfo.t;
                    info = tempInfo;
                }
            }
            return hitAny;
        }
};

#endif