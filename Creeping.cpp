#include "Creeping.h"

void Creeping::selectDir() {
	if(kbhit()) { 
		int tecla=getch();
		switch(tecla){
		case (72):if(dir!='d')dir='u';break;
		case (80):if(dir!='u')dir='d';break;
		case (77):if(dir!='l')dir='r';break;
		case (75):if(dir!='r')dir='l';break;
		case 'l':end = true;
		};
	}
}

void Creeping::move(){
	switch(dir){
	case 'r':moveR();break;
	case 'l':moveL();break;
	case 'd':moveD();break;
	case 'u':moveU();break;
	}
}
	
void Creeping::moveD(){
	ult = crp[0];
	int si = crp.size();
	for(int unsigned i=0;i<crp.size();i++){
		if(si-1 == i){
			crp[i].y = crp[i].y + 1;
		}
		else{
			crp[i] = crp[i+1];
		}
	}
}
	
void Creeping::moveU(){
	ult = crp[0];
	int si = crp.size();
	for(int unsigned i=0;i<crp.size();i++){
		if(si-1 == i){
			crp[i].y = crp[i].y - 1;
		}
		else{
			crp[i] = crp[i+1];
		}
	}
}
	
void Creeping::moveL(){
	ult = crp[0];
	int si = crp.size();
	for(int unsigned i=0;i<crp.size();i++){
		if(si-1 == i){
			crp[i].x = crp[i].x - 2;
		}
		else{
			crp[i] = crp[i+1];
		}
	}
}
	
void Creeping::moveR(){
	ult = crp[0];
	int si = crp.size();
	for(int unsigned i=0;i<crp.size();i++){
		if(si-1 == i){
			crp[i].x = crp[i].x + 2;
		}
		else{
			crp[i] = crp[i+1];
		}
	}
}

vector<int> Creeping::getSnakeX(){
	vector<int> SnakeX;
	for(int i=0;i<crp.size();i++){
		SnakeX.resize(SnakeX.size()+1);
		SnakeX[i] = crp[i].x;
	}
	return SnakeX;
}
	
vector<int> Creeping::getSnakeY(){
	vector<int> SnakeY;
	for(int i=0;i<crp.size();i++){
		SnakeY.resize(SnakeY.size()+1);
		SnakeY[i] = crp[i].y;
	}
	return SnakeY;
}
	
void Creeping::eat(){
	crp.resize(crp.size()+1);
	switch(dir){
	case 'r':
		crp[crp.size()-1].x = crp[crp.size()-2].x + 2;
		crp[crp.size()-1].y = crp[crp.size()-2].y;
		break;
	case 'l':
		crp[crp.size()-1].x = crp[crp.size()-2].x - 2;
		crp[crp.size()-1].y = crp[crp.size()-2].y;
		break;
	case 'd':
	crp[crp.size()-1].x = crp[crp.size()-2].x;
	crp[crp.size()-1].y = crp[crp.size()-2].y + 1;
		break;
	case 'u':
		crp[crp.size()-1].x = crp[crp.size()-2].x;
		crp[crp.size()-1].y = crp[crp.size()-2].y - 1;
		break;
	}
}
	
char Creeping::getDir(){
	return dir;
}
	
bool Creeping::Detect(){
	for(int i=0;i<crp.size()-1;i++){
		if(crp[crp.size()-1].x == crp[i].x && crp[crp.size()-1].y == crp[i].y){
			return true;
		}
	}
	return false;
}
	
bool Creeping::getEnd(){
	return end;
}
