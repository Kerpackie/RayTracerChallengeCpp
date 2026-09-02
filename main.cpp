#include <iostream>

#include "tuple.h"

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
    Projectile projectile {
        .position = Tuple::point(0.0f, 1.0f, 0.0f),
        .velocity = Tuple::vector(1.0f, 1.0f, 1.0f).normalised()
    };

    Environment environment {
        .gravity = Tuple::vector(0.0f, -0.1f, 0.0f),
        .wind = Tuple::vector(-0.01f, 0.0f, 0.0f),
    };


    int ticks = 0;
    while (projectile.position.y > 0.0f) {
        projectile = tick(environment, projectile);
        ticks++;
        std::cout << "Tick: " << ticks
                  << " | Position: (" << projectile.position.x << ", "
                  << projectile.position.y << ", " << projectile.position.z << ")\n";
    }

    return 0;
}
