#include "Worm.h"

Worm::Worm(vector<int> CRPX, vector<int> CRPY, char dir){
	this->dir = dir;
	crp.resize(CRPX.size());
	
	for(int i=0;i<CRPX.size();i++){
		crp[i].x = CRPX[i];
		crp[i].y = CRPY[i];
	}
	ult = crp[0];
}
	
void Worm::Draw(){
	SetConsoleTextAttribute(hConsole, 6);
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
