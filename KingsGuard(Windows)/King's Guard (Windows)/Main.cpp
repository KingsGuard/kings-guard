#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <limits.h>

#include "Enemy.h"
#include "Gameplay.h"
#include "GameLoop.h"
#include "Tutorial.h"

std::string name;
bool narration = true;
bool deadLol = false;
bool WinLol = false;
bool QuitLol = false;

bool checkerBool(bool a) {
	while (1)
	{
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "You have entered wrong input, please enter it again" << std::endl;
			std::cin >> a;
		}
		if (!std::cin.fail())
			return a;
	}
}

int checker(int a) {
	while (1)
	{
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "You have entered wrong input, please enter it again" << std::endl;
			std::cin >> a;
		}
		if (!std::cin.fail())
			return a;
	}

}

int main() {

	start();

	bool stopper = false;
	// The group this game is based off of are called the Crown Guard from the dragon prince, but I thought King's Guard sounds better
	std::cout << "\n====================KING'S GUARD====================\n";
	//std::cout <<  "  ▄█   ▄█▄  ▄█  ███▄▄▄▄      ▄██████▄    █▄   ▄████████         ▄██████▄  ███    █▄     ▄████████    ▄████████ ████████▄     \n";
	//std::cout <<  "  ███ ▄███▀ ███  ███▀▀▀██▄   ███    ███      ███    ███        ███    ███ ███    ███   ███    ███   ███    ███ ███   ▀███   \n";
	//std::cout <<  "  ███▐██▀   ███▌ ███   ███   ███    █▀       ███    █▀         ███    █▀  ███    ███   ███    ███   ███    ███ ███    ███   \n";
	//std::cout <<  " ▄█████▀    ███▌ ███   ███  ▄███             ███              ▄███        ███    ███   ███    ███  ▄███▄▄▄▄██▀ ███    ███   \n";
	//std::cout <<  "▀▀█████▄    ███▌ ███   ███ ▀▀███ ████▄     ▀███████████      ▀▀███ ████▄  ███    ███   ██████████ ▀▀███▀▀▀▀▀   ███    ███   \n";
	//std::cout <<  "  ███▐██▄   ███  ███   ███   ███    ███             ███        ███    ███ ███    ███   ███    ███ ▀███████████ ███    ███   \n";
	//std::cout <<  "  ███ ▀███▄ ███  ███   ███   ███    ███       ▄█    ███        ███    ███ ███    ███   ███    ███   ███    ███ ███   ▄███   \n";
	//std::cout <<  "  ███   ▀█▀ █▀    ▀█   █▀    ████████▀      ▄████████▀         ████████▀  ████████▀    ███    █▀    ███    ███ ████████▀    \n";
	//std::cout <<  "  ▀                                                                                                 ███    ███              \n";
	std::cout << "\n===========PLEASE ENTER ADVENTURER'S NAME===========\n";
	while (!stopper) {
		std::cin >> name;
		//Checking if name is correct
		std::cout << "\n====DO YOU ACCEPT THIS NAME: '" << name << "' (1) FOR YES, (0) FOR NO ===\n";
		stopper = checkerBool(stopper);
		if (!stopper) {
			// Name is incorrect, restart
			std::cout << "\n===========PLEASE ENTER ADVENTURER'S NAME (ONE WORD) ===========\n";
		}
		else if (stopper) {
			// Name is correct, continue
			continue;
		}
	}

	if (name == "Marcos") {
		std::cout << "DEV MODE ACTIVATED: PRESS 1 TO CONTINUE, 0 TO TO PLAY LIKE NORMAL\n";
		stopper = checkerBool(stopper);
		if (stopper) {
			std::cout << "Health set to 1'000'000...\n";
			Info.health = 1000000;
			std::cout << "Damage set to 1'000'000...\n";
			Info.damage = 1000000;
			std::cout << "Healing set to 1'000'000...\n";
			Info.healing = 1000000;
			std::cout << "What level do you want to start at?\n";
			Info.playerLevel = checker(Info.playerLevel);
			for (int y = 0; y < 5; y++) {
				levels[y] = "LOCKED";
			}
			for (int p = 0; p < Info.playerLevel; p++) {
				levels[p] = "UNLOCKED";
			}
		}
	}

	// Begin Tutorial
	std::cout << "\n==== DO YOU WANT TO START THE TUTORIAL? (1) FOR YES, (0) FOR NO  ==== \n";
	stopper = checkerBool(stopper);
	if (stopper) {
		tutorial();
	}

	//Begin First Narration
	std::cout << "\nYou, " << name << " are part of the king's guard. This means you are a part of a 7 person group that defends the king from all assailants.\n";
	std::cout << " The kingdom has been in war for the past 7 years, and if you don't do your job before nightfall, then the war will end...\n";
	std::cout << " with your kings death. Assassins are coming for your king. They are elite warriors, and can not be stopped after nightfall.\n";
	std::cout << " You, alone must enter the forest and find the assasins camp, and destroy them before they get the chance to assasinate your king.\n";
	std::cout << " The other 6 members of the king's guard are defending the king and have put the responsabily on your shoulders alone.\n";
	std::cout << " You have 6 hours to find the assassins before it is too late. \n==========PRESS ANY KEY TO CONTINUE==========\n";
	_getch();


	system("cls");


	while ((!deadLol) && (!WinLol) && (!QuitLol)) {
		GameLoopFunction();
	}

	std::cout << "\n ========== That was the tale of " << name << ". The End ========== \n\n";
	Sleep(5000);
	return 0;
}

//- The name "Soren" means "stern" in Danish, which is rather unfitting since his character is pretty laid back.
//- When Viren gives Soren his mission in the episode "Through the Ice", the moment Soren comprehends his father's intent, his eyes can be seen dilating. This is a common physiological response when adrenaline is introduced into the bloodstream.
//- In early concepts, Claudia and Soren were the same character but were later split into two separate ones.
//- According to the creators, Soren eats a daunting amount of butter. // THIS IS THE BEST ONE!
//- The scar on Soren’s eyebrow was caused during an attempt to mimic Corvus' scar, the intention being to shave a line through his eyebrow, however, a mess up resulted in an actual cut and scar.
//- Soren likes pancakes, butter, and his muscles.He dislikes the moon, moths, and magic(especially if it involves something gross).

//Yes, Soren is my favorite charecter.