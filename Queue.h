#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define QUE_LEN 100


typedef struct times 
{
	int id;
	int arrivetime;
	int servetime;
} Times;                     //������ �� ����ü

typedef struct cQueue
{
	Times queArr[QUE_LEN];
	int front;
	int rear;

}CQueue;                     //ť

typedef CQueue Queue;

void QueueInit(Queue*pq);
int QIsEmpty(Queue*pq);

void Enqueue(Queue*pq, Times times);
Times Dequeue(Queue*pq);
Times QPeek(Queue*pq);

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void QueueInit(Queue*pq)
{
	pq->front = 0;
	pq->rear = 0;
}                                         //ť �ʱ�ȭ

int QIsEmpty(Queue*pq)
{
	return (pq->front == pq->rear);
}
                    //ť�� ������� Ȯ��

void Enqueue(Queue*pq, Times times)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = times;           //ť ����
}

Times Dequeue(Queue*pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}                                           //ť ����

Times QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}                                                //ť ���� �ش簪 ã�ƿ���

