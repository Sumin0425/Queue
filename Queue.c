#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Queue.h"


int simulationtime = 10;
double average_person = 0.8;//�ð��� ��� �ֹ������� ��� ��
int maxtime = 5;//�ѹ� ����ϴµ� �ɸ��� �ִ� �ð�

int customers=0;//���° ������
int served_customers=0;//�� ����� �� ��
int waited_time=0;//������ �� ��ٸ��ð�
int now_clock1=0;//����ð�
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
}//�ֹ��� ���Դ��� Ȯ�� �� ���������� �� ť�� �ֱ�

int servCustomer(Queue* queue) {
	serve_time1 = 0;
	if (QIsEmpty(queue))
		return 0;
	customer = Dequeue(queue);
	serve_time1 = customer.servetime - 1;
	served_customers++;
	waited_time += now_clock1 - customer.arrivetime;
	return serve_time1;
}//ť�� ������������� ����ϱ�

void printstatus() {
	printf("�� ����� ��=%d��\n", served_customers);
	if (waited_time > 0 && served_customers > 0)
	{
		printf("�ѻ���� ��� ��ٸ� �ð�=%d\n", waited_time / served_customers);
		printf("���� ��ٸ����ִ� ��=%d��\n", customers - served_customers);
	}
}//����� ������ �� ��� ����Ʈ


void main() {


	serve_time1 = 0;
	now_clock1 = 0;
	while (now_clock1 < simulationtime) {
		now_clock1++;
		printf("����ð�:%d\n", now_clock1);
		newCustomer(cusQueue, now_clock1);
		if (serve_time1 > 0)
			serve_time1--;
		else
			serve_time1 = servCustomer(cusQueue);
	}
	printstatus();
}//�����Լ�

