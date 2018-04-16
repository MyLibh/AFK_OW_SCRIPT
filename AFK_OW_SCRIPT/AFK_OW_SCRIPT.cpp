#include <ctime>   // std::clock, std::time
#include <cstdlib> // std::srand
#include <string>  // std::to_string, std::string_view

#include "ClickEmulator.hpp"
#include "Debugger.hpp"

constexpr size_t KEYS_NUM  = 8,
			     MOUSE_NUM = 2,
			     TIME_DIFF = 100;

using namespace ClickEmulator;
using namespace NDebugger;

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	WORD keys[KEYS_NUM] = 
	{ 
		Keys::W,
		Keys::A, 
		Keys::S, 
		Keys::D, 
		Keys::E, 
		Keys::Q,
		Keys::SHIFT,
		Keys::SPACE
	};

	WORD mouse[MOUSE_NUM] =
	{
		MouseEvent::LEFTDOWN,
		MouseEvent::RIGHTDOWN
	};

	clock_t tmr     = std::clock();
	bool    enabled = false;
	
	Log(std::string_view("Script started"), std::clog);
	  
	for (size_t i = 0, j = 0; !GetAsyncKeyState(Keys::F10); i = rand() % KEYS_NUM, j = rand() % MOUSE_NUM)
	{
		if (GetAsyncKeyState(Keys::END))
		{
			enabled = !enabled;

			Log(std::string_view(enabled ? "Enabled" : "Disabled"), std::clog);
			SleepEx(6 * TIME_DIFF, FALSE);
		}
		
		if (enabled && std::difftime(std::clock(), tmr) > TIME_DIFF)
		{
			tmr = clock();

			PressKey(keys[i], TIME_DIFF);
			PressKey(keys[i], TIME_DIFF);
			PressMouse(mouse[j], TIME_DIFF);
			MoveMouse(MouseEvent::MOVE, nullptr, TIME_DIFF);

			Debug("Key=" + std::to_string(keys[i]) + ", mouse=" + std::to_string(mouse[j]), std::clog);
		}

		SleepEx(TIME_DIFF, FALSE);
	}
	Log(std::string_view("Script ended"), std::clog);

	system("pause");
	return 0;
}


