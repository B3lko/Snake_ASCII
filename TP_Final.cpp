#include <iostream>
#include <conio2.h>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;

class Mapa{
private:
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	char tt = 219;
public:
	Mapa(){
		for(int i=0;i<120;i++){
			gotoxy(i,1);
			cout<<tt;
			gotoxy(i,30);
			cout<<tt;
		}
		for(int i=0;i<30;i++){
			gotoxy(1,i);
			cout<<tt;
			gotoxy(2,i);
			cout<<tt;
			gotoxy(119,i);
			cout<<tt;
			gotoxy(120,i);
			cout<<tt;
			
			gotoxy(97,i);
			cout<<tt;
			gotoxy(98,i);
			cout<<tt;
			
			
		}
		for(int i=99;i<120;i++){
			gotoxy(i,5);
			cout<<tt;
			gotoxy(i,19);
			cout<<tt;
		}
		gotoxy(102,3);
		cout<<"Score: ";
		
		gotoxy(104,7);
		cout<<"Controls: ";
		
		gotoxy(100,9);
		cout<<"Pause: P";
		gotoxy(100,11);
		cout<<"Up   : Up    Arrow";
		gotoxy(100,13);
		cout<<"Down : Down  Arrow";
		gotoxy(100,15);
		cout<<"Left : Left  Arrow";
		gotoxy(100,17);
		cout<<"Right: Right Arrow";
		
		for(int i=99;i<119;i++){
			gotoxy(i,20);
			SetConsoleTextAttribute(hConsole, 2);
			cout<<tt;
		}
		gotoxy(99,21);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,22);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,23);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,24);
		SetConsoleTextAttribute(hConsole, 5);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 5);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,25);
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt;
		
		gotoxy(99,26);
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt;
		
		gotoxy(99,27);
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 0);
		cout<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,28);
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 7);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 7);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt;
		
		gotoxy(99,29);
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 4);
		cout<<tt<<tt;
		SetConsoleTextAttribute(hConsole, 2);
		cout<<tt<<tt;
	}
};

class Food{
private:
	struct par{
		int x;
		int y;
	};
	char dfood = 178;
	par par1;
public:
	Food(){
		genRand();
	}
	void genRand(){
		srand (time(NULL));
		par1.x = rand()%100 + 1;
		srand (time(NULL));
		par1.y = rand()%30 +1;
	}
	void Draw(){
		gotoxy(par1.x,par1.y);
		cout<<dfood;
		gotoxy(par1.x+1,par1.y);
		cout<<dfood;
	}
};

class Snake{
private:
	struct par{
		int x;
		int y;
	};
	vector<par>snake;
	char dir = 'r';
	const char head = 219;
	char body = 178;
	char tail = 177;
	char space = 32;
	par par1, par2, par3;
	par ult;
public:
	Snake(){
		par1.x = 15;
		par1.y = 15;
		par2.x = 17;
		par2.y = 15;
		par3.x = 19;
		par3.y = 15;
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
		gotoxy(ult.x+1,ult.y);
		cout<<space;
		for(int unsigned i=0;i<snake.size();i++){
			gotoxy(snake[i].x,snake[i].y);
			cout<<head;
			gotoxy(snake[i].x+1,snake[i].y);
			cout<<tail;
		}
		
	}
	void move(){
		
		
		if(kbhit()) { 
			int tecla=getch();
			switch(tecla){
			case (72):if(dir!='d')dir='u';break;
			case (80):if(dir!='u')dir='d';break;
			case (77):if(dir!='l')dir='r';break;
			case (75):if(dir!='r')dir='l';break;
			};
		}
		
		switch(dir){
		case 'r':moveR();break;
		case 'l':moveL();break;
		case 'd':moveD();break;
		case 'u':moveU();break;
		}
	}
	void moveD(){
		ult = snake[0];
		int si = snake.size();
		for(int unsigned i=0;i<snake.size();i++){
			if(si-1 == i){
				snake[i].y = snake[i].y + 1;
			}
			else{
				snake[i] = snake[i+1];
			}
		}
	}
	void moveU(){
		ult = snake[0];
		int si = snake.size();
		for(int unsigned i=0;i<snake.size();i++){
			if(si-1 == i){
				snake[i].y = snake[i].y - 1;
			}
			else{
				snake[i] = snake[i+1];
			}
		}
	}
	void moveL(){
		ult = snake[0];
		int si = snake.size();
		for(int unsigned i=0;i<snake.size();i++){
			if(si-1 == i){
				snake[i].x = snake[i].x - 2;
			}
			else{
				snake[i] = snake[i+1];
			}
		}
	}
	void moveR(){
		ult = snake[0];
		int si = snake.size();
		for(int unsigned i=0;i<snake.size();i++){
			if(si-1 == i){
				snake[i].x = snake[i].x + 2;
			}
			else{
				snake[i] = snake[i+1];
			}
		}
	}
};

class Game{
private:
	Snake snake;
	Food food;
	Mapa mapa;
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
				food.Draw();
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

