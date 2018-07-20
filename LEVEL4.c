#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include"level4game.c"

void draw_player_gamelevel4();
void draw_doors_gamelevel4();
void draw_bullet_gamelevel4();
void reset_bullet_gamelevel4();
void checkhit_gamelevel4();

int d1_gamelevel4,d2_gamelevel4,d3_gamelevel4,d4_gamelevel4,s_gamelevel4,hit_gamelevel4=0;
int shoot_gamelevel4=0,b1_gamelevel4,b2_gamelevel4;
int color_gamelevel4[4]={GREEN,BLUE,YELLOW};
char ch_gamelevel4;
int left_move_gamelevel4=0,right_move_gamelevel4=0;
int gx_gamelevel4=300,gy_gamelevel4=400;
int gx1_gamelevel4,gx2_gamelevel4,gx3_gamelevel4,gx4_gamelevel4,gx5_gamelevel4,gx6_gamelevel4;
int px_gamelevel4=300,py_gamelevel4=400;
int win_gamelevel4=0;
int finish_gamelevel4=0;


int level4()
{
	int gd=DETECT,gm,maxx,maxy;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	while(!finish_gamelevel4)
	{
		setcolor(WHITE);
		setbkcolor(BLACK);
		//settextstyle(0,0,1);
		outtextxy(200,5,"hit_gamelevel4 the door, But be carefull");

		outtextxy(40,18,"                  Blue means play the level game");
		outtextxy(40,30,"Yellow means go to previous level,   Green means go to next level");
		rectangle(0,40,getmaxx(),getmaxy());
		draw_player_gamelevel4();
		draw_doors_gamelevel4();
		draw_bullet_gamelevel4();

		if(kbhit())
		{
			ch_gamelevel4=getch();
			if(ch_gamelevel4=='q')
			{
				exit(0);
			}
			else if(ch_gamelevel4=='a')
			{
				left_move_gamelevel4=1;
			}
			else if(ch_gamelevel4=='d')
			{
				right_move_gamelevel4=1;
			}
			else if(ch_gamelevel4=='w')
			{
				shoot_gamelevel4=1;

			}
		}
		checkhit_gamelevel4();
		if(win_gamelevel4==1)
		{
			finish_gamelevel4=1;
		}

		delay(100);
		nosound();
		clearviewport();
	}
	getch();
	//clearviewport();
	//closegraph();
	return win_gamelevel4;
}
void checkhit_gamelevel4()
{
	if(
	    b1_gamelevel4>40 && b1_gamelevel4<140 &&
	    b2_gamelevel4>50 && b2_gamelevel4<200
	  )
	{
		hit_gamelevel4=1;
		s_gamelevel4=d1_gamelevel4;
	}
	else if(
		 b1_gamelevel4>190 && b1_gamelevel4<290 &&
		b2_gamelevel4>50 && b2_gamelevel4<200
	       )
	{
		hit_gamelevel4=1;
		s_gamelevel4=d2_gamelevel4;
	}
	else if(
		 b1_gamelevel4>340 && b1_gamelevel4<440 &&
		b2_gamelevel4>50 && b2_gamelevel4<200
	       )
	{
		hit_gamelevel4=1;
		s_gamelevel4=d3_gamelevel4;
	}
	else if(
		 b1_gamelevel4>490 && b1_gamelevel4<590 &&
		b2_gamelevel4>50 && b2_gamelevel4<200
	       )
	{
		hit_gamelevel4=1;
		s_gamelevel4=d4_gamelevel4;
	}
	if(hit_gamelevel4)
	{
		hit_gamelevel4=0;
		sound(1500);
		reset_bullet_gamelevel4();

		if(color_gamelevel4[s_gamelevel4]==BLUE)
		{
			delay(100);
			nosound();
			win_gamelevel4=gameplay4();
			finish_gamelevel4=1;

		}
		else if(color_gamelevel4[s_gamelevel4]==GREEN)
		{
			win_gamelevel4=1;
			delay(100);
			nosound();
			finish_gamelevel4=1;
			//gameplay4();
		}
		else if(color_gamelevel4[s_gamelevel4]==YELLOW)
		{
			//
			win_gamelevel4=gameplay4();
			delay(100);
			nosound();
			//gameplay4();
			finish_gamelevel4=1;
		}
		else
		{
			delay(100);
			nosound();
			//win_gamelevel4=3;
		}
	}

}


void draw_bullet_gamelevel4()
{
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(GREEN);
	if(!shoot_gamelevel4)
	{
		b1_gamelevel4=px_gamelevel4+39;
		b2_gamelevel4=py_gamelevel4+30;
	}
	else
	{
		b2_gamelevel4=b2_gamelevel4-20;
		if(b2_gamelevel4<0)
		{
			reset_bullet_gamelevel4();
		}
	}

	bar(b1_gamelevel4,b2_gamelevel4,b1_gamelevel4+2,b2_gamelevel4-8);
}
void reset_bullet_gamelevel4()
{
	shoot_gamelevel4=0;
}
void draw_player_gamelevel4()
{
	if(px_gamelevel4<0 || px_gamelevel4>getmaxx()-40)
	{
		left_move_gamelevel4=right_move_gamelevel4=0;
		if(px_gamelevel4<0)
			px_gamelevel4+=20;
		if(px_gamelevel4>getmaxx()-40)
			px_gamelevel4-=20;
	}
	else
	{
	if(right_move_gamelevel4)
	{
		px_gamelevel4+=20;
		right_move_gamelevel4=0;
	}
	if(left_move_gamelevel4)
	{
		px_gamelevel4-=20;
		left_move_gamelevel4=0;
	}
	}
	setfillstyle(SOLID_FILL,WHITE);
	//fillellipse(px_gamelevel4+42,445,5,5);
	bar(px_gamelevel4+38,430,px_gamelevel4+42,440);
	bar(px_gamelevel4+20,440,px_gamelevel4+60,450);
	bar(px_gamelevel4,450,px_gamelevel4+80,460);//bar(2,450,80,460);//platform
}
void draw_doors_gamelevel4()
{
	d1_gamelevel4=color_gamelevel4[random(4)];
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,d1_gamelevel4);
	bar(40,50,90,200);
	bar(90,50,140,200);
	rectangle(40,50,90,200);
	rectangle(90,50,140,200);
	circle(50,125,5);

	d2_gamelevel4=color_gamelevel4[random(4)];
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,d2_gamelevel4);
	bar(190,50,240,200);
	bar(240,50,290,200);
	rectangle(190,50,240,200);
	rectangle(240,50,290,200);
	circle(200,125,5);

	d3_gamelevel4=color_gamelevel4[random(4)];
	setcolor(color_gamelevel4[random(4)]);
	setfillstyle(SOLID_FILL,d3_gamelevel4);
	bar(340,50,390,200);
	bar(390,50,440,200);
	rectangle(340,50,390,200);
	rectangle(390,50,440,200);
	circle(350,125,5);

	d4_gamelevel4=color_gamelevel4[random(4)];
	setcolor(color_gamelevel4[random(4)]);
	setfillstyle(SOLID_FILL,d4_gamelevel4);
	bar(490,50,540,200);
	bar(540,50,590,200);
	rectangle(490,50,540,200);
	rectangle(540,50,590,200);
	circle(500,125,5);
}