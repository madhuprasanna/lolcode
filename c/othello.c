#include<stdio.h>
#include<graphics.h>

/***************Global Variables****************/
int whichplr,key,r=5,c=5,played[9][9]={0},pr=5,pc=5,ToMenu=0;
void *box,*button[2],*cur,*blnk;
char ch,pln[2][25];int Gain=0,count[2]={0};

/***************Global Functions****************/
int check(void),error(),Opp(int);
void play(void),StoreImages(void),Count(void);
void ConstructBoard(void),Dots(void),Cur(void);
void Setup(void);

/**************Color Setup*********************/
int clr_OTHELLO=LIGHTGREEN,clr_c1=RED,clr_c2=GREEN;
int clr_BRDFCE=LIGHTBLUE,clr_BRDU=LIGHTGRAY,clr_BRDD=DARKGRAY;
int clr_TEXT=MAGENTA,clr_BGGND;

main()
{
int gd=DETECT,gm,j,flag=1;
char *dummy;
void GetDetails(void);

GetDetails();
Setup();
//----USER SCREEN----
initgraph(&gd,&gm,"F:\\TC\\BGI");

StoreImages();
ConstructBoard();
Cur();

setbkcolor(clr_BGGND);
setcolor(clr_OTHELLO);
settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
outtextxy(200,5,"Othello");

setcolor(clr_TEXT);
played[4][4]=played[5][5]=1;
played[4][5]=played[5][4]=2;
Dots();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
outtextxy(460,100,"Players:");
outtextxy(460,300,"Score:");
putimage(465,325,button[0],COPY_PUT);
putimage(465,353,button[1],COPY_PUT);

key=0;
while(1)
{
key++;
whichplr=(key+1)%2+1;

setcolor(BLACK);
outtextxy(460,150,pln[0]);
outtextxy(460,175,pln[1]);
if(whichplr==1)
{
setcolor(clr_c1);
outtextxy(460,150,pln[0]);
}
else
{
setcolor(clr_c2);
outtextxy(460,175,pln[1]);
}

//-----SCORE BOARD----
putimage(465,125,button[whichplr-1],COPY_PUT);
Count();
putimage(500,325,blnk,COPY_PUT);
putimage(500,350,blnk,COPY_PUT);
outtextxy(500,325,(char*)itoa(count[0],dummy,10));
outtextxy(500,350,(char*)itoa(count[1],dummy,10));

/***********User's Input***********/
flag=1;
while(flag)
{
fflush(stdin);
ch=getch();
pr=r;pc=c;
switch(ch)
{
case 72:
  if(r>1)
   r--;
  break;
case 80:
  if(r<8)
  r++;
 break;
case 77:
  if(c<8)
   c++;
  break;
case 75:
  if(c>1)
   c--;
  break;
case 13:
  if(played[r][c]!=0)
   printf("\a");
  else
   flag=0;
  break;
case 'x':
  GetDetails();
  flag=ToMenu=1;
  break;
case 27:
 closegraph();
 clrscr();
 exit(0);
}
Cur();
}

played[r][c]=whichplr;
play();

if(Gain==0)
{
played[r][c]=0;
printf("\a");
key--;
continue;
}
else
 Gain=0;

Dots();
if(key>=60)
{
if(count[0]>count[1])
 printf("%s",pln[0]);
else
 printf("%s",pln[1]);
}

}
} /*****Main Ends*****/

/******************************Functions*****************************/
/******Play******/

void play(void)
{
void ConvertRow(void),ConvertCol(void),ConDia1(void),ConDia2(void);

ConvertRow();
ConvertCol();
ConDia1();
ConDia2();
}

/******ConvertRow*****/
void ConvertRow(void)
{
int left,right,i,ll=played[r][c];
left=c;
right=c;

while(played[r][left-1]==Opp(ll)&&left>1)
left--;
while(played[r][right+1]==Opp(ll)&&right<8)
right++;

if(--left<1)
left=1;
if(++right>8)
right=8;

if(played[r][left]==ll)
 for(i=c-1;i>left;i--)
 {
  played[r][i]=ll;
  Gain=1;
 }
if(played[r][right]==ll)
 for(i=c+1;i<right;i++)
 {
  played[r][i]=ll;
  Gain=1;
 }
}

/******ConvertCol*****/
void ConvertCol(void)
{
int top,bott,i,ll=played[r][c];
top=r;
bott=r;

while(played[top-1][c]==Opp(ll)&&top>1)
top--;
while(played[bott+1][c]==Opp(ll)&&bott<8)
bott++;

if(--top<1)
top=1;
if(++bott>8)
bott=8;

if(played[top][c]==ll)
 for(i=top+1;i<r;i++)
 {
  played[i][c]=ll;
  Gain=1;
 }
if(played[bott][c]==ll)
 for(i=bott-1;i>r;i--)
 {
  played[i][c]=ll;
  Gain=1;
 }
}

