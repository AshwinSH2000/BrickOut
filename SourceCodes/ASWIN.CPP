#include <dos.h>
#include<fstream.h>
#include <conio.h>
#include<graphics.h>
#include<process.h>
#include <stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int x, y, button ,points=0, life=3;
char response=1;
char point[30];
char lifes[10][4]={"3","2","1","0"};
char ps_nm[30], ps_scr[30];

#include "C:\XI\PROJECTS\MOUSE3.cpp"
#include "C:\XI\PROJECTS\HIGHSCOR.CPP"
#include "C:\XI\PROJECTS\PADDLE.cpp"
#include "C:\XI\PROJECTS\BRICKS.cpp"
#include "C:\XI\PROJECTS\INSTRU~1.CPP"
#include "C:\XI\PROJECTS\SIGNIN.CPP"
#include "C:\XI\PROJECTS\SIGNUP.CPP"

clock_t start, end;
char str[10]="0";
int tim;
class TextBox
{
  int Left, Top ;
  char TextValue[30];
public:

  TextBox( int L, int T )
  {
    Left = L; Top = T ;
    strcpy(TextValue, "\0");
  }

  void DrawTextBox()
  {     
    setfillstyle(1,15);
    setcolor(BLACK);
    bar3d( Left, Top, Left + 200, Top + 30, 1, 0 );
  }

  void InputText()
  { 
    setbkcolor(0);
    setcolor(BLACK);
    settextstyle(2,0,7);
    char ch[2] ; int Ind = 0, Scale = 4 ;
    ch[1] = '\0';
    ch[0] = getch();
    setcolor(RED);
    while( ch[0] !=  '\r' )    //next line
    {
     if( ch[0]==8 )
     {
       Ind--;
       bar(Left+Scale, Top+7, Left+Scale+10, Top+26);
       Scale-=10;
     }
     else
     {
       TextValue[Ind++] = ch[0] ;
       outtextxy( Left+ Scale, Top + 7, ch ) ;
     }
      ch[0]= getch();
      if( ch[0]!=8 )
	Scale += 10;
    }
    TextValue[Ind] = '\0';
  }

  void InputPassWord()
  { setbkcolor(0);
    setcolor(BLACK);
    settextstyle(2,0,7);
    char ch[2]; 
    int Ind = 0, Scale = 4 ;
    ch[1] = '\0';
    RETAKE:
    ch[0] = getch();
    if( ch[0]=='\r')
    goto RETAKE;
    setcolor(RED);
    while( ch[0] !=  '\r' )    //next line
    {
     TextValue[Ind++] = ch[0] ;
     outtextxy( Left+ Scale, Top + 7, "*" ) ;
     if( ch[0]==8 )
     {
       Ind--;
       bar(Left+Scale, Top+7, Left+Scale+10, Top+26);
       Scale-=10;
     }
     else
     {
       TextValue[Ind++]=ch[0];
       outtextxy(Left+Scale, Top+7, "*");
     }
     ch[0] = getch();
     if(ch[0]!=8)
       Scale += 10;
    }
    TextValue[Ind]  = '\0';
  }

  char* RetTextValue()
  {
    return TextValue;
  }

};

void draw_brick(int,int,int,int,int);
void half_destroy(int,int,int,int,int);
void full_destroy(int,int,int,int);
void moveball(int&, int&, int, int, int );
int paddle_check(int xcoor, int ycoor);
void printscore( int score);

