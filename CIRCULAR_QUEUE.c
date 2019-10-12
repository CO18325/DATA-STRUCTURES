#include<stdio.h>
#include<stdlib.h>

struct student{
	int roll_no;
	char name[50];
	int tot_marks;
};
struct queue{
	//struct student stud_info;
	int data;
	int size;
	int capacity;
	int front,rear;
	int *list;
};


struct queue* createQueue(int capacity){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->capacity=capacity;
	q->size=0;
	q->front=q->rear=-1;
	q->list=(int *)malloc(q->capacity*(sizeof(int)));
	return q;
}
int isEmpty(struct queue *q){
	//Will return 0 if size=0, else the statement will return 1
	return (q->size==0);
}
int isFull(struct queue *q){
	return (q->size==q->capacity);
}
void enQueue(struct queue *q){
	//The function will return -1 if the list is full
	if(isFull(q)){
		printf("\nQueue is Full!!\n");
		return;
	}
	else{
		int data;
		printf("\nINPUT: ");
		scanf("%d",&data);
		q->rear=(q->rear+1) % (q->capacity);
		q->list[q->rear]=data;
		q->size=q->size+1;
	}
}
int deQueue(struct queue *q){
	int data=-1;
	if(isEmpty(q)){
		printf("\nThe Queue is Empty!!\n");\
		return data;
	}
	data=q->list[q->front];
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
	}else{
		q->front=(q->front+1)%(q->capacity);
		q->size=q->size-1;
	}
	return data;
}

void menu(struct queue *q){
	char choice='y';
	while(choice=='y'||choice=='Y'){
		printf("1. ENQUEUE  2. DEQUEUE\n");
		int opt;
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enQueue(q);
				break;
			case 2:
				printf("Data deleted is %d\n",deQueue(q));
				break;
			default:
				printf("INVALID OPTION\n");
				break;
		}
		printf("DO YOU WANT TO PERFORM MORE OPERATIONS(Y/N): \n");
		choice=getch();
	}
}

void main(){
	int capacity;
	printf("ENTER THE CAPACITY OF THE QUEUE: \n");
	scanf("%d",&capacity);
	struct queue *q = createQueue(capacity);
	menu(q);
}
