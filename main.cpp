#include <iostream>

#include "Canvas.h"
#include "tuple.h"
#include <fstream>

#include "PPMExporter.h"

struct Projectile {
    Tuple position;
    Tuple velocity;
};

struct Environment {
    Tuple gravity;
    Tuple wind;
};

Projectile tick(Environment environment, Projectile projectile) {
    Tuple position = projectile.position + projectile.velocity;
    Tuple velocity = projectile.velocity + environment.gravity + environment.wind;

    return Projectile(position, velocity);
}


int main() {
    /*Projectile projectile {
        .position = Tuple::point(0.0f, 1.0f, 0.0f),
        .velocity = Tuple::vector(1.0f, 1.0f, 1.0f).normalised()
    };

    Environment environment {
        .gravity = Tuple::vector(0.0f, -0.1f, 0.0f),
        .wind = Tuple::vector(-0.01f, 0.0f, 0.0f),
    };*/


    /*
    int ticks = 0;
    while (projectile.position.y > 0.0f) {
        projectile = tick(environment, projectile);
        ticks++;
        std::cout << "Tick: " << ticks
                  << " | Position: (" << projectile.position.x << ", "
                  << projectile.position.y << ", " << projectile.position.z << ")\n";
    }
    */


    auto start = Tuple::point(0.0f, 1.0f, 0.0f);
    auto vel = Tuple::vector(1.0f, 1.8f, 0.0f).normalised() * 11.25;
    Projectile projectile {
        .position = start,
        .velocity = vel,
    };

    auto gravity = Tuple::vector(0.0f, -0.1f, 0.0f);
    auto wind = Tuple::vector(-0.01f, 0.0f, 0.0f);

    Environment environment {
        .gravity = gravity,
        .wind = wind,
    };

    Canvas canvas = Canvas(900, 500);
    Colour colour = Colour(1.0f, 0.0f, 0.0f);

    int ticks = 0;
    while (projectile.position.y > 0.0f) {
        projectile = tick(environment, projectile);
        ticks++;
        std::cout << "Tick: " << ticks
                << " | Position: (" << projectile.position.x << ", "
                << projectile.position.y << ", " << projectile.position.z << ")\n";

        int x = static_cast<int>(projectile.position.x);
        int y = 500 - static_cast<int>(projectile.position.y);

        if (x >= 0 && x < canvas.width && y >= 0 && y < canvas.height) {
            canvas.writePixel(x, y, colour);
        }

    }



    // write canvas to ppm file.
    std::ofstream outfile("canvas.ppm");
    outfile << PPMExporter::exportCanvas(canvas);

    return 0;
}
