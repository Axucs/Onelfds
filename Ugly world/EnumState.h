//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include "Singleton.h"
#include <memory> // std::unique_ptr
#include <functional> // std::function
#include <algorithm> // std::for_each
#include <unordered_map>
#include <string>

//----------------------------------------------------------
class cEnumStateBase
{
public:
	virtual ~cEnumStateBase() = default;
};
//----------------------------------------------------------
template <typename T> class cEnumState : public cEnumStateBase
{
public:
	cEnumState() = default;

	void addState(T type, char* tag)
	{
		mStates.insert(std::make_pair(type, tag));
		mBackStates.insert(std::make_pair(tag, type));
	};

	template <typename T>
	void for_each(std::function<void(const T)> fun)
	{
		std::for_each(mStates.begin(), mStates.end(), [fun](auto iter)
		{
			fun(iter.first);
		});
	};

	template <typename T>
	const char* getStateTag(T type)
	{
		auto iter = mStates.find(type);
		if (iter != mStates.end())
		{
			return iter->second.c_str();
		}
		return nullptr;
	};

	template <typename T>
	T getStateByTag(const char* tag)
	{
		assert(!mBackStates.empty());
		auto iter = mBackStates.find(tag);
		assert(iter != mBackStates.end());
		return iter->second;
	};


	//T operator++() { return x+1; }

private:
	std::unordered_map<T, std::string> mStates;
	std::unordered_map<std::string, T> mBackStates;
};
//----------------------------------------------------------
class cEnumStatesStorage
{
	friend class Singleton<cEnumStatesStorage>;
public:
	void init();

	static cEnumStatesStorage* instance();

	template <typename T>
	void addState(T type, char* tag)
	{
		auto hash = typeid(T).hash_code();
		auto& it = mEnumStates.find(hash);
		if (it != mEnumStates.end())
		{
			auto& ptr = it->second;
			cEnumState<T>* data = dynamic_cast<cEnumState<T>*>(ptr.get());
			data->addState(type, tag);
		}
		else
		{
			auto data = std::make_unique<cEnumState<T>>();
			data->addState(type, tag);
			mEnumStates.insert(std::make_pair(hash, std::move(data)));
		}
	};

	template <typename T>
	cEnumState<T>* getState()
	{
		auto hash = typeid(T).hash_code();
		auto& it = mEnumStates.find(hash);
		if (it != mEnumStates.end())
		{
			auto& ptr = it->second;
			cEnumState<T>* data = dynamic_cast<cEnumState<T>*>(ptr.get());
			return data;
		}
		return nullptr;
	};

	template <typename T>
	const char* getStateTag(T type)
	{
		auto* state = getState<T>();
		if (state)
		{
			return state->getStateTag(type);
		}
		return nullptr;
	};

	template <typename T>
	T getStateByTag(const char* tag)
	{
		auto* state = getState<T>();
		assert(state);
		return state->getStateByTag<T>(tag);
	};

	template <typename T>
	void for_each(std::function<void(const T)> fun)
	{
		auto* state = getState<T>();
		if (state)
		{
			state->for_each<T>(fun);
		}
	};

private:
	cEnumStatesStorage();

	std::unordered_map<size_t, std::unique_ptr<cEnumStateBase>> mEnumStates;
	bool mInited = false;
};
//----------------------------------------------------------
#define ESS cEnumStatesStorage::instance()
//----------------------------------------------------------

/*
static const eTestState All[] = { a, b, c };

for (const auto e: eTestState::All)
	fun(e);

for (const auto e: { eTestState::a, eTestState::b } )
	fun(e);

std::for_each (std::begin(eTestState::All), std::end(eTestState::All), fun);
*/

//	auto* ptr = ESS->getState<eTestState>();

//	const char* state = ESS->getStateTag(eTestState::pf1);

//	ESS->for_each<eTestState>([](const eTestState item) {});


