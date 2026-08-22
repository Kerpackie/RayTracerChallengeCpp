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
};


Tuple point(float x, float y, float z);
Tuple vector(float x, float y, float z);


#endif //RAYTRACERCHALLENGE_TUPLE_H
