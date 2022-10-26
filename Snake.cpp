#include "Snake.h"

Snake::Snake(vector<int> CRPX, vector<int> CRPY, char dir){
	this->dir = dir;
	crp.resize(CRPX.size());
	
	for(int i=0;i<CRPX.size();i++){
		crp[i].x = CRPX[i];
		crp[i].y = CRPY[i];
	}
	ult = crp[0];
}
	
Snake::Snake(){
	par1.x = 15;
	par1.y = 15;
	par2.x = 17;
	par2.y = 15;
	par3.x = 19;
	par3.y = 15;
	for(int i=0;i<3;i++){
		crp.resize(crp.size()+1);
	}
	crp[0] = par1;
	crp[1] = par2;
	crp[2] = par3;
}
	
void Snake::Draw(){
	SetConsoleTextAttribute(hConsole, 2);
	gotoxy(ult.x,ult.y);
	cout<<space;
	gotoxy(ult.x+1,ult.y);
	cout<<space;
	for(int unsigned i=0;i<crp.size();i++){
		gotoxy(crp[i].x,crp[i].y);
		cout<<head;
		gotoxy(crp[i].x+1,crp[i].y);
		cout<<tail;
	}
}
