#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>

extern int checker(int a);

class Enemy {               // The class: Enemy
public:                   // Access specifier: Public
	int Enemy_Health;       // Attribute: Health
	int Enemy_Damage;       // Attribute: Damage
	bool has_been_attacked; // Attribute: IsDamaged
	std::string Enemy_Name; // Attribute: Name
};

#endif
