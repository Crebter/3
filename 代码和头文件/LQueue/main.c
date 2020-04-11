#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LQueue.h"

#define YES 1 	//已经初始化
#define NO 0 	//未初始化 
#define INT 1
#define CHAR 2
#define DOUBLE 3
int data_type = 0;
int main(int argc, char *argv[]) {
	
	int choice;//选择菜单 
	int ISINIT = NO;
	void *queue_data = (void*)malloc(sizeof(void*));//队列元素 
	LQueue *Q = (LQueue*)malloc(sizeof(LQueue));

		
	//决定队列数据类型
	printf("请问您需要什么类型的元素？\n");
	printf("1、整型 2、字符型 3、浮点型\n");
	while (scanf("%d", &data_type) != 1 || data_type < 1 || 3 < data_type)
	{
		while (getchar() != '\n');
		printf("\n非法输入！请重新输入！\n");
	}
	while (getchar() != '\n');//清理内存池
	system("CLS");//清屏
	
	while(1)
	{
		menu();//菜单显示 
		if (ISINIT == YES)//如果链表已经初始化了 
		{
			TraverseLQueue(Q, LPrint);//遍历队列 
		}
		printf("请输入您的指令:");
		while (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n');
			printf("\n您输入的不是整数！请重新输入！\n");
		}
		while (getchar() != '\n');//清理内存池
		system("CLS");//读取之后清屏
		
	
		switch(choice)
		{
			case 1:	//初始化队列 
				InitLQueue(Q);
				ISINIT = YES;
				printf("初始化成功！\n"); 
				Sleep(1000);
				break;
			case 2://销毁队列
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}	
				DestoryLQueue(Q);
				printf("销毁成功！\n"); 
				ISINIT = NO;           //设置为未初始化 
				Sleep(1000);
				break;
			case 3:	//判断是否为空 
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				
				if(TRUE == IsEmptyLQueue(Q))
					printf("队列为空！\n");
				else
					printf("队列不是空！\n");
				Sleep(1000);
				break;
			case 4:  //获得队头元素 
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if (GetHeadLQueue(Q, queue_data) == TRUE)
				{
					//判断数据类型进行输出
					if (data_type == INT)
						printf("获取数据成功！队头数据为%d", *(int *)queue_data);
					else if (data_type == CHAR)
						printf("获取数据成功！队头数据为%c", *(char *)queue_data);
					else if (data_type == DOUBLE)
						printf("获取数据成功！队头数据为%.2f", *(double *)queue_data);
				}
				else
					printf("获取数据失败");
					Sleep(1000);
					system("CLS"); 
				break;
			case 5:   //获得长度 
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				else 
					printf("当前队列的长度为：%d",LengthLQueue(Q)); 
					system("CLS");
				Sleep(1000);
				break;
			case 6:  //入队 
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if (data_type == INT)
				{
					queue_data = (int *)malloc(sizeof(int));
					printf("请输入要入队的值："); 
					while (scanf("%d", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n输入非法！请重新输入！\n");
					}
				}
				
				if (data_type == CHAR)
				{
					queue_data = (char *)malloc(sizeof(char));
					printf("请输入要入队的值：");
					while (scanf("%c", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n输入非法！请重新输入！\n");
					}
				}
				
				if (data_type == DOUBLE)
				{
					queue_data = (double *)malloc(sizeof(double));
					printf("请输入要入队的值：");
					while (scanf("%lf", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n输入非法！请重新输入！\n");
					}
				}
				
				if(EnLQueue(Q,queue_data) == TRUE)
					printf("入队成功！\n");
				else	 
					printf("入队失败！\n");
				break;	
				
			case 7:
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if(DeLQueue(Q) == TRUE)
					printf("出队成功！\n");
				else
					printf("出队失败！\n");
				break;
			case 8:
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				ClearLQueue(Q);
				break;
			case 9:
				if (ISINIT == NO)
				{
					printf("请先初始化队列！\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				printf("请问您需要什么类型的元素？\n");
				printf("1、整型 2、字符型 3、浮点型\n");
				while (scanf("%d", &data_type) != 1 || data_type < 1 || 3 < data_type)
				{
					while (getchar() != '\n');
					printf("\n非法输入！请重新输入！\n");
				}
				while (getchar() != '\n');//清理内存池
				system("CLS");//清屏
	
				if (ISINIT = YES)
					DestoryLQueue(Q);
				ISINIT = NO;
				printf("重置成功！");
				system("CLS");
				break;
			case 10:
				exit(0);						
			default :
				printf("您的输入有误，请重新输入!\n");
				Sleep(1000); 
				fflush(stdin);
		}
	}	
	
	return 0;
}
