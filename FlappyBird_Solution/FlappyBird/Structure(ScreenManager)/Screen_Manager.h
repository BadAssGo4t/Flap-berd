#pragma once

#include <iostream>
#include "raylib.h"

#include "Main.h"
#include "Menu.h"
#include "Game.h"

#include "Buttons.h"


namespace ScreenManager
{
	struct   ScreenConfig
	{
		float width;
		float height;
		const char* name;
	};

	enum GameScreens
	{
		MenuScreen = 0,
		GameScreen,
		InstructionsScreen,
		CreditsScreen,
		End
	};
	extern GameScreens Screens;


	int ScreenManager();
	void SetMenuWindow();
}