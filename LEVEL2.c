#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void hit_hold_game2();
void score_card_game2();
void reset_bullet_game2();
void draw_player_game2();
void draw_robot_game2();
void draw_bullet_game2();
//void draw_explode();
void check_hit_game2();



int hit_game2=0,loc1_game2=0,loc2_game2=0,loc3_game2=0,loc4_game2=0,ctr2_game2=0;
int shoot_game2=0;
int move_up_game2=0,move_down_game2=0,left_key_game2=0;
int get_color_game2        ;
int loc1_ctr_game2,loc2_ctr_game2,loc3_ctr_game2,loc4_ctr_game2;
int score_game2=0;
char sc_game2[10],tm_game2[10];
int timer_game2=100;
int color_game2[4]={GREEN,YELLOW,RED,BLUE};
int py_game2=50,b1_game2=60,b2_game2;
int px_game2=10;
int finish_game2=0,win_game2=0;

int level2()
{
	int gd=DETECT,gm,maxx,maxy;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

	while(!finish_game2)
	{
		score_card_game2();
		setcolor(6);
		settextstyle(0,0,2);
		rectangle(0,0,getmaxx(),getmaxy());
		outtextxy(250,10,"LEVEL 2");
		setcolor(4);
		draw_player_game2();
		draw_bullet_game2();
		draw_robot_game2();

		ctr2_game2++;
		if(kbhit())
		{
			char ch=getch();
			if(ch=='q')
				exit(0);
			if(ch=='s')
				move_down_game2=1;
			if(ch=='w')
				move_up_game2=1;
			if(ch=='M')
				shoot_game2=1;
		}
		check_hit_game2();
		//hit_hold_game2();
		delay(100);
		clearviewport();
		//cleardevice();
	}
	if(win_game2)
	{
		settextstyle(1,0,5);
		outtextxy(40,100,"Level Completed");
	}
	else
	{
		settextstyle(1,0,5);
		outtextxy(40,100,"You Lost! Try Again!");
	}
	getch();

	//closegraph();
	return win_game2;
}
void reset_bullet_game2()
{
	shoot_game2=0;
	b1_game2=60;b2_game2=py_game2+18;

}

