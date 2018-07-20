#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>


void draw_timer_game5();
void draw_scorecard_game5();
void draw_player_game5();
//void draw_bigboss_game5();
void draw_robots_game5();
void draw_pipes_game5();
void draw_bullet_game5();
void reset_bullet_game5();
void checkhit_game5();

int score_game5[5]={10,20,30,40,50},totalscore_game5=0;
int ctr_game5=0,time_game5=60,s_game5=10;
char charscore_game5[10],chartime_game5[10];
int rb1_game5=1,rb2_game5=1,rb3_game5=1,rb4_game5=1,rb5_game5=1;
int a_game5,mb1_game5,mb2_game5,hit_game5=0;
int gun1_game5=1,gun2_game5=0,gun3_game5=0,gun4_game5=0;
int key_right_game5=0,b1_game5,b2_game5,shoot_game5=0;
int pos_game5[14]={8,3,5,2,-2,5,4,-2,4,8,5,6,3,4};
int pos2_game5[4]={2,1,-1,-2};
int movex_game5[6]={4,5,6,7,8,9};
int movey_game5[6]={4,5,6,7,8,9};
int py_game5=400,px_game5=250;
int rx1_game5=100,ry1_game5=42;
int rx2_game5=300,ry2_game5=42;
int rx3_game5=480,ry3_game5=42;
int rx4_game5=1,ry4_game5=135;
int rx5_game5=1,ry5_game5=275;
int left_key_game5=0,right_key_game5=0,up_key_game5=0,down_key_game5=0;
int finish_game5=0,win_game5=0;

