#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int pq[MAX], rear = -1, front = -1, i, j, data;

void check(int data){
	for(i = front; i <= rear; i++){
		if(data >= pq[i]){
			for(j = rear+1; j > i; j--)
				pq[j] = pq[j-1];
			pq[i] = data;
            return;
		}
	}
	pq[i] = data;
}

void insert(){
	if(rear >= MAX-1)
		printf("Queue is full.\n");
	else{
		printf("Enter data.\n");
		scanf("%d", &data);
		if(front == -1 && rear == -1){
			front = 0;
			rear = 0;
			pq[rear] = data;
			return;
		}
		else
			check(data);
		rear++;
	}
}

void delete(){
    int data;
	if (front == rear == -1) {
        printf("Queue is Empty, no more elements can be deleted.\n");
        return;
    }
	printf("Enter the data to be deleted from the queue.\n");
	scanf("%d", &data);
    for (i = 0; i <= rear; i++) {
        if (pq[i] == data) {
            for (; i < rear; i++)
                pq[i] = pq[i + 1];
            pq[i] = -99;
            rear--;
            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("Element %d not found in the queue.\n",data);
}

void display(){
	if(rear == -1)
		printf("Queue is empty.\n");
	else{
		for(i = front; i <= rear; i++)
			printf("%d\t", pq[i]);
		printf("\n");
	}
}
void main(){
	int ch;
	printf("1. Insert an element into the queue.\n");
    printf("2. Delete an element from the queue.\n");
    printf("3. Display elements from the queue.\n");
    printf("4. Exit\n");
	while(1){
		printf("Enter your choice.\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}