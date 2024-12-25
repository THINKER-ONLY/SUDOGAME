#pragma once

#include <Windows.h>

inline void SetWindowsEnv()
{
	SetConsoleOutputCP(65001);
}

inline void SetSystemEnv() { SetWindowsEnv(); }