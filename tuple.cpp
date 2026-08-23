//
// Created by kerpackie on 22/08/2026.
//

#include "tuple.h"

#include <valarray>

Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
}

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 1.0f};
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 0.0f};
}

bool Tuple::operator==(const Tuple& other) const {
    return std::abs(x - other.x) < EPSILON
    && std::abs(y - other.y) < EPSILON;
}

bool Tuple::operator!=(const Tuple& other) const {
    return !(*this == other);
}

Tuple Tuple::operator+(const Tuple& other) const {
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

Tuple Tuple::operator-(const Tuple& other) const {
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

Tuple Tuple::operator*(const Tuple& other) const {
    return {x * other.x, y * other.y, z * other.z, w * other.w};
}

Tuple Tuple::operator/(const Tuple& other) const {
    return {x / other.x, y / other.y, z / other.z, w / other.w};
}

