/*	myrandom.cpp
 *	I'm sure that using rand would be *fine* (I mean, you used it in your example) but why not be extra and set up a Mersenne Twister just because?
 *
 */

#include <random>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomInteger(int min, int max)
{
	std::uniform_int_distribution<> number{ min, max };
	return number(MyRandom::mersenne);
}