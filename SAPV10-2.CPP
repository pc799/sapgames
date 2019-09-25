#include<fstream.h>               //for file commands
#include<stdio.h>                 //for gets(),puts() functions
#include<iostream.h>              //for cout,cin command
#include<stdlib.h>                //for random() function
#include<string.h>                //for strcpy(),strcmp functions
#include<conio.h>                 //for clrscr(),getch() functions
#include<dos.h>                   //for delay() function
#include<graphics.h>              //for graphics commands

//class for account objects...............................................................
class account
{
int acno;                        //account number
char name[20];                   //user name
int pin;                         //account pin
public:
int create_account(int x)        //for creating new account
{
cout<<"\n\n\n\n\n\n\n";
cout<<"\n\n Your account no. is:"<<x+1;
acno=x;
cout<<"\n\n USER NAME:";
gets(name);
cout<<"\n\n PIN:";
cin>>pin;
cout<<"\n\n Your account has been created successfully!!";
getch();
return 0;
}

void view_account()            //for displaying account details
{
cout<<"\n\n\n\n\n\n\n";
cout<<"\n\n ACCOUNT DETAILS:";
cout<<"\n\n NAME:"<<name;
cout<<"\n\n ACCOUNT NO:"<<acno+1;
}

int modify_account(int x)      //for modifying an account
{
cout<<"\n\n\n\n\n\n\n";
cout<<"\n\n MODIFY YOUR ACCOUNT HERE:";
cout<<"\n\n Your account no. is:"<<x+1;
acno=x;
cout<<"\n\n NEW USER NAME:";
gets(name);
cout<<"\n\n NEW PIN:";
cin>>pin;
return 0;
}

int return_acno()            //account no. accessor function
{
return acno;
}

int return_pin()             //pin accessor function
{
return pin;
}
}ac[30];                     //array of objects

//FUNCTION DECLARATIONS..........................................................................
void sign();

int interface(int iacno);

void StonePaperScissor();
void Hangman();
void TicTacToe();

void intro_t();
void intro_h();
void intro_s();

int modify_acc(int iacno);
int view_acc(int iacno);
int delete_acc(int iacno);

void help();

int match(int user,int pc,int x);

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);

int checkwin(char square[]);
void board(char square[]);


const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;
      int signacno,signpin;
      int signch,found=0;

//main function.................................................................................
void main()
{
 clrscr();
 int x,y,i;

 int g=DETECT, d;                           //graphic initialization
 initgraph(&g, &d,"c:\\turboc3\\bgi");
 
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(4);
 int c=150;
 for(int e=0;e<15;e++)
 {
  for(int i=50;i<100;i++)
  {
   settextstyle(SMALL_FONT, HORIZ_DIR, 10);
   outtextxy(x,y,"Loading...");
   settextstyle(SMALL_FONT, HORIZ_DIR, 5);
   outtextxy(x+5,y+5,"SAP GAMES.. ");
   setcolor(3);
   circle(x,y,i);
   circle(x,y,c);
   c--;
   cleardevice();
  }
 }

  setcolor(12);
  settextstyle(SMALL_FONT, HORIZ_DIR, 10);
  settextjustify(x,y);
  outtextxy(x-140,y-60,"()()WELCOME()()");
  delay(150);
  outtextxy(x-135,y-20,"...................");
  delay(150);
  settextstyle(BOLD_FONT, HORIZ_DIR, 4);
  setcolor(11);
  outtextxy(x-130,y+0,"SAP GAMES");
  delay(150);
  settextstyle(SMALL_FONT, HORIZ_DIR, 5);
  outtextxy(x-130,y+60,"..................Let's Play........................");
  setcolor(12);
  delay(1500);
  outtextxy(x-170,y+90,"..Loading completed !! Press any key to continue..");
  getch();

  sign();
  getch();
}

//Interface Function..........................................................................
int interface(int iacno)
{
int ch,gamech,setch;
do
{
clrscr();

cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"1.Games.");
delay(200);
outtextxy(10,150,"2.Help.");
delay(200);
outtextxy(10,200,"3.Settings.");
delay(200);
outtextxy(10,250,"4.Sign Out.");
delay(200);
setcolor(4);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,300,639,300);
setcolor(15);
outtextxy(10,320,"ENTER YOUR CHOICE:");
delay(200);


setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
gotoxy(21,21);
cin>>ch;
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
switch (ch)
{
case 1:
{  clrscr();     cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,95,"GAMES:");
delay(200);
outtextxy(10,140,"1.Stone-Paper-Scissor");
delay(200);
outtextxy(10,190,"2.Hangman");
delay(200);
outtextxy(10,240,"3.Tic-Tac-Toe");
delay(200);
outtextxy(10,290,"4.<Return<<<");
delay(200);
setcolor(4);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,315,639,315);
setcolor(15);
outtextxy(10,320,"ENTER YOUR CHOICE:");
delay(200);


setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
gotoxy(21,21);
cin>>gamech;
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);

switch (gamech)
{
case 1:StonePaperScissor();break;
case 2:Hangman();break;
case 3:TicTacToe();
}
break;
}
case 2:
{
help();
break;
}
case 3:
{  clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"SETTINGS:");
delay(200);
outtextxy(10,150,"1.UPDATE ACCOUNT");
delay(200);
outtextxy(10,200,"2.VIEW ACCOUNT");
delay(200);
outtextxy(10,250,"3.DELETE ACCOUNT");
delay(200);
outtextxy(10,300,"4.<Return<<<");
delay(200);
setcolor(4);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,315,639,315);
setcolor(15);
outtextxy(10,320,"ENTER YOUR CHOICE:");
delay(200);


setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
gotoxy(21,21);
cin>>setch;
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);

switch (setch)
{
case 1:modify_acc(iacno); break;
case 2:view_acc(iacno); break;
case 3:delete_acc(iacno);
      sign();
}

break;
}

}
}
while(ch!=4);
outtextxy(400,355,"..Signing Out !! Miss You:-( !!");
getch();
return 0;
}

//SIGN function................................................................................
void sign()
{

cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"1.Login.");
delay(200);
outtextxy(10,150,"2.Register (if you are a new user).");
delay(200);
outtextxy(10,200,"3.Exit.");
delay(200);
setcolor(4);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,300,639,300);
setcolor(15);
outtextxy(10,320,"ENTER YOUR CHOICE:");
delay(200);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
gotoxy(21,21);
cin>>signch;
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);



if(signch==1)
{
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);


outtextxy(10,110,"SIGN IN HERE>>>");
delay(500);
outtextxy(10,160,"Enter your Account No.: ");
gotoxy(25,11);
cin>>signacno;
delay(500);
outtextxy(10,205,"Enter your PIN: ");
gotoxy(17,14);
cin>>signpin;
delay(500);
int x,y;
cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(4);
 int c=150;
 for(int e=0;e<15;e++)
 {
  for(int i=50;i<100;i++)
  {
   settextstyle(SMALL_FONT, HORIZ_DIR, 10);
   outtextxy(x,y,"Signing in..");
   settextstyle(SMALL_FONT, HORIZ_DIR, 5);
   outtextxy(x+5,y+5,"  SAP GAMES.. ");
   setcolor(3);
   circle(x,y,i);
   circle(x,y,c);
   c--;
   cleardevice();
  }
 }

signacno=signacno-1;
ifstream file("account.dat",ios::binary|ios::in);
file.seekg(0,ios::beg);
while(!file.eof())
	{
	file.read((char*)&ac[signacno-1],sizeof(ac[signacno-1]));
	   if(ac[signacno-1].return_acno()==signacno && ac[signacno-1].return_pin()==signpin)
	    {
		    outtextxy(400,290,"..You are logged in successfully!!");
		    getch();
		    found=1;
		    interface(signacno);
		    exit(0);
	    }
	}

		if (found==0)
		{
			outtextxy(400,290,"..Invalid Login!! Try Again..");
			getch();
			sign();
		}
		file.close();

}

