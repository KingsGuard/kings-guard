#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include<limits>

#include "Enemy.h"
#include "Gameplay.h"
#include "GameLoop.h"
#include "Tutorial.h"

int loot_choice;

bool redoTurn = false;
int healthing_cooldown = 0;
bool player_failed = false;
bool player_fled = false;
int Enemy_Count_Alive;
int Enemy_Count;
std::string turn;
int playerChoice;
int j = 0;
int randomNumberChoice;
int randomNumberFlee;
bool BlockThisTurn;

void BattleLoopFinale(Enemy Enemy_Obj_array[]) {
	system("cls");
	if (healthing_cooldown < 0) {
		healthing_cooldown = 0;
	}
	if (Info.health > 150) {
		Info.health = 150;
	}
	std::cout << "\n=============== YOU ===============\n";
	std::cout << "Name: " << name << std::endl;
	std::cout << "\tHealth: " << Info.health << std::endl;
	std::cout << "\tDamage: " << Info.damage << std::endl;
	std::cout << "\tHealing: " << Info.healing << std::endl;
	std::cout << "\tHealing Cooldown: " << healthing_cooldown << std::endl;

	std::cout << "=============== ENEMYS ===============" << std::endl;
	for (int i = 0; i < Enemy_Count; i++) {
		std::cout << Enemy_Obj_array[i].Enemy_Name << ":\n";
		std::cout << "\tHealth: " << Enemy_Obj_array[i].Enemy_Health << std::endl;
		std::cout << "\tDamage: " << Enemy_Obj_array[i].Enemy_Damage << std::endl;
	}
	std::cout << "\n=============== " << turn << " TURN ===============\n";
	if (turn == "YOUR") {
		BlockThisTurn = false;
		if (Info.health <= 0) {
			player_failed = true;
			deadLol = true;
		}
		else {
			std::cout << "(1) To Attack\n";
			std::cout << "(2) To Heal\n";
			std::cout << "(4) To Block\n"; \
				playerChoice = checker(playerChoice);
			switch (playerChoice) {
			case 1:
				std::cout << "What Enemy do you want to attack?\n";
				while (1)
				{
					playerChoice = checker(playerChoice);
					if (playerChoice > Enemy_Count || playerChoice < 1) {
						std::cout << "You have tried to attack an enemy that doesn't exist, please try again." << std::endl;
						playerChoice = checker(playerChoice);
					}
					else {
						break;
					}
				}
				Enemy_Obj_array[playerChoice - 1].Enemy_Health -= Info.damage;
				Enemy_Obj_array[playerChoice - 1].has_been_attacked = true;
				std::cout << "YOU HAVE ATTACKED\n";
				if (Enemy_Obj_array[playerChoice - 1].Enemy_Health < 1 && (Enemy_Obj_array[playerChoice - 1].Enemy_Name != "DEAD" || Enemy_Obj_array[playerChoice - 1].Enemy_Name != "FLEED")) {
					Enemy_Count_Alive -= 1;
					Enemy_Obj_array[playerChoice - 1].Enemy_Health = 0;
					Enemy_Obj_array[playerChoice - 1].Enemy_Damage = 0;
					Enemy_Obj_array[playerChoice - 1].Enemy_Name = "DEAD";
				}
				break;
			case 2:
				if (healthing_cooldown < 1) {
					Info.health += Info.healing;
					std::cout << "You have healed " << Info.healing << " Health!\n";
					healthing_cooldown = 4;
				}
				else {
					std::cout << "Sorry, your healing cooldown is active. You have to wait: " << healthing_cooldown << " turns\n";
				}
				break;

			case 3:
				std::cout << "Did you not notice that this wasn't an option? You can't flee on the final level! Have a second turn\n";
				Sleep(4000);
				turn = "YOUR";
				redoTurn = true;
				break;
			case 4:
				srand(time(0));
				randomNumberChoice = rand() % 10;
				srand(time(0) + 1);
				randomNumberFlee = rand() % 10;
				if (randomNumberChoice > 2) {
					std::cout << "YOU HAVE BLOCKED THE NEXT ATTACK\n";
					BlockThisTurn = true;
				}
				else {
					std::cout << "YOU HAVE ATTEMPTED TO BLOCK, IT FAILLED\n";
				}
				break;
			}
		}
		if (!redoTurn) {
			turn = "ENEMYS";
		}
		redoTurn = false;
	}

	if (turn == "ENEMYS") {
		for (j = 0; j < Enemy_Count; j++) {
			//Attack
			if (Enemy_Obj_array[j].Enemy_Name == "FLEED" || Enemy_Obj_array[j].Enemy_Name == "DEAD") {
				//do nothing, cause they're dead or long gone
			}
			else if (!BlockThisTurn && !player_fled) {
				Info.health -= Enemy_Obj_array[j].Enemy_Damage;
				std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTACKED YOU\n";
			}
			else if (!player_fled) {
				std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTEMPTED TO ATTACK YOU, BUT WAS BLOCKED\n";
			}
		}
		turn = "YOUR";
		Sleep(2000);
	}
}

