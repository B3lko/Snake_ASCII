#include "Snake.h"
#include "Food.h"
#include "Mapa.h"
#include "Creeping.h"
#include "Worm.h"
#include "Slug.h"

class Game{
private:
	int timer = 200;
	
	Food food;
	Mapa mapa;
	
	Creeping *crp = new Snake;
	
	bool end = false;
	clock_t  ttime = clock()/timer;
	int aux_time;
	vector<int>SnakeX;
	vector<int>SnakeY;
	int score = 0;
	bool comio = false;
	char dir;
	
	int selector = 0;
	
public:
	Game(){
		SnakeX = crp->getSnakeX();
		SnakeY = crp->getSnakeY();
		food.genRand(SnakeX,SnakeY);
	}
	void Update(){
		while(!end){
			crp->selectDir();
			ttime = clock()/timer;
			if(aux_time!=ttime){
				aux_time = ttime;
				
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
			}
		}
	}
	
	void Run(){
		Update();
	}
	
	bool predictEat(){
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
};