else if(signch==2)
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

	outtextxy(10,105,"SIGN UP HERE>>>>>>>>>>>>>>>>>>>>>>>");
	signacno=0;

	ifstream fin("account.dat",ios::binary|ios::in|ios::app);
	while(!fin.eof())
	{
	fin.read((char*)&ac[signacno-1],sizeof(ac[signacno-1]));
	ac[signacno-1].return_acno();
	signacno++;
	}
	fin.close();
	signacno=signacno-1;
	ofstream file("account.dat",ios::binary|ios::app);
	ac[signacno-1].create_account(signacno);
	file.write((char*)&ac[signacno-1],sizeof(ac[signacno-1]));
	file.close();
	sign();
}



else
exit(0);

}

//SETTINGs.............................................................................
int modify_acc(int iacno)
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);


setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"UPDATE ACCOUNT:>>>>>>>>>>>>>>>>>>>>>>>");
delay(500);


  fstream File,FileT;
  File.open("account.dat",ios::binary|ios::in);
  FileT.open("temp.dat",ios::binary|ios::out);
  while(File.read((char *) &ac[iacno-1], sizeof(ac[iacno-1])))
  {
   if(ac[iacno-1].return_acno()==iacno)
     {
       ac[iacno-1].modify_account(iacno);
       FileT.write((char*)&ac[iacno-1],sizeof(ac[iacno-1]));
     }
   else
     {
      FileT.write((char*)&ac[iacno-1],sizeof(ac[iacno-1]));
     }
  }

   FileT.close();
   File.close();
   remove("account.dat");
   rename("temp.dat","account.dat");
   return 0;
}



int view_acc(int iacno)
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"YOUR ACCOUNT DETAILS>>>>>>>>>>>>>>>>>>>>>>>");
delay(500);



    ifstream inFile;

    inFile.open("account.dat",ios::binary|ios::in);
    inFile.seekg(ios::beg);
    while(!inFile.eof())
    {
    inFile.read((char*)&ac[iacno-1],sizeof(ac[iacno-1]));
    if(ac[iacno-1].return_acno()==iacno)
      {
	ac[iacno-1].view_account();
	getch();

	break;
      }
    }

inFile.close();
return 0;
}

int delete_acc(int iacno)
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,105,"GOOD BYE!!>>>>>>>>>>>>>>>>>>>>>>>");
delay(500);

	ifstream inFile;
	ofstream outFile;

	inFile.open("account.dat",ios::binary|ios::in);
	outFile.open("Temp.dat",ios::binary|ios::out);
	inFile.seekg(0,ios::beg);
	while(!inFile.eof())
	{   inFile.read((char*)&ac[iacno-1],sizeof(ac[iacno-1]));
	    if(ac[iacno-1].return_acno()!=iacno)
	      { outFile.write((char*)&ac[iacno-1],sizeof(ac[iacno-1]));
	      }
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	getch(); exit(0);
	return 0;
}

