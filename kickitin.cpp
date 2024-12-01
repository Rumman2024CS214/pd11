#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y);
void printoptions();
int  choices();
void printheader();
void character();
void emptycharacter();
void moveplayerleft();
void moveplayerup();
void moveplayerdown();
void moveplayerright();
void boundary();
void printgoal();
void emptygoal();
void movegoalup();
void movegoaldown();
void movegoal();
void ball();
void emptyball();
void moveballup();
void moveballdown();
void moveballright();
void moveballleft();
void shootball();
void movement();
void movementball();
void printkeeper();
void emptykeeper();
void movekeeperupd();
void movekeeperdownd();
void movekeeper();
int position=0;
int position1=0;
int position2=0;
int bposition=0;
int cposition=0;
int goalposition=0;
void cone();
void emptycone();
void conemove();
void shootcone();
char getCharAtxy(short int x,short int y);
int x=2,y=32;
int lx=70,ly=20;
int bx=12,by=37;
int gx=132,gy=30;
int kx=90,ky=10;
int cx=kx-1,cy=ky+1;
int score=0;
string status[6]={"Cleared!"};
int level[5];
main()
{ 
  int chance1=3,chance2=3;
  int levelindex=0;
  int choice;
  while(choice!=4)
  {
    Sleep(100);
    system("cls");
    printheader();
    printoptions();
    choice=choices();
    if(choice==1)
    {
      system("cls");
      gotoxy(lx,ly);
      cout<<"Enter Level: ";
      cin>>levelindex;
      if(status[levelindex-1]=="Cleared!")
      {
        while(chance2!=0)
        {
          x=2,y=32;
          lx=70,ly=20;
          bx=12,by=37;
          gx=132,gy=30;
          kx=90,ky=10;
          bposition=0;
          Sleep(100);
          system("cls");
          boundary();
          cout<<"Number of Chances: "<<chance2;
          character();
          printgoal();
          printkeeper();
          ball();
          cone();
          while(true)
          {
            movement();
            movekeeper(); 
            movegoal();
            movementball();
            shootcone();
            if(GetAsyncKeyState(VK_SPACE))
            {
              while(bposition==0)
              {
                movekeeper();
                movegoal();
                shootball();
                shootcone();
                if(bposition==1)
                {
                  chance2--;
                  break;
                }
              }
            }
            if(chance2+1==chance1 || chance2+2==chance1 || chance2+3==chance1)
            {
              break;
            }   
          }
        }
        if(status[levelindex]=="Cleared!")
        {
          cout<<"Level 1 Cleared!";
        }
        else
        {
          system("cls");
          x=74,y=22;
          gotoxy(x,y);
          cout<<"Game Over!";
          gotoxy(x-1,y+3);
          cout<<"Score: "<<score;
          Sleep(2000);
        }
      }
      else
      {
        x=65,y=22;
        gotoxy(x,y);
        cout<<"Clear Previous Levels";
        Sleep(200);
      }
    }
  }
  
}


