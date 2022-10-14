#include <iostream>
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
		cout<<"Score: 0";
		
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
	void update(int score){
		SetConsoleTextAttribute(hConsole, 1);
		gotoxy(109,3);
		cout<<score<<endl;
	}
};


