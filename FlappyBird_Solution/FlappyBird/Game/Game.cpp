#include "Game.h"
#include "Screen_Manager.h"


namespace ScreenManager
{
    extern 	ScreenConfig currentScreenConfig;
}

using namespace ScreenManager;


namespace Game
{


    void InitGame() // Init
    {
        currentScreenConfig.name = "FlappyBird - Game";
        SetWindowTitle(currentScreenConfig.name);
    }

    void UpdateGame()
    {
        DrawGame();

    }

    void DrawGame() {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    void UnloadGame()
    {
        std::cout << "Game Unloaded." << '\n';
    }
}