void ConDia1(void)
{
int topr=r,topc=c,bottr=r,bottc=c,i=0,j=0,ll=played[r][c];

while(played[topr-1][topc-1]==Opp(ll)&&(topr>1||topc>1))
{
topr--;
topc--;
}
while(played[bottr+1][bottc+1]==Opp(ll)&&(bottr<8||bottc<8))
{
bottr++;
bottc++;
}

if(--topr<1)
topr=1;
if(--topc<1)
topc=1;
if(++bottr>8)
bottr=8;
if(++bottc>8)
bottc=1;

if(played[topr][topc]==ll)
 for(i=topr+1,j=topc+1;i<r&&j<c;i++,j++)
 {
  played[i][j]=ll;
  Gain=1;
 }
if(played[bottr][bottc]==ll)
 for(i=bottr-1,j=bottc-1;i>r&&j>c;i--,j--)
 {
  played[i][j]=ll;
  Gain=1;
 }
}

/****ConDia2*/
void ConDia2(void)
{
int topr=r,topc=c,bottr=r,bottc=c,i=0,j=0,ll=played[r][c];

while(played[topr-1][topc+1]==Opp(ll)&&(topr>1||topc<8))
{
topr--;
topc++;
}
while(played[bottr+1][bottc-1]==Opp(ll)&&(bottr<8||bottc>1))
{
bottr++;
bottc--;
}

if(--topr<1)
topr=1;
if(++topc>8)
topc=1;
if(++bottr>8)
bottr=8;
if(--bottc<1)
bottc=1;

if(played[topr][topc]==ll)
 for(i=topr+1,j=topc-1;i<r&&j>c;i++,j--)
 {
  played[i][j]=ll;
  Gain=1;
 }
if(played[bottr][bottc]==ll)
 for(i=bottr-1,j=bottc+1;i>r&&j<c;i--,j++)
 {
  played[i][j]=ll;
  Gain=1;
 }
}

void Count(void)
{
int i,j;
count[0]=0;
count[1]=0;
for(i=1;i<=8;i++)
for(j=1;j<=8;j++)
{
if(played[i][j]==1)
 count[0]++;
if(played[i][j]==2)
 count[1]++;
}
}

/*******Opp*******/
int Opp(int ll)
{
int opp;

if(ll==1)
   opp=2;
if(ll==2)
   opp=1;
return(opp);
}

/*****StoreImages******/
void StoreImages(void)
{
int i,j;

/*******Chess Board******/
cleardevice();
rectangle(50,50,100,100);
rectangle(60,60,90,90);

setfillstyle(SOLID_FILL,clr_BRDFCE);
floodfill(65,65,WHITE);

line(50,50,60,60);
line(90,90,100,100);
line(50,100,60,90);
line(100,50,90,60);

setfillstyle(SOLID_FILL,clr_BRDU);
floodfill(59,60,WHITE);
floodfill(60,59,WHITE);
setfillstyle(SOLID_FILL,clr_BRDD);
floodfill(91,60,WHITE);
floodfill(75,95,WHITE);

if((box=(void*)malloc(imagesize(50,50,100,100)))==NULL)
 return;
getimage(50,50,100,100,box);
cleardevice();

/****Cursor***/
rectangle(50,50,100,100);
rectangle(60,60,90,90);

setfillstyle(SOLID_FILL,clr_BRDFCE);
floodfill(65,65,WHITE);

line(50,50,60,60);
line(90,90,100,100);
line(50,100,60,90);
line(100,50,90,60);

setfillstyle(SOLID_FILL,clr_BRDD);
floodfill(59,60,WHITE);
floodfill(60,59,WHITE);

setfillstyle(SOLID_FILL,clr_BRDU);
floodfill(91,60,WHITE);
floodfill(75,95,WHITE);

if((cur=(void*)malloc(imagesize(50,50,100,100)))==NULL)
 return;
getimage(50,50,100,100,cur);
cleardevice();

/******Blank*********/
if((blnk=(void*)malloc(imagesize(50,50,100,100)))==NULL)
 return;
getimage(50,50,100,100,blnk);

/****Coins*****/
setcolor(WHITE);
setfillstyle(SOLID_FILL,clr_BRDFCE);
floodfill(250,250,WHITE);

circle(250,250,6);
circle(250,250,10);
line(257,243,254,246);
line(246,254,243,257);

setfillstyle(SOLID_FILL,clr_c1);
floodfill(250,250,WHITE);
setfillstyle(SOLID_FILL,clr_BRDU);
floodfill(250,242,WHITE);
setfillstyle(SOLID_FILL,clr_BRDD);
floodfill(250,258,WHITE);

if((button[0]=(void*)malloc(imagesize(240,240,260,260)))==NULL)
 return;
getimage(240,240,260,260,button[0]);

circle(250,250,6);
circle(250,250,10);
line(257,243,254,246);
line(246,254,243,257);

setfillstyle(SOLID_FILL,clr_c2);
floodfill(250,250,WHITE);

if((button[1]=(void*)malloc(imagesize(240,240,260,260)))==NULL)
 return;
getimage(240,240,260,260,button[1]);

cleardevice();
}

