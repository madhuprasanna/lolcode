#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<alloc.h>
#include<dos.h>
int score=0;
void main()

{

       int gd=DETECT,gm;
	   initgraph(&gd,&gm,"F:\\TC\\BGI\\");
       setcolor(RED);
       printf("\n\n\n\n\n\n\n\t\t\t\t BALL GAME");
       setcolor(WHITE);
       printf("\n\n\n\t\t\tPress any key to start game");
       printf("\n\n\n\n\t\t Score : %d ",score);
       setcolor(BLUE);
       setcolor(RED);
       rectangle(250,100,350,140);
       getch();
       ball();
       getch();
       closegraph();
       restorecrtmode();

      }

   ball()

      {

	  int n=0,c=0,b=1;
	  int a[100][100];
	  int area1,area2,area3,x,y,i,j;
	  int barx,bary,barincx=1,brickcount=0,visible[100];
	  int ballx,bally,ballincx=1,ballincy=1;
	  char ch;
	  char *ball,*bar,*brick;
	  setcolor(YELLOW);                   /*capture ball*/
	  setfillstyle(SOLID_FILL,YELLOW);
	  fillellipse(100,100,5,5);
	  area1=imagesize(95,95,105,105);
	  ball=malloc(area1);
	  getimage(95,95,105,105,ball);
	  setcolor(YELLOW);                 /*capture bar*/
	  setfillstyle(SOLID_FILL,YELLOW);
	  rectangle(120,120,180,130);
	  floodfill(121,121,YELLOW);
	  area2=imagesize(120,120,180,130);
	  bar=malloc(area2);
	  getimage(120,120,180,130,bar);
	  setcolor(RED);                 /*capture brick*/
	  setfillstyle(SOLID_FILL,RED);
	  rectangle(30,30,60,45);
	  floodfill(31,31,RED);
	  area3=imagesize(30,30,60,45);
	  brick=malloc(area3);
	  getimage(30,30,60,45,brick);
	  clrscr();
	  cleardevice();
       /*initialisations*/
	  x=getmaxx();
	  y=getmaxy();
	  barx=x/2;
	  bary=y-30;
	  ballx=20;
	  bally=150;
	  setcolor(WHITE);
	  rectangle(0,0,x-3,y);
	  putimage(barx,bary,bar,XOR_PUT);
	  putimage(ballx,bally,ball,XOR_PUT);

       /*brick display*/
	  for(i=60;i<=90;i+=15)

	   {

		for(j=0;j<=(x-30);j+=30)

		{

			 putimage(j,i,brick,XOR_PUT);
			 visible[brickcount]=1;
			 brickcount++;
			 a[i][j]=0;

		}


	   }

	   /*movements*/

	 while(1)

	   {

/*ball movement*/
	      delay(3);
	      putimage(ballx,bally,ball,XOR_PUT);
	      if((bally+10==bary)&&(ballx+10>barx)&&(ballx<barx+20))

		{

			ballincy=-2;
			ballincx=-1;

		}

	      if((bally+10==bary)&&(ballx+10>barx+40)&&(ballx<barx+60))

		{

		       ballincy=-2;
		       ballincx=1;

		}

	       if((bally+10==bary)&&(ballx+10>=barx+20)&&(ballx<=barx+40))

		{

		       ballincy=-1;
		       if (ballincx>0) ballincx=1;
		       if (ballincx<0) ballincx=-1;

		}

	      if (ballx>=x-3) ballincx=-1;
	      if (ballx<=0) ballincx=1;
	      if (bally<=0) ballincy=1;
/*	      if (bally>=y-20) ballincy=-1;*/

	      /*brick hit*/

	      for (i=60;i<=90;i+=15)

		{

		 for(j=0;j<=(x-30);j+=30)


		     {
		       if (n==brickcount)

			  {

				      clrscr();
				      cleardevice();
				      setcolor(RED);
				      printf("\n\n\n\n\n\n\n\t\t\t\t STAGE COMPLETED");
				      setcolor(WHITE);
				      printf("\n\n\n\n\n\n\n\n\n\t\t\t\t Score : %d ",score);
				      printf("\n\n\n\t\t\t    Press any key to quit");
				      setcolor(RED);
				      rectangle(250,100,550,140);
				      b=0;
				      getch();
				      exit();

			  }

			  if ((bally>i) && (bally<i+15) && ((ballx+10)>=j) && (ballx<=(j+30)) && (a[i][j]==0))

			  {

					putimage(j,i,brick,XOR_PUT);
					ballincx=-ballincx;
					if (ballincy<0) ballincy=-1;
					if (ballincy>0) ballincy=1;
					a[i][j]=1;
					score+=100;
					n++;
					sound(1500);
					delay(15);
					nosound();
					break;

			  }

			   if (((bally+10)==i) && ((ballx+10)>=j) && (ballx<=(j+30))&&(a[i][j]==0))

			  {

				       putimage(j,i,brick,XOR_PUT);
				       ballincy=-1;
				       if (ballincx<0) ballincx=-1;
				       if (ballincx>0) ballincx=1;
				       a[i][j]=1;
				       score+=100;
				       n++;
				       sound(1500);
				       delay(15);
				       nosound();
			  }

			   if ((bally==(i+15)) && ((ballx+10)>=j) && (ballx<=(j+30))&&(a[i][j]==0))

			  {

				       putimage(j,i,brick,XOR_PUT);
				       ballincy=1;
				       if (ballincx<0) ballincx=-1;
				       if (ballincx>0) ballincx=1;
				       a[i][j]=1;
				       score+=100;
				       n++;
				       sound(1500);
				       delay(15);
				       nosound();

			  }


		     }


		}



	   if((b!=0)&&(c==2))

		{

		    clrscr();
		    cleardevice();
		    setcolor(RED);
		    printf("\n\n\n\n\n\n\n\t\t\t\t GAME OVER");
		    setcolor(WHITE);
		    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t Score : %d ",score);
		    printf("\n\n\n\t\t\t    Press any key to quit");
		    setcolor(RED);
		    rectangle(250,100,350,140);
		    getch();
		    exit();

		}


	   if(bally+10==y-10)

		{


		ballx=20;
		bally=110;
		getch();
		getch();
		c++;

		}

	      ballx+=ballincx;
	      bally+=ballincy;
	      /*bar movement*/
	      if (kbhit())

		{

		      ch=getkey();
		      putimage(barx,bary,bar,XOR_PUT);
		      if (ch==77) barincx=8;
		      if (ch==75) barincx=-8;
		      if (barx<8) barincx=1;
		      if (barx+60>x-8) barincx=-1;
		      barx+=barincx;
		      putimage(barx,bary,bar,XOR_PUT);

		}

	       delay(3);
	       putimage(ballx,bally,ball,XOR_PUT);



	   }


}


getkey()

{

  union REGS i,o;
  i.h.ah=0;
  int86(22,&i,&o);
  return(o.h.ah);

}
