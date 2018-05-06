//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "Console.h"
#include <stdio.h>
#include <stdarg.h>

constexpr size_t BufferSize = 4096;
//----------------------------------------------------------
void Con::Log(uint32_t logLevel, char* msg, ...)
{
	char buffer[BufferSize];

	va_list args;
	va_start(args, msg);
	vsnprintf(buffer, BufferSize, msg, args);
	va_end(args);

	_Log(buffer);
}
//----------------------------------------------------------
void Con::Log(char* msg, ...)
{
	char buffer[BufferSize];

	va_list args;
	va_start(args, msg);
	vsnprintf(buffer, BufferSize, msg, args);
	va_end(args);

	_Log(buffer);
}
//----------------------------------------------------------
void Con::_Log(char* msg)
{
	printf("%s\n", msg);
}
//----------------------------------------------------------
void Con::DebugBreak()
{
	__debugbreak();
}
//----------------------------------------------------------