int level5()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");

	while(!finish_game5)
	{
		ctr_game5++;
		setbkcolor(0);
		setcolor(WHITE);
		rectangle(0,40,getmaxx(),getmaxy());
		outtextxy(getmaxx()/2-40,10,"LEVEL 5");
		draw_scorecard_game5();
		draw_timer_game5();
		draw_player_game5();
		draw_bullet_game5();
		//reset_bullet_game5();
		draw_robots_game5();
		draw_pipes_game5();
		//draw_bigboss_game5();

		if(kbhit())
		{
			char ch=getch();
			if(ch=='w')
			{
				up_key_game5=1;
			}
			else if(ch=='s')
			{
				down_key_game5=1;
			}
			else if(ch=='d')
			{
				right_key_game5=1;
			}
			else if(ch=='a')
			{
				left_key_game5=1;
			}
			else if(ch=='q')
			{
				exit(0);
			}
			else if(ch=='M')
			{
				shoot_game5=1;
			}
		}
		if(shoot_game5)
		{
			if(gun1_game5)
			{
				mb1_game5+=30;
				mb2_game5=b2_game5;
				if((mb1_game5+6)>getmaxx())
				{
					b1_game5=px_game5+60;
					b2_game5=py_game5+18;
					shoot_game5=0;
				}

			}
			else if(gun3_game5)
			{
				mb1_game5-=30;
				mb2_game5=b2_game5;
				if((mb1_game5+6)<0)
				{
					b1_game5=px_game5+18;
					b2_game5=py_game5+18;
					shoot_game5=0;
				}
			}
			else if(gun4_game5)
			{
				mb1_game5=b1_game5;
				mb2_game5-=30;
				if((mb2_game5+6)<40)
				{
					b1_game5=px_game5+52;
					b2_game5=py_game5+7;
					shoot_game5=0;

				}
			}
			//draw_bullet_game5();
		}
		checkhit_game5();
		delay(100);
		nosound();
		clearviewport();
	}
	getch();
	//cleardevice();
	return win_game5;
}
void checkhit_game5()
{
	if(
	    (rx1_game5+25)>(px_game5+30) && (rx1_game5+25)<(px_game5+60) &&
	    (ry1_game5+24)>(py_game5) && (ry1_game5+15)<(py_game5+50)
					||
	    (rx2_game5+25)>(px_game5+30) && (rx2_game5+25)<(px_game5+60) &&
	    (ry2_game5+24)>(py_game5) && (ry2_game5+15)<(py_game5+50)
				      ||
	    (rx3_game5+25)>(px_game5+30) && (rx3_game5+25)<(px_game5+60) &&
	    (ry3_game5+24)>(py_game5) && (ry3_game5+15)<(py_game5+50)
				    ||
	    (rx4_game5+25)>(px_game5+30) && (rx4_game5+25)<(px_game5+60) &&
	    (ry4_game5+24)>(py_game5) && (ry4_game5+15)<(py_game5+50)
				  ||
	    (rx5_game5+25)>(px_game5+30) && (rx5_game5+25)<(px_game5+60) &&
	    (ry5_game5+24)>(py_game5) && (ry5_game5+15)<(py_game5+50)
	  )
	{
		//died=1;
		sound(1000);totalscore_game5-=1;
	}

	if(
	    (rx1_game5-5)>(px_game5+30) && (rx1_game5-5)<(px_game5+60) &&
	    (ry1_game5+28)>(py_game5+15) && (ry1_game5+15)<(py_game5+35)
	    ||
	    (rx2_game5-5)>(px_game5+30) && (rx2_game5-5)<(px_game5+60) &&
	    (ry2_game5+28)>(py_game5+15) && (ry2_game5+15)<(py_game5+35)
	    ||
	    (rx3_game5-5)>(px_game5+30) && (rx3_game5-5)<(px_game5+60) &&
	    (ry3_game5+28)>(py_game5+15) && (ry3_game5+15)<(py_game5+35)
	    ||
	    (rx4_game5-5)>(px_game5+30) && (rx4_game5-5)<(px_game5+60) &&
	    (ry4_game5+28)>(py_game5+15) && (ry4_game5+15)<(py_game5+35)
	    ||
	    (rx5_game5-5)>(px_game5+30) && (rx5_game5-5)<(px_game5+60) &&
	    (ry5_game5+28)>(py_game5+15) && (ry5_game5+15)<(py_game5+35)
	  )
	{
		sound(1000);totalscore_game5-=1;
	}
	else if(
	    (mb1_game5)>(rx1_game5-5) && (mb1_game5)<(rx1_game5+25) &&
	    (mb2_game5)>(ry1_game5-5) && (mb2_game5)<(ry1_game5+25)
	    && shoot_game5
	  )
	{
		hit_game5=1;
		s_game5=0;
		rb1_game5=0;

	}
	else if(
	    (mb1_game5)>(rx2_game5-5) && (mb1_game5)<(rx2_game5+25) &&
	    (mb2_game5)>(ry2_game5-5) && (mb2_game5)<(ry2_game5+25)
	    && shoot_game5
	  )
	{
		hit_game5=1;
		s_game5=1;
		rb2_game5=0;

	}
	else if(
	    (mb1_game5)>(rx3_game5-5) && (mb1_game5)<(rx3_game5+25) &&
		(mb2_game5)>(ry3_game5-5) && (mb2_game5)<(ry3_game5+25)
		&& shoot_game5
	  )
	{
		hit_game5=1;
		s_game5=2;
		rb3_game5=0;

	}
	else if(
	    (mb1_game5)>(rx4_game5-5) && (mb1_game5)<(rx4_game5+25) &&
	    (mb2_game5)>(ry4_game5-5) && (mb2_game5)<(ry4_game5+25)
	    && shoot_game5
	  )
	{
		hit_game5=1;
		s_game5=3;
		rb4_game5=0;
	}
	else if(
	    (mb1_game5)>(rx5_game5-5) && (mb1_game5)<(rx5_game5+25) &&
	    (mb2_game5)>(ry5_game5-5) && (mb2_game5)<(ry5_game5+25)
	    && shoot_game5
	   )
	{
		hit_game5=1;
		s_game5=4;
		rb5_game5=0;

	}


	if(hit_game5)
	{
		reset_bullet_game5();
		sound(1500);
		totalscore_game5+=score_game5[s_game5];
		hit_game5=0;
	}
}

