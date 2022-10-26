#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <vector>
#include <ctime>
#include <conio2.h>
#include <windows.h>
using namespace std;

class Food{
private:
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	struct par{
		int x;
		int y;
	};
	char dfood = 178;
	par par1;
	bool okay,okay2;
public:
	void genRand(vector<int> SnakeX, vector<int> SnakeY);
	void Draw();
	int getX();
	int getY();
};
#endif
