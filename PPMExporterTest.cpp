//
// Created by kerpackie on 03/09/2026.
//

#include "Canvas.h"
#include "PPMExporter.h"
#include <cmath>

#include <gtest/gtest.h>

static std::vector<std::string> splitLines(const std::string& text) {
    std::vector<std::string> lines;
    std::istringstream stream(text);
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }

    return lines;
}

TEST(PPMExporterTest, PPMStratsWithCorrectHeader) {
    Canvas canvas = Canvas(5, 3);

    const std::string test_header =
        "P3\n"
        "5 3\n"
        "255\n";

    std::string ppmCanvas = PPMExporter::exportCanvas(canvas);

    ASSERT_EQ(ppmCanvas.substr(0, test_header.length()), test_header);
}

TEST(PPMExporterTest, PPMPixelDataConstructsCorrectly) {
    Canvas canvas = Canvas(5, 3);
    Colour colour1 = Colour(1.5, 0, 0);
    Colour colour2 = Colour(0, 0.5, 0);
    Colour colour3 = Colour(-0.5, 0, 1);

    canvas.writePixel(0, 0, colour1);
    canvas.writePixel(2, 1, colour2);
    canvas.writePixel(4, 2, colour3);

    std::string ppmCanvas = PPMExporter::exportCanvas(canvas);

    std::vector<std::string> lines = splitLines(ppmCanvas);

    std::string line1 = "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
    std::string line2 = "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0";
    std::string line3 = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255";

    ASSERT_EQ(lines[3], line1);
    ASSERT_EQ(lines[4], line2);
    ASSERT_EQ(lines[5], line3);
}

TEST(PPMExporterTest, PPMEndsWithNewlineCharacters) {
    Canvas canvas = Canvas(5, 3);
    std::string ppmCanvas = PPMExporter::exportCanvas(canvas);

    ASSERT_EQ(ppmCanvas.ends_with('\n'), true);
}

TEST(PPMExporterTest, PPMLinesCannotBeLongerThan70Chars) {
    Canvas canvas = Canvas(10, 2);
    std::string ppmCanvas = PPMExporter::exportCanvas(canvas);

    for (auto lines = splitLines(ppmCanvas); const auto& line: lines) {
        ASSERT_LE(line.length(), 70);
    }
}

