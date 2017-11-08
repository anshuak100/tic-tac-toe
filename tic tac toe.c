#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include<string.h>

//user
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
char squar[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
//computer
int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;
//user
int checkwin();
void diagram();
void user();
//computer
void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);
 COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//present in windows.h
}
void shivam();



 int main()
{


    shivam();



		return 0;
}

//user

void user()
{
	int player=1,i,choice;
    char mark;
    system("cls");
    do{
        diagram();
        player=(player%2)?1:2;
        printf("\t\tplayer %d  Enter position (1 to 9) : ",player);
        //printf("  Enter a number : ");
        scanf("%d",&choice);
        mark=(player==1)?'X':'O';
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
			printf("\nInvalid move ");
			player--;
			getch();
		}
		squar[choice]=square[choice];
		i=checkwin();
		player++;
	}while(i==-1);
    diagram();
	if(i==1){
		printf("\n\t\t==>\aPlayer %d win",--player);
		getch();
		shivam();
	}
	else{
		printf("\n\t\t==>\aGame draw");
		getch();
		shivam();
    }
	getch();
}


int checkwin()
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


void diagram()
{
	system("cls");
	printf("\n\n\t\t\tTic Tac Toe\n\n");
	printf("\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");

	printf("\t\t\t   |   |   \n");
	printf("\t\t\t %c | %c | %c \n",squar[1],squar[2],squar[3]);
	printf("\t\t\t___|___|___\n");
    printf("\t\t\t   |   |   \n");
    printf("\t\t\t %c | %c | %c \n",squar[4],squar[5],squar[6]);
    printf("\t\t\t___|___|___\n");
    printf("\t\t\t   |   |   \n");
    printf("\t\t\t %c | %c | %c \n",squar[7],squar[8],squar[9]);
    printf("\t\t\t   |   |   \n");
}








//comp

void menu()
{
 int choice;
 system("cls");
 printf("\n--------MENU--------");
 printf("\n1 : Play with X");
 printf("\n2 : Play with O");
 printf("\n3 : Main menu");
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 turn = 1;
 switch (choice)
 {
  case 1:
   player = 1;
   comp = 0;
   player_first();
   break;
  case 2:
   player = 0;
   comp = 1;
   start_game();
   break;
  case 3:
    shivam();

  default:
    system("cls");
   menu();
 }
}

int make2()
{
 if(board[5] == 2)
  return 5;
 if(board[2] == 2)
  return 2;
 if(board[4] == 2)
  return 4;
 if(board[6] == 2)
  return 6;
 if(board[8] == 2)
  return 8;
 return 0;
}

int make4()
{
 if(board[1] == 2)
  return 1;
 if(board[3] == 2)
  return 3;
 if(board[7] == 2)
  return 7;
 if(board[9] == 2)
  return 9;
 return 0;
}

int posswin(int p)
{
// p==1 then X   p==0  then  O
 int i;
 int check_val,pos;

 if(p == 1)
  check_val = 18;
 else
  check_val = 50;

 i = 1;
 while(i<=9)//row check
 {
  if(board[i] * board[i+1] * board[i+2] == check_val)
  {
   if(board[i] == 2)
    return i;
   if(board[i+1] == 2)
    return i+1;
   if(board[i+2] == 2)
    return i+2;
  }
  i+=3;
 }

 i = 1;
 while(i<=3)//column check
 {
  if(board[i] * board[i+3] * board[i+6] == check_val)
  {
   if(board[i] == 2)
    return i;
   if(board[i+3] == 2)
    return i+3;
   if(board[i+6] == 2)
    return i+6;
  }
  i++;
 }

 if(board[1] * board[5] * board[9] == check_val)
 {
  if(board[1] == 2)
   return 1;
  if(board[5] == 2)
   return 5;
  if(board[9] == 2)
   return 9;
 }

 if(board[3] * board[5] * board[7] == check_val)
 {
  if(board[3] == 2)
   return 3;
  if(board[5] == 2)
   return 5;
  if(board[7] == 2)
   return 7;
 }
 return 0;
}

void go(int n)
{
 if(turn % 2)
  board[n] = 3;
 else
  board[n] = 5;
 turn++;
}

void player_first()
{
 int pos;

 check_draw();
 draw_board();
 gotoxy(30,18);
 printf("Enter ur position (1-9) :> ");
 scanf("%d",&pos);

 if(board[pos] != 2)
  player_first();

 if(pos == posswin(player))
 {
  go(pos);
  draw_board();
  gotoxy(30,20);
  //textcolor(128+RED);
  printf("Player Wins");
  getch();
  shivam();
 }

 go(pos);
 draw_board();
 start_game();
}

void start_game()
{
 // p==1 then X   p==0  then  O
 if(posswin(comp))
 {
  go(posswin(comp));
  flag = 1;
 }
 else
 if(posswin(player))
  go(posswin(player));
 else
 if(make2())
  go(make2());
 else
  go(make4());
 draw_board();

 if(flag)
 {
  gotoxy(30,20);
  //textcolor(128+RED);
  printf("Computer wins");
  getch();
  shivam();
 }
 else
  player_first();
}

void check_draw()
{
 if(turn > 9)
 {
  gotoxy(30,20);
  //textcolor(128+RED);
  printf("Game Draw");
  getch();
  shivam();
  //exit(0);
 }
}

void draw_board()
{
 int j;
 system("cls");
printf("\n\n\n\n\t\t\t       tic tac toe game\n\n\t\t\t      player vs computer");

 for(j=9;j<17;j++)
 {
  gotoxy(35,j);
  printf("|       |");
 }
 gotoxy(28,11);
 printf("-----------------------");
 gotoxy(28,14);
 printf("-----------------------");

 for(j=1;j<10;j++)
 {
  if(board[j] == 3)
   put_X_O('X',j);
  else if(board[j] == 5)
   put_X_O('O',j);
 }
}

void put_X_O(char ch,int pos)
{
 int m;
 int x = 31, y = 10;

 m = pos;

 if(m > 3)
 {
  while(m > 3)
  {
   y += 3;
   m -= 3;
  }
 }
 if(pos % 3 == 0)
  x += 16;
 else
 {
  pos %= 3;
  pos--;
  while(pos)
  {
   x+=8;
   pos--;
  }
 }
 gotoxy(x,y);
 printf("%c",ch);
}
void shivam()
{
    int a;
    int i;
    for(i=0;i<10;i++)
    {
        board[i]=2;
        squar[i]=' ';
    }
    square[0]='0';
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
    system("cls");
    printf("1. PLAY WITH COMPUTER.\n");
	printf("2. PLAY WITH USER.\n");
	printf("3. Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&a);
	if(a==1)
	{
		//system("cls");
		menu();
		getch();
	}
	else if(a==2)
	{
		//system("cls");
		user();

	}
	else if(a==3)
    {
        exit(0);
    }
	else
    {

		printf("\nInvalid Input");
		shivam();
    }
}