void help()
{clrscr(); int hch;

cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

outtextxy(10,95,"HELP MENU:");
delay(500);
outtextxy(10,140,"1.Stone-Paper-Scissor");
delay(500);
outtextxy(10,190,"2.Hangman");
delay(500);
outtextxy(10,240,"3.Tic-Tac-Toe");
delay(500);
outtextxy(10,290,"4.<Return<<<");
delay(500);
setcolor(4);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,315,639,315);
setcolor(15);
outtextxy(10,320,"ENTER YOUR CHOICE:");
delay(500);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
gotoxy(21,21);
cin>>hch;
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);

 if(hch==1)
  {	clrscr(); cout<<endl;
   cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

	cout<<"\n\n\n\n\n\n\n";
	cout<<"|-----------------STONE-PAPER-SCISSOR---------------------|"<<endl;
	cout<<"|Stone â paper â Scissors is a zero-sum hand,             |"<<endl;
	cout<<"|in which player forms one of three shapes with hand.     |"<<endl;
	cout<<"|These shapes are \"stone\" , \"paper\" , and \"scissors\"|"<<endl;
	cout<<"|---------------------------------------------------------|"<<endl;
	getch();

  }
  else if(hch==2)
  {
	clrscr(); cout<<endl;
	cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

	cout<<"\n\n\n\n\n\n\n";
	cout<<"|----------------------------HANGMAN----------------------------|"<<endl;
	cout<<"|Hangman is a word guessing game.Player thinks of a word and    |"<<endl;
	cout<<"|tries to guess it by suggesting letters within a certain       |"<<endl;
	cout<<"|number of guesses.The word to guess is represented by a        |"<<endl;
	cout<<"|row of asterisk symbol(*),representing each letter of the word.|"<<endl;
	cout<<"|If the player fails he will be HANGED!!,hence the name!!       |"<<endl;
	cout<<"|---------------------------------------------------------------|"<<endl;
	getch();
    }
 else if(hch==3)
  {     clrscr(); cout<<endl;
	cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(BOLD_FONT, HORIZ_DIR, 5);
outtextxy(20,10,"<< SAP GAMES >>");
setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
delay(500);
line(0,95,639,95);

setcolor(10);
setlinestyle(DASHED_LINE,SOLID_FILL,THICK_WIDTH);
line(0,350,639,350);
setcolor(4);
delay(200);
setlinestyle(SOLID_LINE,SOLID_FILL,NORM_WIDTH);
line(0,370,639,370);
delay(500);
setcolor(12);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

	cout<<"\n\n\n\n\n\n\n";
	cout<<"|---------------------------TIC-TAC-TOE-----------------------|"<<endl;
	cout<<"|Tic-tac-toe (also known Xs and Os) is a game for two players,|"<<endl;
	cout<<"|X and O, who take turns marking the spaces in a 3X3 grid.   |"<<endl;
	cout<<"|The player who succeeds in placing three of their marks in a |"<<endl;
	cout<<"|horizontal, vertical, or diagonal row wins the game.         |"<<endl;
	cout<<"|-------------------------------------------------------------|"<<endl;
	getch();
   }

}

void StonePaperScissor()
{
intro_s();
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);

int user,pc=0,score=0;
randomize();

outtextxy(20,10,"..............STONE<>PAPER<>SCISSOR.............");
delay(500);
outtextxy(20,50,"Game info......");
delay(500);
setcolor(7);
outtextxy(20,100,"0-Stone");
setcolor(14);
outtextxy(20,150,"1-Paper");
setcolor(4);
outtextxy(20,200,"2-Scissor");
delay(500);
setcolor(11);
outtextxy(20,250,"Use the 0,1,2 KEYS to execute the required action!");
delay(500);
outtextxy(20,300,"Press any key to start the game....");
getch();
delay(500);
clrscr();

while(score<3 && score>-3)
{
clrscr();
cleardevice();
setbkcolor(0);

cout<<"Enter your particle:";
cin>>user;
pc=random(3);
score=match(user,pc,score);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Your Score:";
cout<<score;
getch();
}

clrscr();
if(score==3)
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(SMALL_FONT, HORIZ_DIR, 10);
delay(200);
outtextxy(200,200,"You Won The Game!!!");
delay(500);
getch();
}
else
{
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(SMALL_FONT, HORIZ_DIR, 8);
delay(200);
outtextxy(50,150,"SORRY!! You have been defeated!!");
delay(500);
getch();
}
}

