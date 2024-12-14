#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

struct Node *header = NULL;
struct Node *CreateNode(int data)
{
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->link = NULL;
	return (newNode);
}

void traversal()
{
	struct Node *ptr;
	ptr = header;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
}

void insertAtFront(int data)
{
	struct Node *newNode;
	newNode = CreateNode(data);
	if (header == NULL)
	{
		header = newNode;
	}
	else
	{
		newNode->link = header;
		header = newNode;
	}
}

void insertAtEnd(int data)
{
	struct Node *newNode;
	newNode = CreateNode(data);
	if (header == NULL)
	{
		header = newNode;
	}
	else
	{
		struct Node *ptr = header;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newNode;
	}
}

void insertAtAny(int data, int pos)
{
	struct Node *newNode, *ptr, *prev;
	newNode = CreateNode(data);
	if (pos == 0)
	{
		newNode->link = header;
		header = newNode;
		return;
	}
	ptr = header;
	int curr_pos = 0;
	while (ptr != NULL && curr_pos < pos)
	{
		prev = ptr;
		ptr = ptr->link;
		curr_pos++;
	}
	if (ptr == NULL && curr_pos != pos)
	{
		printf("Position out of range\n");
		free(newNode);
		return;
	}

	newNode->link = ptr;
	prev->link = newNode;
}

void deleteAtFront()
{
	if (header == NULL)
	{
		printf("The list is empty...!!!");
	}
	else
	{
		struct Node *ptr = header;
		printf("Deleted element: %d\n", ptr->data);
		header = header->link;
		free(ptr);
	}
}

void deleteAtEnd()
{
	if (header == NULL)
	{
		printf("List is empty..!!!");
	}
	else
	{
		struct Node *ptr = header;
		struct Node *prev;
		while (ptr->link != NULL)
		{
			prev = ptr;
			ptr = ptr->link;
		}
		prev->link = NULL;
		printf("Deleted element: %d\n", ptr->data);
		free(ptr);
	}
}

void deleteAtAny(int key)
{
	if (header == NULL)
		printf("List is empty");
	struct Node *ptr1 = header, *ptr2 = NULL;
	if (ptr1->data == key)
	{
		printf("Deleted element: %d\n", ptr1->data);
		header = ptr1->link;
		free(ptr1);
		return;
	}
	while (ptr1 != NULL & ptr1->data != key)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->link;
	}
	if (ptr1 == NULL)
		printf("Key not found");
	else
	{
		printf("Deleted element: %d\n", ptr1->data);
		ptr2->link = ptr1->link;
		free(ptr1);
	}
}

void search(int key)
{
	struct Node *ptr = header;
	int pos = 0;
	if (header == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->data == key)
			{
				printf("\nPosition is %d\n", pos + 1);
				return;
			}
			ptr = ptr->link;
			pos++;
		}
		printf("Key not found\n");
	}
}

int main()
{
	insertAtFront(578);
	insertAtFront(999);
	insertAtFront(7);
	insertAtEnd(63);
	insertAtAny(39, 1);
	insertAtAny(45, 4);
	printf("\nBefore deletion:\n");
	traversal();
	deleteAtFront();
	deleteAtEnd();
	deleteAtAny(999);
	printf("\nAfter deletion:\n");
	traversal();
	search(39);
	return 0;
}