void BattleLoop(Enemy Enemy_Obj_array[]) {
	system("cls");
	if (healthing_cooldown < 0) {
		healthing_cooldown = 0;
	}
	if (Info.health > 150) {
		Info.health = 150;
	}
	std::cout << "\n=============== YOU ===============\n";
	std::cout << "Name: " << name << std::endl;
	std::cout << "\tHealth: " << Info.health << std::endl;
	std::cout << "\tDamage: " << Info.damage << std::endl;
	std::cout << "\tHealing: " << Info.healing << std::endl;
	std::cout << "\tHealing Cooldown: " << healthing_cooldown << std::endl;

	std::cout << "=============== ENEMYS ===============" << std::endl;
	for (int i = 0; i < Enemy_Count; i++) {
		std::cout << Enemy_Obj_array[i].Enemy_Name << ":\n";
		std::cout << "\tHealth: " << Enemy_Obj_array[i].Enemy_Health << std::endl;
		std::cout << "\tDamage: " << Enemy_Obj_array[i].Enemy_Damage << std::endl;
	}
	std::cout << "\n=============== " << turn << " TURN ===============\n";
	if (turn == "YOUR") {
		BlockThisTurn = false;
		if (Info.health <= 0) {
			player_failed = true;
			deadLol = true;
		}
		else {
			std::cout << "(1) To Attack\n";
			std::cout << "(2) To Heal\n";
			std::cout << "(3) To Flee\n";
			std::cout << "(4) To Block\n";
			playerChoice = checker(playerChoice);
			while (playerChoice > 4 || playerChoice < 1) {
				std::cout << "This is choice doesn't exist, please pick again.\n";
				playerChoice = checker(playerChoice);							
			} 
			
			switch (playerChoice) {
			case 1:
				std::cout << "What Enemy do you want to attack?\n";
				while (1)
				{
					playerChoice = checker(playerChoice);
					if (playerChoice > Enemy_Count || playerChoice < 1 || (Enemy_Obj_array[playerChoice - 1].Enemy_Health < 1) && ((Enemy_Obj_array[playerChoice - 1].Enemy_Name != "DEAD") && (Enemy_Obj_array[playerChoice - 1].Enemy_Name != "FLEED"))) {
						std::cout << "You have tried to attack an enemy that doesn't exist, is already dead or has fled, please try again." << std::endl;
					}
					else {
						Enemy_Obj_array[playerChoice - 1].Enemy_Health -= Info.damage;
						Enemy_Obj_array[playerChoice - 1].has_been_attacked = true;
						std::cout << "YOU HAVE ATTACKED\n";
						Enemy_Count_Alive -= 1;
						Enemy_Obj_array[playerChoice - 1].Enemy_Health = 0;
						Enemy_Obj_array[playerChoice - 1].Enemy_Damage = 0;
						Enemy_Obj_array[playerChoice - 1].Enemy_Name = "DEAD";
					}
				}
					
			break;
			case 2:
				if (healthing_cooldown < 1) {
					Info.health += Info.healing;
					std::cout << "You have healed " << Info.healing << " Health!\n";
					healthing_cooldown = 4;
				}
				else {
					std::cout << "Sorry, your healing cooldown is active. You have to wait: " << healthing_cooldown << " turns. Redo your turn\n";
					Sleep(4000);
					turn = "YOUR";
					redoTurn = true;
				}
				break;

			case 3:
				srand(time(0));
				randomNumberChoice = rand() % 10;
				srand(time(0) + 1);
				randomNumberFlee = rand() % 10;

				if (randomNumberFlee > 6) {
					std::cout << "YOU HAVE FLEED\n";
					player_fled = true;
				}
				else {
					std::cout << "YOU HAVE ATTEMPTED TO FLEE, IT FAILLED\n";
				}
				break;

			case 4:
				srand(time(0));
				randomNumberChoice = rand() % 10;
				srand(time(0) + 1);
				randomNumberFlee = rand() % 10;
				if (randomNumberChoice > 2) {
					std::cout << "YOU HAVE BLOCKED THE NEXT ATTACK\n";
					BlockThisTurn = true;
				}
				else {
					std::cout << "YOU HAVE ATTEMPTED TO BLOCK, IT FAILLED\n";
				}
				break;
			}
		}
		if (!redoTurn) {
			turn = "ENEMYS";
		}
		redoTurn = false;
	}

	if (turn == "ENEMYS") {
		srand(time(0));
		randomNumberChoice = rand() % 10;
		srand(time(0) + 1);
		randomNumberFlee = rand() % 10;

		//For every enemy
		for (j = 0; j < Enemy_Count; j++) {

			if (Enemy_Obj_array[j].Enemy_Name == "FLEED" || Enemy_Obj_array[j].Enemy_Name == "DEAD") {
				//do nothing, cause they're dead or long gone
			}

			//makes a choice of what to do
			else if (Enemy_Obj_array[j].Enemy_Health < 15 && Enemy_Obj_array[j].has_been_attacked && !player_fled) {
				//Flee 
				if (randomNumberFlee > 6) {
					//True flee
					std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS FLEED\n";
					Enemy_Count_Alive -= 1;
					Enemy_Obj_array[j].Enemy_Health = 0;
					Enemy_Obj_array[j].Enemy_Damage = 0;
					Enemy_Obj_array[j].Enemy_Name = "FLEED";
				}
				else {
					std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTEMPTED TO FLEE\n";
				}
			}
			else if (Enemy_Obj_array[j].Enemy_Health < 25 && Enemy_Obj_array[j].has_been_attacked && !player_fled) {
				if (randomNumberChoice > 5) {
					if (randomNumberFlee > 6) {
						//True flee
						std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS FLEED\n";
						Enemy_Count_Alive -= 1;
						Enemy_Obj_array[j].Enemy_Health = 0;
						Enemy_Obj_array[j].Enemy_Damage = 0;
						Enemy_Obj_array[j].Enemy_Name = "FLEED";
					}
					else {
						std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTEMPTED TO FLEE\n";
					}
				}
				else {
					//Attack
					if (!BlockThisTurn) {
						Info.health -= Enemy_Obj_array[j].Enemy_Damage;
						std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTACKED YOU\n";
					}
					else {
						std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTEMPTED TO ATTACK YOU, BUT WAS BLOCKED\n";
					}
				}
			}
			else {
				//Attack
				if (!BlockThisTurn && !player_fled) {
					Info.health -= Enemy_Obj_array[j].Enemy_Damage;
					std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTACKED YOU\n";
				}
				else if (!player_fled) {
					std::cout << Enemy_Obj_array[j].Enemy_Name << " HAS ATTEMPTED TO ATTACK YOU, BUT WAS BLOCKED\n";
				}
			}
		}

	}
	turn = "YOUR";
	Sleep(2000);
}


