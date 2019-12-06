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
} Times;                     //저장할 고객 구조체

typedef struct cQueue
{
	Times queArr[QUE_LEN];
	int front;
	int rear;

}CQueue;                     //큐

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
}                                         //큐 초기화

int QIsEmpty(Queue*pq)
{
	return (pq->front == pq->rear);
}
                    //큐가 비었는지 확인

void Enqueue(Queue*pq, Times times)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = times;           //큐 삽입
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
}                                           //큐 삭제

Times QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}                                                //큐 안의 해당값 찾아오기

