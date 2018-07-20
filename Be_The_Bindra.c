#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include"level1.c"
#include"level2.c"
#include"level3.c"
#include"level4.c"
#include"level5.c"

void welcome_screen();
void team_mentor();
void level1_game();
void level2_game();
void level3_game();
void level4_game();
void level5_game();

float octave[7]={130.81,146.83,164.81,174.61,196,220,246.94};
int welcome=1;
int start=1;
int winner=0;
int level_1=1,level_2=0,level_3=0,level_4=0,level_5=0;
int nextlevel=1;
int result=0;
int finish_game=0;

void main()
{
	int gd=DETECT,gm,maxx,maxy;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

	while(welcome)
	{
		welcome_screen();
		//team_mentor();
		if(kbhit())
		{
			welcome=0;
		}
		sound(octave[random(7)]*4);
		delay(300);
		//clearviewport();
	}
	nosound();

	clearviewport();
	//while(start)
	{
		team_mentor();
		if(getche())
		{
			start=0;
		}
		delay(1000);
		getche();
	}
	//while(level_1)
	//do
	//nextlevel=4;
	//while(nextlevel>0)
	{
		clearviewport();
		level1_game();
		if(nextlevel==2)
		{
			clearviewport();
			level2_game();

		}
		//nextlevel=3;
		if(nextlevel==3)
		{
			clearviewport();
			level3_game();
		}
		//nextlevel=4;
		if(nextlevel==4)
		{
			clearviewport();
			level4_game();
		}

		if(nextlevel==5)
		{
			clearviewport();
			level5_game();
			nextlevel=6;
		}
		if(nextlevel==0)
		{
		//	outtextxy(100,100,"Sorry, You lost! Try Again" );
		//	finish_game=1;
		//	nextlevel=0;
		}
	}//while(nextlevel);
	getch();
}
void level5_game()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 5");
	settextstyle(1,0,3);
	setcolor(CYAN);
	outtextxy(230,70,"INSTRUCTIONS");
	setcolor(WHITE);
	outtextxy(40,100,"-This level contains robots coming from tunnels.");
	outtextxy(40,130,"-The player has to shoot the robots.");
	outtextxy(40,160,"-The player can move up with 'w','s','a','d' key.");
	outtextxy(40,190,"-Killing white robot provide 50 points .");
	outtextxy(40,220,"-Killing cyan robot will provide 40 points.");

	outtextxy(40,250,"-Killing red robot will provide 30 points.");
	outtextxy(40,280,"-Killing blue robot will provide 20 points.");
	outtextxy(40,310,"-Killing yellow robot will provide 10 points.");
	outtextxy(40,340,"-If robot touches player,he will be died.");

	outtextxy(40,370,"-You need to score 50 points to win");
	outtextxy(40,400," this level within 60 seconds.");

	getch();

	//do
	{
	result=level5();
	if(result)
	{
		nextlevel=6;
		clearviewport();
		//outtextxy(100,100,"Game Finished! You Won!");


	}
	else
	{
		nextlevel=0;
//		nextlevel=0;
	}
	}//while(result==0);


}

void level4_game()
{
	setcolor(WHITE);
	setbkcolor(BLACK);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 4");
	settextstyle(1,0,3);
	setcolor(CYAN);
	outtextxy(230,70,"INSTRUCTIONS");
	setcolor(WHITE);
	outtextxy(40,100,"-This level contains 4 doors and the color changes rapidly.");
	outtextxy(40,130,"-The player has to shoot any door.");
	outtextxy(40,160,"-The player can move left with 'a' key.");
	outtextxy(40,190,"-The player can move right with 'd' key.");
	outtextxy(40,220,"-The player can shoot with the 'w' key.");

	outtextxy(40,250,"-Green door takes you to the next level");
	outtextxy(40,280,"-Yellow and Blue door takes you to the level game");
	//outtextxy(40,310,"-Blue door takes you to the level game");
	//outtextxy(40,340,"-");

	//outtextxy(40,370,"-You need to score 70 points to win");
	//outtextxy(40,400," this level within 120 seconds.");

	getch();
	//do

	result=level4();
	if(result)
	{
		nextlevel=5;


	}

	else
	{
		nextlevel=0;
	}


}
void level3_game()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 3");
	settextstyle(1,0,3);
	setcolor(CYAN);
	outtextxy(230,70,"INSTRUCTIONS");
	setcolor(WHITE);
	outtextxy(40,100,"-This level contains robot that is moving randomly.");
	outtextxy(40,130,"-The player has to shoot the robot with in range.");
	outtextxy(40,160,"-The player can move with 'w','s','a','d' keys");
	outtextxy(40,190,"-The player can shoot with the right arrow key.");

	outtextxy(40,220,"-Each shoot gives 100 points.");

	outtextxy(40,250,"-You need to score 300 points to win");
	outtextxy(40,280," this level within 60 seconds.");

	getch();
	//do
	{
	result=level3();
	if(result)
	{
		nextlevel=4;
	}
	else
	{
		nextlevel=0;
//		nextlevel=0;
	}
	}//while(result==0);
}

void level2_game()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 2");
	settextstyle(1,0,3);
	setcolor(CYAN);
	outtextxy(230,70,"INSTRUCTIONS");
	setcolor(WHITE);
	outtextxy(40,100,"-This level contains robots that are fixed.");
	outtextxy(40,130,"-The player has to shoot the robots.");
	outtextxy(40,160,"-The player can move up with 'w' key.");
	outtextxy(40,190,"-The player can move down with 's' key.");
	outtextxy(40,220,"-The player can shoot with the right arrow key.");

	outtextxy(40,250,"-Green robot give 5 points.");
	outtextxy(40,280,"-Red robot gives 10 points.");
	outtextxy(40,310,"-Yellow robot gives 15 points.");
	outtextxy(40,340,"-Blue robot gives -10 points.");

	outtextxy(40,370,"-You need to score 120  points to win");
	outtextxy(40,400," this level within 100 seconds.");

	getch();
	//do
	{
	result=level2();
	if(result)
	{
		nextlevel=3;

	}
	else
	{
		nextlevel=0;
	}
	}//while(result==0);

}
void level1_game()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(250,20,"LEVEL 1");
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
	//do
	{
	result=level1();
	if(result)
	{
		nextlevel=2;

	}
	else
	{
		nextlevel=0;
	}
	}//while(result==0);
}
void team_mentor()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);

	settextstyle(3,0,1);
	setcolor(BLUE);
	outtextxy(100,110,"Mentor:");
	outtextxy(100,200,"Team Members:");
	delay(500);
	setcolor(WHITE);
	outtextxy(160,130,"Prof : Anand Gupta");
	outtextxy(160,220,"Nikhil Kumar");
	outtextxy(160,240,"Nikunj Gupta");
	outtextxy(160,260,"Bhavya Sahay");
	outtextxy(160,280,"Deepanshu Aggarwal");

	setcolor(GREEN);
	settextstyle(0,0,1);
	outtextxy(30,430,"Press any key to continue...");

 //	outtext

}
void welcome_screen()
{
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(3,3,getmaxx()-3,getmaxy()-3);

	settextstyle(7,0,6);
	setcolor(RED);
	outtextxy(120,100,"Be The Bindra");

	settextstyle(1,0,2);
	setcolor(CYAN);
	outtextxy(260,250,"WELCOME");

	setcolor(GREEN);
	settextstyle(0,0,1);
	outtextxy(30,430,"Press any key to continue...");


}