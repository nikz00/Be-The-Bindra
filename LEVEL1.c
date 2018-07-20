#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>

int check_hit();
void draw_timer();
void draw_burst();
void reset_bullet();
void draw_bullet();
void draw_player();
void draw_balloon();
void score_card();

int p1,p2,p3,p4,p5,q1,q2,q3,q4,q5;
int dec=20;
int shoot=0;
int timer=60;
char sc[10],tm[10];
int score=0;
int i=0;
int loc=0,get_color=5;
int ctr=0;
int py=50,down_arrow=0;
int b1=60,b2=68,key_left=0,hit=0;
int color[4]={GREEN,YELLOW,RED,BLUE};
int win_game1=0;
int finish_game1=0;

int level1()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setbkcolor(0);
	while(!finish_game1)//!kbhit())
	{
		score_card();
		setcolor(WHITE);
		rectangle(0,0,getmaxx(),getmaxy());
		draw_player();
		draw_bullet();
		draw_timer();
		draw_balloon();
		ctr++;

		if(ctr>99)
		{
			ctr=0;
		}

		if(kbhit())
		{
			char ch=getch();
			if(ch=='q')
				exit(0);
			if (ch=='M')
			{
				shoot=1;
			}
			if(ch=='s')
			{
				down_arrow=1;
			}
			if(ch=='w')
			{
				down_arrow=-1;
			}


		}        /*
		if(key_left==1)
		{
			draw_bullet();
		}          */
		/*if(score>=70)
		{
			win_game1=1;
		}
		else
		{
			win_game1=0;
		} */
		check_hit();
		delay(100);
		clearviewport();
	}
	if(win_game1)
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
	return win_game1;
}
void draw_timer()
{
	if(ctr%10==0)
	{
		timer--;
	}
}
void score_card()
{
	setcolor(CYAN);
	rectangle(10,350,140,getmaxy()-5);
	if(hit)
	{
	if(get_color==0)
		score+=5;
	else if(get_color==1)
		score+=15;
	else if(get_color==2)
		score+=10;
	else if(get_color==3)
		score-=10;
	hit=0;

	}
	settextstyle(1,0,1);
	outtextxy(40,353,"LEVEL 1");
	outtextxy(20,370,"TOTAL SCORE");

	itoa(score,sc,10);
	outtextxy(65,385,sc);

	itoa(timer,tm,10);
	setcolor(RED);
	outtextxy(45,410,"Timer");
	outtextxy(55,425,tm);
	if(timer<=0)
	{
		win_game1=0;
		finish_game1=1;
	}
	if(score>=10)
	{
		win_game1=1;
		finish_game1=1;
	}

 }



int check_hit()
{
	if((b1+6)>(p1-15)&&(b1+6)<(p1+15)&&(b2+3)<(q1+50)&&(b2+3)>(q1-20)
		   ||(b1+6)>(p2-15)&&(b1+6)<(p2+15)&&(b2+3)<(q2+50)&&(b2+3)>(q2-20)
		   ||(b1+6)>(p3-15)&&(b1+6)<(p3+15)&&(b2+3)<(q3+50)&&(b2+3)>(q3-20)
		   ||(b1+6)>(p4-15)&&(b1+6)<(p4+15)&&(b2+3)<(q4+50)&&(b2+3)>(q4-20)
		   ||(b1+6)>(p5-15)&&(b1+6)<(p5+15)&&(b2+3)<(q5+50)&&(b2+3)>(q5-20)
		  )
	{
		hit=1;
		//clear_balloon();
		sound(1500);
		draw_burst();
		//delay(200);
		nosound();
		//getch();
		reset_bullet();
		loc=0;

	}
	return hit;

}
void draw_burst()
{
	int x=b1+6, y=b2+3;
	setfillstyle(SOLID_FILL,0);

	bar(150,5,getmaxx(),getmaxy());
	line(x-16,y-12,x-10,y-2);
	line(x-10,y-2,x-16,y);
	line(x-16,y,x-10,y+2);
	line(x-10,y+2,x-16,y+12);

	line(x-16,y+12,x-6,y+2);
	line(x-6,y+2,x,y+12);
	line(x,y+12,x+6,y+2);
	line(x+6,y+2,x+16,y+12);

	line(x-16,y-12,x-6,y-2);
	line(x-6,y-2,x,y-12);
	line(x,y-12,x+6,y-2);
	line(x+6,y-2,x+16,y-12);

	line(x+16,y-12,x+10,y-2);
	line(x+10,y-2,x+16,y);
	line(x+16,y,x+10,y+2);
	line(x+10,y+2,x+16,y+12);
	while(1)
	{
		   delay(300);
		   break;
	}
}

