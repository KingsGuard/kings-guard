#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#define Sleep(x) usleep((x)*1000) 
#include <unistd.h>
#include <stdio.h>

#include "Enemy.h"
#include "Gameplay.h"
#include "GameLoop.h"
#include "Tutorial.h"

void tutorial() {
	system("clear");
	std::cout << "\n========= STARTING TUTORIAL =========\n";
	std::cout << "King's Guard is a text-based rpg style game, based off of the TV series 'The Dragon Prince'.\n";
	std::cout << "The game works by giving you a choice of 4 combat mechanics, attacking, healing, fleeing, and blocking.\n";
	std::cout << "If you want to finish your mission, you must skillfully use attacking, healing, and blocking, and fleeing as a last resort.\n";
	std::cout << "There is also a loot systen, so when you finish each battle, you can choose an option between two sources of loot.\n";
	std::cout << "There is an exception to this rule, if you flee, you don't get loot, meaning that if you flee a lot, you won't be powerfull enough to win.\n";
	std::cout << "Let's try a example combat scene. \n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
	std::cout << "\n=============== YOU ===============\n";
	std::cout << "Name: " << name << std::endl;
	std::cout << "\tHealth: " << "100" << std::endl;
	std::cout << "\tDamage: " << "10" << std::endl;
	std::cout << "\tHealing: " << "10" << std::endl;
	std::cout << "\tHealing Cooldown: " << "0" << std::endl;

	std::cout << "=============== ENEMYS ===============" << std::endl;
	std::cout << "Training Dummy" << "\n";
	std::cout << "\tHealth: " << "5" << std::endl;
	std::cout << "\tDamage: " << "0" << std::endl;
	std::cout << "\n=============== " << "YOUR" << " TURN ===============\n";
	std::cout << "(1) To Attack\n";
	std::cout << "(2) To Heal\n";
	std::cout << "(3) To Flee\n";
	std::cout << "(4) To Block\n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
	std::cout << "\nThis is the combat scene, and we have pitted you against your worst enemy... Training dummy!\n";
	std::cout << "We will go down the list, starting with attack. To trigger attack, you must enter the key '1'.\n";
	std::cout << "If you put in any input other than 1-4, you will have to choose again.\n";
	std::cout << "Then you will have to put in what enemy you want to attack, after this message pops up:\n";
	std::cout << "'What Enemy do you want to attack?'\n";
	std::cout << "You cannot put in anything but a number, and this number has to have a correlating enemy.\n";
	std::cout << "You cannot put in a number that is higher than the count of enemys, or any number that doesn't have an alive enemy there.\n";
	std::cout << "So for this example, you would put in '1' and that would attack enemy one. Training dummy.\n";
	std::cout << "This is what it would look like now.\n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
	std::cout << "\n=============== YOU ===============\n";
	std::cout << "Name: " << name << std::endl;
	std::cout << "\tHealth: " << "100" << std::endl;
	std::cout << "\tDamage: " << "10" << std::endl;
	std::cout << "\tHealing: " << "10" << std::endl;
	std::cout << "\tHealing Cooldown: " << "0" << std::endl;

	std::cout << "=============== ENEMYS ===============" << std::endl;
	std::cout << "DEAD" << "\n";
	std::cout << "\tHealth: " << "0" << std::endl;
	std::cout << "\tDamage: " << "0" << std::endl;
	std::cout << "\n=============== " << "YOUR" << " TURN ===============\n";
	std::cout << "YOU HAVE ATTACKED\n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
	std::cout << "\nThen you whould be redirected to the loot page. And then back to the main menu.\n";
	std::cout << "But say instead of being at 100 health, you where at 50, and you wanted to heal.\n";
	std::cout << "Then you wouldn't press one, instead you would press 2, to heal, instead of 1 to attack.\n";
	std::cout << "Then if your healing cooldown is 0, you would heal, you need to wait for your healing cooldown to return to 0 before healing again.\n";
	std::cout << "If you don't wait, then that turn will be wasted, and you will receive a message.\n";
	std::cout << "If you want to flee, then you press 3, instead of 1 or 2. This will give you a chance of fleeing, or wasting your turn, so it's a big risk.\n";
	std::cout << "The final option is blocking, this gives you a chance to not take damage until your next turn.\n";
	std::cout << "This helps if you want to heal, but you have the healing cooldown, this can be very usefull in fights.\n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
	std::cout << "You have finished the tutorial, congratulations, you are now ready to be an official King's Guard, have fun!\n";
	std::cout << "You will now be redirected to the beggining of the game.\n";
	std::cout << "Press any key to continue...\n";
	getchar();
	system("clear");
}