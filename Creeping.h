#ifndef CREEPING_H
#define CREEPING_H
#include <iostream>
#include <conio2.h>
#include <vector>
#include <windows.h>
using namespace std;

class Creeping{
protected:
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	struct par{
		int x;
		int y;
	};
	char dir = 'r';
	vector<par> crp;
	par ult;
	
	char head = 219;
	char body = 178;
	char tail = 177;
	char space = 32;
	par par1, par2, par3;
	bool end = false;
public:
	virtual void Draw() = 0;
	void selectDir();
	void move(char dir);
	void moveD();
	void moveU();
	void moveL();
	void moveR();
	vector<int> getSnakeX();
	vector<int> getSnakeY();
	void eat();
	char getDir();
	bool Detect();
	bool getEnd();
	void setDir(char dir);
};
#endif
