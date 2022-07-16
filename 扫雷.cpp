#include<bits/stdc++.h>
#include<time.h>
#include<windows.h> 
using namespace std;
int flag=0,aaa=0;
void menu()
{
	cout<<"**********************"<<endl;
	cout<<"***1.play****2.exit***"<<endl;
	cout<<"**********************"<<endl;
}
void initboard(char(*board)[11],char set)
{
	for (int i=1;i<=10;i++)
	    for (int j=1;j<=10;j++)
	      board[i][j]=set;
}
void  displayboard(char(*board)[11])
{
	for (int i=0;i<=10;i++)
	{
		if (i==0)
		    cout<<"   ";
		else
		    printf("%d ",i);
	}
	printf("\n");
	for (int i=1;i<=10;i++)
	{
		if (i==10)
	  	    printf("%d ",i);
	  	else
	  	    printf("%d  ",i);
	  	for (int j=1;j<=10;j++)
	  	    printf("%c ",board[i][j]);
	  	printf("\n");
    }
}
void setmine(char (*board)[11])
{
	int count=10;
	while (count)
	{
		int x=rand()%10+1;
		int y=rand()%10+1;
		if (board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
	}
}
int getmine(char (*board)[11],int x,int y)
{
	int count=0;
	for (int i=x-1;i<=x+1;i++)
	  for (int j=y-1;j<=y+1;j++)
	  {
	  	if (board[i][j]=='1')
	  	    count++;
	  }
	return count;
}
void playmove(char (*mine)[11],char (*show)[11])
{
	int x,y;
	int win=0;
	printf("请输入坐标 -> ");
	while (win<90)
	{
		scanf("%d %d",&x,&y);
		getchar();
		printf("坐标为 %d %d\n",x,y);
		if (x>=1&&x<=10&&y>=1&&y<=10)
        {
    	    if (mine[x][y]=='1')
    	    {
    		    show[x][y]='x';
    		    flag=1;
    		    break;
		    }
		    else
		    {
			    int count=getmine(mine,x,y);
			    show[x][y]=count+'0';
			    displayboard(show);
			    win++;
		    }
	    }
	    else
		    printf("输入坐标超出边界，请重新输入！\n");
	}
	if (win==90)
	{
		printf("恭喜你，游戏通关\n");
		aaa=1;
	}
}
void game()
{
	//getchar();
	char show[11][11]={0},mine[11][11]={0}; 
	initboard(mine,'0');//电脑后台棋盘（0为空 1为雷） 
	initboard(show,'#');//玩家棋盘（#初始） 
	displayboard(show);
	//displayboard(mine);
	setmine(mine);//设置雷 
	displayboard(mine);
	while (1)
	{
		playmove(mine,show);
		Sleep(1000);
		displayboard(show);
	    if (flag==1)
	    {
	    	printf("\n哎呀，你被炸死了~\n");
    		printf("游戏结束\n\n");
	    	flag=0;
	    	return;
		}
		if (aaa=1)
		{
			aaa=0;
			break;
		}
	}
}
void test()
{
	int n;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择 ->");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\n");
		        printf("游戏即将开始\n棋盘大小：10 X 10\n雷数：10个\n\n");
				game();
				break;
			case 2:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	}while(n);
}
int main ()
{
	while(1)
	{
	    test();
	}
	return 0;
 } 
