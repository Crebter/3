#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LQueue.h"

#define YES 1 	//�Ѿ���ʼ��
#define NO 0 	//δ��ʼ�� 
#define INT 1
#define CHAR 2
#define DOUBLE 3
int data_type = 0;
int main(int argc, char *argv[]) {
	
	int choice;//ѡ��˵� 
	int ISINIT = NO;
	void *queue_data = (void*)malloc(sizeof(void*));//����Ԫ�� 
	LQueue *Q = (LQueue*)malloc(sizeof(LQueue));

		
	//����������������
	printf("��������Ҫʲô���͵�Ԫ�أ�\n");
	printf("1������ 2���ַ��� 3��������\n");
	while (scanf("%d", &data_type) != 1 || data_type < 1 || 3 < data_type)
	{
		while (getchar() != '\n');
		printf("\n�Ƿ����룡���������룡\n");
	}
	while (getchar() != '\n');//�����ڴ��
	system("CLS");//����
	
	while(1)
	{
		menu();//�˵���ʾ 
		if (ISINIT == YES)//��������Ѿ���ʼ���� 
		{
			TraverseLQueue(Q, LPrint);//�������� 
		}
		printf("����������ָ��:");
		while (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n');
			printf("\n������Ĳ������������������룡\n");
		}
		while (getchar() != '\n');//�����ڴ��
		system("CLS");//��ȡ֮������
		
	
		switch(choice)
		{
			case 1:	//��ʼ������ 
				InitLQueue(Q);
				ISINIT = YES;
				printf("��ʼ���ɹ���\n"); 
				Sleep(1000);
				break;
			case 2://���ٶ���
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}	
				DestoryLQueue(Q);
				printf("���ٳɹ���\n"); 
				ISINIT = NO;           //����Ϊδ��ʼ�� 
				Sleep(1000);
				break;
			case 3:	//�ж��Ƿ�Ϊ�� 
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				
				if(TRUE == IsEmptyLQueue(Q))
					printf("����Ϊ�գ�\n");
				else
					printf("���в��ǿգ�\n");
				Sleep(1000);
				break;
			case 4:  //��ö�ͷԪ�� 
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if (GetHeadLQueue(Q, queue_data) == TRUE)
				{
					//�ж��������ͽ������
					if (data_type == INT)
						printf("��ȡ���ݳɹ�����ͷ����Ϊ%d", *(int *)queue_data);
					else if (data_type == CHAR)
						printf("��ȡ���ݳɹ�����ͷ����Ϊ%c", *(char *)queue_data);
					else if (data_type == DOUBLE)
						printf("��ȡ���ݳɹ�����ͷ����Ϊ%.2f", *(double *)queue_data);
				}
				else
					printf("��ȡ����ʧ��");
					Sleep(1000);
					system("CLS"); 
				break;
			case 5:   //��ó��� 
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				else 
					printf("��ǰ���еĳ���Ϊ��%d",LengthLQueue(Q)); 
					system("CLS");
				Sleep(1000);
				break;
			case 6:  //��� 
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if (data_type == INT)
				{
					queue_data = (int *)malloc(sizeof(int));
					printf("������Ҫ��ӵ�ֵ��"); 
					while (scanf("%d", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n����Ƿ������������룡\n");
					}
				}
				
				if (data_type == CHAR)
				{
					queue_data = (char *)malloc(sizeof(char));
					printf("������Ҫ��ӵ�ֵ��");
					while (scanf("%c", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n����Ƿ������������룡\n");
					}
				}
				
				if (data_type == DOUBLE)
				{
					queue_data = (double *)malloc(sizeof(double));
					printf("������Ҫ��ӵ�ֵ��");
					while (scanf("%lf", queue_data) != 1)
					{
						while (getchar() != '\n');
						printf("\n����Ƿ������������룡\n");
					}
				}
				
				if(EnLQueue(Q,queue_data) == TRUE)
					printf("��ӳɹ���\n");
				else	 
					printf("���ʧ�ܣ�\n");
				break;	
				
			case 7:
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				if(DeLQueue(Q) == TRUE)
					printf("���ӳɹ���\n");
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 8:
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				ClearLQueue(Q);
				break;
			case 9:
				if (ISINIT == NO)
				{
					printf("���ȳ�ʼ�����У�\n");
					Sleep(1000);
					system("CLS");
					break;
				}
				printf("��������Ҫʲô���͵�Ԫ�أ�\n");
				printf("1������ 2���ַ��� 3��������\n");
				while (scanf("%d", &data_type) != 1 || data_type < 1 || 3 < data_type)
				{
					while (getchar() != '\n');
					printf("\n�Ƿ����룡���������룡\n");
				}
				while (getchar() != '\n');//�����ڴ��
				system("CLS");//����
	
				if (ISINIT = YES)
					DestoryLQueue(Q);
				ISINIT = NO;
				printf("���óɹ���");
				system("CLS");
				break;
			case 10:
				exit(0);						
			default :
				printf("����������������������!\n");
				Sleep(1000); 
				fflush(stdin);
		}
	}	
	
	return 0;
}
