#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
#include <conio2.h>
#include "Creeping.h"
using namespace std;

class Snake : public Creeping{
public:
	Snake(vector<int> CRPX, vector<int> CRPY, char dir);
	Snake();
	void Draw() override;
};
#endif
