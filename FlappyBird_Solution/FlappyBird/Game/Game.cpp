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
static Texture2D background;
static Texture2D midground;
static Texture2D foreground;

float scrollingBack = 0.0f;
float scrollingMid = 0.0f;
float scrollingFore = 0.0f;

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
        background = LoadTextureFromImage(background_layer2);
        UnloadImage(background_layer2);

        background_layer3 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-mid-trees.png");
        ImageResize(&background_layer3, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        midground = LoadTextureFromImage(background_layer3);
        UnloadImage(background_layer3);

        background_layer4 = LoadImage("../Resources/parallax_demon_woods_pack/layers/parallax-demon-woods-close-trees.png");
        ImageResize(&background_layer4, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
        foreground = LoadTextureFromImage(background_layer4);
        UnloadImage(background_layer4);

    }

    void UpdateGame()
    {
        scrollingBack -= 0.1f;
        scrollingMid -= 0.5f;
        scrollingFore -= 1.0f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width * 2) scrollingBack = 0;
        if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
        if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;

        DrawGame();

    }

    void DrawGame() {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background_layer1_text, 0, 0, WHITE);
        DrawTextureEx(background, Vector2{ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(background, Vector2{ background.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

        // Draw midground 
        DrawTextureEx(midground, Vector2{ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(midground, Vector2{ midground.width * 2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

        // Draw foreground
        DrawTextureEx(foreground, Vector2{ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(foreground, Vector2{ foreground.width * 2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);

        DrawText("FlappyBerd!", currentScreenConfig.width/3, 100, 30, LIGHTGRAY);

        EndDrawing();
    }

    void UnloadGame()
    {
        UnloadTexture(background_layer1_text);
        UnloadTexture(background);
        UnloadTexture(midground);
        UnloadTexture(foreground);
        std::cout << "Game Unloaded." << '\n';
    }
}
