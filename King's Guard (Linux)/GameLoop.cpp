#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
#include <limits>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "Enemy.h"
#include "Gameplay.h"
#include "GameLoop.h"
#include "Tutorial.h"
	 
int choice;
bool on_Menu = true;
std::string levels[5] = {"UNLOCKED", "LOCKED", "LOCKED", "LOCKED", "LOCKED"};
std::string Messages;


Information Info;


int start() {
	Info.playerLevel = 1;
	Info.health = 100;
	Info.damage = 10;
	Info.healing = 15;
	return 0;
}

void GameLoopFunction() {
	
	std::cout << "Player Name: " << name << std::endl;
	std::cout << "Player Level: " << Info.playerLevel << std::endl << std::endl;
	std::cout << "Forest ================= "<< levels[0] << std::endl;
	std::cout << "Swamp ================== "<< levels[1] << std::endl;
	std::cout << "Field ================== "<< levels[2] << std::endl;
	std::cout << "Hills ================== "<< levels[3] << std::endl;
	std::cout << "Assasin's Hideout ====== "<< levels[4] << std::endl << std::endl;
	std::cout << "Health: " << Info.health << std::endl;
	std::cout << "Damage: " << Info.damage << std::endl;
	std::cout << "Healing: " << Info.healing << std::endl << std::endl;

	std::cout << "Enter (1) to start the next level, Enter (2) to quit the game\n";
	choice = getchar();
	usleep(100);

	
	switch (choice-48) {
			case 1:

				switch (int(Info.playerLevel)) {
					case 1:
						system("clear");
						Level1();
						levels[1] = "UNLOCKED";
						break;
					case 2:
						system("clear");
						Level2();
						levels[2] = "UNLOCKED";
						break;
					case 3:
						system("clear");
						Level3();
						levels[3] = "UNLOCKED";
						break;
					case 4:
						system("clear");
						Level4();
						levels[4] = "UNLOCKED";
						break;
					case 5:
						system("clear");
						Level5();
						break;
				}
		break;
		case 2:
			QuitLol = true;
			break;
	}
	system("clear");
}
