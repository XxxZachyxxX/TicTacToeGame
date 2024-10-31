#pragma once
#include <iostream>
#include <random>


class RandomNumberAlgorithm
{
public:
	RandomNumberAlgorithm()
	{

	}
	~RandomNumberAlgorithm()
	{
		
	}
	static const short GET_NUMBER();
	static void SET_VIRTUAL_FIELD(char virtualField[]);
private:
	static char virtuelField[];
	static bool WatchDang();
};

