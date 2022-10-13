#include "Snake.h"
#include "Food.h"
#include "Mapa.h"

class Game{
private:
	Snake snake;
	Food food;
	Mapa mapa;
	bool end = false;
	clock_t  ttime = clock()/500;
	int aux_time;
	vector<int>SnakeX;
	vector<int>SnakeY;
public:
	Game(){
		SnakeX = snake.getSnakeX();
		SnakeY = snake.getSnakeY();
		food.genRand(SnakeX,SnakeY);
	}
	void Update(){
		while(!end){
			ttime = clock()/500;
			if(aux_time!=ttime){
				aux_time = ttime;
				snake.move();
				snake.draw();
				food.Draw();
			}
		}
	}
	
	void Run(){
		Update();
	}
};
