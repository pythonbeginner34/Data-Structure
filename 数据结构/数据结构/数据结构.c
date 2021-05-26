//#include<stdio.h>
//
//
//int MaxSubseqSum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)//i��������˵�λ��
//	{
//		for (j = i; j < N; j++)//j�������Ҷ˵�λ��
//		{
//			ThisSum = 0;//ThisSum�Ǵ�A[i]��A[j]�����к�
//			for (k = i; k <= j; k++)
//			{
//				ThisSum += A[k];
//			}
//			if (ThisSum > MaxSum)//����µõ������к͸���
//			{
//				MaxSum = ThisSum;//����½��
//			}
//		}
//	}
//	return MaxSum;//T(N) = O(N^3)
//}
//
//
//int MaxSubseqSun2(int A[], int N)
//{
//	int ThisSum2, MaxSum = 0;
//	int i, j;
//	for (i = 0; i < N; i++)
//	{
//		ThisSum2 = 0;
//		for (j = i; j < N; j++)//��ͬһ��i��ʱ��ֻ����j�ĺ����ۼӾͿ��Բ���Ҫ��ʹ��k
//		{
//			ThisSum2 += A[j];
//			if (ThisSum2 > MaxSum)
//				MaxSum = ThisSum2;
//		}
//	}
//	return MaxSum;//T(N) = O(N^2)
//}
//
////�㷨4�����ߴ���
//
//int MaxSumseqSum4(int A[], int N)
//{
//	int ThisSum4, MaxSum;
//	int i;
//	ThisSum4 = MaxSum = 0;
//	for (i = 0; i < N; i++)
//	{
//		ThisSum4 += A[i];//�����ۼ�
//		if (ThisSum4 > MaxSum)
//		{
//			MaxSum = ThisSum4;//���ָ��������µ�ǰ���
//		}
//		else if (ThisSum4 < 0)//�����ǰ����Ϊ��
//		{
//			ThisSum4 = 0;//�򲻿���ʹ����Ĳ��ֺ���������
//		}
//	}
//	return MaxSum;//T(N) = O(M)
//
//}
//

//
//typedef struct LNode* List;
//
//struct LNode
//{
//	ElementType Data[MAX_SIZE];
//	int Last;
//};
//
//struct LNode L;
//List PtrL;
////��ʼ���������յ�˳���)
//
//List MakeEmpty()
//{
//	List PtrL;//�����ṹ��ָ��PtrL;
//	PtrL = (List)malloc(sizeof(struct LNode));//Ϊ�ṹ��ָ�뿪�ٿռ�
//	PtrL->Last = -1;//last = -1;����û��Ԫ��
//	return PtrL;//���ؽṹ��ָ��
//}
//
//
////����
//int Find(ElementType X, List PtrL)
//{
//	int i = 0;
//	while (i <= PtrL->Last && PtrL->Data[i] != X)
//	{
//		i++;
//	}//��������ѭ������ʱ����ѭ����i > PtrL->last �� PtrL->Data[i] = X
//	if (i > PtrL->Last)
//	{
//		return -1;//û�ҵ�����-1
//	}
//	else
//	{
//		return i;//�ҵ��˷��ش���λ�õ��±�
//	}
//}
//
////���룺�����Ա�ĵ�i��λ���ϲ���һ���µ�Xֵ���൱�ڲ��뵽����ĵ�i-1��λ�ã�������Ҫ������i-1���Ժ��λ������ƶ�һλ
//
//void insert(ElementType X, int i, List PtrL)
//{
//	int j;
//	if (PtrL->Last == MAXSIZE - 1)//��ռ����������ܲ���
//	{
//		printf("����");
//		return;
//	}
//	if (i < 1 || i > PtrL->Last + 2)//������λ�õĺϷ���
//	{
//		printf("λ�ò��Ϸ�\n");
//		return;
//	}
//	for (j = PtrL->Last; j >= i - 1; j--)
//	{
//		PtrL->Data[j + 1] = PtrL->Data[j];
//	}
//	PtrL->Data[i - 1] = X;//��i��n�����Ԫ�������
//	PtrL->Last++;//��Ԫ�ز���
//	return;//���Last��ֱָ�����Ԫ��
//	//ƽ���ƶ�����Ϊn/2��ƽ��ʱ������ΪO(n)
//}
//
////ɾ��
//
//void Del(ElementType X, int i, List PtrL)
//{
//	int j;
//	if (i < 1 || i >  PtrL->Last + 1)//���Ϸ���
//	{
//		printf("�����ڵ�%d��Ԫ��", i);
//		return;
//	}
//	for (j = i; j < PtrL->Last; j++)
//	{
//		PtrL->Data[i - 1] = PtrL->Data[j];//���±�Ϊi��n��Ԫ����ǰ�ƶ�
//	}
//	PtrL->Last--;//Last��ָ�����Ԫ��
//	return;
//}



