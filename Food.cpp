#include <iostream>
#include "food.h"
#include <ctime>
#include <conio2.h>
using namespace std;

void Food::genRand(vector<int> SnakeX, vector<int> SnakeY){
	okay2 = false;
	
	while(!okay2){
		okay2 = true;
		
		srand (time(NULL));
		okay = false;
		while(!okay){
			par1.x = 3 + rand()% (96 - 3);
			if(par1.x%2!=0){
				okay = true;
			}
		}
		srand (time(NULL));
		par1.y = 2 + rand()% (29 - 2);
		
		for(int i=0;i<SnakeX.size();i++){
			if(SnakeX[i]==par1.x && SnakeY[i]==par1.y){
				okay2 = false;
			}
		}
	}
	this->Draw();
}
	
void Food::Draw(){
	SetConsoleTextAttribute(hConsole, 4);
	gotoxy(par1.x,par1.y);
	cout<<dfood;
	gotoxy(par1.x+1,par1.y);
	cout<<dfood;
}
	
int Food::getX(){
	return par1.x;
}
	
int Food::getY(){
	return par1.y;
}

