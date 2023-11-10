#include "Screen_Manager.h"

namespace ScreenManager
{
	ScreenConfig currentScreenConfig;

	static void Change();

	GameScreens Screens;

	int ScreenManager()
	{
		SetTargetFPS(60);

		Menu::InitMenu();

		while (!WindowShouldClose())
		{
			Change();
		}

		CloseWindow();
		Menu::UnloadMenu();
		//Unloader::UnloadAll();
		return 0;
	}


	static void Change()
	{
		switch (Screens)
		{

		case MenuScreen: {
			Menu::UpdateMenu();
		} break;
		case GameScreen: {
			Game::UpdateGame();
		} break;

		}
	}

	void SetWindow()
	{
		SetWindowSize(static_cast<int>(currentScreenConfig.width), static_cast<int>(currentScreenConfig.height));
		SetWindowTitle(currentScreenConfig.name);
	}
}