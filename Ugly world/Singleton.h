//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <assert.h>
#include <type_traits>

template <typename T> class Singleton final
{
public:
	Singleton() = delete;
	static inline T* instance() noexcept(std::is_nothrow_default_constructible<T>::value)
	{
		static T instance;
		return &instance;
	}
};