int match(int user,int pc,int x)
{
if(user==0 && pc==0)
{
setcolor(7);outtextxy(10,100,"Your Choice:0-STONE");
delay(500);
setcolor(7);outtextxy(10,150,"PC Choice:0-STONE");
delay(500);
setcolor(11);outtextxy(10,200,"DRAW!!");
delay(500);
}

else if(user==0 && pc==1)
{
setcolor(7);outtextxy(10,100,"Your Choice:0-STONE");
delay(500);
setcolor(14);outtextxy(10,150,"PC Choice:1-PAPER");
delay(500);
setcolor(11);outtextxy(10,200,"Stone got CAUGHT!!");
delay(500);
x--;
}

else if(user==0 && pc==2)
{
setcolor(7);outtextxy(10,100,"Your Choice:0-STONE");
delay(500);
setcolor(4);outtextxy(10,150,"PC Choice:2-SCISSOR");
delay(500);
setcolor(11);outtextxy(10,200,"Stone HIT scissor!!");
delay(500);
x++;
}

else if(user==1 && pc==0)
{
setcolor(14);outtextxy(10,100,"Your Choice:1-PAPER");
delay(500);
setcolor(7);outtextxy(10,150,"PC Choice:0-STONE");
delay(500);
setcolor(11);outtextxy(10,200,"Paper CAPTURED stone!!");
delay(500);
x++;
}

else if(user==1 && pc==1)
{
setcolor(14);outtextxy(10,100,"Your Choice:1-PAPER");
delay(500);
setcolor(14);outtextxy(10,150,"PC Choice:1-PAPER");
delay(500);
setcolor(11);outtextxy(10,200,"DRAW!!");
delay(500);
}

else if(user==1 &&  pc==2)
{
setcolor(14);outtextxy(10,100,"Your Choice:1-PAPER");
delay(500);
setcolor(4);outtextxy(10,150,"PC Choice:2-SCISSOR");
delay(500);
setcolor(11);outtextxy(10,200,"PAPER got CUT!!");
delay(500);
x--;
}

else if(user==2 && pc==0)
{
setcolor(4);outtextxy(10,100,"Your Choice:2-SCISSOR");
delay(500);
setcolor(7);outtextxy(10,150,"PC Choice:0-STONE");
delay(500);
setcolor(11);outtextxy(10,200,"Scissor got HIT");
delay(500);
x--;
}

else if(user==2 && pc==1)
{
setcolor(4);outtextxy(10,100,"Your Choice:2-SCISSOR");
delay(500);
setcolor(14);outtextxy(10,150,"PC Choice:1-PAPER");
delay(500);
setcolor(11);outtextxy(10,200,"Scissor CUT paper!!");
delay(500);
x++;
}

else if(user==2 && pc==2)
{
setcolor(4);outtextxy(10,100,"Your Choice:2-SCISSOR");
delay(500);
setcolor(4);outtextxy(10,150,"PC Choice:2-SCISSOR");
delay(500);
setcolor(11);outtextxy(10,200,"DRAW!!");
delay(500);
}
return x;
}


void Hangman()
{
intro_h();
clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(SMALL_FONT, HORIZ_DIR, 5);
delay(200);


	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"dhoni",
		"maxwell",
		"steyn",
		"clarke",
		"smith",
		"afridi",
		"cook",
		"root",
		"bumrah",
		"ashwin"
	};


	randomize();
	int n=random(10);
	strcpy(word,words[n]);


	initUnknown(word, unknown);


	outtextxy(20,10,"..............Welcome to hangman.............");
	delay(500);
	outtextxy(20,50,"Guess a cricket player Name");
	delay(500);
	outtextxy(20,100,"Each letter is represented by a *(ashtrick)");
	delay(500);
	outtextxy(20,150,"You have to type only one letter in one try");
	delay(500);
	outtextxy(20,200,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	delay(500);
	getch();

	while (num_of_wrong_guesses < MAX_TRIES)
	{
			clrscr();
			cleardevice();
			setbkcolor(0);
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;

		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
    cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		
		if (strcmp(word, unknown) == 0)
		{       clrscr();
			cleardevice();
			setbkcolor(7);
	     cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe word was : " << word << endl;
		 settextstyle(1,HORIZ_DIR,3);setbkcolor(0);setcolor(3);
		outtextxy(175,200, "Yeah! You got it!");
			break;
		}

	getch();
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{               clrscr();
			cleardevice();
		      settextstyle(1,HORIZ_DIR,3);setbkcolor(0);setcolor(3);
		outtextxy(175,200,"Sorry,you lose...you've been hanged." );
		cout<< endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe word was : " << word << endl;
	}
	getch();

}

int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{

		if (guess == guessword[i])
			return 0;

		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}


int checkwin(char square[])
{

	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}



void board(char square[])
{

clrscr();
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(SMALL_FONT, HORIZ_DIR, 10);
delay(200);


	outtextxy(200,10,"Tic Tac Toe");
	delay(100);
	cout<<"\n\n\n\n\n\n\n\n\n";
	setcolor(4); settextstyle(SMALL_FONT, HORIZ_DIR, 7);
	outtextxy(175,100,"Player 1 (X)  -  Player 2 (O)");
	cout << endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t" << "     |     |     " << endl;
	cout<<"\t\t\t\t" << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout<<"\t\t\t\t" << "_____|_____|_____" << endl;
	cout<<"\t\t\t\t" << "     |     |     " << endl;
	cout<<"\t\t\t\t" << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout<<"\t\t\t\t" << "_____|_____|_____" << endl;
	cout<<"\t\t\t\t" << "     |     |     " << endl;
	cout<<"\t\t\t\t" << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout<<"\t\t\t\t" << "     |     |     " << endl << endl;
}
void TicTacToe()
{
intro_t();
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int player = 1,it,choice;
char mark;
clrscr();
cleardevice();
setbkcolor(13);

	clrscr();
	do
	{
		board(square);
		player=(player%2)?1:2;
		cout << "\t\t\tPlayer " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			getch();
		}
		it=checkwin(square);
		player++;
	}while(it==-1);
	board(square);
	if(it==1)
			cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";
	getch();

}