void shootball()
{
  if(getCharAtxy(bx+8,by+6)=='/' || getCharAtxy(bx+7,by+6)=='/' || getCharAtxy(bx+6,by+6)=='/' || getCharAtxy(bx+5,by+6)=='/' || getCharAtxy(bx+4,by+6)=='/' || getCharAtxy(bx+3,by+6)=='/' || getCharAtxy(bx+2,by+6)=='/' || getCharAtxy(bx+1,by+6)=='/' || getCharAtxy(bx,by+6)=='/' || getCharAtxy(bx-1,by+6)=='/' || getCharAtxy(bx-1,by+5)=='/' || getCharAtxy(bx-1,by+4)=='/' || getCharAtxy(bx-1,by+3)=='/' || getCharAtxy(bx-1,by+2)=='/' || getCharAtxy(bx-1,by+1)=='/' || getCharAtxy(bx-1,by)=='/' || getCharAtxy(bx-1,by-1)=='/' || getCharAtxy(bx,by-1)=='/' || getCharAtxy(bx+1,by-1)=='/' || getCharAtxy(bx+2,by-1)=='/' || getCharAtxy(bx+3,by-1)=='/' || getCharAtxy(bx+4,by-1)=='/' || getCharAtxy(bx+5,by-1)=='/' || getCharAtxy(bx+6,by-1)=='/' || getCharAtxy(bx+7,by-1)=='/' || getCharAtxy(bx+8,by-1)=='/' || getCharAtxy(bx+8,by)=='/' || getCharAtxy(bx+8,by+1)=='/' || getCharAtxy(bx+8,by+2)=='/' || getCharAtxy(bx+8,by+3)=='/' || getCharAtxy(bx+8,by+4)=='/' || getCharAtxy(bx+8,by+5)=='/')
  {
    bposition=1;
  }
  else if(getCharAtxy(bx+8,by+6)=='_' || getCharAtxy(bx+7,by+6)=='_' || getCharAtxy(bx+6,by+6)=='_' || getCharAtxy(bx+5,by+6)=='_' || getCharAtxy(bx+4,by+6)=='_' || getCharAtxy(bx+3,by+6)=='_' || getCharAtxy(bx+2,by+6)=='_' || getCharAtxy(bx+1,by+6)=='_' || getCharAtxy(bx,by+6)=='_' || getCharAtxy(bx-1,by+6)=='_' || getCharAtxy(bx-1,by+5)=='_' || getCharAtxy(bx-1,by+4)=='_' || getCharAtxy(bx-1,by+3)=='_' || getCharAtxy(bx-1,by+2)=='_' || getCharAtxy(bx-1,by+1)=='_' || getCharAtxy(bx-1,by)=='_' || getCharAtxy(bx-1,by-1)=='_' || getCharAtxy(bx,by-1)=='_' || getCharAtxy(bx+1,by-1)=='_' || getCharAtxy(bx+2,by-1)=='_' || getCharAtxy(bx+3,by-1)=='_' || getCharAtxy(bx+4,by-1)=='_' || getCharAtxy(bx+5,by-1)=='_' || getCharAtxy(bx+6,by-1)=='_' || getCharAtxy(bx+7,by-1)=='_' || getCharAtxy(bx+8,by-1)=='_' || getCharAtxy(bx+8,by)=='_' || getCharAtxy(bx+8,by+1)=='_' || getCharAtxy(bx+8,by+2)=='_' || getCharAtxy(bx+8,by+3)=='_' || getCharAtxy(bx+8,by+4)=='_' || getCharAtxy(bx+8,by+5)=='_')
  {
    bposition=1;
  }
  else if(getCharAtxy(bx+8,by+6)=='|' || getCharAtxy(bx+7,by+6)=='|' || getCharAtxy(bx+6,by+6)=='|' || getCharAtxy(bx+5,by+6)=='|' || getCharAtxy(bx+4,by+6)=='|' || getCharAtxy(bx+3,by+6)=='|' || getCharAtxy(bx+2,by+6)=='|' || getCharAtxy(bx+1,by+6)=='|' || getCharAtxy(bx,by+6)=='|' || getCharAtxy(bx-1,by+6)=='|' || getCharAtxy(bx-1,by+5)=='|' || getCharAtxy(bx-1,by+4)=='|' || getCharAtxy(bx-1,by+3)=='|' || getCharAtxy(bx-1,by+2)=='|' || getCharAtxy(bx-1,by+1)=='|' || getCharAtxy(bx-1,by)=='|' || getCharAtxy(bx-1,by-1)=='|' || getCharAtxy(bx,by-1)=='|' || getCharAtxy(bx+1,by-1)=='|' || getCharAtxy(bx+2,by-1)=='|' || getCharAtxy(bx+3,by-1)=='|' || getCharAtxy(bx+4,by-1)=='|' || getCharAtxy(bx+5,by-1)=='|' || getCharAtxy(bx+6,by-1)=='|' || getCharAtxy(bx+7,by-1)=='|' || getCharAtxy(bx+8,by-1)=='|' || getCharAtxy(bx+8,by)=='|' || getCharAtxy(bx+8,by+1)=='|' || getCharAtxy(bx+8,by+2)=='|' || getCharAtxy(bx+8,by+3)=='|' || getCharAtxy(bx+8,by+4)=='|' || getCharAtxy(bx+8,by+5)=='|')
  {
    bposition=1;
  }
  else if(getCharAtxy(bx-1,by+5)=='#' || getCharAtxy(bx-1,by+4)=='#' || getCharAtxy(bx-1,by+3)=='#' || getCharAtxy(bx-1,by+2)=='#' || getCharAtxy(bx-1,by+1)=='#' || getCharAtxy(bx-1,by)=='#' || getCharAtxy(bx-1,by-1)=='#' || getCharAtxy(bx,by-1)=='#' || getCharAtxy(bx+1,by-1)=='#' || getCharAtxy(bx+2,by-1)=='#' || getCharAtxy(bx+3,by-1)=='#' || getCharAtxy(bx+4,by-1)=='#' || getCharAtxy(bx+5,by-1)=='#' || getCharAtxy(bx+6,by-1)=='#' || getCharAtxy(bx+7,by-1)=='#' || getCharAtxy(bx+8,by-1)=='#' || getCharAtxy(bx+8,by)=='#' || getCharAtxy(bx+8,by+1)=='#' || getCharAtxy(bx+8,by+2)=='#' || getCharAtxy(bx+8,by+3)=='#' || getCharAtxy(bx+8,by+4)=='#' || getCharAtxy(bx+8,by+5)=='#')
  {
    bposition=1;
  }
  else if(getCharAtxy(bx+8,by+6)=='X' || getCharAtxy(bx+7,by+6)=='X' || getCharAtxy(bx+6,by+6)=='X' || getCharAtxy(bx+5,by+6)=='X' || getCharAtxy(bx+4,by+6)=='X' || getCharAtxy(bx+3,by+6)=='X' || getCharAtxy(bx+2,by+6)=='X' || getCharAtxy(bx+1,by+6)=='X' || getCharAtxy(bx,by+6)=='X' || getCharAtxy(bx-1,by+6)=='X' || getCharAtxy(bx-1,by+5)=='X' || getCharAtxy(bx-1,by+4)=='X' || getCharAtxy(bx-1,by+3)=='X' || getCharAtxy(bx-1,by+2)=='X' || getCharAtxy(bx-1,by+1)=='X' || getCharAtxy(bx-1,by)=='X' || getCharAtxy(bx-1,by-1)=='X' || getCharAtxy(bx,by-1)=='X' || getCharAtxy(bx+1,by-1)=='X' || getCharAtxy(bx+2,by-1)=='X' || getCharAtxy(bx+3,by-1)=='X' || getCharAtxy(bx+4,by-1)=='X' || getCharAtxy(bx+5,by-1)=='X' || getCharAtxy(bx+6,by-1)=='X' || getCharAtxy(bx+7,by-1)=='X' || getCharAtxy(bx+8,by-1)=='X' || getCharAtxy(bx+8,by)=='X' || getCharAtxy(bx+8,by+1)=='X' || getCharAtxy(bx+8,by+2)=='X' || getCharAtxy(bx+8,by+3)=='X' || getCharAtxy(bx+8,by+4)=='X' || getCharAtxy(bx+8,by+5)=='X')
  {
    position=3;
  }
  else if(getCharAtxy(bx+8,by-1)==' ' || getCharAtxy(bx-1,by+6)==' ' && bposition==0)
  {
    emptyball();
    bx=bx+1;
    ball();
  }

}
  
