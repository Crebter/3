#include<stdio.h>
#include<stdlib.h> 
#include "LQueue.h"
#define INT 1
#define CHAR 2
#define DOUBLE 3
extern int data_type;//�����ⲿ����

void menu()
{
 	printf("***************˳����е���ʾ******************\n");
    printf("*   1.��ʼ������             6.���   	      *\n");
    printf("*   2.���ٶ���               7.����           *\n");
    printf("*   3.�ж϶����Ƿ��         8.��ն���       *\n");
    printf("*   4.��ȡ����ͷ             9.������������   *\n");
    printf("*   5.��ѯ���г���           10.�˳�          *\n");  
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

	//������ӵ�Ϊ��ͷ�����βָ��ͷ���
	if (Q->front->next == NULL)
		Q->rear = Q->front;

	free(need_delete_node);
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue *Q)
{
	while (Q->rear != Q->front)//ʣ��ͷ���
	{
		DeLQueue(Q);
	}
		printf("��ճɹ���");
		Sleep(500);
		system("CLS"); 
		return;
}

Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q))
{
	if(IsEmptyLQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;	
	}
	else
	{
		Node * temp;
		temp = Q->front;
		printf("���е�Ԫ���У�"); 
		while (temp != Q->rear)
		{
			temp = temp->next;//��ͷ���֮��ʼ
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
