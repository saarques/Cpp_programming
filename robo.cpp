#include <graphics.h>
void wait_for_char(){
	//Wait for a key press
	int in = 0;
	while (in == 0)
		in = getchar();
}

int main(){
	// initwindow(800, 800); //creating a window
	int gd = DETECT, gm; // left = 100, top = 100, right = 200, bottom = 200, x = 300, y = 150, radius = 50;
	initgraph(&gd, &gm, NULL);
	line(750, 750, 100, 750);
	line(100, 750, 100, 100);

	//arm1
	line(130, 600, 240, 500);
	//arm2
	line(240, 500, 265, 400);
	//arm3
	line(265, 400, 300, 425);

	//grapple
	line(300, 435, 300, 415);
	line(300, 415, 310, 422);
	line(300, 435, 310, 429);

	// joints
	circle(130, 600, 4);
	circle(240, 500, 4);
	circle(265, 400, 4);   // 3rd link
	circle(300, 425, 2);
	getch();
	delay(5000);
	wait_for_char();
	closegraph();
	return 0;
}