// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Debugger.hpp"

namespace NDebugger
{

#pragma region FUNCTION_DEFINITION

	WORD GetConsoleColor()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbf;
	
		if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbf))
			throw std::runtime_error("Could not get console text attributes\n");

		return csbf.wAttributes;
	}

	WORD SetConsoleColor(WORD color)
	{
		WORD old = GetConsoleColor();

		if (!SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
			throw std::runtime_error("Could not set console text attributes\n");

		return old;
	}

	WORD SetConsoleColor(Colors color, Colors background /* = TextColor::Black */)
	{
		return SetConsoleColor((static_cast<WORD>(background) << 4) | static_cast<WORD>(color));
	}

#pragma endregion

} // namespace NDebugger

