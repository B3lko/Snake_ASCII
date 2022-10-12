#include <iostream>
using namespace std;

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

