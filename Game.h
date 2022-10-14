#include "Snake.h"
#include "Food.h"
#include "Mapa.h"

class Game{
private:
	int timer = 200;
	Snake snake;
	Food food;
	Mapa mapa;
	bool end = false;
	clock_t  ttime = clock()/timer;
	int aux_time;
	vector<int>SnakeX;
	vector<int>SnakeY;
	int score = 0;
	bool comio = false;
public:
	Game(){
		SnakeX = snake.getSnakeX();
		SnakeY = snake.getSnakeY();
		food.genRand(SnakeX,SnakeY);
	}
	void Update(){
		while(!end){
			snake.selectDir();
			ttime = clock()/timer;
			if(aux_time!=ttime){
				aux_time = ttime;
				
				if(predictEat()){
					food.genRand(SnakeX,SnakeY);
					snake.eat();
					score++;
					mapa.update(score);
					comio = true;
				}
				
				if(!comio){
					snake.move();
				}
				comio = false;
				snake.draw();
			}
		}
	}
	
	void Run(){
		Update();
	}
	
	bool predictEat(){
		char dir = snake.getDir();
		SnakeX = snake.getSnakeX();
		SnakeY = snake.getSnakeY();
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
