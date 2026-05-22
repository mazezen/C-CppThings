#include "raylib.h"

// eval cc core_input_mouse_wheel.c $(pkg-config --libs --cflags raylib) -o core_input_mouse_wheel.out
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel");

    int boxPositionY = screenHeight / 2 - 40;
    int boxPositionX = screenWidth / 2 - 40;
    int boxSpeed = 4;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // MOVE
        boxPositionY -= (int)(GetMouseWheelMove() * boxSpeed);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(boxPositionX, boxPositionY, 80, 80, MAROON);

        DrawText("Use mouse wheel to move the cube up and down", 10, 10, 20, GRAY);
        DrawText(TextFormat("Box position Y: %03f", boxPositionY), 10, 40, 20, LIGHTGRAY);

        EndDrawing();
    }

    // close
    CloseWindow();

    return 0;
}
