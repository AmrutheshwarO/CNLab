#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int pri_que[MAX];
int front, rear;

void insert_by_priority(int data) {
    if(rear >= MAX -1) {
        printf("Queue overflow, no more elements can be inserted.\n");
        return;
    }
    if((front == -1) && (rear == -1)) {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void delete_by_priority(int data) {
    int i; 
    if((front == -1) && (rear == -1)) {
        printf("No more elements can be deleted.\n");
        return;
    }
    for(i = 0; i <= rear; i++) {
        if(data == pri_que[i]){
            for(; i < rear; i++)
                pri_que[i] = pri_que[i+1];
            pri_que[i] = -99;
            rear--;
            if(rear == -1)
                front = -1;
            return;
        }
    }
    printf("%d was not found in the queue to be deleted", data);
}

void create() {
    front = rear = -1;
}

void check(int data) {
    int i, j;
    for(i = 0; i <= rear; i++) {
        if(data >= pri_que[i]) {
            for(j = rear+1; j > 1; j--)
                pri_que[j] = pri_que[j-1];
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void display_pqueue() {
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
        return;
    }
    for(; front <= rear; front++)
        printf("%d\t", pri_que[front]);
    front = 0;
}

void main() {
    int n, ch;
    printf("1. Insert an element into the queue.\n");
    printf("2. Delete an element from the queue.\n");
    printf("3. Display the queue elements.\n");
    printf("4. Exit.\n");
    create();
    while(1) {
        printf("Enter your choice.\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter the value to be inserted.\n");
                    scanf("%d", &n);
                    insert_by_priority(n);
                    break;
            case 2: printf("Enter the value to be deleted.\n");
                    scanf("%d", &n);
                    delete_by_priority(n);
                    break;
            case 3: display_pqueue();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}