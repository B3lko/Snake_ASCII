#include "Mapa.h"
#include <conio2.h>
#include <windows.h>

Mapa::Mapa(){
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
	cout<<"Score: 0";
	
	gotoxy(104,7);
	cout<<"Controls: ";
	
	gotoxy(100,9);
	cout<<"Leave: L";
	gotoxy(100,11);
	cout<<"Up   : Up    Arrow";
	gotoxy(100,13);
	cout<<"Down : Down  Arrow";
	gotoxy(100,15);
	cout<<"Left : Left  Arrow";
	gotoxy(100,17);
	cout<<"Right: Right Arrow";
	
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			gotoxy(99+j,20+i);
			switch(pixel_art[i][j]){
			case 0:SetConsoleTextAttribute(hConsole, 2);break;
			case 1:SetConsoleTextAttribute(hConsole, 0);break;
			case 2:SetConsoleTextAttribute(hConsole, 4);break;
			case 3:SetConsoleTextAttribute(hConsole, 5);break;
			case 4:SetConsoleTextAttribute(hConsole, 7);break;
			}
			cout<<tt;
		}
	}
}
	
void Mapa::update(int score){
	SetConsoleTextAttribute(hConsole, 7);
	gotoxy(109,3);
	cout<<score<<endl;
}

void Mapa::lost(){
	gotoxy(42,11);
	cout<<"     You lost!"<<endl;
	gotoxy(42,14);
	cout<<"Press R to play again"<<endl;
	gotoxy(42,16);
	cout<<"         Or"<<endl;
	gotoxy(42,18);
	cout<<"Press E to exit game";
}

void Mapa::clean(){
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
	for(int i=3;i<97;i++){
		for(int j=2;j<30;j++){
			gotoxy(i,j);
			cout<<" ";
		}
	}
}
