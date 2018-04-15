//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <type_traits>

template <typename Underlying, typename UniqueTag>
class ExplicitIntegralID final
{
public:
	using UnderlyingType = Underlying;
	static_assert(std::is_integral<UnderlyingType>::value, "ExplicitIntegralID is for arithmetic types only");

	constexpr explicit ExplicitIntegralID(UnderlyingType value) noexcept
		: mUnderlyingValue(value)
	{
	}
	constexpr ExplicitIntegralID() noexcept = default;

	constexpr const UnderlyingType& underlying() const noexcept
	{
		return mUnderlyingValue;
	}

	constexpr bool operator==(ExplicitIntegralID) const noexcept;
	constexpr bool operator!=(ExplicitIntegralID) const noexcept;
	constexpr bool operator<(ExplicitIntegralID) const noexcept;
	constexpr bool operator<=(ExplicitIntegralID) const noexcept;
	constexpr bool operator>(ExplicitIntegralID) const noexcept;
	constexpr bool operator>=(ExplicitIntegralID) const noexcept;

private:
	UnderlyingType mUnderlyingValue;
};

template <typename T>
struct IsExplicitIntegralID : std::false_type {};

template <typename UType, typename UTag>
struct IsExplicitIntegralID<ExplicitIntegralID<UType, UTag>> : std::true_type {};

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator==(ExplicitIntegralID other) const noexcept
{
	return mUnderlyingValue == other.mUnderlyingValue;
}

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator!=(ExplicitIntegralID other) const noexcept
{
	return !operator==(other);
}

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator<(ExplicitIntegralID other) const noexcept
{
	return mUnderlyingValue < other.mUnderlyingValue;
}

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator<=(ExplicitIntegralID other) const noexcept
{
	return mUnderlyingValue <= other.mUnderlyingValue;
}

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator>(ExplicitIntegralID other) const noexcept
{
	return mUnderlyingValue > other.mUnderlyingValue;
}

template <typename UType, typename UTag>
constexpr bool ExplicitIntegralID<UType, UTag>::operator>=(ExplicitIntegralID other) const noexcept
{
	return mUnderlyingValue >= other.mUnderlyingValue;
}

namespace std
{

template <typename UType, typename UTag>
struct hash<ExplicitIntegralID<UType, UTag>>
{
	size_t operator()(const ExplicitIntegralID<UType, UTag> value) const
	{
		return std::hash<UType>{}(value.underlying());
	}
};

} // namespace std

namespace DictHash
{

template <typename UType, typename UTag>
size_t hash(const ExplicitIntegralID<UType, UTag> value)
{
	return hash(value.underlying());
}

} // namespace DictHash

