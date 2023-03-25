#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=20, height=20,gameOver;
int x,y,fruitX,fruitY,score,flag;
void setup()
{
    gameOver=0;
    x=width/2;
    y=height/2;

    lebel1:
    fruitX=rand()%20;
    if(fruitX==0)
        goto lebel1;
    lebel2:
    fruitY=rand()%20;
    if(fruitY==0)
        goto lebel2;
        score=0;
}
void draw()
{
    int i,j;
    system("cls");
    for(i=0; i<width; i++)
    {
         for(j=0; j<height; j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
            printf("*");
            }
        else
        {
            if(i==x && j==y)
                printf("O");
            else if(i==fruitX && j==fruitY)
                printf("F");
            else

            printf(" ");
        }
        }
        printf("\n");
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'z':
            flag=4;
            break;
        case 'x':
            gameOver=1;
            break;
        }
    }
}
void MakeLogic()
{
    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;

    default:
        break;

    }
    if(x<0 || x>width || y<0 || y>height)
    gameOver=1;
    if(x==fruitX && y==fruitY)
    {
        lebel3:
    fruitX=rand()%20;
    if(fruitX==0)
        goto lebel3;
    lebel4:
    fruitY=rand()%20;
    if(fruitY==0)
        goto lebel4;
        score+=10;
    }
}
int main()
{
    int m,n;
    setup();
    while(!gameOver)
    {
        draw();
        input();
        MakeLogic();
        for(m=0; m<1000; m++)
        {
            for(n=0; n<10000; n++)
            {

            }
        }
    }

    return 0;

}
