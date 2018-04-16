#pragma once

//====================================================================================================================================
//!
//!	\file   Debugger.hpp
//!
//! \brief	Header file for displaying information in a stream in different colors for Windows 
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

#include <Windows.h>   // GetStdHandle, SetConsoleTextAttribute
#include <iostream>    // std::basic_ostream
#include <string_view> // std::basic_string_view

namespace NDebugger
{

#pragma region ENUMS

	enum class Colors : WORD
	{
		Black        = 0x00,
		Blue         = 0x01,
		Green        = 0x02,
		Cyan         = 0x03,
		Red          = 0x04,
		Magenta      = 0x05,
		Brown        = 0x06,
		LightGray    = 0x07,
		DarkGray     = 0x08,
		LightBlue    = 0x09,
		LightGreen   = 0x0A,
		LightCyan    = 0x0B,
		LightRed     = 0x0C,
		LightMagenta = 0x0D,
		Yellow       = 0x0E,
		White        = 0x0F
	};

#pragma endregion
	
#pragma region FUNCTION_DECLARATION

//====================================================================================================================================
//!
//! \brief	 Gets console color
//!
//! \return  Current console text attributes
//!
//! \throw   std::runtime_error  
//!
//! \note    For STD_OUTPUT_HANDLE
//! 
//====================================================================================================================================

	WORD GetConsoleColor();
 
//====================================================================================================================================
//!
//! \brief	 Sets console color
//!
//! \param   color  Text and background as WORD
//!
//! \return  Previous console text attributes
//!
//! \throw   std::runtime_error  
//!
//! \note    For STD_OUTPUT_HANDLE
//! 
//====================================================================================================================================

	WORD SetConsoleColor(WORD color);

//====================================================================================================================================
//!
//! \brief	 Sets console color
//!
//! \param   text        Text color
//! \param   background  Background color
//!
//! \return  Previous console text attributes
//!
//! \throw   std::runtime_error     
//!
//! \note    For STD_OUTPUT_HANDLE
//! 
//====================================================================================================================================

	WORD SetConsoleColor(Colors text, Colors background = Colors::Black);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[ERROR] message\n' ([ERROR] in red)
//!
//! \param  message  Message for output
//! \param  rOstr    Stream for output
//!
//! \throw  std::runtime_error     
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	void Error(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[ERROR] message\n' ([ERROR] in red)
//!
//! \param  crMessage  Message for output
//! \param  rOstr      Stream for output
//!
//! \throw  std::runtime_error     
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	inline void Error(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[LOG] message\n' ([LOG] in light blue)
//!
//! \param  message  Message for output
//! \param  rOstr    Stream for output
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	void Log(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[LOG] message\n' ([LOG] in light blue)
//!
//! \param  crMessage  Message for output
//! \param  rOstr      Stream for output
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	inline void Log(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[DEBUG] message\n' ([DEBUG] in brown)
//!
//! \param  message  Message for output
//! \param  rOstr    Stream for output
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	void Debug(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as '[DEBUG] message\n' ([DEBUG] in brown)
//!
//! \param  crMessage  Message for output
//! \param  rOstr      Stream for output
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	inline void Debug(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr);

//====================================================================================================================================
//!
//! \brief	Outputs message as 'message' (in color)
//!
//! \param  message  Message for output
//! \param  rOstr    Stream for output
//! \param  color    Text color
//! \param  bckg     Background color
//! \param  endl     Should put std::endl in the end
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	void Text(std::basic_string_view<Char, Traits>  message, 
		      std::basic_ostream<Char, Traits>     &rOstr, 
		      Colors                                color = Colors::LightGray, 
		      Colors                                bckg  = Colors::Black,
		      bool                                  endl  = true);

//====================================================================================================================================
//!
//! \brief	Outputs message as 'message' (in color)
//!
//! \param  crMessage  Message for output
//! \param  rOstr      Stream for output
//! \param  color      Text color
//! \param  bckg       Background color
//! \param  endl       Should put std::endl in the end
//!
//! \throw  std::runtime_error 
//!
//====================================================================================================================================

	template<typename Char, typename Traits = std::char_traits<Char>>
	inline void Text(const std::basic_string<Char, Traits> &crMessage,
		             std::basic_ostream<Char, Traits>      &rOstr,
		             Colors                                 color = Colors::LightGray,
		             Colors                                 bckg  = Colors::Black,
		             bool                                   endl  = true);

#pragma endregion 

#pragma region FUNCTION_DEFINITION

	template<typename Char, typename Traits>
	void Error(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr)
	{
		auto old = SetConsoleColor(Colors::Red);

		rOstr << "[ERROR] ";

		SetConsoleColor(old);

		rOstr << message.data() << std::endl;
	}

	template<typename Char, typename Traits>
	inline void Error(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr)
	{
		Error(std::basic_string_view<Char, Traits>(crMessage), rOstr);
	}

	template<typename Char, typename Traits>
	void Log(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr)
	{
		auto old = SetConsoleColor(Colors::LightBlue);

		rOstr << "[LOG] ";

		SetConsoleColor(old);

		rOstr << message.data() << std::endl;
	}

	template<typename Char, typename Traits>
	inline void Log(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr)
	{
		Log(std::basic_string_view<Char, Traits>(crMessage), rOstr);
	}

	template<typename Char, typename Traits>
	void Debug(std::basic_string_view<Char, Traits> message, std::basic_ostream<Char, Traits> &rOstr)
	{
		auto old = SetConsoleColor(Colors::Brown);

		rOstr << "[DEBUG] ";

		SetConsoleColor(old);

		rOstr << message.data() << std::endl;
	}

	template<typename Char, typename Traits>
	inline void Debug(const std::basic_string<Char, Traits> &crMessage, std::basic_ostream<Char, Traits> &rOstr)
	{
		Debug(std::basic_string_view<Char, Traits>(crMessage), rOstr);
	}

	template<typename Char, typename Traits>
	void Text(std::basic_string_view<Char, Traits>  message, 
			  std::basic_ostream<Char, Traits>     &rOstr, 
			  Colors                                color /* = Colors::LightGray */, 
		      Colors                                bckg  /* = Colors::Black */, 
		      bool                                  endl  /* = true */)
	{
		auto old = SetConsoleColor(color, bckg);

		rOstr << message.data(); 

		if(endl)
			rOstr << std::endl;

		SetConsoleColor(old);
	}

	template<typename Char, typename Traits>
	inline void Text(const std::basic_string<Char, Traits> &crMessage,
		             std::basic_ostream<Char, Traits>      &rOstr,
		             Colors                                 color /* = Colors::LightGray */,
		             Colors                                 bckg  /* = Colors::Black */,
		             bool                                   endl  /* = true */)
	{
		Text(std::basic_string_view<Char, Traits>(crMessage), rOstr, color, bckg, endl);
	}

#pragma endregion

} //namespace NDebugger

