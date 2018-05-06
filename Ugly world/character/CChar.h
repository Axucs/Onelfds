//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

//----------------------------------------------------------
template<typename T>
T clamp(T in, T min, T max)
{
	if (in < min) return min;
	if (in > max) return max;
	return in;
};
//----------------------------------------------------------
class tKnowledge
{
private:
	int mRS;
	static const int ArraySize = 9;
	int mM[ArraySize];
public:
	tKnowledge(int rs, int m[ArraySize])
	{
		mRS = rs;
		for (auto n = 0; n < ArraySize; n++)
		{
			mM[n] = m[n];
		}
	}
	int RSChange(int Change)
	{
		mRS = mRS + Change;
		mRS = clamp(mRS, 0, 5);
	}
};
//----------------------------------------------------------
class tTrait
{
private:
	enum EStatus
	{
		Entrenched,
		There,
		None
	};

	int     mGrowth;
	int     mInfluence;
	EStatus mStatus;
public:

	tTrait(int G, int I, EStatus S)
	{
		mGrowth = G;
		mInfluence = I;
		mStatus = S;
	}
	int InfluenceChange(int Change)
	{
		int min = 0;
		int max = 5;
		switch (mStatus)
		{
			case Entrenched: min = 3; break;
			case There: break;
			case None: max = 2; break;
		}
		mInfluence = mInfluence + Change;
		mInfluence = clamp(mInfluence, min, max);
	}
	int GrowthChange(int Change)
	{
		mGrowth = mGrowth + Change;
		if (mGrowth > 10)
		{
			InfluenceChange(+1);
			mGrowth = 0;
		}
		else if (mGrowth < 0)
		{
			InfluenceChange(-1);
			mGrowth = 10;
		}
	};
};
//----------------------------------------------------------
class tWorldViewPos
{
private:
	int mView;
public: 
	tWorldViewPos(int x) : mView(x)
	{
	};
};
//----------------------------------------------------------
