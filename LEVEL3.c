#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

void draw_player_game3();
void draw_range_game3();
void draw_robot_game3();
void score_card_game3();
void draw_bullet_game3();
void reset_bullet_game3();
void checkhit_game3();
void timer_game3();

char chartime_game3[10],charscore_game3[10];
int win_game3=0;
int hit_game3=0;
int gametime_game3=60,totalscore_game3=0,score_game3=100;

int ctr_game3=0,set_eye_game3=0;;
int color_game3[4]={GREEN,YELLOW,RED,BLUE},get_color_game3;
int py_game3=300,px_game3=200;
int rx_game3, ry_game3;
int down_arrow_game3=0;
int move_right_game3=0,move_left_game3=0,move_up_game3=0,move_down_game3=0;
int left_key_game3=0,right_key_game3,up_key_game3=0,down_key_game3=0;
int gun1_game3=1,gun2_game3=0,gun3_game3=0,gun4_game3=0;
int b1_game3,b2_game3,shoot_game3=0;
int mb1_game3,mb2_game3;
int finish_game3=0;

int level3()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	while(!finish_game3)
	{
		setbkcolor(8);
		ctr_game3++;

		draw_range_game3();
		draw_player_game3();
		draw_bullet_game3();

		draw_robot_game3();

		if(kbhit())
		{
			char ch=getch();
			if(ch=='d')
				right_key_game3=1;
			if(ch=='a')
				left_key_game3=1;
			if(ch=='s')
				down_key_game3=1;
			if(ch=='w')
				up_key_game3=1;
			if(ch=='q')
				exit(0);
			if(ch=='M')
				shoot_game3=1;
		}
		if(shoot_game3)
		{
			if(gun1_game3)
			{
				mb1_game3+=30;
				mb2_game3=b2_game3;
				if((mb1_game3+6)>getmaxx())
				{
					b1_game3=px_game3+60;
					b2_game3=py_game3+18;
					shoot_game3=0;
				}

			}
			else if(gun3_game3)
			{
				mb1_game3-=30;
				mb2_game3=b2_game3;
				if((mb1_game3+6)<0)
				{
					b1_game3=px_game3+18;
					b2_game3=py_game3+18;
					shoot_game3=0;
				}
			}
			else if(gun4_game3)
			{
				mb1_game3=b1_game3;
				mb2_game3-=30;
				if((mb2_game3+6)<0)
				{
					b1_game3=px_game3+52;
					b2_game3=py_game3+7;
					shoot_game3=0;

				}
			}
			//draw_bullet_game3();
		}
		checkhit_game3();
		score_card_game3();
		timer_game3();
		delay(100);
		nosound();
		if(totalscore_game3>=20)
		{
			finish_game3=1;
			win_game3=1;
		}
		else
		{
			win_game3=0;
		}
		cleardevice();

	}
	if(win_game3)
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
	return win_game3;
}

void timer_game3()
{
	if(ctr_game3%10==0)
	{
		gametime_game3--;
	}

	itoa(gametime_game3,chartime_game3,10);
	settextstyle(1,0,1);
	outtextxy(40,getmaxy()-80,"Timer");
	outtextxy(50,getmaxy()-60,chartime_game3);
	if(gametime_game3<=0)
	{
		finish_game3=1;
		win_game3=0;
	}
}
void checkhit_game3()
{
	/*
	if(
	    (px_game3+35)<(rx1-5) && (px_game3+5)>(rx1+15) &&
	    (py_game3-10)<(ry1-5) && (py_game3+50)>(ry1+15)
	    ||
	    (px_game3+35)<(rx2-5) && (px_game3+5)>(rx2+15) &&
	    (py_game3-10)<(ry2-5) && (py_game3+50)>(ry2+15)
	    ||
	    (px_game3+35)<(rx3-5) && (px_game3+5)>(rx3+15) &&
	    (py_game3-10)<(ry3-5) && (py_game3+50)>(ry3+15)
	    ||
	    (px_game3+35)<(rx4-5) && (px_game3+5)>(rx4+15) &&
	    (py_game3-10)<(ry4-5) && (py_game3+50)>(ry4+15)
	    ||
	    (px_game3+35)<(rx5-5) && (px_game3+5)>(rx5+15) &&
	    (py_game3-10)<(ry5-5) && (py_game3+50)>(ry5+15)
	  )
	{
		//hit_game3=1;
		sound(1000);
	}
	 */
	if(
	    (mb1_game3)>(rx_game3-6) && (mb1_game3)<(rx_game3+25) &&
	    (mb2_game3)>(ry_game3) && (mb2_game3)<(ry_game3+30)
	  )
	{
		hit_game3=1;
		//s=0;
		//rb1=0;

	}
	/*
	if(
	    (mb1_game3)>(rx2-5) && (mb1_game3)<(rx2+25) &&
	    (mb2_game3)>(ry2-5) && (mb2_game3)<(ry2+25)
	  )
	{
		hit_game3=1;
		s=1;
		rb2=0;
	}
	if(
	    (mb1_game3)>(rx3-5) && (mb1_game3)<(rx3+25) &&
	    (mb2_game3)>(ry3-5) && (mb2_game3)<(ry3+25)
	  )
	{
		hit_game3=1;
		s=2;
		rb3=0;
	}
	if(
	    (mb1_game3)>(rx4-5) && (mb1_game3)<(rx4+25) &&
	    (mb2_game3)>(ry4-5) && (mb2_game3)<(ry4+25)
	  )
	{
		hit_game3=1;
		s=3;
		rb4=0;
	}
	if(
	    (mb1_game3)>(rx5-5) && (mb1_game3)<(rx5+25) &&
	    (mb2_game3)>(ry5-5) && (mb2_game3)<(ry5+25)
	   )
	{
		hit_game3=1;
		s=4;
		rb5=0;
	}
	*/

	if(hit_game3)
	{
		reset_bullet_game3();
		sound(1500);
		totalscore_game3+=score_game3;
		//hit_game3=0;
	}
}


