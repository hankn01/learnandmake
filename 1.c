//2020115974 한강민
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 20

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

int rear = -1;
int front = -1;
element queue[MAX_QUEUE_SIZE];

void addq(element k);
element deleteq();
void queueFull();
element queueEmpty();

int main(int argc, char* argv[])
{
	char input[80];				
	char* delimiter = " \n";	
	char* op = NULL;			
	element student;
	int cnt;

	printf("<< linear queue operations where MAX_QUEUE_SIZE is %d>>\n", MAX_QUEUE_SIZE);
	printf("add 1 Jung\n");
	printf("delete\n\n");
	printf("**************************************************\n");
	
	while (1) 
	{
		gets(input);			
		op = strtok(input, delimiter); 

		if (!strcmp(op, "add"))
		{
			sscanf(input + strlen(op) + 1, "%d%s", &student.id, student.name); // 문자열에서 원하는 형식으로 데이터를 가져옴
			addq(student);

		}
		else if (!strcmp(op, "delete"))
		{
			if (deleteq().id == -1)
			{
				printf("queue is empty, cannot delete element.");
				exit(EXIT_FAILURE);
			}
			else
			{

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
    int i;
    element tmp;
    if (front == -1 && rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue is full, cannot add element!\n");
        for (i = 0; i <=rear; i++)
        {
            tmp = deleteq();
            printf("%d %s\n", tmp.id, tmp.name);
        }
        exit(EXIT_FAILURE);


    }
    else
    {
		printf("array shifting...\n");
		for(i=0;i<(rear-front);i++)
		{
			queue[i] = queue[front+i+1];
		}
		rear = rear - front-1;
		front = -1;

    }
}

void addq(element item)
{
    if (rear == MAX_QUEUE_SIZE - 1)
        queueFull();
    queue[++rear] = item;
}

element deleteq()
{
    if (front == rear)
        return queueEmpty();
    return queue[++front];

}
