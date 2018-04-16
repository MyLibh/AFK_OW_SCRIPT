#include <string> // std::to_string, std::string_view

#include "ClickEmulator.hpp"
#include "Debugger.hpp"

using namespace NDebugger;

namespace ClickEmulator
{

#pragma region FUNCTION_DEFINITION

	bool PressKey(WORD key, DWORD time)
	{
		INPUT input = { INPUT_KEYBOARD };
		input.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
		input.ki.wVk   = key;

		if (SendInput(1, &input, sizeof(INPUT)) != 1)
		{
			Error(std::string_view("Cannot send input(INPUT_KEYBOARD) with key '" + std::to_string(key) + "'"), std::cerr);

			return FALSE;
		}
		Sleep(time);

		input.ki.dwFlags = KEYEVENTF_KEYUP;
		if (SendInput(1, &input, sizeof(INPUT)) != 1)
		{
			Error(std::string_view("Cannot send input(INPUT_KEYBOARD) with key '" + std::to_string(key) + "' and flag(KEYEVENTF_KEYUP)"), std::cerr);

			return FALSE;
		}

		return TRUE;
	}

	bool PressMouse(WORD key, DWORD time)
	{
		INPUT input = { INPUT_MOUSE };
		input.mi.dwFlags = key;

		if (SendInput(1, &input, sizeof(INPUT)) != 1)
		{
			Error(std::string_view("Cannot send input(INPUT_MOUSE) with flag(" + std::to_string(key) + ")"), std::cerr);

			return FALSE;
		}
		Sleep(time);

		input.mi.dwFlags = (key <<= 1);
		if (SendInput(1, &input, sizeof(INPUT)) != 1)
		{
			Error(std::string_view("Cannot send input(INPUT_MOUSE) with flag(" + std::to_string(key) + ")"), std::cerr);

			return FALSE;
		}

		return TRUE;
	}

	bool MoveMouse(WORD event, const PPOINT cPoint, DWORD time)
	{
		static const INT WIDTH  = GetSystemMetrics(SM_CXSCREEN),
			             HEIGHT = GetSystemMetrics(SM_CYSCREEN);

		static auto calc = [](INT size) -> LONG { return ((rand() % (size >> 2)) * (!(rand() % 2 == 0) ? -1 : 1)); };

		INPUT input = { INPUT_MOUSE };
		input.mi.dx      = cPoint ? cPoint->x : calc(WIDTH);
		input.mi.dy      = cPoint ? cPoint->y : calc(HEIGHT);
		input.mi.dwFlags = event;

		if (SendInput(1, &input, sizeof(INPUT)) != 1)
		{
			Error(std::string_view("Cannot send input(INPUT_MOUSE) with flag(" + std::to_string(event) + ") and dx=" + std::to_string(input.mi.dx) + ", dy=" + std::to_string(input.mi.dy)), std::cerr);

			return FALSE;
		}
		Sleep(time);

		return TRUE;
	}
#pragma endregion

} // namespace ClickEmulator