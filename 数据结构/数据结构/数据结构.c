//#include<stdio.h>
//
//
//int MaxSubseqSum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)//i是子列左端的位置
//	{
//		for (j = i; j < N; j++)//j是子列右端的位置
//		{
//			ThisSum = 0;//ThisSum是从A[i]到A[j]的子列和
//			for (k = i; k <= j; k++)
//			{
//				ThisSum += A[k];
//			}
//			if (ThisSum > MaxSum)//如果新得到的子列和更大
//			{
//				MaxSum = ThisSum;//则更新结果
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
//		for (j = i; j < N; j++)//在同一个i的时候只需在j的后面累加就可以不需要在使用k
//		{
//			ThisSum2 += A[j];
//			if (ThisSum2 > MaxSum)
//				MaxSum = ThisSum2;
//		}
//	}
//	return MaxSum;//T(N) = O(N^2)
//}
//
////算法4：在线处理
//
//int MaxSumseqSum4(int A[], int N)
//{
//	int ThisSum4, MaxSum;
//	int i;
//	ThisSum4 = MaxSum = 0;
//	for (i = 0; i < N; i++)
//	{
//		ThisSum4 += A[i];//向右累加
//		if (ThisSum4 > MaxSum)
//		{
//			MaxSum = ThisSum4;//发现更大和则更新当前结果
//		}
//		else if (ThisSum4 < 0)//如果当前子列为负
//		{
//			ThisSum4 = 0;//则不可能使后面的部分和增大，抛弃
//		}
//	}
//	return MaxSum;//T(N) = O(M)
//
//}
//


typedef struct LNode* List;

struct LNode
{
	ElementType Data[MAX_SIZE];
	int Last;
};

struct LNode L;
List PtrL;
//初始化（创建空的顺序表)

List MakeEmpty()
{
	List PtrL;//创建结构体指针PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));//为结构体指针开辟空间
	PtrL->Last = -1;//last = -1;代表没有元素
	return PtrL;//返回结构体指针
}


//查找
int Find(ElementType X, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X)
	{
		i++;
	}//当不满足循环条件时跳出循环：i > PtrL->last 或 PtrL->Data[i] = X
	if (i > PtrL->Last)
	{
		return -1;//没找到返回-1
	}
	else
	{
		return i;//找到了返回储存位置的下标
	}
}

//插入：在线性表的第i个位置上插入一个新的X值，相当于插入到数组的第i-1个位置，这样就要把数组i-1及以后的位置向后移动一位

void insert(ElementType X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1)//表空间已满，不能插入
	{
		printf("表满");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2)//检查插入位置的合法性
	{
		printf("位置不合法\n");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)
	{
		PtrL->Data[j + 1] = PtrL->Data[j];
	}
	PtrL->Data[i - 1] = X;//将i到n后面的元素向后移
	PtrL->Last++;//新元素插入
	return;//最后Last仍直指向最后元素
	//平均移动次数为n/2，平均时间性能为O(n)
}

//删除

void Del(ElementType X, int i, List PtrL)
{
	int j;
	if (i < 1 || i >  PtrL->Last + 1)//检查合法性
	{
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i; j < PtrL->Last; j++)
	{
		PtrL->Data[i - 1] = PtrL->Data[j];//将下标为i到n的元素向前移动
	}
	PtrL->Last--;//Last仍指向最后元素
	return;
}



