//
// Created by kerpackie on 22/08/2026.
//

#ifndef RAYTRACERCHALLENGE_TUPLE_H
#define RAYTRACERCHALLENGE_TUPLE_H


struct Tuple {
    float x;
    float y;
    float z;
    float w;

    Tuple(float x, float y, float z, float w);

    static Tuple point(float x, float y, float z);
    static Tuple vector(float x, float y, float z);

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] Tuple normalised() const;

    static float dotProduct(const Tuple &a, const Tuple &b);
    static Tuple crossProduct(const Tuple &a, const Tuple &b);

    bool operator==(const Tuple &other) const;
    bool operator!=(const Tuple &other) const;

    Tuple operator+(const Tuple &other) const;
    Tuple operator-(const Tuple &other) const;
    Tuple operator-() const;
    Tuple operator*(float scalar) const;
    Tuple operator/(float scalar) const;

private:
    static constexpr float EPSILON = 0.00001f;
};




#endif //RAYTRACERCHALLENGE_TUPLE_H