void main()
{
  int gd= DETECT, gm;
  initgraph(&gd, &gm, "  ");
  initmouse();
  int k, l, z;
  k=getmaxx()/2;
  l=getmaxy()/2;
  for(z=20; z<500; z++)
  {
    delay(10);
    setcolor(z/10);
    arc(k,l,0,360, z-5);
  }
  cleardevice();
  setbkcolor(9);
  moveto(70, 70);
  settextstyle(0, 0, 9);
  outtextxy(135,50,"BRICK");
  outtextxy(195,170,"OUT");
  settextstyle(0,0,3);
  outtextxy(20,290,"By:");
  outtextxy(20,335,"ASHWIN AND SHAMANTH");
  getch();

  //login and signup
  cleardevice();
  settextstyle(0, 0, 5);
  cleardevice();
  setbkcolor(0);
  BRICK();
  setfillstyle(10,15);
  bar(540,100,100,400);
  settextstyle(0,0,2);
  bar(200,200,400,230);
  bar(200,270,400,300);
  outtextxy(200,200,"LOGIN");
  outtextxy(200,270,"SIGN UP");
  char *Uname;
  char *Pword;
  while(1)
  {
    getmousepos( &button,&x, &y );
    showmouseptr();
    if(x>=200 && x<=400 && y>=200 && y<= 230 )
    {
      if(button&1==1)
      { RE_LOGIN:
	setcolor(WHITE);
	cleardevice();
	BRICK();
	settextstyle(0,0,2);
	setfillstyle(10,15);
	bar(540,100,100,400);
	outtextxy(120,120,"LOGIN PAGE" );
	ttextstyle(0,0,2);
	outtextxy(200,180,"USERNAME");
	outtextxy(200,250,"PASSWORD");
	TextBox USerName( 200, 200 ) ;
	TextBox PAssWord( 200 , 270 );

	USerName.DrawTextBox() ;
        PAssWord.DrawTextBox();
	USerName.InputText() ;
	PAssWord.InputPassWord();
	Uname = USerName.RetTextValue();
	Pword = PAssWord.RetTextValue();
	if( Check(Uname,Pword) != 1 )
	{  
           cleardevice();
	   setbkcolor(BLACK);
	   outtextxy(70,100,"Either the password or the username is wrong.");
	   outtextxy(70,120,"Please try again...");
	   outtextxy(70,150,"To Sign Up as a new user, press SPACEBAR");
	   outtextxy(70,170,"To Login again press any key");
	   char a;
	   a=getch();
	   if(a==32)
	     goto SIGNUP;
	   else
	     goto RE_LOGIN;
	}
	if( Check(Uname,Pword ) == 1 )
	{
	  cleardevice();
	  setbkcolor(BLACK);
	  setcolor(GREEN);
	  char welc[50]={">>>...SUCCESSFULLY LOGGED IN"};
	  char welc2[50]={" WELCOME TO ATARI...."};
	  strcat(welc2,Uname );
	  outtextxy(100,100,welc);
	  outtextxy(100,130,welc2);
	  getch();
	  break;
	}
      }
    }

    if(x>=200 && x<=400 && y>=270 && y<= 300)
    {
      if(button&1==1)
      {   
        SIGNUP:
	setcolor(WHITE);
	cleardevice();
	BRICK();
	settextstyle(0,0,2);
	setfillstyle(10,15);
	bar(580,100,70,400);
	outtextxy(90,120,"SIGN-UP PAGE" );
	settextstyle(0,0,2);
	outtextxy(200,180,"USERNAME");
	outtextxy(200,250,"PASSWORD");
	TextBox UserName( 200, 200 ) ;
	TextBox PassWord( 200 , 270 );
	UserName.DrawTextBox() ;
	PassWord.DrawTextBox();
	UserName.InputText() ;
	PassWord.InputPassWord();
	Uname = UserName.RetTextValue();
	Pword = PassWord.RetTextValue();
	Sign(Uname,Pword);
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	char welc[50]={">>>...SUCCESSFULLY SIGNED UP"};
	char welc2[50]={" WELCOME TO ATARI, "};
	strcat(welc2,Uname );
	outtextxy(100,100,welc);
	outtextxy(100,130,welc2);
	getch();
	break;
      }  
     }
   }

  int xcoor=600,ycoor=400,count,run_value,update_x,update_y, i, time=0;
  int game_level=0;
  cleardevice();
  int maxx, maxy;
  char pattern[8] = {0x00, 0x70, 0x20, 0x27, 0x25, 0x27, 0x04, 0x04};

  maxx = getmaxx();
  maxy = getmaxy();
  setcolor(getmaxcolor());
  setfillpattern(pattern, getmaxcolor());

  // fill the screen with the pattern 
  bar(0, 0, maxx, maxy);
  getch();

  // get the current user defined fill pattern 
  getfillpattern(pattern);

  // alter the pattern we grabbed 
  pattern[4] -= 1;
  pattern[5] -= 3;
  pattern[6] += 3;
  pattern[7] -= 4;

  // select our new pattern 
  setfillpattern(pattern, getmaxcolor());

  // fill the screen with the new pattern 
  bar(0, 0, maxx, maxy);

  getch();
  setcolor(BLUE);
  settextstyle(0,0,6);
  char welc[50]={"WELCOME"};
  outtextxy(150,100,welc);
  char toat[50]={"TO ATARI"};
  outtextxy(150,190,toat);
  outtextxy(140,270,Uname);
  setcolor(GREEN);
  char welc1[50]={"WELCOME"};
  outtextxy(150,98,welc);
  char toat1[50]={"TO ATARI"};
  outtextxy(152,188,toat);
  outtextxy(142,268,Uname);
  getch();
  int game_level=0;
  setbkcolor(BLACK);
  cleardevice();
  option:
  cleardevice();
  BRICK();
  setcolor(12);
  setfillstyle(1,1);
  bar3d(200,90,360,130,5,40);
  setcolor(12);
  settextstyle(1,0,1);
  outtextxy(250,100,"PLAY");
  setfillstyle(1,1);
  bar3d(200,160,360,200,5,40);
  outtextxy(220,170,"HALL OF FAME");
  setfillstyle(1,1);
  bar3d(200,230,360,270,5,40);
  outtextxy(220,240,"INSTRUCTIONS");
  setfillstyle(1,1);
  bar3d(200,300,360,340,5,50);
  outtextxy(250,310,"QUIT");
  setfillstyle(1,11);
  floodfill(362,320,12);
  setfillstyle(1,11);
  floodfill(362,240,12);
  setfillstyle(1,11);
  floodfill(362,160,12);
  setfillstyle(1,11);
  floodfill(362,100,12);
  setfillstyle(1,11);
  floodfill(352,299,12);
  setfillstyle(1,11);
  floodfill(352,229,12);
  setfillstyle(1,11);
  floodfill(352,159,12);
  setfillstyle(1,11);
  floodfill(352,89,12);
  char username[50];
  showmouseptr();
  while(1)
  {
    getmousepos( &button,&x, &y);
    if(x>=200 && x<=360 && y>=160 && y<= 200)
    {
      if(button&1==1)
      {  hallofame();
         goto option;
      }
    }
    if(x>=200 && x<=360 && y>=300 && y<= 340)
    {
      if(button&1==1)
        exit(0);
    }
    if(x>=200 && x<=360 && y>=230 && y<= 270)
    {
      if(button&1==1)
      {   
        instru();
        goto option;
      }
    }
    if(x>=200 && x<=360 && y>=100 && y<= 130)
    {
      if(button&1==1)
      {
        button=-1;
	cleardevice();
	BRICK();
	setfillstyle(1,1);
	bar3d(90,90,560,130,5,40);
	outtextxy(100,100," CHOOSE YOUR PREFERENCE ");
	bar3d(200,160,360,200,5,40);
	outtextxy(220,170,"AMATEUR ");
	bar3d(200,230,360,270,5,40);
	outtextxy(220,240," PRO ");
	while(1)
	{
	   getmousepos(&button, &x, &y);
	   if(button==1)
	   {  if( x>230 && x< 320 && y > 170 && y < 200)
	      {	 
                game_level=1;  goto AMATEUR;  
              }
	      if( x>220 && x < 310 && y >240 && y < 270)
	      { 
                game_level=2;   goto PRO;     
              }
	   }
	   if(kbhit())
	     break;
	 }
	 getch();
         break;
       }
     }
   } 

  // Level Pro begins here.
  PRO:
  cleardevice();
  initmouse();
  showmouseptr();
  setbkcolor(BLACK);
  setcolor(YELLOW);
  line(0,462,700,462);
  setcolor(WHITE);
  settextstyle(3,0,1);
  outtextxy(5,458,"LIVES: ");
  setcolor(MAGENTA);
  outtextxy(80,458,lifes[0]);
  setcolor(WHITE);
  outtextxy(150,458,"LEVEL:");
  setcolor(MAGENTA);
  outtextxy(230,458,"PRO");
  setcolor(WHITE);
  outtextxy(310,458,"SCORE: ");
  itoa(points,point,10);
  setcolor(MAGENTA);
  outtextxy(380,458,point);
  setcolor(WHITE);
  outtextxy(480,458,"TIME: ");
  replay:
  setbkcolor(BLACK);

  draw_brick(10,10,60,30,4);
  draw_brick(10,40,60,60,1);
  draw_brick(10,70,60,90,6);
  draw_brick(10,100,60,120,14);
  draw_brick(10,130,60,150,2);
  draw_brick(10,160,60,180,3);
  start1:
  settextstyle(0,0,2);
  setcolor(WHITE);
  outtextxy(100,400,"PRESS SPACEBAR TO BEGIN ");
  outtextxy(70,430,"PRESS ESC TO EXIT ANYTIME ");
  if(getch()==32)
    ;
  else 
    goto start1;
  settextstyle(0,0,5);
  time=0;
  setcolor(WHITE);
  start = clock();
  settextstyle(0,0,2);
  setcolor(BLACK);
  outtextxy(100,400,"PRESS SPACEBAR TO BEGIN");
  outtextxy(70,430,"PRESS ESC TO EXIT ANYTIME ");
  moveball(xcoor,ycoor,54,-3,-4);
  half_destroy(430,160,480,180,3);
  moveball(xcoor,ycoor,60,-3,4);
  if( paddle_check(xcoor,ycoor) )  
    goto gameover;
  moveball(xcoor,ycoor,40,-3,-6);
  half_destroy(130,160,180,180,3);
  moveball(xcoor,ycoor,25,-5,+1);
  moveball(xcoor,ycoor,45,+5,+5);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,63,5,-4);
  half_destroy(550,160,600,180,3);
  moveball(xcoor,ycoor,6,5,5);
  moveball(xcoor,ycoor,42,-5,5);
  if( paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,48,-5,-5);
  full_destroy(130,160,180,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,25,-5,4);
  moveball(xcoor,ycoor,25,6,6);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,62,6,-4);
  half_destroy(490,160,540,180,3);
  moveball(xcoor,ycoor,15,6,4);
  moveball(xcoor,ycoor,45,-6,4);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,48,-6,-5);
  half_destroy(10,160,60,180,3);
  moveball(xcoor,ycoor,50,6,5);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,35,7,-6);
  moveball(xcoor,ycoor,54,-6,4);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,51,-5 ,-5);
  full_destroy(10,160,60,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,48,4,5);
  if( paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,67,6,-2);
  moveball(xcoor,ycoor,54,-4,-2);
  half_destroy(370,160,420,180,3);
  moveball(xcoor,ycoor,43,-5,6);
  if( paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,38,-2,-6);
  half_destroy(70,160,120,180,3 );
  moveball(xcoor,ycoor,30,-3,3);
  moveball(xcoor,ycoor,41,4,3);
  if( paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,52,5,-4);
  full_destroy(430,160,480,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor, 55,2,4);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,57,-3,-4);
  full_destroy(370,160,420,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,53,-4,4);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,35,-5,-3);
  moveball(xcoor,ycoor,53,6,-2);
  half_destroy(310,160,360,180,3);
  moveball(xcoor,ycoor,73,4,3);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,12,2,-4);
  moveball(xcoor,ycoor,84,-1,-2);
  full_destroy(490,160,540,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,45,-6,5);
  if( paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,55,-5,-3);
  moveball(xcoor,ycoor,45,6,-2);
  half_destroy(250,160,300,180,3);
  moveball(xcoor,ycoor,51,2,5);
  if( paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,55,3,-4);
  full_destroy(550,160,600,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,43,-2,5);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,74,-3,-3);
  half_destroy(190,160,240,180,3);
  moveball(xcoor,ycoor,56,-3,4);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,21,-3,-2);
  moveball(xcoor,ycoor,88,3,-2);
  full_destroy(250,160,300,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,41,4,5);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,52,3,-5);
  half_destroy(550,130,600,150,2);
  moveball(xcoor,ycoor,46,-2,6);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,96,-5,-1);
  moveball(xcoor,ycoor,73,4,-2);
  full_destroy(310,160,360,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,61,4,4);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,25,3,-2);
  moveball(xcoor,ycoor,207,-2,-1);
  full_destroy(190,160,240,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,50,-2,5);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,50,0,-5);
  full_destroy(70,160,120,180);
  points+=1;
  printscore(points);
  moveball(xcoor,ycoor,52,-2,3);
  moveball(xcoor,ycoor,36,4,3);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,66,3,-4);
  half_destroy(370,130,420,150,2);
  moveball(xcoor,ycoor,62,-3,4);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,66,-2,-4);
  half_destroy(10,130,60,150,2);
  moveball(xcoor,ycoor,52,3,5);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  setcolor(RED);
  setfillstyle(1,4);
  fillellipse(398,393,5,5);
  setfillstyle(1,2);
  fillellipse(398,393,4,4);
  setfillstyle(1,3);
  fillellipse(398,393,3,3);
  setcolor(WHITE);
  moveball(xcoor,ycoor,70,6,-1);
  moveball(xcoor,ycoor,105,-3,-2);
  full_destroy(250,130,300,150);
  full_destroy(190,130,240,150);
  points+=4;
  printscore(points);
  moveball(xcoor,ycoor,10,-6,-2);
  full_destroy(190,100,240,120);
  full_destroy(130,100,180,120);
  points+=6;
  printscore(points);
  moveball(xcoor,ycoor,10,-6,-2);
  full_destroy(130,70,180,90);
  full_destroy(70,70,120,90);
  points+=8;
  printscore(points);
  moveball(xcoor,ycoor,10,-6,-2);
  full_destroy(10,40,60,60);
  full_destroy(70,40,120,60);
  points+=5;
  printscore(points);
  moveball(xcoor,ycoor,20,-4,-1);
  full_destroy(10,70,60,90);
  points+=4;
  moveball(xcoor,ycoor,10,2,-3);
  full_destroy(10,10,60,30);
  points+=6;
  printscore(points);
  moveball(xcoor,ycoor,10,4,4);
  moveball(xcoor,ycoor,13,2,2);
  full_destroy(70,100,120,120);
  points+=3;
  printscore(points);
  moveball(xcoor,ycoor,10,2,2);
  full_destroy(130,130,180,150);
  points+=2;
  printscore(points);
  full_destroy(70,130,120,150);
  points+=2;
  printscore(points);
  moveball(xcoor,ycoor,50,2,6);
  if(paddle_check(xcoor,ycoor) ) 
    goto gameover;
  moveball(xcoor,ycoor,60,3,-4);
  full_destroy(370,130,420,150);
  points+=2;
  printscore(points);
  moveball(xcoor,ycoor,50,4,4);
  moveball(xcoor,ycoor,25,-3,3);
  if(paddle_check(xcoor,ycoor) )
    goto gameover;
  moveball(xcoor,ycoor,100,-5,-4);
  // Level Pro ends here.

  //Level Amateur begins here.
  AMATEUR:
  if( game_level== 1)
  {
    int xcoor=600,ycoor=400,count,run_value,update_x,update_y, i, time=0;
    cleardevice();
    initmouse();
    showmouseptr();
    setbkcolor(BLACK);
    setcolor(YELLOW);
    line(0,462,700,462);
    setcolor(WHITE);
    settextstyle(3,0,1);
    outtextxy(5,458,"LIVES: ");
    setcolor(MAGENTA);
    outtextxy(80,458,lifes[0]);
    setcolor(WHITE);
    outtextxy(150,458,"LEVEL:");
    setcolor(MAGENTA);
    outtextxy(210,458,"AMATEUR");
    setcolor(WHITE);
    outtextxy(310,458,"SCORE: ");
    itoa(points,point,10);
    setcolor(MAGENTA);
    outtextxy(380,458,point);
    setcolor(WHITE);
    outtextxy(480,458,"TIME: ");

    replay:
    setbkcolor(BLACK);
    draw_brick(10,10,60,30,4);
    draw_brick(10,40,60,60,1);
    draw_brick(10,70,60,90,6);
    draw_brick(10,100,60,120,14);
    draw_brick(10,130,60,150,2);
    draw_brick(10,160,60,180,3);
    start2:
    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(100,400,"PRESS SPACEBAR TO BEGIN ");
    outtextxy(70,430,"PRESS ESC TO EXIT ANYTIME ");
    if(getch()==32)
      ;
    else 
      goto start2;
    settextstyle(0,0,5);
    time=0;
    setcolor(WHITE);
    start = clock();

    settextstyle(0,0,2);
    setcolor(BLACK);
    outtextxy(100,400,"PRESS SPACEBAR TO BEGIN");
    outtextxy(70,430,"PRESS ESC TO EXIT ANYTIME ");
    moveball(xcoor,ycoor,54,-3,-4);
    full_destroy(430,160,480,180);     
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,60,-3,4);
    if( paddle_check(xcoor,ycoor) )  
      goto gameover;
    moveball(xcoor,ycoor,40,-3,-6);
    full_destroy(130,160,180,180);   
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,25,-5,+1);
    moveball(xcoor,ycoor,45,+5,+5);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,63,5,-4);
    full_destroy(550,160,600,180);      
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,6,5,5);
    moveball(xcoor,ycoor,42,-5,5);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,52,-5,-5);
    full_destroy(70,160,120,180);           
    points+=1;
    printscore(points);
    full_destroy(70,130,120,150);               
    points+=2;
    printscore(points);
    moveball(xcoor,ycoor,25,-5,4);
    moveball(xcoor,ycoor,28,6,6);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,62,6,-4);
    full_destroy(490,160,540,180);               
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,15,6,4);
    moveball(xcoor,ycoor,45,-6,4);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,48,-6,-5);
    full_destroy(10,160,60,180);                      
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,50,6,5);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,32,6,-8);
    full_destroy(550,130,600,150);                  
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,68,-6,4);
    if( paddle_check(xcoor,ycoor) )
      goto gameover;
    moveball(xcoor,ycoor,20,-5 ,-5);
    moveball(xcoor, ycoor, 34,5,-5);
    full_destroy(190,160,240,180);    
    points+=1;
    printscore(points);
    moveball(xcoor,ycoor,49,5,5);
    if( paddle_check(xcoor,ycoor) )
      goto gameover;
    moveball(xcoor,ycoor,33, 5,-5);
    moveball(xcoor,ycoor,20,-5,-5);
    full_destroy(490,130,540,150);  
    points+=2;
    printscore(points);
    moveball(xcoor,ycoor,70,-4,4);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor,ycoor,58,-4,-4);
    moveball(xcoor,ycoor,22,5,-4);
    full_destroy(70,100,120,150);    
    points+=3;
    printscore(points);
    moveball(xcoor,ycoor,3,5,3);
    full_destroy(130,130,180,150);  
    points+=2;
    printscore(points);
    // quicksilver
    setcolor(9);
    fillellipse(593,317,4,4);
    setcolor(7);
    fillellipse(593,317,2,2);
    moveball(xcoor,ycoor,75,5,4);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor, ycoor, 18, 6,-5);
    moveball(xcoor, ycoor, 33, -6,-5);
    full_destroy(370,160,420,180);     
    points+=1;
    printscore(points);
    moveball(xcoor, ycoor, 3, -6,-5);
    full_destroy(370,130,420,150);            
    points+=2;
    printscore(points);
    moveball(xcoor, ycoor, 4, -6, -5);
    full_destroy(310,100,360,150);
    points+=3;
    printscore(points);
    moveball(xcoor, ycoor, 9, -6, -5);
    full_destroy(310,70,360,90);          
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 7, -6, -5);
    full_destroy(250,70,300,90);            
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 2, -6,-5);
    full_destroy(250,40,300,60);               
    points+=5;
    printscore(points);
    moveball(xcoor, ycoor, 4, -6, -5);
    full_destroy( 250,10,300,30);          
    points+=6;
    printscore(points);
    moveball(xcoor, ycoor, 3, -6,-5);
    full_destroy(190,10,240,30);         
    points+=6;
    printscore(points);
    moveball(xcoor, ycoor, 5, -6, 4);
    full_destroy(190,40,240,60);      
    points+=5;
    printscore(points);
    moveball(xcoor, ycoor, 5,  -6, 4);
    full_destroy(130,40,180,60);         
    points+=5;
    printscore(points);
    moveball(xcoor, ycoor, 4, -6, 4);
    full_destroy(130,70,180,90);          
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 3, -6, 4);
    full_destroy(70,70,120,90);          
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 13,-6,4);
    full_destroy(10,130,60,150);         
    points+=2;
    printscore(points);
    moveball(xcoor, ycoor, 13,-6,4);
    moveball(xcoor, ycoor, 60, 6, 4);
    if( paddle_check(xcoor,ycoor) ) 
      goto gameover;
    moveball(xcoor, ycoor,52, 6, -5);
    moveball(xcoor, ycoor,7, -6, -5);
    full_destroy(550,100,600,120);    
    points+=3;
    printscore(points);
    moveball(xcoor, ycoor, 4, -6, -5);
    full_destroy(550,70,600,90);          
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 3, -6, -5);
    full_destroy(490,70,540,90);
    points+=4;
    printscore(points);
    moveball(xcoor, ycoor, 5, -6, -5);
    full_destroy(490, 40, 540, 60);     
    points+=5;
    printscore(points);
    moveball(xcoor, ycoor, 5, -6, -5);
    full_destroy(490, 10, 540, 30);     
    points+=6;
    printscore(points);

    end = clock();
    time=(end-start)/CLK_TCK;
    cout<<time;


  }
  // Level Amateur ends here.
  gameover:
  setcolor(15);
  settextstyle(0,0,2);
  outtextxy(100,400,"* GAME OVER *");
  outtextxy(100,420,"YOUR POINTS ARE:");
  itoa(points,point,10);
  outtextxy(400,420,point);
  cleardevice();
  outtextxy(100,100,"Hi ");
  outtextxy(150,100,Uname);
  outtextxy(100,190,"Congrats! You did well...");
  outtextxy(100,220,"You scored ");
  outtextxy(290,220,point);
  outtextxy(330,220,"points");
  end = clock();
  time=(end-start)/CLK_TCK;
  cout<<time;
  strcpy(ps_nm, Uname);
  strcat(ps_nm, ".");
  strcpy(ps_scr, point);
  strcat(ps_scr, ".");
  check_score(ps_nm, ps_scr);
  getch();
  closegraph();
}


