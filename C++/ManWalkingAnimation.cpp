#include<iostream.h>

#include<conio.h>

#include<graphics.h>

#include<stdio.h>

#include<stdlib.h>

#include<dos.h>

void main ()

{

int gd=DETECT,gm;

int rhx,rhy,j,i;

clrscr();

initgraph(&gd,&gm,"C:\\TC\\BGI");

 

for (i = 0;i<500;i+=5)

{

line(5,380,650,380);

if(i%2==0)

{

line(25+i,380,35+i,340);

line(45+i,380,35+i,340);

line(35+i,310,25+i,330);

delay(20);

}

else

{

line(35+i,380,35+i,340);

line(35+i,310,40+i,330);

delay(20);

}

line(35+i,340,35+i,310);

circle(35+i,300,10);

line(35+i,310,50+i,330);

line(50+i,330,46+i,280);

line(8+i,285,96+i,269);

setcolor(RED);

arc(50+i,270,0,200,45);

arc(45+i,330,180,360,5);

rhx=getmaxx();

rhy=getmaxy();

for (j=0;j<100;j++)

{

outtextxy(random(rhx),random(rhy-50),"|");

setcolor (WHITE

);

}

delay(200);

cleardevice();

}

getch();

}
