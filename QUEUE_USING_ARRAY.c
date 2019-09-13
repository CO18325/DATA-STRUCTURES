#include<stdio.h>
#include<stdlib.h>

int enqueue(int *arr,int front,int element){
    *(arr+front+1)=element;
    front++;
    return front;
}

int dequeue(int *arr,int rear){
    return
}


void main(){
    int arr[50];
    int rear,front;
    front=enqueue(arr,front);
    display(arr);
    rear=dequeue(arr,rear)
}
