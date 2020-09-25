//2020115974 �Ѱ���
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 20
#define MALLOC(p,s) \
	if(!(p=malloc(s))) { \
	fprintf(stderr,"�޸� ����"); \
	exit(EXIT_FAILURE);\
	}

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

int rear = 0;
int front = 0;
element *queue;
int capacity = 2;

void addq(element k);
element deleteq();
void queueFull();
element queueEmpty();
void copy(element *a, element *b, element *newQ);


int main(int argc, char* argv[])
{
	element deltmp;
	char input[80];				
	char* delimiter = " \n";	
	char* op = NULL;			
	element student;
	int cnt;
	queue = (element *)malloc(sizeof(element) * capacity);
	printf("<< circular queue operations where the initial capacity is %d>>\n", capacity);
	printf("add 1 Jung\n");
	printf("delete\n\n");
	printf("**************************************************\n");
	
	while (1) 
	{
		gets(input);			
		op = strtok(input, delimiter); 

		if (!strcmp(op, "add"))
		{
			sscanf(input + strlen(op) + 1, "%d%s", &student.id, student.name); // ���ڿ����� ���ϴ� �������� �����͸� ������
			addq(student);

		}
		else if (!strcmp(op, "delete"))
		{
			deltmp = deleteq();
			if (deltmp.id == -1)
			{
				printf("queue is empty, cannot delete element.");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("deleted item : %d %s\n",deltmp.id,deltmp.name);
			}

		}
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");

	}

	return 0;
}

element queueEmpty()
{
    element tp;
    tp.id = -1;
    strcpy(tp.name,"empty");
    return tp;
}

void queueFull()
{
	int start;
	
	element *newQueue;
	MALLOC(newQueue,2*capacity*sizeof(*queue));
    
    start = (front+1) % capacity; rear--;
    if(start<2)
    	copy(queue+start,queue+start+capacity-1,newQueue);
    else
    {
    	copy(queue+start,queue+capacity,newQueue);
    	copy(queue,queue+rear+1,newQueue+capacity-start);
			
	}
	front = 2 * capacity - 1;
	rear = capacity -1;
	capacity *=2;
	free(queue);
	queue = newQueue;
	printf("queue capacity is doubled.\n");
	printf("current queue capacity is %d.\n",capacity);
}

void addq(element item)
{
	rear = (rear+1) % capacity;
    if (front==rear)
        queueFull();
    queue[rear] = item;
}

element deleteq()
{
	element item;
    if (front == rear)
        return queueEmpty();
    front = (front+1)%capacity;
    return queue[front];

}
void copy(element *a, element *b, element *newQ)
{
	while (a != b)
	{
		*newQ++ = *a++;
	}
}
