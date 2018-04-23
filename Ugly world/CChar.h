//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

//----------------------------------------------------------
class Them
{
private:
	int RS;
public:
	Them(int rs)
	{
		RS = rs;
	}
	int RSChange(int Change)
	{
		int min = 0;
		int max = 5;
		//if (RS > min && RS < max) { RS = RS + Change ;}
		if (RS >= min && RS <= max) { RS = RS + Change; }
		if (RS > max) { RS = max; }
		if (RS < min) { RS = min; }
	}
};
//----------------------------------------------------------
class Trait
{
private:
	enum EStatus
	{
		Entrenched,
		There,
		None
	};

	int Growth;
	int Influence;
	EStatus Status;
public:

	Trait(int G, int I, EStatus S)
	{
		Growth = G; Influence = I; Status = S;
	}
	int InfluenceChange(int Change)
	{
		int min = 0;
		int max = 5;
		switch (Status)
		{
		case Entrenched: min = 3; break;
		case There: break;
		case None: max = 2; break;
		}
		if (Influence >= min && Influence <= max) { Influence = Influence + Change; }
		if (Influence > max) { Influence = max; }
		if (Influence < min) { Influence = min; }
	}

	int GrowthChange(int Change) {
		Growth = Growth + Change;
		if (Growth > 10) { InfluenceChange(+1), Growth = 0; }
		else if (Growth < 0) { InfluenceChange(-1), Growth = 10; }
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
