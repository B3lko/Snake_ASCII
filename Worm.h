#ifndef WORM_H
#define WORM_H
#include <iostream>
#include <conio2.h>
#include "Creeping.h"
#include <vector>
using namespace std;

class Worm : public Creeping{
public:
	Worm(vector<int> CRPX, vector<int> CRPY, char dir);
	void Draw() override;
};
#endif
