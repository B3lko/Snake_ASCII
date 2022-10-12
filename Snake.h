#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
#include <conio2.h>
using namespace std;

class Snake{
private:
	struct par{
		int x;
		int y;
	};
	vector<par> snake;
	char dir = 'r';
	char head = 219;
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
	
	void draw(){
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
#endif
