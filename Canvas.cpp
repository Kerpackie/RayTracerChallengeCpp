//
// Created by kerpackie on 02/09/2026.
//

#include "Canvas.h"


Colour Canvas::getPixel(int x, int y) const {
    if (!validatePixel(x, y)) {
        return {};
    };

    return pixels[y * width + x];
}

void Canvas::writePixel(int x, int y, const Colour &colour) {

    if (!validatePixel(x, y)) return;

    pixels[y * width + x] = colour;
}

bool Canvas::validatePixel(int x, int y) const {
    return
        x >= 0 &&
        x < width &&
        y >= 0 &&
        y < height;
}