void Level1() {
	player_fled = false;
	Sleep(100);
	std::cout << "\n\n=================================== LEVEL 1 ===================================\n\n";
	std::cout << "You begin your journey to destroy the assasins, by walking into the great forest. \n";
	std::cout << "You begin to walk, and notice a few broken branches and twigs, and begin to pick up a trail. \n";
	std::cout << "You see the remanants of an old camp. The assasins camp. But unfortunatly it isn't empty!!\n";
	std::cout << "But it isn't filled with assasins, but two full grown bears! You must fight to survive!\n";
	std::cout << "===== ( Press any key to continue ) =====\n";
	_getch();

	Enemy_Count = 2;
	Enemy_Count_Alive = Enemy_Count;
	turn = "YOUR";

	Enemy Bear1;
	Bear1.has_been_attacked = false;
	Bear1.Enemy_Health = 25;
	Bear1.Enemy_Damage = 8;
	Bear1.Enemy_Name = "Bear 1";
	Enemy Bear2;
	Bear2.has_been_attacked = false;
	Bear2.Enemy_Health = 30;
	Bear2.Enemy_Damage = 6;
	Bear2.Enemy_Name = "Bear 2";
	Enemy Level1Bears[2] = { Bear1, Bear2 };

	while (Enemy_Count_Alive > 0 && !player_fled && !player_failed) {
		BattleLoop(Level1Bears);
		healthing_cooldown--;
	}
	system("cls");
	if (Enemy_Count_Alive < 1) {
		std::cout << "Congrats! You have defeated the bears, your loot: (1) Bear claws (13 damage), (2) Bear fat (17 healing)\n";
		loot_choice = checker(loot_choice);
		if (loot_choice == 1) {
			std::cout << "You have chosen the bear claws!\n";
			Info.damage = 13;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else if (loot_choice == 2) {
			std::cout << "You have chosen the bear fat!\n";
			Info.healing = 17;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else {
			std::cout << "You have skipped choosing loot.\n";
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}

		Info.playerLevel++;

	}
	else if (player_fled) {
		std::cout << "You have taken the cowardly way out, but maybe a smarter move than staying. Bears aren't afraid of tearing you apart!\n";
		std::cout << "===== ( Press any key to continue ) =====\n";
		_getch();
		Info.playerLevel++;

	}
	else {
		system("cls");
		std::cout << "You have died, and failed your mission.\n";
		Sleep(5000);
		deadLol = true;
		player_failed = true;
	}
}

void Level2() {
	player_fled = false;
	Sleep(100);
	std::cout << "\n\n=================================== LEVEL 2 ===================================\n\n";
	std::cout << "After the bear encounter, you hurry on, you don't have much time to find the assasins.\n";
	std::cout << "You begin to start getting lost, you've lost the assasin's trail a long time ago. \n";
	std::cout << "Right ahead, you notice that the trees are disapearing, and the trail forwards leads to a swamp\n";
	std::cout << "You slowly enter the swamp, but you feel eyes on your back, you turn around and see three swamp monsters!!\n";
	std::cout << "===== ( Press any key to continue ) =====\n";
	_getch();

	Enemy_Count = 3;
	Enemy_Count_Alive = Enemy_Count;
	turn = "YOUR";

	Enemy SwampMonster1;
	SwampMonster1.has_been_attacked = false;
	SwampMonster1.Enemy_Health = 40;
	SwampMonster1.Enemy_Damage = 3;
	SwampMonster1.Enemy_Name = "Swamp Monster 1";
	Enemy SwampMonster2;
	SwampMonster2.has_been_attacked = false;
	SwampMonster2.Enemy_Health = 20;
	SwampMonster2.Enemy_Damage = 9;
	SwampMonster2.Enemy_Name = "Swamp Monster 2";
	Enemy SwampMonster3;
	SwampMonster3.has_been_attacked = false;
	SwampMonster3.Enemy_Health = 5;
	SwampMonster3.Enemy_Damage = 6;
	SwampMonster3.Enemy_Name = "Baby Swamp Monster";
	Enemy SwampMonsters[3] = { SwampMonster1, SwampMonster2, SwampMonster3 };

	player_fled = false;
	player_failed = false;

	while (Enemy_Count_Alive > 0 && !player_fled && !player_failed) {
		BattleLoop(SwampMonsters);
		healthing_cooldown--;
	}
	system("cls");
	if (Enemy_Count_Alive < 1) {
		std::cout << "Congrats! You have defeated the Swamp monsters!, your loot: , (1) Deadly Branch (18 Damage), (2) Swampy Potion (19 Healing)\n";
		loot_choice = checker(loot_choice);
		if (loot_choice == 1) {
			std::cout << "You have chosen the Deadly Branch!!\n";
			Info.damage = 18;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else if (loot_choice == 2) {
			std::cout << "You have chosen the Swampy Potion!\n";
			Info.healing = 19;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else {
			std::cout << "You have skipped choosing loot.\n";
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}

		Info.playerLevel++;

	}
	else if (player_fled) {
		std::cout << "You have taken the cowardly way out, but maybe a smarter move than staying, those swamp monsters where scary!\n";
		Info.playerLevel++;
		std::cout << "===== ( Press any key to continue ) =====\n";
		_getch();
	}
	else {
		system("cls");
		std::cout << "You have died, and failed your mission.\n";
		Sleep(5000);
		deadLol = true;
		player_failed = true;
	}
}

void Level3() {
	player_fled = false;
	Sleep(100);
	std::cout << "\n\n=================================== LEVEL 3 ===================================\n\n";
	std::cout << "Your feet plastered with a thick layer of muddy goo, you continue on in your journey. \n";
	std::cout << "You pass a small windmill, and spot some blood coated on the door, it looks like there was a fight. \n";
	std::cout << "Looks like nobody is home. You think of what you would do if you where an assasin.\n";
	std::cout << "You think. You realize that they can't have gone the way you came, they cant have gone east, and they havn't gone west.\n";
	std::cout << "There is only one way they could go, and that's straight ahead, or north, right through the big open field.\n";
	std::cout << "Adventuring on, you pause for a break in the long grass. While sitting down, you notice somebody very stealthy flick through the underbrush.\n";
	std::cout << "It's an assasin scout! You must fight him before he sneak attacks you!\n";
	std::cout << "===== ( Press any key to continue ) =====\n";
	_getch();

	Enemy_Count = 1;
	Enemy_Count_Alive = Enemy_Count;
	turn = "YOUR";

	Enemy AssasinScout;
	AssasinScout.has_been_attacked = false;
	AssasinScout.Enemy_Health = 70;
	AssasinScout.Enemy_Damage = 15;
	AssasinScout.Enemy_Name = "Assasin Scout";
	Enemy Level3AssasinScout[1] = { AssasinScout };

	while (Enemy_Count_Alive > 0 && !player_fled && !player_failed) {
		BattleLoop(Level3AssasinScout);
		healthing_cooldown--;
	}
	system("cls");
	if (Enemy_Count_Alive < 1) {
		std::cout << "Congrats! You have defeated the Assasin, your loot: (1) Assasins Blade (30 damage), (2) Healing Potion (health goes to 150)\n";
		loot_choice = checker(loot_choice);
		if (loot_choice == 1) {
			std::cout << "You have chosen the Assasins Blades!\n";
			Info.damage = 30;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else if (loot_choice == 2) {
			std::cout << "You have chosen the Healing Potion !\n";
			Info.health = 150;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else {
			std::cout << "You have skipped choosing loot.\n";
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}

		Info.playerLevel++;

	}
	else if (player_fled) {
		std::cout << "You have taken the cowardly way out, but maybe a smarter move than staying. Assasins are a deadly threat\n";
		Info.playerLevel++;
		std::cout << "===== ( Press any key to continue ) =====\n";
		_getch();
	}
	else {
		system("cls");
		std::cout << "You have died, and failed your mission.\n";
		Sleep(5000);
		deadLol = true;
		player_failed = true;
	}
}

void Level4() {
	player_fled = false;
	Sleep(100);
	std::cout << "\n\n=================================== LEVEL 4 ===================================\n\n";
	std::cout << "After the battle with the assasins, you noticed that they released a hawk, carrying a message.\n";
	std::cout << "You follow the path of the hawk, and notice it turning slightly west, but still heading north.\n";
	std::cout << "It looks to be headed towards the mountains, a dangerous area, surounded by magical foes!\n";
	std::cout << "You prepare yourself, and turn towards the mountain. After a few hours, your peaceful hiking get interuppted with a bang.\n";
	std::cout << "It looks to be a enourmous moving rock! You must destroy the Rock Giant and it's numerous minions!\n";
	std::cout << "===== ( Press any key to continue ) =====\n";
	_getch();

	Enemy_Count = 6;
	Enemy_Count_Alive = Enemy_Count;
	turn = "YOUR";

	Enemy Magmatitan;
	Magmatitan.has_been_attacked = false;
	Magmatitan.Enemy_Health = 70;
	Magmatitan.Enemy_Damage = 5;
	Magmatitan.Enemy_Name = "Rock Giant";
	Enemy magmaMinion1;
	magmaMinion1.has_been_attacked = false;
	magmaMinion1.Enemy_Health = 10;
	magmaMinion1.Enemy_Damage = 2;
	magmaMinion1.Enemy_Name = "Rock Minion 1";
	Enemy magmaMinion2;
	magmaMinion2.has_been_attacked = false;
	magmaMinion2.Enemy_Health = 10;
	magmaMinion2.Enemy_Damage = 3;
	magmaMinion2.Enemy_Name = "Rock Minion 2";
	Enemy magmaMinion3;
	magmaMinion3.has_been_attacked = false;
	magmaMinion3.Enemy_Health = 10;
	magmaMinion3.Enemy_Damage = 4;
	magmaMinion3.Enemy_Name = "Rock Minion 3";
	Enemy magmaMinion4;
	magmaMinion4.has_been_attacked = false;
	magmaMinion4.Enemy_Health = 10;
	magmaMinion4.Enemy_Damage = 5;
	magmaMinion4.Enemy_Name = "Rock Minion 4";
	Enemy magmaMinion5;
	magmaMinion5.has_been_attacked = false;
	magmaMinion5.Enemy_Health = 10;
	magmaMinion5.Enemy_Damage = 5;
	magmaMinion5.Enemy_Name = "Rock Minion 5";

	Enemy MagmaMonsters[6] = { Magmatitan, magmaMinion1, magmaMinion2, magmaMinion3, magmaMinion4, magmaMinion5 };

	while (Enemy_Count_Alive > 0 && !player_fled && !player_failed) {
		BattleLoop(MagmaMonsters);
		healthing_cooldown--;
	}
	system("cls");
	if (Enemy_Count_Alive < 1) {
		std::cout << "Congrats! You have defeated the Rock Giant, your loot: (1) Rock Gloves (40 damage), (2) Rock Giant Heart (40 healing)\n";
		loot_choice = checker(loot_choice);
		if (loot_choice == 1) {
			std::cout << "You have chosen the Rock Gloves!\n";
			Info.damage = 40;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else if (loot_choice == 2) {
			std::cout << "You have chosen the Rock Giant Heart!\n";
			Info.healing = 40;
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}
		else {
			std::cout << "You have skipped choosing loot.\n";
			std::cout << "===== ( Press any key to continue ) =====\n";
			_getch();
		}

		Info.playerLevel++;

	}
	else if (player_fled) {
		std::cout << "You have taken the cowardly way out, but maybe a smarter move than staying. Rock Giants will crush you if you're not carefull! \n";
		Info.playerLevel++;
		std::cout << "===== ( Press any key to continue ) =====\n";
		_getch();
	}
	else {
		system("cls");
		std::cout << "You have died, and failed your mission.\n";
		Sleep(5000);
		deadLol = true;
		player_failed = true;
	}
}



void Level5() {
	player_fled = false;
	Sleep(100);
	std::cout << "\n\n=================================== LEVEL 5 ===================================\n\n";
	std::cout << "Your clothes are scarred, and your armour sooty, that fight with the Rock Giant was tough.\n";
	std::cout << "You barely got out of there alive, and you must now find and destroy the assasins camp. \n";
	std::cout << "During the battle, you saw a few elf assasins, they have to be close.\n";
	std::cout << "The mountain naturrally leads the way, and after not long, you eventually get to the end. To the camp.\n";
	std::cout << "You spot all the assasins, and the assasins spot you, hang on tight, because they're not going down with a fight!\n";
	std::cout << "There are 5 of them, it looks like one is missing, it must be the scout you fought off.\n";
	std::cout << "You look them in the eyes. This is ending, one way, or another...\n";
	std::cout << "===== ( Press any key to continue ) =====\n";
	_getch();

	Enemy_Count = 5;
	Enemy_Count_Alive = Enemy_Count;
	turn = "YOUR";

	Enemy Runnan;
	Runnan.has_been_attacked = false;
	Runnan.Enemy_Health = 100;
	Runnan.Enemy_Damage = 5;
	Runnan.Enemy_Name = "Assasin Leader";

	Enemy Rayla;
	Rayla.has_been_attacked = false;
	Rayla.Enemy_Health = 30;
	Rayla.Enemy_Damage = 7;
	Rayla.Enemy_Name = "Assasin Fighter 2";

	Enemy Ram;
	Ram.has_been_attacked = false;
	Ram.Enemy_Health = 50;
	Ram.Enemy_Damage = 5;
	Ram.Enemy_Name = "Assasin Fighter 3";

	Enemy Skor;
	Skor.has_been_attacked = false;
	Skor.Enemy_Health = 40;
	Skor.Enemy_Damage = 5;
	Skor.Enemy_Name = "Assasin Fighter 4";

	Enemy Andromeda;
	Andromeda.has_been_attacked = false;
	Andromeda.Enemy_Health = 50;
	Andromeda.Enemy_Damage = 5;
	Andromeda.Enemy_Name = "Assasin Fighter 5";
	Enemy Level5Assasin[5] = { Runnan, Rayla, Ram, Skor, Andromeda };

	// RIP Callisto, they never returned from their scouting mission

	while (Enemy_Count_Alive > 0 && !player_fled && !player_failed) {
		BattleLoopFinale(Level5Assasin);
		healthing_cooldown--;
	}
	system("cls");
	if (Enemy_Count_Alive < 1) {
		std::cout << "Congrats! You have defeated the Assasins! You restored safety to your king! \n";
		std::cout << "When you return home, everybody chears your name: " << name << "! " << name << "! " << name << "!\n";
		std::cout << "Your king is alive and healthy, all because of you! Congratulations!\n\n";
		std::cout << "===== You have unlocked DEV mode, to use it, you must play again, but using the name Marcos =====\n";
		std::cout << "===== ( Press any key to end ) =====\n";
		_getch();
		WinLol = true;
	}
	else if (player_fled) {
		std::cout << "Why are you looking at the source code? Actually, why did I put this in a cout statement, there's no way that you could ever get here unless theres a bug!\n";
		// std::cout << "You have taken the cowardly way out, but maybe a smarter move than staying. Assasins are a deadly threat.\n";
		Sleep(10000);
	}
	else {
		system("cls");
		std::cout << "You have died, and failed your mission.\n";
		Sleep(5000);
		deadLol = true;
		player_failed = true;
	}
}