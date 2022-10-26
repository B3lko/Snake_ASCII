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
			
			if(crp->getEnd()){
				this->end=true;
				end2 = true;
				this->brestart = false;
			}
			
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
				if(lastdir=='r' && dir=='l' || lastdir=='l' && dir=='r' || lastdir=='d' && dir=='u' || lastdir=='u' && dir=='d'){
					dir = lastdir;
				}
					crp->move(dir);
					lastdir = crp->getDir();
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
	
	if(end2 != true){
		mapa.lost();
		answer = false;
		while(!answer){
			if(kbhit()) { 
				int tecla=getch();
				switch(tecla){
				case 'r':this->restart();answer = true;end=false;break;
				case 'e':answer = true;brestart = false;break;
				}
			}
		}
	}
	
}

void Game::Run(){
	while(brestart){
		Update();
	}
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

void Game::restart(){
	delete crp;
	crp = new Snake;
	score = 0;
	mapa.update(score);
	mapa.clean();
	SnakeX = crp->getSnakeX();
	SnakeY = crp->getSnakeY();
	food.genRand(SnakeX,SnakeY);
	crp->setDir('r');
	dir = 'r';
	lastdir = 'r';
}
