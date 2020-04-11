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
 	printf("***************˳����е���ʾ*******************\n");
    printf("*   1.��ʼ������              6.��ѯ���г���   *\n");
    printf("*   2.���ٶ���                7.��� 	       *\n");
    printf("*   3.�ж϶����Ƿ���          8.����           *\n");
    printf("*   4.�ж϶����Ƿ��          9.��ն���       *\n");
    printf("*   5.��ȡ����ͷ              10.������������  *\n"); 
    printf("************************************************\n");
}
//��ʼ�� 
void InitAQueue(AQueue *Q)
{
	Q->length = 0; 
	Q->front = 0; 
	Q->rear = 0;
}

//����
void DestoryAQueue(AQueue *Q)
{	
	free(Q);
} 


//�ж��Ƿ�Ϊ������
Status IsFullAQueue(const AQueue *Q)
{	

	return (Q->front == (Q->rear+1)%MAXQUEUE ? TRUE : FALSE );	
} 


//�ж��Ƿ�Ϊ�ն��� 
Status IsEmptyAQueue(const AQueue *Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
} 


//��ȡ��ͷ
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

//��ȡ���г��� 
int LengthAQueue(AQueue *Q)
{	
	return Q->length;
} 


//������� 
Status EnAQueue(AQueue *Q, void *data)
{

	if(IsFullAQueue(Q) || NULL == Q)
	{	
		return FALSE;//���� 
	}
	else
	{
		
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->length++;
	    return TRUE;
	}
	
}

//����
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


//��ն���
void ClearAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("�����Ѿ�Ϊ�գ�");
		Sleep(500);
		system("CLS"); 
		return;		
	}
	else
	{
		Q->front = 0; 
		Q->rear = 0;
		Q->length = 0;
		printf("��ճɹ���");
		Sleep(500);
		system("CLS"); 
		return;
	}
	
} 


//�������� 
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;	
	}
	else
	{	
		printf("���е�Ԫ��ֵ�У�\n"); 
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


//��ӡԪ��
void APrint(void *q)
{	
	if (data_type == INT)
		printf("%d<-", *(int *)q);
	if (data_type == CHAR)
		printf("%c<-", *(char *)q);
	if (data_type == DOUBLE)
		printf("%.2f<-", *(double *)q);
} 
