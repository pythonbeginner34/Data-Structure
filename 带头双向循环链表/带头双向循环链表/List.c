#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = 0;
	return newnode;
}

LTNode* ListInit()
{
	LTNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

bool ListEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void ListDestory(LTNode* phead)
{
	assert(phead);
	if (ListEmpty(phead))
	{
		free(phead);
		phead = NULL;
	}
	else
	{
		LTNode* cur = phead->next;
		while (cur != phead)
		{
			LTNode* tail = phead->prev;
			LTNode* tailprev = tail->prev;
			tailprev->next = phead;
			phead->prev = tailprev;
			free(tail);
			tail = NULL;
		}
		free(cur);
		cur = NULL;
	}
}

size_t ListSize(LTNode* phead)
{
	assert(phead);
	size_t count = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);
	newnode->prev = tail;
	tail->next = newnode;
	phead->prev = newnode;
	newnode->next = phead;
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	LTNode* newnode = BuyListNode(x);
	newnode->next = cur;
	cur->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LTNode* cur = phead->next;
	if (cur->next == phead)
	{
		phead->next = phead;
		phead->prev = phead;
	}
	cur = cur->next;
	phead->next = cur;
	cur->prev = phead;
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return  NULL;
}

void ListErase(LTNode* phead, LTNode* pos)
{
	assert(pos);
	assert(!ListEmpty(phead));
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
	pos = NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}
