#include<stdio.h>
#include<stdlib.h> 
#include "LQueue.h"
#define INT 1
#define CHAR 2
#define DOUBLE 3
extern int data_type;//引用外部变量

void menu()
{
 	printf("***************顺序队列的演示******************\n");
    printf("*   1.初始化队列             6.入队   	      *\n");
    printf("*   2.销毁队列               7.出队           *\n");
    printf("*   3.判断队列是否空         8.清空队列       *\n");
    printf("*   4.获取队列头             9.重置数据类型   *\n");
    printf("*   5.查询队列长度           10.退出          *\n");  
    printf("***********************************************	\n");
}

void InitLQueue(LQueue *Q)
{
	Node *head;
	head = (Node *)malloc(sizeof(Node));
	Q->front = head;
	Q->rear = head;
	Q->length = 0;
}

void DestoryLQueue(LQueue *Q)
{
	free(Q);
}

Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (Q == NULL)
		return FALSE;
	if (IsEmptyLQueue(Q) == TRUE)
		return FALSE;

	if (data_type == INT)
		*(int *)e = *(int *)Q->front->next->data;
	else if (data_type == DOUBLE)
		*(double *)e = *(double *)Q->front->next->data;
	else if (data_type == CHAR)
		*(char *)e = *(char *)Q->front->next->data;

	return TRUE;
}

int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		return FALSE;
	newnode->data = data;
	newnode->next = NULL;
	Q->rear->next = newnode;
	Q->rear = newnode;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q) == TRUE)
		return FALSE;

	Node *need_delete_node;
	need_delete_node = Q->front->next;
	Q->front->next = need_delete_node->next;

	//如果出队的为队头，则队尾指向头结点
	if (Q->front->next == NULL)
		Q->rear = Q->front;

	free(need_delete_node);
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue *Q)
{
	while (Q->rear != Q->front)//剩下头结点
	{
		DeLQueue(Q);
	}
		printf("清空成功！");
		Sleep(500);
		system("CLS"); 
		return;
}

Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q))
{
	if(IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;	
	}
	else
	{
		Node * temp;
		temp = Q->front;
		printf("队列的元素有："); 
		while (temp != Q->rear)
		{
			temp = temp->next;//从头结点之后开始
			foo(temp->data);
		}
		printf("\n");
		return TRUE;
	}
	
}

void LPrint(void *q)
{
	if (data_type == INT)
		printf("%d<-", *(int *)q);
	else if (data_type == CHAR)
		printf("%c<-", *(char *)q);
	else if (data_type == DOUBLE)
		printf("%.2f<-", *(double *)q);
}
