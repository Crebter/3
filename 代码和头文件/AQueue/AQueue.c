#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AQueue.h" 
extern int data_type;

#define INT 1
#define CHAR 2
#define DOUBLE 3


void menu()
{
 	printf("***************顺序队列的演示*******************\n");
    printf("*   1.初始化队列              6.查询队列长度   *\n");
    printf("*   2.销毁队列                7.入队 	       *\n");
    printf("*   3.判断队列是否满          8.出队           *\n");
    printf("*   4.判断队列是否空          9.清空队列       *\n");
    printf("*   5.获取队列头              10.重置数据类型  *\n"); 
    printf("************************************************\n");
}
//初始化 
void InitAQueue(AQueue *Q)
{
	Q->length = 0; 
	Q->front = 0; 
	Q->rear = 0;
}

//销毁
void DestoryAQueue(AQueue *Q)
{	
	free(Q);
} 


//判断是否为满队列
Status IsFullAQueue(const AQueue *Q)
{	

	return (Q->front == (Q->rear+1)%MAXQUEUE ? TRUE : FALSE );	
} 


//判断是否为空队列 
Status IsEmptyAQueue(const AQueue *Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
} 


//获取队头
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(IsEmptyAQueue(Q) || NULL == Q)  
		return FALSE;
	else
	{
		if (data_type == INT)
			*(int *)e = *(int *)Q->data[Q->front];
		else if (data_type == CHAR)
			*(char *)e = *(char *)Q->data[Q->front];	
		else if (data_type == DOUBLE)
			*(double *)e = *(double *)Q->data[Q->front];
		return TRUE;
	}
} 

//获取队列长度 
int LengthAQueue(AQueue *Q)
{	
	return Q->length;
} 


//插入队列 
Status EnAQueue(AQueue *Q, void *data)
{

	if(IsFullAQueue(Q) || NULL == Q)
	{	
		return FALSE;//满了 
	}
	else
	{
		
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->length++;
	    return TRUE;
	}
	
}

//出队
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q) == TRUE)
		return FALSE;	
	else
	{
		Q->front = (Q->front+1)%MAXQUEUE;
		Q->length--;
		return TRUE;	
	} 
} 


//清空队列
void ClearAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列已经为空！");
		Sleep(500);
		system("CLS"); 
		return;		
	}
	else
	{
		Q->front = 0; 
		Q->rear = 0;
		Q->length = 0;
		printf("清空成功！");
		Sleep(500);
		system("CLS"); 
		return;
	}
	
} 


//遍历队列 
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;	
	}
	else
	{	
		printf("队列的元素值有：\n"); 
		int t = Q->front;
		while(t != Q->rear)
		{
			foo(Q->data[t]);
			t = (t + 1) % MAXQUEUE; 	
		}
		printf("\n"); 
		return TRUE;	
	}	
}	


//打印元素
void APrint(void *q)
{	
	if (data_type == INT)
		printf("%d<-", *(int *)q);
	if (data_type == CHAR)
		printf("%c<-", *(char *)q);
	if (data_type == DOUBLE)
		printf("%.2f<-", *(double *)q);
} 
