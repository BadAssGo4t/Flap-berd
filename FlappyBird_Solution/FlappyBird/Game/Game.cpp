#include "Game.h"
#include "Screen_Manager.h"


namespace ScreenManager
{
    extern 	ScreenConfig currentScreenConfig;
}

using namespace ScreenManager;

static Image background_layer1;
static Image background_layer2;
static Image background_layer3;
static Image background_layer4;

static Texture2D background_layer1_text;
static Texture2D background_layer2_text;
static Texture2D background_layer3_text;
static Texture2D background_layer4_text;

namespace Game
{


    void InitGame() // Init
    {
        currentScreenConfig.name = "FlappyBird - Game";
        SetWindowTitle(currentScreenConfig.name);

        background_layer1 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-bg.png");
        ImageResize(&background_layer1, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        background_layer1_text = LoadTextureFromImage(background_layer1);
        UnloadImage(background_layer1);

        background_layer2 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-far-trees.png");
        ImageResize(&background_layer2, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        background_layer2_text = LoadTextureFromImage(background_layer2);
        UnloadImage(background_layer2);

        background_layer3 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-mid-trees.png");
        ImageResize(&background_layer3, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        background_layer3_text = LoadTextureFromImage(background_layer3);
        UnloadImage(background_layer3);

        background_layer4 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-close-trees.png");
        ImageResize(&background_layer4, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        background_layer4_text = LoadTextureFromImage(background_layer4);
        UnloadImage(background_layer4);

    }

    void UpdateGame()
    {
        DrawGame();

    }

    void DrawGame() {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background_layer1_text, 0, 0, WHITE);
        DrawTexture(background_layer2_text, 0, 0, WHITE);
        DrawTexture(background_layer3_text, 0, 0, WHITE);
        DrawTexture(background_layer4_text, 0, 0, WHITE);

        DrawText("FlappyBerd!", currentScreenConfig.width/3, 100, 40, LIGHTGRAY);

        EndDrawing();
    }

    void UnloadGame()
    {
        UnloadTexture(background_layer1_text);
        UnloadTexture(background_layer2_text);
        UnloadTexture(background_layer3_text);
        UnloadTexture(background_layer4_text);
        std::cout << "Game Unloaded." << '\n';
    }
}