/*****ConstructBoard*****/
void ConstructBoard(void)
{
int i,j;
cleardevice();

for(i=50;i<=400;i+=50)
for(j=50;j<=400;j+=50)
{
   putimage(i,j,box,COPY_PUT);
}
}

/******Dots*******/
void Dots(void)
{
int i,j;

for(i=1;i<=8;i++)
for(j=1;j<=8;j++)
{
if(played[i][j]==1)
 putimage(50*j+15,50*i+15,button[0],COPY_PUT);
if(played[i][j]==2)
 putimage(50*j+15,50*i+15,button[1],COPY_PUT);
}
}

/******Cur*****/

void Cur(void)
{
putimage(50*c,50*r,cur,COPY_PUT);
if(played[r][c]==1)
 putimage(50*c+15,50*r+15,button[0],COPY_PUT);
if(played[r][c]==2)
 putimage(50*c+15,50*r+15,button[1],COPY_PUT);

if(pr!=r||pc!=c)
{
putimage(50*pc,50*pr,box,COPY_PUT);
if(played[pr][pc]==1)
 putimage(50*pc+15,50*pr+15,button[0],COPY_PUT);
if(played[pr][pc]==2)
 putimage(50*pc+15,50*pr+15,button[1],COPY_PUT);
}
}

void Setup(void)
{
int ch;
void Custom(void);

clrscr();
printf("\t\t\t\tSetup Colour");
printf("\n\n\n\t1.Defaults");
printf("\n\t2.Customize...");
printf("\n\t3.Exit Setup");

printf("\n\n\tChoose..");
scanf("%d",&ch);

switch(ch)
{
case 1:
	clr_OTHELLO=LIGHTGREEN;clr_c1=RED;clr_c2=GREEN;
	clr_BRDFCE=BROWN;clr_BRDU=LIGHTRED;clr_BRDD=RED;
	clr_TEXT=MAGENTA;
	break;
case 2:
	Custom();
	break;
case 3:
	return;
}
}

void Custom(void)
{
int i,ch;
char *clrnames[]={"BLACK","BLUE","GREEN","CYAN","RED","MAGENTA","BROWN",
		 "LIGHTGRAY","DARKGRAY","LIGHTBLUE","LIGHTGREEN",
		  "LIGHTCYAN","LIGHTRED","LIGHTMAGENTA","YELLOW","WHITE"
	       };
clrscr();
printf("\t\t\t\tColors\n\n");

for(i=0;i<15;i++)
{
printf("\n\t%d.%s",i,clrnames[i]);
}

i=7;

gotoxy(40,i++);
printf("Othello:");
scanf("%d",&clr_OTHELLO);

gotoxy(40,i++);
printf("Player1:");
scanf("%d",&clr_c1);

gotoxy(40,i++);
printf("player2:");
scanf("%d",&clr_c2);

gotoxy(40,i++);
printf("Board:");
scanf("%d",&clr_BRDFCE);

gotoxy(40,i++);
printf("Light");
scanf("%d",&clr_BRDU);

gotoxy(40,i++);
printf("Shadow:");
scanf("%d",&clr_BRDD);

gotoxy(40,i++);
printf("Text:");
scanf("%d",&clr_TEXT);

gotoxy(40,i++);
printf("Back Ground:");
scanf("%d",&clr_BGGND);

getch();
}

void GetDetails(void)
{
int gd=DETECT,gm,i,j;

initgraph(&gd,&gm,"D:\\TC\\BGI");
closegraph();
//----PLAYER NAME-----
clrscr();
gotoxy(10,10);
printf("Player1:");
scanf("%s",pln[0]);
gotoxy(10,11);
printf("Player2:");
scanf("%s",pln[1]);

whichplr=0;key=0;r=5;c=5;pr=5;pc=5;ch='\0';Gain=0;count[0]=0,count[1]=0;
pln[0][25]='\0';pln[1][25]='\0';

for(i=0;i<9;i++)
 for(j=0;j<9;j++)
  played[i][j]=0;

  if(ToMenu==1)
   initgraph(&gd,&gm,"D:\\TC\\BGI");
}