void gotoxy(int x,int y)
{
  COORD coordinates;
  coordinates.X=x;
  coordinates.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}



void printoptions()
{
  cout<<"                                                                   1. NEW GAME                                                            "<<endl;
  cout<<"                                                                                                                                          "<<endl;
  cout<<"                                                                   2. LOAD GAME                                                           "<<endl;
  cout<<"                                                                                                                                          "<<endl;
  cout<<"                                                                   3.  OPTIONS                                                            "<<endl;
  cout<<"                                                                                                                                          "<<endl;
  cout<<"                                                                    4.  EXIT                                                              "<<endl;
  cout<<"                                                                                                                                          "<<endl;
}                                            


void printheader()
{
cout<<"            _______________________________________________________________________________________________________________________________ "<<endl;
cout<<"            |                                                                                                                              |"<<endl;
cout<<"            |    ##      ##  ##########   ########  ##      ##        ##########  ############       ##########  ###          ##       ##  |"<<endl; 
cout<<"            |    ##     ##       ##      ##         ##     ##             ##           ##                ##      ## #         ##       ##  |"<<endl;
cout<<"            |    ##    ##        ##      ##         ##    ##              ##           ##                ##      ##  #        ##       ##  |"<<endl; 
cout<<"            |    ##   ##         ##      ##         ##   ##               ##           ##                ##      ##   #       ##       ##  |"<<endl;
cout<<"            |    ##  ##          ##      ##         ##  ##                ##           ##                ##      ##    #      ##       ##  |"<<endl;
cout<<"            |    #####           ##      ##         #####                 ##           ##                ##      ##     #     ##       ##  |"<<endl;
cout<<"            |    ##  ##          ##      ##         ##  ##                ##           ##                ##      ##      #    ##       ##  |"<<endl;
cout<<"            |    ##   ##         ##      ##         ##   ##               !#           ##                ##      ##       #   ##       ##  |"<<endl;
cout<<"            |    ##    ##        ##      ##         ##    ##              ##           ##                ##      ##        #  ##           |"<<endl;
cout<<"            |    ##     ##       ##      ##         ##     ##             ##           ##                ##      ##         # ##       @@  |"<<endl;
cout<<"            |    ##      ##  ##########   ########  ##      ##        ##########       ##            ##########  ##          ###       @@  |"<<endl;
cout<<"            |______________________________________________________________________________________________________________________________|"<<endl;
cout<<"                                                                                                                                            "<<endl; 
cout<<"                                                                                                                                            "<<endl;
cout<<"                                                                                                                                            "<<endl;
}

