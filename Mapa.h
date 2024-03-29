#include <iostream>
#include <windows.h>
using namespace std;

class Mapa{
private:
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	char tt = 219;
	int pixel_art[10][20] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
		{0,0,0,0,1,1,2,2,0,0,0,0,2,2,1,1,0,0,0,0},
		{0,0,0,0,1,1,2,2,0,0,0,0,2,2,1,1,0,0,0,0},
		{3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3},
		{0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,4,4,0,0,0,0,4,4,2,2,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0},
	};
public:
	Mapa();
	void update(int score);
	void lost();
	void clean();
};