void reset_bullet()
{
	shoot=0;
	b1=60;b2=py+18;

}
/*
void draw_bullet()
{
	setfillstyle(SOLID_FILL,GREEN);
	setcolor(GREEN);
	if(!shoot)
	{
		b1=px+39;
		b2=py+30;
	}
	else
	{
		b2=b2-20;
		if(b2<0)
		{
			reset_bullet();
		}
	}
	bar(b1,b2,b1+2,b2-8);
}*/

void draw_bullet()
{
	setfillstyle(SOLID_FILL,3);
	setcolor(3);
	if(!shoot)
	{
		b2=py+18;

	}
	else
	{
		b1=b1+30;
		if(b1>getmaxx())
		{
			reset_bullet();
		}
	}
	bar(b1,b2,b1+6,b2+3);
	if((b1+6)>getmaxx())
		reset_bullet();
}
void draw_balloon()
{
	if(ctr<1){
		 p1=190;q1=400;
		 p2=280;q2=400;
		 p3=370;q3=400;
		 p4=460;q4=400;
		 p5=550;q5=400;
	}

	if(ctr<20  )
		get_color=random(4),loc=1;//get_color=random(4),loc=random(4)+1;
	else if(ctr<40 )
		get_color=random(4),loc=2;//get_color=random(4),loc=random(4)+1;
	else if(ctr<60 )
		get_color=random(4),loc=3;//get_color=random(4),loc=random(4)+1;
	else if( ctr<80 )
		get_color=random(4),loc=4;//get_color=random(4),loc=random(4)+1;
	else if(ctr<100 )
		get_color=random(4),loc=5;

	setfillstyle(SOLID_FILL, color[get_color]);
	setcolor(color[get_color]);
	switch(loc)
	{
		case 1:	fillellipse(p1,q1,15,20 );
			line(p1,q1+20,p1,q1+30);
			q1=q1-dec;
			q1=(q1+20)-dec;
			break;

		case 2:
			fillellipse(p2,q2,15,20);
			line(p2,q2,p2,q2+30);
			q2=q2+20-dec;
			q2=q2-dec;
			break;

		case 3:
			fillellipse(p3,q3,15,20);
			line(p3,q3,p3,q3+30);
			q3=q3-dec;
			q3=q3+20-dec;
			break;

		case 4:
			fillellipse(p4,q4,15,20);

			line(p4,q4,p4,q4+30);
			q4=q4-dec;
			q4=q4+20-dec;
			break;

		case 5:
			fillellipse(p5,q5,15,20);

			line(p5,q5,p5,q5+30);
			q5=q5-dec;
			q5=q5+20-dec;
			break;
		case 0:
			break;
	}

}
void draw_player()
{
	setcolor(WHITE);
	if(py<50)
	{
		py=50;
		//return;
	}
	if(py>300)
	{
		py=300;
	}

	if(down_arrow==1)
	{
		py+=25;
		down_arrow=0;
	}
	else if(down_arrow==-1)
	{
		py-=25;
		down_arrow=0;
	}

	//head & throat
	circle(40,py,10);
	line(40,py+10,40,py+15);
	//body
	rectangle(30,py+15,50,py+28);
	rectangle(30,py+28,50,py+35);
	//legs
	line(35,py+35,35,py+50);
	line(45,py+35,45,py+50);
	line(35,py+50,40,py+50);
	line(45,py+50,50,py+50);
	//gun
	line(43,py+18,60,py+18);
	line(43,py+18,43,py+24);
	line(43,py+24,46,py+24);
	line(46,py+24,46,py+21);
	line(46,py+21,60,py+21);
	line(60,py+21,60,py+18);

}