int choices()
{
  system("cls");
  printheader();
  printoptions();
  int ch;
  int x,y;
  x=65,y=25;
  gotoxy(x,y);
  cout<<"ENTER CHOICE: ";
  cin>>ch;
  return ch;
}  

void status1()
{
  cout<<"YOU MISSED BY AN INCH!";
}

void status2()
{
  cout<<"KEEPER STOPPED THE BALL!";
}

void status3()
{
  cout<<"POOR SHOT, YOU MISSED!";
}

void status4()
{
  cout<<"EXCELLENT SHOT, YOU SCORED A GOAL!";
}

void boundary()
{
 cout<<"########################################################################################################################################################"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"##                                                                                                                                                    ##"<<endl;
 cout<<"########################################################################################################################################################"<<endl;
}

void character()
{
gotoxy(x,y); 
cout<<" .:--:.  "<<endl;
gotoxy(x,y+1);
cout<<":: . .:: "<<endl;
gotoxy(x,y+2);
cout<<"':  - :' "<<endl;
gotoxy(x,y+3);
cout<<" ''''''  "<<endl;
gotoxy(x,y+4);
cout<<"   ||    "<<endl;
gotoxy(x,y+5);
cout<<"  /||\\  "<<endl;
gotoxy(x,y+6);
cout<<" / || \\ "<<endl;
gotoxy(x,y+7);
cout<<"   ||    "<<endl;
gotoxy(x,y+8);
cout<<"  /  \\  "<<endl;
gotoxy(x,y+9);
cout<<" /    \\ "<<endl;
}

void emptycharacter()
{
gotoxy(x,y); 
cout<<"         "<<endl;
gotoxy(x,y+1);
cout<<"         "<<endl;
gotoxy(x,y+2);
cout<<"         "<<endl;
gotoxy(x,y+3);
cout<<"         "<<endl;
gotoxy(x,y+4);
cout<<"         "<<endl;
gotoxy(x,y+5);
cout<<"         "<<endl;
gotoxy(x,y+6);
cout<<"         "<<endl;
gotoxy(x,y+7);
cout<<"         "<<endl;
gotoxy(x,y+8);
cout<<"         "<<endl;
gotoxy(x,y+9);
cout<<"         "<<endl;
}

