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
    SetTargetFPS(30);

    Game game = Game();

    // Game Loop
    while(WindowShouldClose() == false) {
        BeginDrawing();

        if (EventTriggered(0.2)) {
            game.Update();
        }

        // Drawing
        ClearBackground(background);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
} 