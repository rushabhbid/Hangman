#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<time.h>
#include<dos.h>

int c1=0,c2=0,c3=0,c4=0,k=0,l=0;

void hang()
{
 if(c2==2)
 {
	setcolor(0);
 }
 else
 {
	setcolor(CYAN);
 }
	switch(c1)
	{
	 case 1:
		line(190,100,190,130);
		break;
	 case 2:
		//HEAD
		circle(190,150,20);
		break;
	 case 3:
		delay(500);
		line(175,175,205,175);
		line(175,235,205,235);
		line(170,175+5,170,225+5);
		line(210,175+5,210,225+5);
		line(190,170,190,175);
		arc(175,180,90,180,5);
		arc(175,230,180,-90,5);
		arc(205,230,-90,0,5);
		arc(205,180,0,90,5);
		break;
	 case 4:
		//left hand
		line(170,200,140,160);
		line(140,160,140,155);
		break;
	 case 5:
		//Right hand
		line(210,200,240,160);
		line(240,160,240,155);
		break;
	 case 6:
		//left leg
		line(182,235,170,275);
		line(187,235,175,275);
		line(170,275,175,275);
		line(170,275,170,280);
		line(175,275,175,280);
		line(170,280,175,280);
		delay(500);
		if(c2!=2){
		settextstyle(0,0,0);
		outtextxy(220,120,"H");
		delay(500);
		outtextxy(230,116,"E");
		delay(500);
		outtextxy(240,112,"L");
		delay(500);
		outtextxy(250,108,"P");
		delay(500);
		outtextxy(270,102,"M");
		delay(500);
		outtextxy(280,98,"E");
		delay(500);
		outtextxy(290,94,".");
		delay(500);
		outtextxy(300,90,".");
		delay(500);
		outtextxy(310,86,".");
		delay(500);
		}
		else
		{
		settextstyle(0,0,1);
		outtextxy(220,120,"H");
		outtextxy(230,116,"E");
		outtextxy(240,112,"L");
		outtextxy(250,108,"P");
		outtextxy(270,102,"M");
		outtextxy(280,98,"E");
		outtextxy(290,94,".");
		outtextxy(300,90,".");
		outtextxy(310,86,".");
		}
		break;
	 case 7:
		//Right leg
		line(190,235,203,275);
		line(195,235,208,275);
		line(203,275,208,275);
		line(203,275,203,280);
		line(208,275,208,280);
		line(203,280,208,280);
		break;
	}
}


int main() {

	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	do {
	c1=0,c2=0,c3=0,c4=0,k=0,l=0;
//Start screen
	clrscr();
	closegraph();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(BLACK);
	settextstyle(0,0,3);
	outtextxy(200,50,"HANGMAN 2.0");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	settextstyle(0,0,2);
	cout<<"RULES:"<<endl;
	cout<<"1) A movie name is to be guessed."<<endl;
	cout<<"2) Entire name is given as blanks. You have to guess letter by letter."<<endl;
	cout<<"3) For each correct guess, you unlock that letter in the movie name."<<endl;
	cout<<"4) For each wrong guess, a body part is drawn."<<endl;
	cout<<"5) Once the entire body is drawn, you lose. You can afford 6 wrong guesses."<<endl;
	cout<<"6) Everytime you guess two letters consecutively, you get an extra life."<<endl;
	   cout<<"7) Enter space bar while playing to exit"<<endl<<endl;
	cout<<"\tPress Any Key to continue.";
	int r=0;
	while(!kbhit()) {r++;}
	getch();
	cleardevice();
	pa:
	    c4=0;
	    char movies[42][21] = {

	"tubelight",

	"daddy",

	"raees",

	"kaabil",

	"jagga jasoos",

	"raabta",

	"entertainment",

	"half girlfriend",

	"ok jaanu",

	"sultan",

	"dangal",

	"simran",

	"mom",

	"baahubali",

	"hindi medium",

	"inside out",

	"terminator",

	"fast and furious",

	"naam shabana",

	"harry potter",

	"tangled",

	"judwa 2",

	"hera pheri",

	"golmaal",

	"baadshaho",

	"toilet",

	"shubh mangal savdhan",

	"lucknow central",

	"mubarakan",

	"noor",

	"rustom",

	"pink",

	"udta punjab",

	"fan",

	"annabelle",

	"transformer",

	"despicable me",

	"it",

	"spider man",

	"batman",

	"superman",

	"the boss baby"
   } ;

//random number generation
	   time_t rand = time(NULL);
	   r=rand%42;

	      int length=0;
	      int x=30,y=400;
	   for(int i=0;movies[r][i]!='\0';i++) {
	      if(movies[r][i]==' ')
		 outtextxy(x,y-10,"/");
	      else
		line(x,y,x+20,y);
	      x=x+30;
	      length++;
		delay(50);
	   }

	setcolor(CYAN);
	line(100,100,100,300);


	line(90,100,190,100);
	line(150,100,100,150);

	line(100,300,85,320);
	line(100,300,100,330);
	line(100,300,125,320);

	setfillstyle(SOLID_FILL,RED);
	line(85,320,100,330);
	line(125,320,100,330);
	line(85,320,125,320);
	floodfill(101,325,CYAN);
	floodfill(99,325,CYAN);


//working code
	   char ch,temp;
	   char o[1];
	   int x1=250,y1=30;
	   outtextxy(30,30,"Wrong Guesses: ");

//loop for keyboardhit
	   while(c1<7 && ch!=' ') {
		setcolor(WHITE);
		ch=getch();
		temp=ch;
		c3=0;

		for(int j=0;j<length;j++) {
			sprintf(o,"%c",ch-32);
			if(ch==movies[r][j] && ch!=' ') {
				setcolor(BLACK);
				line(30+j*30,y,50+30*j,y);
				setcolor(WHITE);
				settextstyle(0,0,2);
				outtextxy(30+j*30,y-15,o);
				c3++;
				c4++;
				movies[r][j]='|';
			}
			if(movies[r][j]==' ') {
				movies[r][j]='|';
				c4++;
			}
			ch=temp;
		}
		if(c3==0){
		  c2=0;
		  c1++;
		  hang();
		  x1=x1+20;
		  settextstyle(0,0,2);
		  outtextxy(x1,y1,o);
		}
		else
		  c2++;
		if(c2==2 && c1!=0) {
		   hang();
		   c1--;
		   c2--;
		}
		if(c4==length){
			break;
		}
	   }
	if(c1==7){
		settextstyle(0,0,3);
		for(k=0,l=getmaxy()/2;k<getmaxx()/2-200;k=k+2){
			setcolor(WHITE);
			outtextxy(k,l,"You Killed Him!!");
			delay(1);
			setcolor(BLACK);
			outtextxy(k,l,"You Killed Him!!");
		}
		setcolor(WHITE);
		outtextxy(k,l,"You Killed Him!!");
		settextstyle(0,0,2);
	}


	if(c4==length){
		settextstyle(0,0,3);
		for(k=0,l=getmaxy()/2;k<getmaxx()/2-200;k=k+2){
			setcolor(WHITE);
			outtextxy(k,l,"You Nailed It!!");
			delay(1);
			setcolor(BLACK);
			outtextxy(k,l,"You Nailed It!!");
		}
		setcolor(WHITE);
		outtextxy(k,l,"You Nailed It!!");
		settextstyle(0,0,2);
	}
		outtextxy(k-30,l+30,"Press any key to play again");
		outtextxy(k-30,l+60,"Press Space again to exit..");

}
	while(getch() != ' ');

	closegraph();
	return 0;

}