void moveplayerright()
{
 if(getCharAtxy(x+110,y)==' ')
 {
 emptycharacter();
 x=x+1;
 character();
 }
}

void moveplayerleft()
{
 if(getCharAtxy(x-1,y)==' ')
 { 
 emptycharacter();
 x=x-1;
 character();
 }
}

void moveplayerup()
{
 if(getCharAtxy(x,y-1)==' ')
 {
 emptycharacter();
 y=y-1;
 character();
 }
}

void moveplayerdown()
{
 if(getCharAtxy(x,y+10)==' ')
 {
 emptycharacter();
 y=y+1;
 character();
 }
}

char getCharAtxy(short int x,short int y)
{
  CHAR_INFO ci;
  COORD xy={0,0};
  SMALL_RECT rect={x,y,x,y};
  COORD coordBufSize;
  coordBufSize.X=1;
  coordBufSize.Y=1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci,coordBufSize,xy,&rect) ? ci.Char.AsciiChar:' ';
}


void printgoal()
{
  gotoxy(gx,gy);
  cout<<"________________ "<<endl;
  gotoxy(gx,gy+1);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+2);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+3);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+4);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+5);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+6);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+7);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+8);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl;
  gotoxy(gx,gy+9);
  cout<<"XXXXXXXXXXXXXXXX|"<<endl; 
  gotoxy(gx,gy+10);
  cout<<"________________|"<<endl;
}

void emptygoal()
{
  gotoxy(gx,gy);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+1);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+2);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+3);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+4);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+5);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+6);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+7);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+8);
  cout<<"                 "<<endl;
  gotoxy(gx,gy+9);
  cout<<"                 "<<endl; 
  gotoxy(gx,gy+10);
  cout<<"                 "<<endl;
}

void movegoalup()
{
  Sleep(20);
  emptygoal();
  gy=gy-1;
  printgoal();
}

void movegoaldown()
{
  Sleep(20);
  emptygoal();
  gy=gy+1;
  printgoal();
}



void ball()
{
  gotoxy(bx,by);
  cout<<" .:::::. "<<endl;
  gotoxy(bx,by+1);
  cout<<".:::::::."<<endl;
  gotoxy(bx,by+2);
  cout<<":::::::::"<<endl;
  gotoxy(bx,by+3);
  cout<<" ::::::: "<<endl;
  gotoxy(bx,by+4);
  cout<<"  '''''  "<<endl;
}

void emptyball()
{
  gotoxy(bx,by);
  cout<<"         "<<endl;
  gotoxy(bx,by+1);
  cout<<"         "<<endl;
  gotoxy(bx,by+2);
  cout<<"         "<<endl;
  gotoxy(bx,by+3);
  cout<<"         "<<endl;
  gotoxy(bx,by+4);
  cout<<"         "<<endl;

}

void moveballup()
{
  if(getCharAtxy(bx,by-7)==' ')
  {
    emptyball();
    by=by-1;
    ball();
  }
}

void moveballdown()
{
  if(getCharAtxy(bx,by+1)==' ')
  {
    emptyball();
    by=by+1;
    ball();
  }
}

void moveballright()
{
  if(getCharAtxy(bx+100,by)==' ')
  {
    emptyball();
    bx=bx+1;
    ball();
  }
}

void moveballleft()
{
  if(getCharAtxy(bx-6,by)==' ')
  {
    emptyball();
    bx=bx-1;
    ball();
  }
}

void movementball()
{
  if(GetAsyncKeyState(VK_RIGHT))
  {
    moveballright();
  }
  if(GetAsyncKeyState(VK_LEFT))
  {
    moveballleft();
  }
  if(GetAsyncKeyState(VK_UP))
  {
    moveballup();
  }
  if(GetAsyncKeyState(VK_DOWN))
  {
    moveballdown();
  }
}

