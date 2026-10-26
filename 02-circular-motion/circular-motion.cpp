
#include "raylib.h"
#include <cmath>

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Circular Motion");
    SetTargetFPS(60);

    // Physics parameters
    const double radius = 3.0;
    const double speed = 5.0;
    const double mass = 1.0;
    const double angularVelocity = speed / radius;

    const float pixelsPerMetre = 80.0f;
    const float orbitRadius =
        static_cast<float>(radius) * pixelsPerMetre;

    const Vector2 center = {650.0f, 350.0f};

    double time = 0.0;

    while (!WindowShouldClose())
    {
        const double dt = GetFrameTime();
        time += dt;

        const double angle = angularVelocity * time;

        const Vector2 position = {
            center.x + orbitRadius *
                static_cast<float>(std::cos(angle)),
            center.y + orbitRadius *
                static_cast<float>(std::sin(angle))
        };

        const double acceleration = (speed * speed) / radius;
        const double force = mass * acceleration;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Title
        DrawText("Circular Motion", 30, 25, 28, BLACK);
        DrawText("Uniform circular motion", 30, 62, 18, DARKGRAY);
        DrawLine(30, 95, 970, 95, LIGHTGRAY);

        // Physics information
        DrawText("PHYSICS", 30, 125, 18, DARKGRAY);

        DrawText("Speed", 30, 170, 18, GRAY);
        DrawText(TextFormat("%.2f m/s", speed),
                 30, 195, 24, BLACK);

        DrawText("Radius", 30, 245, 18, GRAY);
        DrawText(TextFormat("%.2f m", radius),
                 30, 270, 24, BLACK);

        DrawText("Mass", 30, 320, 18, GRAY);
        DrawText(TextFormat("%.2f kg", mass),
                 30, 345, 24, BLACK);

        DrawLine(30, 395, 270, 395, LIGHTGRAY);

        DrawText("Centripetal acceleration",
                 30, 420, 17, DARKGRAY);
        DrawText(TextFormat("%.2f m/s^2", acceleration),
                 30, 445, 24, BLACK);

        DrawText("Centripetal force",
                 30, 500, 17, DARKGRAY);
        DrawText(TextFormat("%.2f N", force),
                 30, 525, 24, BLACK);

        // Circular path
        DrawCircleLines(
            static_cast<int>(center.x),
            static_cast<int>(center.y),
            orbitRadius,
            LIGHTGRAY
        );

        // Radius line
        DrawLineEx(center, position, 2.0f, BLUE);

        // Centre and moving object
        DrawCircleV(center, 5.0f, DARKBLUE);
        DrawCircleV(position, 11.0f, RED);

        DrawText("Centre",
                 static_cast<int>(center.x + 12),
                 static_cast<int>(center.y + 8),
                 16, DARKGRAY);

        DrawText("Object",
                 static_cast<int>(position.x + 15),
                 static_cast<int>(position.y - 10),
                 16, DARKGRAY);

        DrawLine(30, 645, 970, 645, LIGHTGRAY);
        DrawText("ESC to exit", 30, 660, 16, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
