#pragma once

//====================================================================================================================================
//!
//!	\file   ClickEmulator.hpp
//!
//! \brief	Header file for emulating mouse/keyboard for Windows 
//!
//====================================================================================================================================

#ifndef __cplusplus
#error
#error  Must use C++ to compile.
#error
#endif /* __cplusplus */

#if !defined (WIN32) && !defined (__WIN32__) && !defined(_WIN32) && !defined(_WIN32_WINNT)
#error
#error  Windows is the only supported system.
#error
#endif /* !defined (WIN32) && !defined (__WIN32__) && !defined(_WIN32) && !defined(_WIN32_WINNT) */

typedef unsigned short WORD;
typedef unsigned long DWORD;

struct tagPOINT;
typedef tagPOINT *PPOINT;

namespace ClickEmulator
{

#pragma region ENUMS

	enum Mouse : WORD
	{
		LBUTTON = 0x01,
		RBUTTON,
		MBUTTON = 0x04,
		XBUTTON1,
		XBUTTON2
	};

	enum Keys : WORD
	{
		BACK  = 0x08,
		TAB,
		CLEAR = 0x0C,
		ENTER,
		SHIFT = 0x10,
		CTRL,
		ALT,
		PAUSE,
		CAPSLOCK,
		ESC   = 0x1B,
		SPACE = 0x20,
		PAGEUP,
		PAGEDOWN,
		END,
		HOME,
		LEFT,
		UP,
		RIGHT,
		DOWN,
		SELECT,
		PRINT,
		EXECUTE,
		PRINTSCREEN,
		INSERT,
		DEL,
		HELP,
		K0,
		K1,
		K2,
		K3,
		K4,
		K5,
		K6,
		K7,
		K8,
		K9,
		A = 0x41,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		LWIN,
		RWIN,
		APPS,
		SLEEP = 0x5F,
		NUM0,
		NUM1,
		NUM2,
		NUM3,
		NUM4,
		NUM5,
		NUM6,
		NUM7,
		NUM8,
		NUM9,
		MUL,
		ADD,
		SEPARATOR,
		SUB,
		DEC,
		DIV,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9, 
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,
		F16,
		F17,
		F18,
		F19,
		F20,
		F21,
		F22,
		F23,
		F24,
		NUM = 0x90,
		SCROLL
	};

	enum MouseEvent : WORD // MOUSEEVENTF_***
	{
		MOVE            = 0x0001,
		LEFTDOWN        = 0x0002, 
		LEFTUP          = 0x0004,
		RIGHTDOWN       = 0x0008, 
		RIGHTUP         = 0x0010,
		MIDDLEDOWN      = 0x0020,
		MIDDLEUP        = 0x0040,
		XDOWN           = 0x0080,
		XUP             = 0x0100,
		WHEEL           = 0x0800,
		HWHEEL          = 0x1000,
		MOVE_NOCOALESCE = 0x2000,
		VIRTUALDESK     = 0x4000,
		ABS             = 0x8000 // ABSOLUTE
	};

#pragma endregion

#pragma region FUNCTION_DECLARATION

	//====================================================================================================================================
	//!
	//! \brief	 Emulates key pressing
	//!
	//! \param   key    Key to emulate
	//! \param   delay  Delay to wait
	//!
	//! \return  Success of the function
	//!
	//! \throw   std::runtime_error     
	//!
	//====================================================================================================================================

	bool PressKey(WORD key, DWORD delay);

	//====================================================================================================================================
	//!
	//! \brief	 Emulates mouse pressing
	//!
	//! \param   button  Button to emulate
	//! \param   time    Delay to wait
	//!
	//! \return  Success of the function
	//!
	//! \throw   std::runtime_error     
	//!
	//====================================================================================================================================

	bool PressMouse(WORD button, DWORD delay);

	//====================================================================================================================================
	//!
	//! \brief	 Emulates mouse moving
	//!
	//! \param   event   Mouse move event
	//! \param   cPoint  Dx/Dy for moving, if nullptr then uses special formula
	//! \param   delay   Delay to wait
	//!
	//! \return  Success of the function
	//!
	//! \throw   std::runtime_error     
	//!
	//====================================================================================================================================

	bool MoveMouse(WORD event, const PPOINT cPoint, DWORD delay);

#pragma endregion

} // namespace ClickEmulator
