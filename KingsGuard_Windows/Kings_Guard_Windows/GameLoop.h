#ifndef GAMELOOP_H
#define GAMELOOP_H

void GameLoopFunction();
int start();

struct Information {
public:
	int healing;
	int hours_left;
	long double playerLevel;
	int health;
	float damage;
};

extern std::string levels[5];
extern int checker(int a);
extern std::string name;
extern struct Information Info;
extern bool deadLol;
extern bool QuitLol;

#endif