#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<iostream.h>

int calculatehrs(int h)
{
int x;
switch(h)
{
case 0: x=90;
break;
case 1:
case 13: x=60;
break;
case 2:
case 14: x=30;
break;
case 3:
case 15: x=0;
break;
case 4:
case 16: x=330;
break;
case 5:
case 17: x=300;
break;
case 6:
case 18: x=270;
break;
case 7:
case 19: x=240;
break;
case 8:
case 20: x=210;
break;
case 9:
case 21: x=180;
break;
case 10:
case 22: x=150;
break;
case 11:
case 23: x=120;
break;
case 12:
case 24: x=90;
break;
}
return(x);
}

int calculatemin(int m)
{
int x;
if(m%5==0)
{
switch(m)
{
case 0: x=90;
break;
case 5: x=60;
break;
case 10: x=30;
break;
case 15: x=360;
break;
case 20: x=330;
break;
case 25: x=300;
break;
case 30: x=270;
break;
case 35: x=240;
break;
case 40: x=210;
break;
case 45: x=180;
break;
case 50: x=150;
break;
case 55: x=120;
break;
case 60: x=90;
break;
}
}
else
{
if(m>0&&m<15)
{
switch(m)
{
case 1: x=84;
break;
case 2: x=78;
break;
case 3: x=72;
break;
case 4: x=66;
break;
case 6: x=54;
break;
case 7: x=48;
break;
case 8: x=42;
break;
case 9: x=36;
break;
case 11: x=24;
break;
case 12: x=18;
break;
case 13: x=12;
break;
case 14: x=6;
break;
}
}
if(m>15&&m<30)
{
switch(m)
{
case 16: x=354;
break;
case 17: x=348;
break;
case 18: x=342;
break;
case 19: x=336;
break;
case 21: x=324;
break;
case 22: x=318;
break;
case 23: x=312;
break;
case 24: x=306;
break;
case 26: x=294;
break;
case 27: x=288;
break;
case 28: x=282;
break;
case 29: x=276;
break;
}
}

if(m>30&&m<45)
{
switch(m)
{
case 31: x=264;
break;
case 32: x=258;
break;
case 33: x=252;
break;
case 34: x=246;
break;
case 36: x=234;
break;
case 37: x=228;
break;
case 38: x=222;
break;
case 39: x=216;
break;
case 41: x=204;
break;
case 42: x=198;
break;
case 43: x=192;
break;
case 44: x=186;
break;
}
}

if(m>45&&m<60)
{
switch(m)
{
case 46: x=174;
break;
case 47: x=168;
break;
case 48: x=162;
break;
case 49: x=156;
break;
case 51: x=144;
break;
case 52: x=138;
break;
case 53: x=132;
break;
case 54: x=126;
break;
case 56: x=114;
break;
case 57: x=108;
break;
case 58: x=102;
break;
case 59: x=96;
break;
}
}

}
return(x);
}
int changehrs(int m,int a)
{
if(m>15&&m<=30)
a-=12;
if(m>30&&m<=45)
a-=18;
if(m>45&&m<60)
a-=24;
return (a);
}

void main()
{
int gdriver=DETECT,gmode,h,m,s,a,b,c;
initgraph(&gdriver,&gmode,”c:\tc\bgi”);

struct  time t;
gettime(&t);
h=t.ti_hour;
m=t.ti_min;
s=t.ti_sec;

a=calculatehrs(h);
b=calculatemin(m);
c=calculatemin(s);
a=changehrs(m,a);

for(int i=a;i>0;i-=6)
for(int j=b;j>0;j-=6)
for(int k=c;k>0;k-=6)
{
setbkcolor(7);
settextstyle(1,HORIZ_DIR,5);
setcolor(BLUE);
outtextxy(190,20,”Analog Clock”);
settextstyle(8,HORIZ_DIR,2);

setcolor(BLUE);
circle(300,200,102);
setcolor(YELLOW);
circle(300,200,100);
outtextxy(385,185,”3″);
outtextxy(288,98,”12″);
outtextxy(207,185,”9″);
outtextxy(295,270,”6″);

circle(345,123,2);
circle(378,155,2);
circle(378,245,2);
circle(345,280,2);
circle(253,278,2);
circle(223,245,2);
circle(223,155,2);
circle(253,123,2);

setcolor(RED);
pieslice(300,200,i-1,i,75);
setcolor(WHITE);
pieslice(300,200,j-1,j,85);

setcolor(BLUE);
pieslice(300,200,k-1,k,95);

setcolor(RED);
settextstyle(3,HORIZ_DIR,1);
outtextxy(360,400,”Press any key to exit…!!”);
sleep(1);
clearviewport();

if(i==6)
a=360;
if(j==6)
b=360;
if(k==6)
c=360;

if(kbhit())
{
setcolor(YELLOW);
setbkcolor(BLUE);
settextstyle(1,HORIZ_DIR,8);
outtextxy(130,150,”Thank You”);
sleep(3);
exit(0);
}

}
}