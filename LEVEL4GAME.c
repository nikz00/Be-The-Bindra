#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
//#include<iostream.h>


void draw_player_game4();
//void draw_doors(int );
void scorecard_game4();
void draw_bar_game4();
void draw_bullet_game4();
void reset_bullet_game4();
void checkhit_game4();
void timer_game4();


char ch_game4,charscore_game4[10],chartime_game4[10];
int gametime_game4=60;
int finish_game4=0;
int score_game4[4]={10,20,30,40};
int totalscore_game4=0;
int b1_game4,b2_game4,by_game4=50;
int px_game4=300,py_game4=400;
int hit_game4=0,s_game4;
int move_right_game4=0,move_left_game4=0;
int ctr_game4=1;
int win_game4=0;
int shoot_game4=0;
int rangebx_game4[2]={20,30};
int bx1_game4=40;
int bx2_game4=500;
int bx3_game4=20;
int bx4_game4=530;
int bx5_game4=100;

int gameplay4()
{
	int gd=DETECT,gm;//,maxx,maxy;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 4");
	settextstyle(1,0,3);
	setcolor(CYAN);
	outtextxy(230,70,"INSTRUCTIONS");
	setcolor(WHITE);
	outtextxy(40,100,"-This level contains balloons that are moving up.");
	outtextxy(40,130,"-The player has to shoot the balloons.");
	outtextxy(40,160,"-The player can move up with 'w' key.");
	outtextxy(40,190,"-The player can move down with 's' key.");
	outtextxy(40,220,"-The player can shoot with the right arrow key.");

	outtextxy(40,250,"-Green balloon give 5 points.");
	outtextxy(40,280,"-Red balloon gives 10 points.");
	outtextxy(40,310,"-Yellow balloon gives 15 points.");
	outtextxy(40,340,"-Blue balloon gives -10 points.");

	outtextxy(40,370,"-You need to score 70 points to win");
	outtextxy(40,400," this level within 120 seconds.");

	getch();
	settextstyle(0,0,1);
	while(!finish_game4)
	{
		setcolor(WHITE);

		rectangle(0,40,getmaxx(),getmaxy());
		scorecard_game4();
		draw_player_game4();
		draw_bullet_game4();
		checkhit_game4();
		draw_bar_game4();
		timer_game4();
		ctr_game4++;
		if(kbhit())
		{
			ch_game4=getch();
			if(ch_game4=='d')
			{
				move_right_game4=1;
			}
			else if(ch_game4=='a')
			{
				move_left_game4=1;
			}
			else if(ch_game4=='q')
			{
				exit(0);
			}
			else if(ch_game4=='w')
			{
				shoot_game4=1;

			}
		}


		delay(100);
		nosound();
		clearviewport();
	}
	if(win_game4)
	{
		settextstyle(1,0,5);
		outtextxy(40,100,"Level Completed");
	}
	else
	{
		settextstyle(1,0,5);
		outtextxy(40,100,"You Lost! Try Again!");
	}
	//getch();
	//closegraph();
	return win_game4;
}
void checkhit_game4()
{
	if(
	     b1_game4>bx3_game4 && b1_game4<(bx3_game4+40) &&
	     b2_game4>(by_game4+50) && b2_game4<(by_game4+65)
	   )
	{
		hit_game4=1;
		s_game4=2;
		bx3_game4=-20;
	}

	if(
	     b1_game4>bx4_game4 && b1_game4<(bx4_game4+40) &&
	     b2_game4>(by_game4+75) && b2_game4<(by_game4+90)
	   )
	{
		hit_game4=1;
		s_game4=3;
		bx4_game4=-20;
	}
	if(hit_game4)
	{
		sound(1500);
		hit_game4=0;
		totalscore_game4+=score_game4[s_game4];
		reset_bullet_game4();
	}
}
void scorecard_game4()
{
	setcolor(WHITE);
	outtextxy(300,20,"LEVEL 4");
	setcolor(CYAN);
	itoa(totalscore_game4,charscore_game4,10);
	outtextxy(500,20,"Scorecard");
	outtextxy(500,30,charscore_game4);
	if(totalscore_game4>50)
	{
		clearviewport();
		settextstyle(1,0,7);
		setcolor(CYAN);
		//outtextxy(150,150,"YOU WON!");
		getch();
		finish_game4=1;
		//finish_game4=1;
		win_game4=1;
	}

}
void timer_game4()
{
	if(ctr_game4%10==0)
	{
		gametime_game4--;
	}
	itoa(gametime_game4,chartime_game4,10);
	outtextxy(50,20,"Timer");
	outtextxy(60,30,chartime_game4);
	if(gametime_game4==0)
	{
		clearviewport();
		settextstyle(1,0,7);
		setcolor(RED);
		//outtextxy(150,150,"Game Over!");
		getch();
		finish_game4=1;
		win_game4=0;
	}
}
void draw_bullet_game4()
{
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(GREEN);
	if(!shoot_game4)
	{
		b1_game4=px_game4+39;
		b2_game4=py_game4+30;
	}
	else
	{
		b2_game4=b2_game4-20;
		if(b2_game4<0)
		{
			reset_bullet_game4();
		}
	}

	bar(b1_game4,b2_game4,b1_game4+2,b2_game4-8);
}
void reset_bullet_game4()
{
	shoot_game4=0;
}
void draw_bar_game4()
{
	/*
	if(bx1_game4>getmaxx() || bx1_game4<0)
	{
		bx1_game4=40;
	}
	if(bx2_game4>getmaxx() || bx2_game4<0)
	{
		bx2_game4=500;
	}   */
	if(bx3_game4>getmaxx() || bx3_game4<0)
	{
		bx3_game4=20;
	}
	if(bx4_game4>getmaxx() || bx4_game4<0)
	{
		bx4_game4=530;
	}
	/*if(bx5_game4>getmaxx() || bx5_game4<0)
	{
		bx5_game4=10;
	} */
	if(ctr_game4%10==0)
	{
	//randomize();
	//bx1_game4=bx1_game4+rangebx_game4[random(2)];//bx1_game4=random(getmaxx()-20);
	//bx2_game4=bx2_game4-rangebx_game4[random(2)];//bx2_game4=random(getmaxx()-20);
	bx3_game4=bx3_game4+rangebx_game4[random(2)];//bx3_game4=random(getmaxx()-20);
	bx4_game4=bx4_game4-rangebx_game4[random(2)];//bx4_game4=random(getmaxx()-20);
	//bx5_game4=bx5_game4+rangebx_game4[random(2)];//bx5_game4=random(getmaxx()-20);
	}

       /*
	setfillstyle(SOLID_FILL,RED);
	bar(bx1_game4,by_game4,bx1_game4+40,by_game4+15);//bar(250,50,290,65);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(bx2_game4,by_game4+25,bx2_game4+40,by_game4+40);
       */
	setfillstyle(SOLID_FILL,GREEN);
	bar(bx3_game4,by_game4+50,bx3_game4+40,by_game4+65);

	setfillstyle(SOLID_FILL,BLUE);
	bar(bx4_game4,by_game4+75,bx4_game4+40,by_game4+90);
       /*
	setfillstyle(SOLID_FILL,YELLOW);
	bar(bx5_game4,by_game4+100,bx5_game4+40,by_game4+115);
       */
}
void draw_player_game4()
{
	if(px_game4<0 || px_game4>getmaxx()-40)
	{
		move_right_game4=move_left_game4=0;
		if(px_game4<0)
			px_game4+=20;
		if(px_game4>getmaxx()-40)
			px_game4-=20;
	}
	else
	{
	if(move_right_game4)
	{
		px_game4+=20;
		move_right_game4=0;
	}
	if(move_left_game4)
	{
		px_game4-=20;
		move_left_game4=0;
	}
	}
	setfillstyle(SOLID_FILL,WHITE);
	//fillellipse(px_game4+42,445,5,5);
	bar(px_game4+38,430,px_game4+42,440);
	bar(px_game4+20,440,px_game4+60,450);
	bar(px_game4,450,px_game4+80,460);//bar(2,450,80,460);//platform
}