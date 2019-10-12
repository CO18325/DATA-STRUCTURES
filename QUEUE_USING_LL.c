#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *link;
};

struct queue{
    struct listNode *front;
    struct listNode *rear;
};

struct queue* createQueue(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=NULL;
    return q;
};

int isEmpty(struct queue *q){
    if(q->front==NULL){
        return 1;
    }
    return 0;
}

void enQueue(struct queue* q){
    int data;
    printf("INPUT: ");
    scanf("%d",&data);
    struct listNode *temp=(struct listNode*)malloc(sizeof(struct listNode));
    temp->data=data;
    temp->link=NULL;
    if(q->front==NULL){
        q->front=q->rear=temp;
    }else{
        q->rear->link=temp;
        q->rear=temp;
    }
}

int deQueue(struct queue *q){
    if(isEmpty(q)){
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    int data=q->front->data;
    struct listNode *temp=q->front;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
        q->front=q->front->link;
    free(temp);
    return data;
}

int frontElement(struct queue *q){
    if(isEmpty(q)){
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    return q->front->data;
}

int sizeOfQueue(struct queue *q){
    if(isEmpty(q)){
        printf("QUEUE IS EMPTY\n");
        return 0;
    }
    int size=1;
    struct listNode *temp=q->front;
    while(temp!=q->rear){
        temp=temp->link;
        size++;
    }
    return size;
}

void menu(struct queue *q){
    int opt;
    char choice='y';
    while(choice=='y'||choice=='Y'){
        printf("\n1.ENQUEUE\t2.DEQUEUE\t3.FIRST ELEMENT\n4.SIZE\t\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                enQueue(q);
                break;
            case 2:
                printf("ELEMENT DELETED: %d\n",deQueue(q));
                break;
            case 3:
                printf("FIRST ELEMENT IS: %d\n",frontElement(q));
                break;
            case 4:
                printf("SIZE OF THE QUEUE IS: %d\n",sizeOfQueue(q));
        }
        printf("DO YOU WANT TO PERFORM MORE OPERATIONS[Y/N]: ");
        choice=getch();
    }
}

void deleteQueue(struct queue *q){
    struct listNode *temp=q->front;
    while(temp){
        q->front=q->front->link;
        free(temp);
        temp=q->front;
    }
    printf("\n\nQUEUE IS DELETED");

}

void main(){
    struct queue *q=createQueue();
    menu(q);
    deleteQueue(q);
}
