#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void enqueue(int *arr, int size) 
{
	int item;
	printf("Enter the item to insert into the queue:");
	scanf("%d", &item);

	if ((rear + 1) % size == front) 
	{
        	printf("Queue is full\n");
	} 
	else 
	{
		if (front == -1) 
		{
		    front = 0;
		}

        rear = (rear + 1) % size;
        arr[rear] = item;
	}
}

void dequeue(int *arr,int size)
{

	int item;

	if (front == -1) 
	{
		printf("The queue is empty\n");
	} 
	else 
	{
		item = arr[front];
		printf("Deleted item is:%d\n", item);

        	if (front == rear) 
		      {
            		front = rear = -1;
        	} 
		else 
		{
            		front = (front + 1) % size;
		}
	}
}

void traversal(int *arr,int size) 
{
	if (front == -1) 
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Queue elements:");
	int i = front;

	do 
	{
	printf("%d ", arr[i]);
	i = (i + 1) % size;
	} 
	while (i != front);
	printf("\n");
}



int main() 
{
	int size;

	printf("Enter the size of the array:");

	scanf("%d", &size);

	int *arr = (int *)malloc(size * sizeof(int));

	int choice;

	do 
	{
		printf("---------------------------");

		printf("\nEnter the operation number:\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n\n");

		scanf("%d", &choice);

		printf("- - - - - - - - - - - - - -\n");

		switch (choice) 
		{
		    case 1:
			enqueue(arr, size);
			break;
		    case 2:
			dequeue(arr,size);
			break;
		    case 3:
			traversal(arr,size);
			break;
		    case 4:
			printf("Exit\n");
			break;
		}
	} 
	while (choice != 4);


	return 0;
}
