#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Queue.h"


int simulationtime = 10;
double average_person = 0.8;//시간당 평균 주문들어오는 사람 수
int maxtime = 5;//한번 배달하는데 걸리는 최대 시간

int customers=0;//몇번째 고객인지
int served_customers=0;//총 배달한 고객 수
int waited_time=0;//고객들이 총 기다린시간
int now_clock1=0;//현재시간
int serve_time1 = 0;

Times customer = { 0,0,0 };
Queue qqueue;
Queue* cusQueue= &qqueue;



int random()
{
	return rand()%2;
}

bool newCustomer(Queue* queue, int arrivetime1) {
	if (random() ==1)
	{
		
		customer.id = ++customers;
		customer.arrivetime = arrivetime1;
		customer.servetime = (int)(maxtime*rand()/RAND_MAX) + 1;
		Enqueue(queue, customer);
		return true;
	}
	else return false;
}//주문이 들어왔는지 확인 후 도착했으면 고객 큐에 넣기

int servCustomer(Queue* queue) {
	serve_time1 = 0;
	if (QIsEmpty(queue))
		return 0;
	customer = Dequeue(queue);
	serve_time1 = customer.servetime - 1;
	served_customers++;
	waited_time += now_clock1 - customer.arrivetime;
	return serve_time1;
}//큐가 비어있지않으면 배달하기

void printstatus() {
	printf("총 배달한 고객=%d명\n", served_customers);
	if (waited_time > 0 && served_customers > 0)
	{
		printf("한사람당 평균 기다린 시간=%d\n", waited_time / served_customers);
		printf("현재 기다리고있는 고객=%d명\n", customers - served_customers);
	}
}//배달이 끝나면 총 결과 프린트


void main() {


	serve_time1 = 0;
	now_clock1 = 0;
	while (now_clock1 < simulationtime) {
		now_clock1++;
		printf("현재시각:%d\n", now_clock1);
		newCustomer(cusQueue, now_clock1);
		if (serve_time1 > 0)
			serve_time1--;
		else
			serve_time1 = servCustomer(cusQueue);
	}
	printstatus();
}//메인함수