//intro functions...........................................................

void intro_t()
{  int i,j;
   clrscr();
   cleardevice();
   setbkcolor(BLACK);
   gotoxy (25,12);
   settextstyle(1,HORIZ_DIR,7);
   for(i=0;i<=3;i++)
   {
   setcolor(i%16);
   outtextxy(2,2,"   Tic-Tac-Toe   ");
   settextstyle(1,HORIZ_DIR,7);
   outtextxy(20,200,"");
   delay(100);
   outtextxy(180,200,"X");
   delay(100);
   outtextxy(220,200,"O");
   delay(100);
   outtextxy(260,200,"X");
   delay(100);
   outtextxy(180,300,"O");
   delay(100);
   outtextxy(220,300,"X");
   delay(100);
   outtextxy(260,300,"O");
   delay(100);
   outtextxy(180,400,"X");
   delay(100);
   outtextxy(220,400,"O");
   delay(100);
   outtextxy(260,400,"X");
   delay(100);
   delay(1000);
}
}

void intro_h()
{  int i,j;
   clrscr();
   cleardevice();
   setbkcolor(BLACK);
   gotoxy (25,12);
   settextstyle(1,HORIZ_DIR,7);
   for(i=0;i<=3;i++)
   {
   setcolor(i%16);
   outtextxy(2,2,"   Hang-Man   ");
   settextstyle(1,HORIZ_DIR,7);
   outtextxy(20,200,"");
   delay(100);
   outtextxy(180,200,"A");
   delay(100);
   outtextxy(220,200,"C");
   delay(100);
   outtextxy(260,200,"E");
   delay(100);
   outtextxy(180,300,"F");
   delay(100);
   outtextxy(220,300,"P");
   delay(100);
   outtextxy(260,300,"R");
   delay(100);
   outtextxy(180,400,"O");
   delay(100);
   outtextxy(220,400,"X");
   delay(100);
   outtextxy(260,400,"Z");
   delay(100);
   delay(1000);
}
}

void intro_s()
{  int i,j;
   clrscr();
   cleardevice();
   setbkcolor(BLACK);
   gotoxy (25,12);
   settextstyle(1,HORIZ_DIR,7);
   for(i=0;i<=3;i++)
   {
   setcolor(i%16);
   outtextxy(2,2,"StonePaperScissor");
   settextstyle(1,HORIZ_DIR,7);
   outtextxy(20,200,"");
   delay(100);
   outtextxy(180,200,"0");
   delay(100);
   outtextxy(220,200,"1");
   delay(100);
   outtextxy(260,200,"2");
   delay(100);
   outtextxy(180,300,"O");
   delay(100);
   outtextxy(220,300,"1");
   delay(100);
   outtextxy(260,300,"2");
   delay(100);
   outtextxy(180,400,"0");
   delay(100);
   outtextxy(220,400,"1");
   delay(100);
   outtextxy(260,400,"2");
   delay(100);
   delay(1000);
}
}






/*
CREDITS....................................................................
<<SAP>>GAMES, C++ project created by Santhosh, Ashwanth and Praveen.
2017.V.10.2
...........................................................................
*/

