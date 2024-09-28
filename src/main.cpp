#include <raylib.h>
#include <Polygon.hpp>

int main() {
    InitWindow(1280, 720, "Polytest");
    SetTargetFPS(60);

    Polygon poly({{200.f, 100.f}, {400.f, 100.f}, {350.f, 300.f}, {250.f, 300.f}});
    Polygon player({{10.f, 10.f}, {20.f, 10.f}, {20.f, 20.f}, {10.f, 20.f}});

    while(!WindowShouldClose()) {
        float speedX = 0.f;
        float speedY = 0.f;

        if(IsKeyDown(KEY_W)) {
            speedY -= 3.0f;
        }

        if(IsKeyDown(KEY_S)) {
            speedY += 3.0f;
        }

        if(IsKeyDown(KEY_A)) {
            speedX -= 3.0f;
        }

        if(IsKeyDown(KEY_D)) {
            speedX += 3.0f;
        }

        if(IsKeyPressed(KEY_R)) {
            player = Polygon({{10.f, 10.f}, {20.f, 10.f}, {20.f, 20.f}, {10.f, 20.f}});
        }

        speedX = poly.flipCollideX(player, speedX);
        player.move(speedX, 0.0f);

        speedY = poly.flipCollideY(player, speedY);
        player.move(0.0f, speedY);

        BeginDrawing();
            ClearBackground(BLACK);

            poly.draw();
            player.draw();
        EndDrawing();
    }

    CloseWindow();
}