void draw_player_game5()
{
	if(left_key_game5)
	{
		if(px_game5>0)
			px_game5-=10;

		left_key_game5=0;
		gun3_game5=1;
		gun1_game5=gun2_game5=gun4_game5=0;
		b1_game5=px_game5+18;
		b2_game5=py_game5+18;
		shoot_game5=0;

	}
	else if(right_key_game5)
	{
		if((px_game5+50)<getmaxx())
			px_game5+=10;
		right_key_game5=0;
		gun1_game5=1;
		gun2_game5=gun3_game5=gun4_game5=0;
		b1_game5=px_game5+60;
		b2_game5=py_game5+18;
		shoot_game5=0;
	}
	else if(up_key_game5)
	{
		if((py_game5)>50)
			py_game5-=10;
		up_key_game5=0;
		gun4_game5=1;
		gun1_game5=gun2_game5=gun3_game5=0;
		b1_game5=px_game5+52;
		b2_game5=py_game5+7;
		shoot_game5=0;

	}
	else if(down_key_game5)
	{
		if((py_game5+30)<getmaxy())
			py_game5+=10;
		down_key_game5=0;
		gun2_game5=1;
		gun2_game5=gun3_game5=gun4_game5=0;

	}
	//head & throat
	circle(px_game5+40,py_game5,10);
	line(px_game5+40,py_game5+10,px_game5+40,py_game5+15);
	//body
	rectangle(px_game5+30,py_game5+15,px_game5+50,py_game5+28);
	rectangle(px_game5+30,py_game5+28,px_game5+50,py_game5+35);
	//legs
	line(px_game5+35,py_game5+35,px_game5+35,py_game5+50);
	line(px_game5+45,py_game5+35,px_game5+45,py_game5+50);
	line(px_game5+35,py_game5+50,px_game5+40,py_game5+50);
	//line(px_game5+45,py_game5+50,px_game5+50,py_game5+50);
	//gun
	if(gun1_game5)
	{
		line(px_game5+43,py_game5+18,px_game5+60,py_game5+18);
		line(px_game5+43,py_game5+18,px_game5+43,py_game5+24);
		line(px_game5+43,py_game5+24,px_game5+46,py_game5+24);
		line(px_game5+46,py_game5+24,px_game5+46,py_game5+21);
		line(px_game5+46,py_game5+21,px_game5+60,py_game5+21);
		line(px_game5+60,py_game5+21,px_game5+60,py_game5+18);
	}
	else if(gun2_game5)
	{
		line(px_game5+43,py_game5+18,px_game5+60,py_game5+18);
		line(px_game5+43,py_game5+18,px_game5+43,py_game5+24);
		line(px_game5+43,py_game5+24,px_game5+46,py_game5+24);
		line(px_game5+46,py_game5+24,px_game5+46,py_game5+21);
		line(px_game5+46,py_game5+21,px_game5+60,py_game5+21);
		line(px_game5+60,py_game5+21,px_game5+60,py_game5+18);
	}
	else if(gun3_game5)
	{
		line(px_game5+36,py_game5+18,px_game5+19,py_game5+18);
		line(px_game5+36,py_game5+18,px_game5+36,py_game5+24);
		line(px_game5+36,py_game5+24,px_game5+33,py_game5+24);
		line(px_game5+33,py_game5+24,px_game5+33,py_game5+21);
		line(px_game5+33,py_game5+21,px_game5+19,py_game5+21);
		line(px_game5+19,py_game5+21,px_game5+19,py_game5+18);
	}
	else if(gun4_game5)
	{
		line(px_game5+48,py_game5+21,px_game5+52,py_game5+21);
		line(px_game5+52,py_game5+21,px_game5+52,py_game5+7);
		line(px_game5+52,py_game5+7,px_game5+55,py_game5+7);
		line(px_game5+55,py_game5+7,px_game5+55,py_game5+25);
		line(px_game5+55,py_game5+25,px_game5+48,py_game5+25);
		line(px_game5+48,py_game5+25,px_game5+48,py_game5+22);
	}
}

void reset_bullet_game5()
{
	if(gun1_game5)
	{
		b1_game5=px_game5+60;
		b2_game5=py_game5+18;
		shoot_game5=0;
	}
	else if(gun3_game5)
	{
		b1_game5=px_game5+18;
		b2_game5=py_game5+18;
		shoot_game5=0;
	}
	else if(gun4_game5)
	{
		b1_game5=px_game5+52;
		b2_game5=py_game5+7;
		shoot_game5=0;
	}
	//key_right_game5=0;
	//shoot_game5=0;
	//b1_game5=px_game5+60;b2_game5=py_game5+18;

}
void draw_bullet_game5()
{
	setfillstyle(SOLID_FILL,3);
	setcolor(3);
	if(gun1_game5)
	{
		if (shoot_game5)
		{
			bar(mb1_game5,b2_game5,mb1_game5+6,b2_game5+3);
		}
		else
		{
			b1_game5=px_game5+60;
			b2_game5=py_game5+18;
			bar(b1_game5,b2_game5,b1_game5+6,b2_game5+3);
			mb1_game5=b1_game5;
		}
	}
	else if(gun2_game5)
	{

	}
	else if(gun3_game5)
	{
		if (shoot_game5)
		{
			bar(mb1_game5,b2_game5,mb1_game5+6,b2_game5+3);
		}
		else
		{
			b1_game5=px_game5+18;
			b2_game5=py_game5+18;
			bar(b1_game5,b2_game5,b1_game5+6,b2_game5+3);
			mb1_game5=b1_game5;
		}
	}
	else if(gun4_game5)
	{
		if (shoot_game5)
		{
			bar(b1_game5,mb2_game5,b1_game5+3,mb2_game5+6);
		}
		else
		{
			b1_game5=px_game5+52;
			b2_game5=py_game5+7;
			bar(b1_game5,b2_game5,b1_game5+3,b2_game5+6);
			mb2_game5=b2_game5;
		}
	}


	//if((mb1_game5+6)>getmaxx())//||(b2_game5+6)>getmaxy())


}