void reset_bullet_game3()
{

	if(gun1_game3)
	{
		b1_game3=px_game3+60;
		b2_game3=py_game3+18;
		shoot_game3=0;
	}
	else if(gun3_game3)
	{
		b1_game3=px_game3+18;
		b2_game3=py_game3+18;
		shoot_game3=0;
	}
	else if(gun4_game3)
	{
		b1_game3=px_game3+52;
		b2_game3=py_game3+7;
		shoot_game3=0;
	}
	//key_right=0;
	//shoot_game3=0;
	//b1_game3=px_game3+60;b2_game3=py_game3+18;

}
void draw_bullet_game3()
{
	setfillstyle(SOLID_FILL,3);
	setcolor(3);
	if(gun1_game3)
	{
		if (shoot_game3)
		{
			bar(mb1_game3,b2_game3,mb1_game3+6,b2_game3+3);
		}
		else
		{
			b1_game3=px_game3+60;
			b2_game3=py_game3+18;
			bar(b1_game3,b2_game3,b1_game3+6,b2_game3+3);
			mb1_game3=b1_game3;
		}
	}
	else if(gun2_game3)
	{

	}
	else if(gun3_game3)
	{
		if (shoot_game3)
		{
			bar(mb1_game3,b2_game3,mb1_game3+6,b2_game3+3);
		}
		else
		{
			b1_game3=px_game3+18;
			b2_game3=py_game3+18;
			bar(b1_game3,b2_game3,b1_game3+6,b2_game3+3);
			mb1_game3=b1_game3;
		}
	}
	else if(gun4_game3)
	{
		if (shoot_game3)
		{
			bar(b1_game3,mb2_game3,b1_game3+3,mb2_game3+6);
		}
		else
		{
			b1_game3=px_game3+52;
			b2_game3=py_game3+7;
			bar(b1_game3,b2_game3,b1_game3+3,b2_game3+6);
			mb2_game3=b2_game3;
		}
	}


	//if((mb1_game3+6)>getmaxx())//||(b2_game3+6)>getmaxy())


}

void score_card_game3()
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL,CYAN);
	bar(10,getmaxy()-80,getmaxx()-10,getmaxy()-10);
	setcolor(RED);
	settextstyle(1,0,1);
	itoa(totalscore_game3,charscore_game3,10);
	outtextxy(470,getmaxy()-80,"Score Card");
	outtextxy(480,getmaxy()-60,charscore_game3);
	settextstyle(0,0,3);
	outtextxy(220,getmaxy()-70,"LEVEL 3");
	/*if(totalscore_game3>=20)
	{
		finish_game3=1;
		win_game3=1;
	}*/
}

