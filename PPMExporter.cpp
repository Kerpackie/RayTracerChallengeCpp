//
// Created by kerpackie on 03/09/2026.
//

#include "PPMExporter.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace {
    std::string buildHeader(const int width, const int height) {
        return "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
    }

    int scaleTo255(float val) {
        float clampedVal = std::ranges::clamp(val, 0.0f, 1.0f);
        return static_cast<int>(std::round(clampedVal * 255.0f));
    }

    std::string buildPixelData(const Canvas& canvas) {
        std::string pixelData;

        for (int y = 0; y < canvas.height; y++) {
            size_t currentLineLength = 0;

            for (int x = 0; x < canvas.width; x++) {
                Colour colour = canvas.getPixel(x, y);

                int components[3] = {
                    scaleTo255(colour.red),
                    scaleTo255(colour.green),
                    scaleTo255(colour.blue),
                };

                for (int component: components) {
                    std::string numString = std::to_string(component);

                    if (currentLineLength + numString.length() + 1 > 70) {
                        pixelData += '\n';
                        pixelData += numString;
                        currentLineLength = numString.length();
                    } else {
                        if (currentLineLength > 0) {
                            pixelData += ' ';
                            currentLineLength++;
                        }
                        pixelData += numString;
                        currentLineLength += numString.length();
                    }
                }
            }
            pixelData += '\n';
        }

        return pixelData;
    }


}

std::string PPMExporter::exportCanvas(const Canvas &canvas) {
    return buildHeader(canvas.width, canvas.height) + buildPixelData(canvas);
}
