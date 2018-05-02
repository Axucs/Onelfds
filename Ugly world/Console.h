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

class Con
{
public:
	static void Log(uint32_t logLevel, char* msg, ...);
	static void Log(char* msg, ...);
	static void DebugBreak();
private:
	static void _Log(char* msg);
};

class PlatformAssert final
{
public:
	enum class Type { ISV, FatalError, Error, Warning };

	template <typename... T>
	static void Perform(Type type, const char* fileName, const char* functionName, size_t lineNumber, const char* format, const T&... args)
	{
		char buf[256] = { 0 };
		sprintf_s(buf, sizeof(buf), "Error: file=%s function=%s line=%u %s", fileName, functionName, static_cast<uint32_t>(lineNumber), format);
		Con::Log(buf, args...);
		Con::DebugBreak();
	}
};

#define AssertError(condition, format, ...) { \
	if (static_cast<bool>(condition) == false) { \
		::PlatformAssert::Perform(::PlatformAssert::Type::Error, __FILE__, __FUNCTION__, __LINE__, (format), ##__VA_ARGS__); \
	} \
}

