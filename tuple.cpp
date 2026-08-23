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

float Tuple::magnitude() const {
    return std::sqrt(
        (x * x) + (y * y) +
        (z * z) + (w * w));
}

Tuple Tuple::normalised() const {
    float magnitude = this->magnitude();
    return {
        x / magnitude,
        y / magnitude,
        z / magnitude,
        w / magnitude };
}

float Tuple::dotProduct(const Tuple &a, const Tuple &b) {
    return
        (a.x * b.x) +
        (a.y * b.y) +
        (a.z * b.z) +
        (a.w * b.w);
}

Tuple Tuple::crossProduct(const Tuple &a, const Tuple &b) {
    return vector(
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x));
}

bool Tuple::operator==(const Tuple& other) const {
    return
    std::abs(x - other.x) < EPSILON &&
    std::abs(y - other.y) < EPSILON &&
    std::abs(z - other.z) < EPSILON &&
    std::abs(w - other.w) < EPSILON;

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

Tuple Tuple::operator-() const {
    return { -x, -y, -z, -w };
}

Tuple Tuple::operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}

Tuple Tuple::operator/(float scalar) const {
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}

