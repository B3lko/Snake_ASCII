#ifndef SLUG_H
#define SLUG_H
#include <iostream>
#include <conio2.h>
#include "Creeping.h"
#include <vector>
using namespace std;

class Slug : public Creeping{
public:
	
	Slug(vector<int> CRPX, vector<int> CRPY, char dir);
	void Draw() override;
};
#endif
