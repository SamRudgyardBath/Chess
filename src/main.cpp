#include <iostream>
#include <raylib.hpp>
#include <raymath.hpp>
#include <deque>

#include <game.hpp>

double lastUpdateTime = 0.;
bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << "Starting the game..." << endl;
    InitWindow(2*offset + cellSize*8, 2*offset + cellSize*8, "Chess");
    // SetTargetFPS(30);

    Game game = Game();

    // Game Loop
    while(WindowShouldClose() == false) {
        BeginDrawing();

        game.Update();

        // Drawing
        ClearBackground(background);
        DrawText(TextFormat("FPS: %i", GetFPS()), offset, 0, 40, WHITE);
        DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), 5 * cellSize, 0, 40, WHITE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
} 