void draw_robot_game3()
{
	if(hit_game3)
	{
		rx_game3=random(getmaxx())+20;
		ry_game3=random(getmaxy())+20;
		while(ry_game3>(getmaxy()-120))
			ry_game3=random(getmaxy())+20;

		hit_game3=0;
	}
	else
	{
//	setcolor(14);

	//rectangle(px_game3-100,py_game3-80,px_game3+100,py_game3+120);
	//get_color_game3=random(4);
		if( 	(rx_game3+10)>(px_game3-100) && (rx_game3+10)<(px_game3+100) &&
			(rx_game3+10)>(py_game3-80) && (rx_game3+10)<(py_game3+120)
		  )
		{
		get_color_game3=random(4);
		setfillstyle(SOLID_FILL,color_game3[get_color_game3]);
		setcolor(color_game3[get_color_game3]);
		set_eye_game3=1;

		//outtextxy(100,100,"score_game3 Card");

		}
		else
		{
			get_color_game3=8;
			setfillstyle(SOLID_FILL,get_color_game3);
			setcolor(get_color_game3);
			set_eye_game3=0;
		}
		//randomize();


	 }
		bar(rx_game3,ry_game3,rx_game3+20,ry_game3+10);//bar(400,100,420,110);
		bar(rx_game3+7,ry_game3+10,rx_game3+14,ry_game3+14);//bar(407,110,414,114);
		bar(rx_game3-5,ry_game3+14,rx_game3+25,ry_game3+28);//bar(395,114,425,128);
		if(set_eye_game3)
			setfillstyle(SOLID_FILL,6);
		bar(rx_game3+5,ry_game3+2,rx_game3+7,ry_game3+4);//bar(405,102,407,104);//eye1 r1
		bar(rx_game3+13,ry_game3+2,rx_game3+15,ry_game3+4);//bar(413,102,415,104);//eye2   r1

		setfillstyle(SOLID_FILL,WHITE);
		//bar(370,128,450,129);

		setfillstyle(SOLID_FILL,WHITE);
		//bar(320,348,400,349); //platform
	if(ctr_game3%60==0||ctr_game3==1)
	{
		rx_game3=random(getmaxx())+20;
		ry_game3=random(getmaxy())+20;
		while(ry_game3>(getmaxy()-120))
			ry_game3=random(getmaxy())+20;
	}
}
void draw_range_game3()
{
	setfillstyle(SOLID_FILL,15);
	setcolor(8);
	fillellipse(px_game3+30,py_game3+20,100,100);
}
/*
void draw_player_game3()
{
	if(move_down_game3==1)
	{
		py_game3+=25;
		move_down_game3=0;
	}
	else if(move_up_game3==1)
	{
		py_game3-=25;
		move_up_game3=0;
	}
	else if(move_right_game3)
	{
		px_game3+=25;
		move_right_game3=0;
	}
	else if(move_left_game3)
	{
		px_game3-=25;
		move_left_game3=0;
	}
	if(px_game3<0 || py_game3<0 || px_game3>getmaxx() || py_game3>getmaxy()-200)
	{
		move_left_game3=move_right_game3=move_up_game3=move_down_game3=0;
		if(px_game3<0)
			px_game3+=25;
		else if(py_game3<0)
			py_game3+=25;
		else if(px_game3>getmaxx())
			px_game3-=25;
		else if(py_game3>getmaxy()-200)
			py_game3-=25;
	}
	//setfillstyle(SOLID_FILL,4);
	setcolor(4);
	//head & throat
	circle(px_game3,py_game3,10);
	line(px_game3,py_game3+10,px_game3,py_game3+15);
	//body
	rectangle(px_game3-10,py_game3+15,px_game3+10,py_game3+28);
	rectangle(px_game3-10,py_game3+28,px_game3+10,py_game3+35);
	//legs
	line(px_game3-5,py_game3+35,px_game3-5,py_game3+50);
	line(px_game3+5,py_game3+35,px_game3+5,py_game3+50);
	line(px_game3-5,py_game3+50,px_game3,py_game3+50);
	line(px_game3+5,py_game3+50,px_game3+10,py_game3+50);
	//gun
	line(px_game3+3,py_game3+18,px_game3+20,py_game3+18);
	line(px_game3+3,py_game3+18,px_game3+3,py_game3+24);
	line(px_game3+3,py_game3+24,px_game3+6,py_game3+24);
	line(px_game3+6,py_game3+24,px_game3+6,py_game3+21);
	line(px_game3+6,py_game3+21,px_game3+20,py_game3+21);
	line(px_game3+20,py_game3+21,px_game3+20,py_game3+18);
}
*/
void draw_player_game3()
{
	if(left_key_game3)
	{
		if(px_game3>0)
			px_game3-=10;

		left_key_game3=0;
		gun3_game3=1;
		gun1_game3=gun2_game3=gun4_game3=0;
		b1_game3=px_game3+18;
		b2_game3=py_game3+18;
		shoot_game3=0;
	}
	else if(right_key_game3)
	{
		if((px_game3+50)<getmaxx())
			px_game3+=10;
		right_key_game3=0;
		gun1_game3=1;
		gun2_game3=gun3_game3=gun4_game3=0;
		b1_game3=px_game3+60;
		b2_game3=py_game3+18;
		shoot_game3=0;
	}
	else if(up_key_game3)
	{
		if((py_game3)>50)
			py_game3-=10;
		up_key_game3=0;
		gun4_game3=1;
		gun1_game3=gun2_game3=gun3_game3=0;
		b1_game3=px_game3+52;
		b2_game3=py_game3+7;
		//shoot_game3=0;

	}
	else if(down_key_game3)
	{
		if((py_game3+30)<getmaxy())
			py_game3+=10;
		down_key_game3=0;
		gun2_game3=1;
		gun2_game3=gun3_game3=gun4_game3=0;

	}
	if(px_game3<0 || py_game3<0 || px_game3>getmaxx() || py_game3>getmaxy()-200)
	{
		left_key_game3=right_key_game3=up_key_game3=down_key_game3=0;
		if(px_game3<0)
			px_game3+=25;
		else if(py_game3<0)
			py_game3+=25;
		else if(px_game3>getmaxx())
			px_game3-=25;
		else if(py_game3>getmaxy()-120)
			py_game3-=25;
	}
	//head & throat
	circle(px_game3+40,py_game3,10);
	line(px_game3+40,py_game3+10,px_game3+40,py_game3+15);
	//body
	rectangle(px_game3+30,py_game3+15,px_game3+50,py_game3+28);
	rectangle(px_game3+30,py_game3+28,px_game3+50,py_game3+35);
	//legs
	line(px_game3+35,py_game3+35,px_game3+35,py_game3+50);
	line(px_game3+45,py_game3+35,px_game3+45,py_game3+50);
	line(px_game3+35,py_game3+50,px_game3+40,py_game3+50);
	line(px_game3+45,py_game3+50,px_game3+50,py_game3+50);
	//gun
	if(gun1_game3)
	{
		line(px_game3+43,py_game3+18,px_game3+60,py_game3+18);
		line(px_game3+43,py_game3+18,px_game3+43,py_game3+24);
		line(px_game3+43,py_game3+24,px_game3+46,py_game3+24);
		line(px_game3+46,py_game3+24,px_game3+46,py_game3+21);
		line(px_game3+46,py_game3+21,px_game3+60,py_game3+21);
		line(px_game3+60,py_game3+21,px_game3+60,py_game3+18);
	}
	else if(gun2_game3)
	{
		line(px_game3+43,py_game3+18,px_game3+60,py_game3+18);
		line(px_game3+43,py_game3+18,px_game3+43,py_game3+24);
		line(px_game3+43,py_game3+24,px_game3+46,py_game3+24);
		line(px_game3+46,py_game3+24,px_game3+46,py_game3+21);
		line(px_game3+46,py_game3+21,px_game3+60,py_game3+21);
		line(px_game3+60,py_game3+21,px_game3+60,py_game3+18);
	}
	else if(gun3_game3)
	{
		line(px_game3+36,py_game3+18,px_game3+19,py_game3+18);
		line(px_game3+36,py_game3+18,px_game3+36,py_game3+24);
		line(px_game3+36,py_game3+24,px_game3+33,py_game3+24);
		line(px_game3+33,py_game3+24,px_game3+33,py_game3+21);
		line(px_game3+33,py_game3+21,px_game3+19,py_game3+21);
		line(px_game3+19,py_game3+21,px_game3+19,py_game3+18);
	}
	else if(gun4_game3)
	{
		line(px_game3+48,py_game3+21,px_game3+52,py_game3+21);
		line(px_game3+52,py_game3+21,px_game3+52,py_game3+7);
		line(px_game3+52,py_game3+7,px_game3+55,py_game3+7);
		line(px_game3+55,py_game3+7,px_game3+55,py_game3+25);
		line(px_game3+55,py_game3+25,px_game3+48,py_game3+25);
		line(px_game3+48,py_game3+25,px_game3+48,py_game3+22);
	}
}