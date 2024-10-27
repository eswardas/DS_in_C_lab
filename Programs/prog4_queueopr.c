#include <stdio.h>
#include <stdlib.h>


int rear=-1;
int front=-1;


void enqueue(int* arr,int size)
{
	int item;
	printf("Enter the item to insert into the queue:");
	scanf("%d",&item);
	if(rear==size-1)
	{
		printf("Queue is full");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front = 0;


		}
		rear++;	
		arr[rear] = item;	


	}
}




void dequeue(int* arr)
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("The queue is empty\n");
	}
	else
	{
		int item = arr[front];
		printf("Deleted item is:%d\n",item);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front++;
			
		}
	}
}




void traversal(int* arr)
{
	if(front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements:");
	for(int i=front;i<=rear;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int main()
{


	int size;
	printf("Enter the size of the array:");
	scanf("%d",&size);
	int* arr = (int*)malloc(size * sizeof(int));
	int choice;


	do
	{
		printf("---------------------------");
		printf("\nEnter the operation number:\n\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n\n");
		scanf("%d",&choice);
		printf("- - - - - - - - - - - - - -\n");
		switch(choice)
		{
			case 1:
				enqueue(arr,size);
				break;
			case 2:
				dequeue(arr);
				break;


			case 3:
				traversal(arr);
				
				break;


			case 4:
				printf("Exit\n");
				break;


		}
	}
	while(choice!=4);




	return 0;
}