void draw_bullet_game2()
{
	setfillstyle(SOLID_FILL,3);
	setcolor(3);
	if(!shoot_game2)
	{
		b2_game2=py_game2+18;

	}
	else
	{
		b1_game2=b1_game2+30;
		if(b1_game2>getmaxx())
		{
			reset_bullet_game2();
		}
	}
	bar(b1_game2,b2_game2,b1_game2+6,b2_game2+3);
	if((b1_game2+6)>getmaxx())
		reset_bullet_game2();
}
/*
void draw_bullet_game2()
{
	if(!shoot_game2)
	{
		b1_game2=px_game2+50;
	}
	else
	{
		b1_game2+=20;
		if(b2_game2>getmaxx())
		{
			reset_bullet_game2();
		}
	}
	b2_game2=py_game2+18;
	setfillstyle(SOLID_FILL,3);
	setcolor(3);
	bar(b1_game2,b2_game2,b1_game2+6,b2_game2+3);
	if((b1_game2+6)>getmaxx())
		reset_bullet_game2();
}
*/
void check_hit_game2()
{
	if(((b1_game2+6)>395 && (b1_game2+6)<425 && (b2_game2+3)>100 && (b2_game2+3)<128  && loc1_game2==0)
	   ||((b1_game2+6)>275 && (b1_game2+6)<305 && (b2_game2+3)>180 && (b2_game2+3)<208 && loc2_game2==0)
	   ||((b1_game2+6)>545 && (b1_game2+6)<575 && (b2_game2+3)>260 && (b2_game2+3)<288 && loc3_game2==0)
	   ||((b1_game2+6)>345 && (b1_game2+6)<375 && (b2_game2+3)>320 && (b2_game2+3)<348 && loc4_game2==0)
	  )
	{
		if(((b1_game2+6)>395 && (b1_game2+6)<425 && (b2_game2+3)>100 && (b2_game2+3)<128  ))
		{
			loc1_game2=1;
			loc1_ctr_game2++;

		}
		if((b1_game2+6)>275 && (b1_game2+6)<305 && (b2_game2+3)>180 && (b2_game2+3)<208)
		{
			loc2_game2=1;
			loc2_ctr_game2++;
		}
		if((b1_game2+6)>545 && (b1_game2+6)<575 && (b2_game2+3)>260 && (b2_game2+3)<288)
		{
			loc3_game2=1;
			loc3_ctr_game2++;
		}
		if((b1_game2+6)>345 && (b1_game2+6)<375 && (b2_game2+3)>320 && (b2_game2+3)<348)
		{
			loc4_game2=1;
			loc4_ctr_game2++;
		}
		hit_game2=1;
		sound(2000);
		//draw_explode();
		delay(500);
		nosound();
		reset_bullet_game2();
	}
}
/*
void draw_explode()
{
	setfillstyle(SOLID_FILL,0);
	bar(365,90,430,127);
	arc(395,100,0,180,10);
	arc(415,100,0,180,10);
	arc(425,110,270,90,10);
	arc(415,120,180,0,10);
	arc(395,120,180,0,10);
	arc(385,110,90,270,10);
	line(405,90,405,75);
	line(430,95,440,85);
	line(430,125,440,135);
	line(405,130,405,145);
	line(380,125,365,135);
	line(380,95,365,85);
	setfillstyle(SOLID_FILL,0);
	bar(245,170,310,207);
	arc(275,180,0,180,10);
	arc(295,180,0,180,10);
	arc(305,190,270,90,10);
	arc(295,200,180,0,10);
	arc(275,200,180,0,10);
	arc(265,190,90,270,10);
	line(285,160,285,145);
	line(310,165,320,155);
	line(310,195,320,185);
	line(285,200,285,195);
	line(260,195,245,185);
	line(260,165,245,135);
	setfillstyle(SOLID_FILL,0);
	bar(525,250,580,287);
	setfillstyle(SOLID_FILL,0);
	bar(325,310,380,347);
}
*/
void score_card_game2()
{
	setcolor(CYAN);
	rectangle(10,350,140,getmaxy()-10);
	if(hit_game2)
	{
	if(get_color_game2==0)
		score_game2+=5;
	else if(get_color_game2==1)
		score_game2+=15;
	else if(get_color_game2==2)
		score_game2+=10;
	else if(get_color_game2==3)
		score_game2-=10;

	hit_game2=0;
	}
	settextstyle(1,0,2);
	outtextxy(40,350,"Timer");
	outtextxy(27,390,"Scorecard");
	outtextxy(22,410,"Total Score");

	itoa(score_game2,sc_game2,10);
	outtextxy(70,430,sc_game2);

	itoa(timer_game2,tm_game2,10);
	setcolor(RED);
	outtextxy(60,370,tm_game2);
	if(timer_game2<=0)
	{
		win_game2=0;
		finish_game2=1;
	}
	else
	{
		if(ctr2_game2%10==0)
			timer_game2--;
	}
	if(score_game2>=20)
	{
		win_game2=1;
		finish_game2=1;
	}


 }

void draw_player_game2()
{
	if(py_game2<50)
	{
		py_game2=50;
		//return;
	}
	if(py_game2>300)
	{
		py_game2=300;
	}

	if(move_down_game2==1)
	{
		py_game2+=25;
		move_down_game2=0;
	}
	else if(move_up_game2==1)
	{
		py_game2-=25;
		move_up_game2=0;
	}

	//head & throat
	circle(40,py_game2,10);
	line(40,py_game2+10,40,py_game2+15);
	//body
	rectangle(30,py_game2+15,50,py_game2+28);
	rectangle(30,py_game2+28,50,py_game2+35);
	//legs
	line(35,py_game2+35,35,py_game2+50);
	line(45,py_game2+35,45,py_game2+50);
	line(35,py_game2+50,40,py_game2+50);
	line(45,py_game2+50,50,py_game2+50);
	//gun
	line(43,py_game2+18,60,py_game2+18);
	line(43,py_game2+18,43,py_game2+24);
	line(43,py_game2+24,46,py_game2+24);
	line(46,py_game2+24,46,py_game2+21);
	line(46,py_game2+21,60,py_game2+21);
	line(60,py_game2+21,60,py_game2+18);

}

