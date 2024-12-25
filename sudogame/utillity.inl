#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>

inline unsigned int random(int begin, int end)
{
	std::random_device rd;
	std::mt19937 g(rd());
	return std::uniform_int_distribution<unsigned>(begin, end)(g);
}

inline std::vector<int> get_unit()
{
	return std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

inline std::vector<int> shuffle_unit()
{
	std::vector<int> unit = get_unit();
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(unit.begin(), unit.end(), g);
	return unit;
}

inline void message(const char* msg = "", bool lf = true)
{
	std::cout << msg;
	if (lf) std::cout << std::endl;
}

inline void message(const std::string& msg, bool lf = true)
{
	message(msg.c_str(), lf);
}

#ifdef _WIN32
#include <conio.h>
#endif

inline void cls(void)
{
#ifdef _WIN32
	system("cls");

#endif

}

