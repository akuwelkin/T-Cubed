#include <iostream>
#include "tcubed.h"
#include <stdlib.h>


using namespace std;

int main()
{
	cout<<"Hello World!!!\n";
	cout<<"Cool guys 4 life!\n";

	gameboard g;
	g.placepiece('X',0,0);
	g.placepiece('X',1,1);
	g.placepiece('O',2,2);
	g.placepiece('O',2,1);

	g.printBoard();
	system("pause");

	return 0;
	//hello
}