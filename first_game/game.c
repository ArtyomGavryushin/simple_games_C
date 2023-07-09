#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	char mas[10][21];
	int i;
	int x = 10, y = 5;
	char key;
	int ox, oy;
	int ax = 5, ay = 3;
	int counter = 0;

	srand(time(NULL));
	
	do
	{
		sprintf(mas[0], "####################");
		for (i = 1; i < 9; i++)
			sprintf(mas[i], "#                  #");
		sprintf(mas[9], "####################");

		mas[y][x] = '@';
		mas[ay][ax] = '*';

		system("cls");
		for (i = 0; i < 10; i++)
			printf("%s\n", mas[i]);
			printf("Counter:%d\n", counter);

		key = getch();


		ox = x;
		oy = y;
		if (key == 'w') y--;
		if (key == 's') y++;
		if (key == 'a') x--;
		if (key == 'd') x++;

		if (mas[y][x] == '#')
		{
			x = ox;
			y = oy;
		}
		if ((x == ax) && (y == ay))
		{
			ax = rand() * 1.0 / RAND_MAX * 18 + 1;
			ay = rand() * 1.0 / RAND_MAX * 8 + 1;
			counter++;
		}

	} while (key != 'e');
	
	return 0;
}
