#include <iostream>
#include "Queen.h"

int main()
{
	Queen f(6);
	f.place(0, 0);
	f.place(1, 2);
	f.place(2, 4);
	f.place(3, 1);
	f.place(4, 3);
	int count = 1;
	f.print();
	std::cout<<f.place_queen(count)<<'\n'<<'\n';
	f.print();
}
