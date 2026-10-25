
#include "raylib.h"
#include <cmath>

int main()
{
    
    const int screenWidth = 900;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Circular Motion");
    SetTargetFPS(60);

    
    const double radius = 3.0;          
    const double speed = 5.0;           
    const double mass = 1.0;
    const double angularVelocity = speed / radius; 

    
    const float pixelsPerMetre = 120.0f;
    const float orbitRadius = static_cast<float>(radius) * pixelsPerMetre;

    const Vector2 center = {
        screenWidth / 2.0f,
        screenHeight / 2.0f
    };

    double time = 0.0;

    while (!WindowShouldClose())
    {
        const double dt = GetFrameTime();
        time += dt;

        
        const double angle = angularVelocity * time;

        const Vector2 position = {
            center.x + orbitRadius * static_cast<float>(std::cos(angle)),
            center.y + orbitRadius * static_cast<float>(std::sin(angle))
        };

        
        const double centripetalAcceleration = (speed * speed) / radius;
        const double centripetalForce = mass * centripetalAcceleration;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        DrawCircleLines(
            static_cast<int>(center.x),
            static_cast<int>(center.y),
            orbitRadius,
            LIGHTGRAY
        );

        
        DrawCircleV(center, 6.0f, DARKBLUE);

        
        DrawCircleV(position, 12.0f, RED);

        EndDrawing();

        
        (void)centripetalForce;
        (void)centripetalAcceleration;
    }

    CloseWindow();
    return 0;
}
