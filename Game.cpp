#include "Game.h"

Game::Game(){
	SnakeX = crp->getSnakeX();
	SnakeY = crp->getSnakeY();
	food.genRand(SnakeX,SnakeY);
}

void Game::Update(){
	while(!end){
		crp->selectDir();
		ttime = clock()/timer;
		if(aux_time!=ttime){
			aux_time = ttime;
			this->end=crp->getEnd();
			if(predictEat()){
				food.genRand(SnakeX,SnakeY);
				crp->eat();
				score++;
				mapa.update(score);
				comio = true;
				
				dir = crp->getDir();
				SnakeX = crp->getSnakeX();
				SnakeY = crp->getSnakeY();
				
				delete crp;
				switch(selector){
				case 0: crp = new Worm(SnakeX,SnakeY,dir);selector=1;break;
				case 1: crp = new Slug(SnakeX,SnakeY,dir);selector=2;break;
				case 2: crp = new Snake(SnakeX,SnakeY,dir);selector=0;break;
				}
			}
			
			if(!comio){
				crp->move();
			}
			comio = false;
			crp->Draw();
			
			if(DetectCollision()){
				end = true;
			}
			
			if(crp->Detect()){
				end = true;
			}
			
		}
	}
	gotoxy(10,15);
}

void Game::Run(){
	Update();
}
	
bool Game::predictEat(){
	dir = crp->getDir();
	SnakeX = crp->getSnakeX();
	SnakeY = crp->getSnakeY();
	int fx = food.getX();
	int fy = food.getY();
	switch(dir){
		case 'r':
			if(SnakeX[SnakeX.size()-1] + 2 == fx && SnakeY[SnakeX.size()-1] == fy){
				return true;
			}
			break;
		case 'l':
			if(SnakeX[SnakeX.size()-1] - 2 == fx && SnakeY[SnakeX.size()-1] == fy){
				return true;
			}
			break;
		case 'd':
			if(SnakeX[SnakeX.size()-1] == fx && SnakeY[SnakeX.size()-1] + 1 == fy){
				return true;
			}
			break;
		case 'u':
			if(SnakeX[SnakeX.size()-1] == fx && SnakeY[SnakeX.size()-1] - 1 == fy){
				return true;
			}
			break;
	}
	return false;
}
	
bool Game::DetectCollision(){
	SnakeX = crp->getSnakeX();
	SnakeY = crp->getSnakeY();
	int SNKX,SNKY;
	SNKX = SnakeX[SnakeX.size()-1];
	SNKY = SnakeY[SnakeY.size()-1];
	if(SNKX<=2 || SNKX>=96){
		return true;
	}
	if(SNKY<=1 || SNKY>=30){
		return true;
	}
	else{
		return false;
	}
}
