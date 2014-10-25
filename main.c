/*VS 'scanf' error figyelmen kívül hagyása.*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i, ora, perc, mp;
	double mp_sz, perc_sz, ora_sz, pi;
	double xo, yo, xp, yp, xm, ym;
	double bx, by, cx, cy;

	pi = 3.14159265359;

	/*Adatbekérés*/
	scanf("%d %d %d", &ora, &perc, &mp);

	/*Mutatók pozícióinak kiszámítása*/
	mp_sz = ((-6)*mp + 90)*(pi / 180);
	perc_sz = ((-6)*perc + ((-6)*mp / 60) + 90)*(pi / 180);
	ora_sz = ((-30)*ora + ((-6)*perc / 12) + 90)*(pi / 180);

	xo = 180 * cos(ora_sz) + 300;
	yo = 180 * sin(ora_sz) + 300;
	xp = 230 * cos(perc_sz) + 300;
	yp = 230 * sin(perc_sz) + 300;
	xm = 260 * cos(mp_sz) + 300;
	ym = 260 * sin(mp_sz) + 300;

	/*Az óra alapjának megrajzolása*/
	printf("\n\n<svg width=\"600\" height=\"600\" xmlns=\"http:/*www.w3.org/2000/svg\" version=\"1.1\">\n");
	printf("<circle cx=\"300\" cy=\"300\" r=\"290\" stroke=\"silver\" fill=\"black\" stroke-width=\"10\"/>\n");

	/*A perc- és órajelzések megrajzolása*/
	for (i = 1; i <= 60; ++i){
		bx = 280 * cos(((-6)*i + 90)*(pi / 180)) + 300;
		by = 280 * sin(((-6)*i + 90)*(pi / 180)) + 300;
		if (i % 5 == 0){
			cx = 220 * cos(((-6)*i + 90)*(pi / 180)) + 300;
			cy = 220 * sin(((-6)*i + 90)*(pi / 180)) + 300;
			printf("<line x1=\"%.4f\" y1=\"%.4f\" x2=\"%.4f\" y2=\"%.4f\" stroke=\"silver\" stroke-width=\"10\"/>\r\n", bx, by, cx, cy);
		}
		else{
			cx = 250 * cos(((-6)*i + 90)*(pi / 180)) + 300;
			cy = 250 * sin(((-6)*i + 90)*(pi / 180)) + 300;
			printf("<line x1=\"%.4f\" y1=\"%.4f\" x2=\"%.4f\" y2=\"%.4f\" stroke=\"silver\" stroke-width=\"5\"/>\r\n", bx, by, cx, cy);
		}
	}

	/*Mutatók megrajzolása*/
	printf("<line x1=\"300\" y1=\"300\" x2=\"%.4f\" y2=\"%.4f\" stroke=\"silver\" stroke-width=\"10\"/>\n", xo, 600 - yo);
	printf("<line x1=\"300\" y1=\"300\" x2=\"%.4f\" y2=\"%.4f\" stroke=\"silver\" stroke-width=\"10\"/>\n", xp, 600 - yp);
	printf("<line x1=\"300\" y1=\"300\" x2=\"%.4f\" y2=\"%.4f\" stroke=\"red\" stroke-width=\"3\"/>\n", xm, 600 - ym);

	printf("<circle cx=\"300\" cy=\"300\" r=\"5\" stroke=\"silver\" fill=\"silver\" />\n");
	printf("</svg>\n");
	return 0;
}