void draw_robot_game2()
{
	//setcolor(14);

	get_color_game2=random(4);
	setfillstyle(SOLID_FILL,color_game2[get_color_game2]);
	setcolor(color_game2[get_color_game2]);

	if(loc1_game2!=1)
	{
		bar(400,100,420,110);
		bar(407,110,414,114);
		bar(395,114,425,128);
	}
	else
	{
		//t1=timer_game2-5;
		if(loc1_ctr_game2==20)
		{
			loc1_ctr_game2=0;
			loc1_game2=0;
		}
		loc1_ctr_game2++;
	}
	setfillstyle(SOLID_FILL,WHITE);
	bar(370,128,450,129);


	get_color_game2=random(4);
	setfillstyle(SOLID_FILL,color_game2[get_color_game2]);
	setcolor(color_game2[get_color_game2]);
	if(loc2_game2!=1)
	{
	bar(280,180,300,190);//face
	bar(287,190,294,194);
	bar(275,194,305,208);
	}
	else
	{
		if(loc2_ctr_game2==20)
		{
			loc2_ctr_game2=0;
			loc2_game2=0;
		}
		loc2_ctr_game2++;
	}
	setfillstyle(SOLID_FILL,WHITE);
	bar(250,208,330,209);

	get_color_game2=random(4);
	setfillstyle(SOLID_FILL,color_game2[get_color_game2]);
	setcolor(color_game2[get_color_game2]);
	if(loc3_game2!=1)
	{
	bar(550,260,570,270);
	bar(557,270,564,274);
	bar(545,274,575,288);
	}
	else
	{
		if(loc3_ctr_game2==20)
		{
			loc3_ctr_game2=0;
			loc3_game2=0;
		}
		loc3_ctr_game2++;
	}
	setfillstyle(SOLID_FILL,WHITE);
	bar(520,288,600,289);

	get_color_game2=random(4);
	setfillstyle(SOLID_FILL,color_game2[get_color_game2]);
	setcolor(color_game2[get_color_game2]);
	if(loc4_game2!=1)
	{
	bar(350,320,370,330);
	bar(357,330,364,334);
	bar(345,334,375,348);
	}
	else
	{
		if(loc4_ctr_game2==20)
		{
			loc4_ctr_game2=0;
			loc4_game2=0;
		}
		loc4_ctr_game2++;
	}
	setfillstyle(SOLID_FILL,WHITE);
	bar(320,348,400,349);

	setfillstyle(SOLID_FILL,6);
	if(loc1_game2!=1)
	{
	bar(405,102,407,104);//eye1 r1
	bar(413,102,415,104);//eye2   r1
	}
	if(loc2_game2!=1)
	{
	bar(285,182,287,184);//eye r2
	bar(293,182,295,184);//eye   r2
	}
	if(loc3_game2!=1)
	{
	bar(555,262,557,264);//r3
	bar(563,262,565,264);    //r3
	}
	if(loc4_game2!=1)
	{
	bar(355,322,357,324);
	bar(363,322,365,324);
	}

	setfillstyle(SOLID_FILL,12);
	if(loc1_game2!=1)
		bar(408,106,412,108);//mouth    r1
	if(loc2_game2!=1)
		bar(288,186,292,188);//r2
	if(loc3_game2!=1)
		bar(558,266,562,268);//r3
	if(loc4_game2!=1)
		bar(358,326,362,328);

}