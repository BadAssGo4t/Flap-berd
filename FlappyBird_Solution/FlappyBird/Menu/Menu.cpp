#include "Menu.h"
#include "Screen_Manager.h"

namespace ScreenManager
{
	extern 	ScreenConfig currentScreenConfig;
}

using namespace ScreenManager;

namespace Menu
{
	Button::NewBasicButton playBttn;

	static Image background;
	static Texture2D backgroundTex;
	static Vector2 mousePoint;



	void InitMenu()
	{
		// Setting up screen
		currentScreenConfig.width = 1024.0f;
		currentScreenConfig.height = 768.0f;
		currentScreenConfig.name = "Asteroids - Menu";

		InitWindow(static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height), currentScreenConfig.name);

		//Setting up Buttons
		playBttn.setBounds(currentScreenConfig.width / 4, currentScreenConfig.height / 14, currentScreenConfig.width / 2, (currentScreenConfig.height / 15) * 4 /*height based on the division of the screen*/);
		playBttn.setBasicButton({ 80, 80, 80, 255 }/*DARKGRAY*/, "Play");
		//end

		background = LoadImage("../Resources/Backgrounds/BlueWave.png");
		ImageResize(&background, static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
		backgroundTex = LoadTextureFromImage(background);
		UnloadImage(background);

		std::cout << "Finished Menu Init";
	}


	void UpdateMenu()
	{
		DrawMenu();

		mousePoint = GetMousePosition();



		if (CheckCollisionPointRec(mousePoint, playBttn.Bounds)) //Checks state of the DEV BTTN
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) { playBttn.changeColor({ 255, 203, 0, 255 }); }
			else playBttn.changeColor({ 200, 200, 200, 255 });

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { playBttn.Action = true; }
		}
		else playBttn.changeColor({ 80, 80, 80, 255 });

		if (playBttn.Action)
		{
			std::cout << "action";
			playBttn.Action = false;
			Game::InitGame();
			Screens = GameScreen;
		}
	}

	void DrawMenu() {

		BeginDrawing();

		ClearBackground(GetColor(0x052c46ff));

		DrawTexture(backgroundTex, 0, 0, WHITE);

		DrawRectangleRec(playBttn.Bounds, playBttn.btnColor);
		DrawRectangleLinesEx(playBttn.Bounds, playBttn.frame, BLACK);
		DrawText(playBttn.name, static_cast<int>(currentScreenConfig.width) / 2 - MeasureText(playBttn.name, 30) / 2, static_cast<int>(playBttn.Bounds.y) + 15, 30, BLACK);

		EndDrawing();
	}

	void UnloadMenu()
	{
		UnloadTexture(backgroundTex);
		std::cout << "Menu Unloaded." << '\n';
	}
}

