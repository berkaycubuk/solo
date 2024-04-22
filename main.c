/*
* Solo v0.1.0
*/

#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const char* SCREEN_TITLE = "Solo v0.1.0";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 1.0f, 0.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(camera);
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);
            EndMode3D();

            DrawText(SCREEN_TITLE, 20, 20, 10, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
