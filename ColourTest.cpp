//
// Created by kerpackie on 02/09/2026.
//


#include "Colour.h"
#include <cmath>

#include <gtest/gtest.h>

TEST(ColourTest, ColourCreatesColour) {
    Colour colour = Colour(1.0f, 1.0f, 1.0f);
    EXPECT_FLOAT_EQ(colour.red, 1.0f);
    EXPECT_FLOAT_EQ(colour.green, 1.0f);
    EXPECT_FLOAT_EQ(colour.blue, 1.0f);
}

TEST(ColourTest, ColourCreatedWithAllZeroValuesByDefaultConstructor) {
    Colour colour;

    EXPECT_FLOAT_EQ(colour.red, 0.0f);
    EXPECT_FLOAT_EQ(colour.green, 0.0f);
    EXPECT_FLOAT_EQ(colour.blue, 0.0f);
}

TEST(ColourAddition, AddsTwoColours) {
    Colour colour1 = Colour(0.9f, 0.6f, 0.75f);
    Colour colour2 = Colour(0.7f, 0.1f, 0.25f);

    Colour colour3 = colour1 + colour2;

    EXPECT_FLOAT_EQ(colour3.red, 1.6f);
    EXPECT_FLOAT_EQ(colour3.green, 0.7f);
    EXPECT_FLOAT_EQ(colour3.blue, 1.0f);
}

TEST(ColourSubtraction, SubtractsTwoColours) {
    Colour colour1 = Colour(0.9f, 0.6f, 0.75f);
    Colour colour2 = Colour(0.7f, 0.1f, 0.25f);

    Colour colour3 = colour1 - colour2;

    EXPECT_FLOAT_EQ(colour3.red, 0.2f);
    EXPECT_FLOAT_EQ(colour3.green, 0.5f);
    EXPECT_FLOAT_EQ(colour3.blue, 0.5f);
}

TEST(ColourMultiplication, MultipliesTwoColours) {
    Colour colour1 = Colour(1.0f, 0.2f, 0.4f);
    Colour colour2 = Colour(0.9f, 1.0f, 0.1f);

    Colour colour3 = colour1 * colour2;

    ASSERT_FLOAT_EQ(colour3.red, 0.9f);
    ASSERT_FLOAT_EQ(colour3.green, 0.2f);
    ASSERT_FLOAT_EQ(colour3.blue, 0.04f);

}

TEST(ColourMultiplication, MultipliesColourByScalar) {
    Colour colour1 = Colour(0.2f, 0.3f, 0.4f);

    Colour colour2 = colour1 * 2;
    ASSERT_FLOAT_EQ(colour2.red, 0.4f);
    ASSERT_FLOAT_EQ(colour2.green, 0.6f);
    ASSERT_FLOAT_EQ(colour2.blue, 0.8f);
}