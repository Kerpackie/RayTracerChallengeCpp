//
// Created by kerpackie on 02/09/2026.
//

#include "Canvas.h"
#include <cmath>

#include <gtest/gtest.h>

TEST(CanvasTest, CanvasCreatesWithCorrectHeightWidth) {
    Canvas canvas = Canvas(10, 20);

    EXPECT_EQ(canvas.height, 20);
    EXPECT_EQ(canvas.width, 10);
}

TEST(CanvasTest, CanvasCreatesWithAllBlack) {
    Canvas canvas = Canvas(10, 20);

    for (auto pixel: canvas.pixels) {
        EXPECT_FLOAT_EQ(pixel.red, 0.0f);
        EXPECT_FLOAT_EQ(pixel.green, 0.0f);
        EXPECT_FLOAT_EQ(pixel.blue, 0.0f);
    }
}

TEST(CanvasTest, CanvasCreatesCorrectSize) {
    Canvas canvas = Canvas(10, 20);

    EXPECT_EQ(canvas.pixels.size(), 200);
}

TEST(CanvasPixelTest, GetPixelAtXYReturnsPixel) {
    Canvas canvas = Canvas(10, 20);
    Colour red = Colour(1.0f, 0.0f, 0.0f);

    canvas.pixels[0] = red;

    EXPECT_EQ(canvas.getPixel(0,0), red);

}

TEST(CanvasPixelTest, WritePixelToCanvas) {
    Canvas canvas = Canvas(10, 20);
    Colour red = Colour(1.0f, 0.0f, 0.0f);

    canvas.writePixel(2, 3, red);

    EXPECT_EQ(canvas.getPixel(2,3), red);
}

TEST(CanvasPixelTest, GetColourOutOfBoundsReturnsDefaultColour) {
    Canvas canvas = Canvas(10, 20);
    Colour default_colour = {};
    Colour out_of_bounds_colour = canvas.getPixel(-1, 0);

    EXPECT_EQ(out_of_bounds_colour, default_colour);
}