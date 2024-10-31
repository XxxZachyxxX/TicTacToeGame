#include "RandomNumberAlgorithm.h"

char RandomNumberAlgorithm::virtuelField[9] = {};

const short RandomNumberAlgorithm::GET_NUMBER()
{
	


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution distrib(0, 8);

	return distrib(gen);
}
bool RandomNumberAlgorithm::WatchDang()
{
	
	return false;
}
void RandomNumberAlgorithm::SET_VIRTUAL_FIELD(char VIRTUAL_FIELD[])
{
	
}