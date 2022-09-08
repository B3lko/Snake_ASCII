#include <iostream>
#include <conio2.h>
#include <vector>
#include <ctime>
using namespace std;

class Snake{
private:
	struct par{
		int x;
		int y;
	};
	vector<par>snake;
	char direction = 'r';
	const char head = 219;
	char body = 178;
	char tail = 177;
	char space = 32;
	par par1, par2, par3;
	par ult;
public:
	Snake(){
		par1.x = 1;
		par1.y = 1;
		par2.x = 3;
		par2.y = 1;
		par3.x = 5;
		par3.y = 1;
		for(int i=0;i<3;i++){
			snake.resize(snake.size()+1);
		}
		snake[0] = par1;
		snake[1] = par2;
		snake[2] = par3;
	}
	void Draw(){
		gotoxy(ult.x,ult.y);
		cout<<space;
		for(int unsigned i=0;i<snake.size();i++){
			gotoxy(snake[i].x,snake[i].y);
			cout<<head;
		}
		
	}
	void move(){
		ult = snake[0];
		int si = snake.size();
		for(int unsigned i=0;i<snake.size();i++){
			if(si = i){
				snake[i].x = snake[i].x + 2;
			}
			else{
				snake[i].x = snake[i+1].x;
			}
		}
	}
};

class Game{
private:
	Snake snake;
	bool end = false;
	clock_t  ttime = clock()/1000;
	int aux_time;
public:
	Game(){
		
	}
	void Update(){
		while(!end){
			ttime = clock()/1000;
			if(aux_time!=ttime){
				aux_time = ttime;
				snake.move();
				snake.Draw();
			}
		}
	}
	void Run(){
		Update();
	}
};

int main(int argc, char *argv[]) {
	Game game;
	game.Run();
	return 0;
}