void printscore( int score)
{   
  static int updated, old=0;
  updated=score;
  char updated_array[10], old_array[10];
  itoa(updated,updated_array,10);
  itoa(old,old_array,10);
  setcolor(BLACK);
  settextstyle(3,0,1);
  outtextxy(380,458,old_array);
  setcolor(MAGENTA);
  settextstyle(3,0,1);
  outtextxy(380,458,updated_array);
  old=updated;
}


void moveball(int& xcoor, int& ycoor, int run_value, int update_x , int update_y)
{
  for(int game=0 ; game<run_value ; game++ )
  { 
    if( ( kbhit() ) )
    {
      cleardevice();
      outtextxy(100,100,"Exiting the game");
      outtextxy(100,130,"You scored ");
      outtextxy(290,130,point);
      outtextxy(330,130," points");
      getch();
      menu();
      exit(0);
    }
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    getmousepos( &button, &x, &y );
    fillellipse(xcoor, ycoor, 5,5);
    paddle();
    delay(1);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(xcoor, ycoor, 5,5);
    xcoor+=update_x ; ycoor+=update_y;

    settextstyle(3,0, 2);

    setcolor(BLACK);
    outtextxy(530, 458, str);
    end = clock();
    tim=(end-start)/CLK_TCK;
    itoa(tim, str, 10);
    delay(10);
    setcolor(MAGENTA);
    outtextxy(530, 458, str);
    delay(10);
  }
}


