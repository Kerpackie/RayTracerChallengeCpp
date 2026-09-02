//
// Created by kerpackie on 02/09/2026.
//

#ifndef RAYTRACERCHALLENGE_COLOUR_H
#define RAYTRACERCHALLENGE_COLOUR_H


struct Colour {

    float red;
    float green;
    float blue;

    Colour(float red = 0.0f, float green = 0.0f, float blue = 0.0f);

    Colour operator+(const Colour &other) const;
    Colour operator-(const Colour &other) const;
    Colour operator*(const Colour &other) const;
    Colour operator*(const float &scalar) const;

    bool operator==(const Colour &other) const;
    bool operator!=(const Colour &other) const;
private:
    static constexpr float EPSILON = 0.00001f;
};


#endif //RAYTRACERCHALLENGE_COLOUR_H
