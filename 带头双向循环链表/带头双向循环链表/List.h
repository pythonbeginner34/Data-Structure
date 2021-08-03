#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}LTNode;

void ListPrint(LTNode* phead);
LTNode* BuyListNode(LTDataType x);
LTNode* ListInit();

bool ListEmpty(LTNode* phead);
void LsitDestory(LTNode* phead);
size_t ListSize(LTNode* phead);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);

void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType x);
void ListErase(LTNode* phead, LTNode* pos);
