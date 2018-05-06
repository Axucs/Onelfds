//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include "../util/Singleton.h"
#include <memory> // std::unique_ptr
#include <functional> // std::function
#include <algorithm> // std::for_each
#include <unordered_map>
#include <string>
#include "../console/Console.h" // AsertError

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
		AssertError(mStates.find(type) == mStates.end(), "type already exists");
		AssertError(mBackStates.find(tag) == mBackStates.end(), "tag already exists");
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
		AssertError(!mBackStates.empty(), "BackState is empty");
		auto iter = mBackStates.find(tag);
		AssertError(iter != mBackStates.end(), "Tag not found");
		return iter->second;
	};

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
		AssertError(tag && tag[0], "tag is empty");
		auto* state = getState<T>();
		AssertError(state, "State not found");
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