void draw_brick(int left,int top,int right,int bot, int colour)
{
  for(int i=1;i<=10;i++)
  {  
     setfillstyle(SOLID_FILL,colour);
     bar(left,top,right,bot);
     left=right+10;
     right=right+60;
  }
}


void half_destroy( int left,int top,int right,int bot,int colour)
{
  setfillstyle(2,colour);
  bar(left,top,right,bot);
}


void full_destroy( int left,int top,int right,int bot)
{
  setfillstyle(1,BLACK);
  bar(left,top,right,bot);
}


int paddle_check(int xcoor, int ycoor)
{ 
  static int li=0;
  getmousepos( &button, &x, &y );
  if( (xcoor>x) && (xcoor<(x+100)) && (ycoor>420) )
    return 0;
  else if( (xcoor<x) || (xcoor>(x+120)) && (ycoor>420) )
  { 
    if(life==0)
      return 1;
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(100,400,"LOST A LIFE");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"LOST A LIFE");
    life--;
    setcolor(BLACK);
    settextstyle(3,0,1);
    outtextxy(80,458,lifes[li]);      
    // lifes = { "3" , "2" , "1" , "0"};
    settextstyle(3,0,1);
    setcolor(MAGENTA);
    li++;
    outtextxy(80,458,lifes[li]);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(100,400,"RESUMING GAME IN.... ");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"RESUMING GAME IN.... ");
    setcolor(15);
    outtextxy(100,400,"3");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"3");
    setcolor(15);
    outtextxy(100,400,"2");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"2");
    setcolor(15);
    outtextxy(100,400,"1");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"1");
    setcolor(15);
    outtextxy(100,400,"R`APIDAMENTE !");
    delay(1000);
    setcolor(0);
    outtextxy(100,400,"R`APIDAMENTE !");
    return 0;
  }
}






























































