#include "Snake.h"
#include "Food.h"
#include "Mapa.h"

class Game{
private:
	Snake snake;
	Food food;
	Mapa mapa;
	bool end = false;
	clock_t  ttime = clock()/1000;
	int aux_time;
public:
	void Update(){
		while(!end){
			ttime = clock()/1000;
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
