#include <iostream>
#include <cstring>

#include "system_env.hpp"
#include "scene.hpp"
#include "input.hpp"
#include "i18n.hpp"
#include "utillity.inl"


static void printHelp()
{
	std::cout << std::endl;
	std::cout << "sudoku - a little game in command line" << std::endl
			  << std::endl;
	std::cout << "Usage:" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t -1 <path> \t specify path file to load, optional." << std::endl << std::endl;
}


int main(int argc, char **argv)
{
	SetSystemEnv();

	CScene scene;

	if (argc == 1)
	{
		InputLanguage();
		int eraseGridNumber = inputDifficulty();
		scene.generate();
		scene.eraseRandomGrids(eraseGridNumber);
	}
	else if (argc == 3 && !strcmp(argv[1], "-1"))
	{
		/*
		if (!scene.load(argv[2]))
		{
			message(I18n::Instance().Get(I18n::Key::LOAD_PROGRESS_FAIL));
			return 0;
		}*/
		InputLanguage();
	}
	else
	{
		printHelp();
		return 0;
	}

	scene.setMode(inputKeyMode());
	scene.play();

	return 0;
}