void movement()
{
   
  if(GetAsyncKeyState(VK_RIGHT))
  {
   moveplayerright();
  }
  if(GetAsyncKeyState(VK_LEFT))
  {
   moveplayerleft();  
  }
  if(GetAsyncKeyState(VK_UP))
  {
   moveplayerup();
  }
  if(GetAsyncKeyState(VK_DOWN))
  {
   moveplayerdown();
  }
}


void printkeeper()
{
  gotoxy(kx,ky); 
  cout<<" ______  "<<endl;
  gotoxy(kx,ky+1);
  cout<<"| . .  | "<<endl;
  gotoxy(kx,ky+2);
  cout<<"| --   | "<<endl;
  gotoxy(kx,ky+3);
  cout<<"|______| "<<endl;
  gotoxy(kx,ky+4);
  cout<<"   ||    "<<endl;
  gotoxy(kx,ky+5);
  cout<<"  /||\\  "<<endl;
  gotoxy(kx,ky+6);
  cout<<" / || \\ "<<endl;
  gotoxy(kx,ky+7);
  cout<<"   ||    "<<endl;
  gotoxy(kx,ky+8);
  cout<<"  /  \\  "<<endl;
  gotoxy(kx,ky+9);
  cout<<" /    \\ "<<endl;
}

void emptykeeper()
{
  gotoxy(kx,ky); 
  cout<<"         "<<endl;
  gotoxy(kx,ky+1);
  cout<<"         "<<endl;
  gotoxy(kx,ky+2);
  cout<<"         "<<endl;
  gotoxy(kx,ky+3);
  cout<<"         "<<endl;
  gotoxy(kx,ky+4);
  cout<<"         "<<endl;
  gotoxy(kx,ky+5);
  cout<<"         "<<endl;
  gotoxy(kx,ky+6);
  cout<<"         "<<endl;
  gotoxy(kx,ky+7);
  cout<<"         "<<endl;
  gotoxy(kx,ky+8);
  cout<<"         "<<endl;
  gotoxy(kx,ky+9);
  cout<<"         "<<endl;
}

void movekeeperupd()
{
  if(getCharAtxy(kx,ky-1)==' ' && position==0)
  {
  emptykeeper();
  ky=ky-1;
  printkeeper();
  Sleep(1);
  }
}

void movekeeperdownd()
{
  if(getCharAtxy(kx-20,ky)==' ' && position!=0)
  {
  Sleep(1);
  emptykeeper();
  ky=ky+1;
  printkeeper();
  }
}

void cone()
{
  gotoxy(cx,cy);
  cout<<"   *   "<<endl;
  gotoxy(cx,cy+1);
  cout<<"  ***  "<<endl;
  gotoxy(cx,cy+2);
  cout<<"  ***  "<<endl;
  gotoxy(cx,cy+3);
  cout<<" *****  "<<endl;
}

void emptycone()
{
  gotoxy(cx,cy);
  cout<<"       "<<endl;
  gotoxy(cx,cy+1);
  cout<<"       "<<endl;
  gotoxy(cx,cy+2);
  cout<<"       "<<endl;
  gotoxy(cx,cy+3);
  cout<<"       "<<endl;
}

void conemove()
{
  Sleep(1);
  emptycone();
  cx=cx-1;
  cone();
}

void shootcone()
{
  if(getCharAtxy(cx-1,cy+3)=='#')
  {
    cposition++;
  }
  if(getCharAtxy(cx-1,cy+3)==' ')
  {
    cposition=0;
  }
  if(cposition==0)
  {
    conemove();
  }
  else
  {
    cx=kx-1;
  }
}


void movekeeper(){
    if(getCharAtxy(kx,ky-1)=='#')
    {
      position++;
    }
    if(getCharAtxy(kx,ky+10)=='#'){
      position=0;
    }
    if(position==0)
    {
      movekeeperupd();
    }
    else{
      movekeeperdownd();
    }
  }

void movegoal()
{
  if(goalposition==0)
  {
    if(getCharAtxy(gx,gy-1)=='#')
    {
      position1=1;
    }
    if(getCharAtxy(gx,gy+11)=='#')
    {
      position1=0;
    }
    if(position1==0)
    {
      movegoalup();
    }
    else if(position1 == 1)
    {
      movegoaldown();
    }
  }
}