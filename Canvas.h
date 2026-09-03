//
// Created by kerpackie on 02/09/2026.
//

#ifndef RAYTRACERCHALLENGE_CANVAS_H
#define RAYTRACERCHALLENGE_CANVAS_H
#include <vector>

#include "Colour.h"


struct Canvas {
    int width;
    int height;
    std::vector<Colour> pixels;

    Canvas(int w, int h) : width(w), height(h), pixels(w * h) {}

    [[nodiscard]] Colour getPixel(int x, int y) const;
    void writePixel(int x, int y, const Colour& colour);



private:
    [[nodiscard]] bool validatePixel(int x, int y) const;
};


#endif //RAYTRACERCHALLENGE_CANVAS_H
