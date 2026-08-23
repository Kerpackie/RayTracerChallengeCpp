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

    float magnitude() const;

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
