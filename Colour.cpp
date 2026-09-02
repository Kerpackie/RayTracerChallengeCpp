//
// Created by kerpackie on 02/09/2026.
//

#include "Colour.h"

#include <valarray>

Colour::Colour(float red, float green, float blue) : red(red), green(green), blue(blue) {}

Colour Colour::operator+(const Colour &other) const {
    return { red + other.red, green + other.green, blue + other.blue};
}

Colour Colour::operator-(const Colour &other) const {
    return { red - other.red, green - other.green, blue - other.blue};
}

// Harmand Product.
Colour Colour::operator*(const Colour &other) const {
    return { red * other.red, green * other.green, blue * other.blue};
}

Colour Colour::operator*(const float &scalar) const {
    return { red * scalar, green * scalar, blue * scalar};
}

bool Colour::operator==(const Colour &other) const {
    return
    std::abs(red - other.red) < EPSILON &&
    std::abs(green - other.green) < EPSILON &&
    std::abs(blue - other.blue) < EPSILON;
}

bool Colour::operator!=(const Colour &other) const {
    return !(*this == other);
}