void draw_scorecard_game5()
{
	setcolor(CYAN);
	itoa(totalscore_game5,charscore_game5,10);
	outtextxy(getmaxx()-100,10,"Scorecard");
	outtextxy(getmaxx()-100,25,charscore_game5);
	if(totalscore_game5>300)
	{
		win_game5=1;
		finish_game5=1;
	}
}

void draw_timer_game5()
{
	setcolor(RED);
	outtextxy(20,10,"Timer");
	if(ctr_game5==10)
	{
		time_game5--;
		ctr_game5=0;
	}
	itoa(time_game5,chartime_game5,10);
	outtextxy(30,25,chartime_game5);
	setcolor(WHITE);
	if(time_game5==0)
	{
		win_game5=0;
		finish_game5=1;
	}
}

void draw_robots_game5()
{
	if(rb1_game5)
	{
		setfillstyle(SOLID_FILL,YELLOW);
		setcolor(YELLOW);
//set1
		bar(rx1_game5,ry1_game5,rx1_game5+20,ry1_game5+10);//bar(400,100,420,110);
		bar(rx1_game5+7,ry1_game5+10,rx1_game5+14,ry1_game5+14);//bar(407,110,414,114);
		bar(rx1_game5-5,ry1_game5+14,rx1_game5+25,ry1_game5+28);//bar(395,114,425,128);
		//if(set_eye)
		setfillstyle(SOLID_FILL,6);
		bar(rx1_game5+5,ry1_game5+2,rx1_game5+7,ry1_game5+4);//bar(405,102,407,104);//eye1 r1
		bar(rx1_game5+13,ry1_game5+2,rx1_game5+15,ry1_game5+4);//bar(413,102,415,104);//eye2   r1
		if(rx1_game5>getmaxx() || ry1_game5>getmaxy()|| rx1_game5<0 )
		{
			rx1_game5=100;ry1_game5=42;
		}
	 }
	 else if(ctr_game5==5)
	 {
		rx1_game5=100;ry1_game5=42;
		rb1_game5=1;
	 }

	 if(rb2_game5)
	 {
		setfillstyle(SOLID_FILL,BLUE);
		setcolor(BLUE);
//set2
		bar(rx2_game5,ry2_game5,rx2_game5+20,ry2_game5+10);//bar(400,100,420,110);
		bar(rx2_game5+7,ry2_game5+10,rx2_game5+14,ry2_game5+14);//bar(407,110,414,114);
		bar(rx2_game5-5,ry2_game5+14,rx2_game5+25,ry2_game5+28);//bar(395,114,425,128);
		//if(set_eye)
		setfillstyle(SOLID_FILL,6);
		bar(rx2_game5+5,ry2_game5+2,rx2_game5+7,ry2_game5+4);//bar(405,102,407,104);//eye1 r1
		bar(rx2_game5+13,ry2_game5+2,rx2_game5+15,ry2_game5+4);//bar(413,102,415,104);//eye2   r1
		if(rx2_game5>getmaxx() || ry2_game5>getmaxy() || rx2_game5<0)
		{
			rx2_game5=300;ry2_game5=42;
		}
	}
	else if(ctr_game5==5)
	{
		rx2_game5=300;ry2_game5=42;
		rb2_game5=1;
	}
//set3
	if(rb3_game5)
	{
		setfillstyle(SOLID_FILL,RED);
		setcolor(RED);
		bar(rx3_game5,ry3_game5,rx3_game5+20,ry3_game5+10);//bar(400,100,420,110);
		bar(rx3_game5+7,ry3_game5+10,rx3_game5+14,ry3_game5+14);//bar(407,110,414,114);
		bar(rx3_game5-5,ry3_game5+14,rx3_game5+25,ry3_game5+28);//bar(395,114,425,128);
		//if(set_eye)
		setfillstyle(SOLID_FILL,6);
		bar(rx3_game5+5,ry3_game5+2,rx3_game5+7,ry3_game5+4);//bar(405,102,407,104);//eye1 r1
		bar(rx3_game5+13,ry3_game5+2,rx3_game5+15,ry3_game5+4);//bar(413,102,415,104);//eye2   r1
		if(rx3_game5>getmaxx() || ry3_game5>getmaxy() || rx3_game5<0)
		{
			rx3_game5=480;ry3_game5=42;

		}
	}
	else if(ctr_game5==5)
	{
		rx3_game5=480;ry3_game5=42;
		rb3_game5=1;
	}
//set4
	if(rb4_game5)
	{
		setfillstyle(SOLID_FILL,CYAN);
		setcolor(CYAN);
		bar(rx4_game5,ry4_game5,rx4_game5+20,ry4_game5+10);//bar(400,100,420,110);
		bar(rx4_game5+7,ry4_game5+10,rx4_game5+14,ry4_game5+14);//bar(407,110,414,114);
		bar(rx4_game5-5,ry4_game5+14,rx4_game5+25,ry4_game5+28);//bar(395,114,425,128);
		//if(set_eye)
		setfillstyle(SOLID_FILL,6);
		bar(rx4_game5+5,ry4_game5+2,rx4_game5+7,ry4_game5+4);//bar(405,102,407,104);//eye1 r1
		bar(rx4_game5+13,ry4_game5+2,rx4_game5+15,ry4_game5+4);//bar(413,102,415,104);//eye2   r1
		if(rx4_game5>getmaxx() || ry4_game5>getmaxy() || rx4_game5<0)
		{
			rx4_game5=1;ry4_game5=135;


		}
	}
	else if(ctr_game5==5)
	{
		rx4_game5=1;ry4_game5=135;
		rb4_game5=1;
	}
//set5
	if(rb5_game5)
	{
		setfillstyle(SOLID_FILL,WHITE);
		setcolor(WHITE);
		bar(rx5_game5,ry5_game5,rx5_game5+20,ry5_game5+10);//bar(400,100,420,110);
		bar(rx5_game5+7,ry5_game5+10,rx5_game5+14,ry5_game5+14);//bar(407,110,414,114);
		bar(rx5_game5-5,ry5_game5+14,rx5_game5+25,ry5_game5+28);//bar(395,114,425,128);
		//if(set_eye)
		setfillstyle(SOLID_FILL,6);
		bar(rx5_game5+5,ry5_game5+2,rx5_game5+7,ry5_game5+4);//bar(405,102,407,104);//eye1 r1
		bar(rx5_game5+13,ry5_game5+2,rx5_game5+15,ry5_game5+4);//bar(413,102,415,104);//eye2   r1
		if(rx5_game5>getmaxx() || ry5_game5>getmaxy() || rx5_game5<0)
		{
			rx5_game5=1;ry5_game5=275;
		}
	}
	else  if(ctr_game5==5)
	{
		rb5_game5=1;
		rx5_game5=1;ry5_game5=275;
	}
//	a_game5=random(5);
	//randomize();
	//if(a_game5==0)
	{

		rx1_game5=rx1_game5+movex_game5[random(6)];
		ry1_game5=ry1_game5+pos_game5[random(14)];
		rx1_game5=rx1_game5-(1.2*pos_game5[random(14)]);

		rx2_game5=rx2_game5+(2*pos_game5[random(14)]);
		ry2_game5=ry2_game5+pos_game5[random(14)];
		rx2_game5=rx2_game5-(2*pos_game5[random(6)]);

		rx3_game5=rx3_game5-movex_game5[random(6)];
		ry3_game5=ry3_game5+pos_game5[random(14)];
		rx3_game5=rx3_game5+(2*pos_game5[random(14)]);

		rx4_game5=rx4_game5+(1.5*pos_game5[random(14)]);
		ry4_game5=ry4_game5+pos2_game5[random(4)];
		//rx4_game5=rx4_game5-pos_game5[random(14)];

		rx5_game5=rx5_game5+(1.7*pos_game5[random(14)]);
		ry5_game5=ry5_game5+pos2_game5[random(4)];
		//rx5_game5=rx5_game5-pos_game5[random(14)];
	}
}

void draw_pipes_game5()
{
	setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);

	bar(80,41,140,60);
	fillellipse(80,55,5,5);
	fillellipse(140,55,5,5);

	bar(280,41,340,60);
	fillellipse(280,55,5,5);
	fillellipse(340,55,5,5);

	bar(460,41,520,60);
	fillellipse(460,55,5,5);
	fillellipse(520,55,5,5);

	bar(1,120,20,180);
	fillellipse(15,120,5,5);
	fillellipse(15,180,5,5);

	bar(1,260,20,320);
	fillellipse(15,260,5,5);
	fillellipse(15,320,5,5);

	bar(getmaxx()+1,150,getmaxx()-20,300);
	fillellipse(getmaxx()-15,150,5,5);
	fillellipse(getmaxx()-15,300,5,5);


}