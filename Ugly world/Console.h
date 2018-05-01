//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <cstdint> // uint32_t

#define LOG_MESSAGE		1u
#define LOG_WARNING		2u
#define LOG_ERROR		3u
#define LOG_CRITICAL	4u
#define LOG_FATAL		5u
#define LOG_ALWAYS		6u
#define LOG_DEBUG		LOG_WARNING
#define LOG_PUREDUMP	0x80000000u

namespace Con
{
	static void Log(uint32_t logLevel, char* msg, ...);
	static void Log(char* msg, ...);
};
