/*******************************************************************************************
 *
 *   raylib [core] example - input mouse
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 5.5
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

//------------------------------------------------------------------------------------
// eval cc core_input_mouse.c $(pkg-config --libs --cflags raylib) -o core_input_mouse.out
// eval cc core_input_mouse.c $(pkg-config --libs --cflags raylib) -o core_input_mouse.out
//------------------------------------------------------------------------------------
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse");

    Vector2 ballPosition = {-100.0f, -100.0f};
    Color ballColor = DARKBLUE;

    SetTargetFPS(60);
    //------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // detect window close button or ESC
    {
        // Update
        //------------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_H))
        {
            if (IsCursorHidden())
                ShowCursor();
            else
                HideCursor();
        }

        ballPosition = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            ballColor = MAROON;
        else if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
            ballColor = LIME;
        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
            ballColor = DARKBLUE;
        else if (IsMouseButtonDown(MOUSE_BUTTON_SIDE))
            ballColor = PURPLE;
        else if (IsMouseButtonDown(MOUSE_BUTTON_EXTRA))
            ballColor = YELLOW;
        else if (IsMouseButtonDown(MOUSE_BUTTON_FORWARD))
            ballColor = ORANGE;
        else if (IsMouseButtonDown(MOUSE_BUTTON_BACK))
            ballColor = BEIGE;
        //------------------------------------------------------------------------------------

        // Draw
        //------------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, 50, ballColor);
        DrawText("Move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY);
        DrawText("Press 'H' to toggle cursor visility", 10, 30, 20, DARKGRAY);

        if (IsCursorHidden())
            DrawText("CURSOR HIDDEN", 20, 60, 20, RED);
        else
            DrawText("CURSOR VISIBLE", 20, 60, 20, LIME);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
