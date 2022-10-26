#include "Snake.h"
#include "Food.h"
#include "Mapa.h"
#include "Creeping.h"
#include "Worm.h"
#include "Slug.h"

class Game{
private:
	int timer = 100;
	
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
	Game();
	void Update();
	void Run();
	bool predictEat();
	bool DetectCollision();
};
