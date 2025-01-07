#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *Rlink;
	struct Node *Llink;
};

struct Node *header = NULL;

struct Node *CreateNode(int data)
{
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->Rlink = NULL;
	newnode->Llink = NULL;
	return (newnode);
};

void insertAtFront(int data)
{
	struct Node *newnode;
	int pos = 1;
	newnode = CreateNode(data);
	if (header == NULL)
	{
		header = newnode;
		printf("Inserted at position: %d\n", pos);
	}
	else
	{
		newnode->Llink = NULL;
		newnode->Rlink = header;
		header = newnode;
		printf("Inserted at position: %d\n", pos);
	}
}

void insertAtEnd(int data)
{
	struct Node *newnode = CreateNode(data);
	struct Node *ptr = header;
	int pos = 1;

	if (header == NULL)
	{
		header = newnode;
		printf("Inserted at position: %d\n", pos);
	}
	else
	{
		while (ptr->Rlink != NULL)
		{
			ptr = ptr->Rlink;
			pos++;
		}
		ptr->Rlink = newnode;
		newnode->Llink = ptr;
		printf("Inserted at position: %d\n", pos + 1);
	}
}

void insertAtAny(int data, int pos)
{
	struct Node *newnode = CreateNode(data);
	struct Node *ptr = header, *prev;
	int currentPos = 0;

	if (pos == 0)
	{
		newnode->Rlink = header;
		if (header != NULL)
			header->Llink = newnode;
		header = newnode;
		printf("Inserted at position: %d\n", pos + 1);
	}
	else
	{
		while (ptr != NULL && currentPos < pos - 1)
		{
			prev = ptr;
			ptr = ptr->Rlink;
			currentPos++;
		}
		if (ptr != NULL)
		{
			newnode->Llink = prev;
			newnode->Rlink = ptr;
			prev->Rlink = newnode;
			ptr->Llink = newnode;
			printf("Inserted at position: %d\n", pos + 1);
		}
		else
		{
			printf("Position not found\n");
			free(newnode);
		}
	}
}

void deleteAtFront()
{
	struct Node *ptr = header;
	int pos = 1;
	if (header == NULL)
		printf("Empty List\n");
	else
	{
		header = header->Rlink;
		if (header != NULL)
			header->Llink = NULL;
		free(ptr);
		printf("Deleted from position: %d\n", pos);
	}
}

void deleteAtEnd()
{
	struct Node *prev, *ptr = header;
	int pos = 1;
	if (header == NULL)
		printf("Empty List\n");
	else
	{
		while (ptr->Rlink != NULL)
		{
			prev = ptr;
			ptr = ptr->Rlink;
			pos++;
		}
		prev->Rlink = NULL;
		free(ptr);
		printf("Deleted from position: %d\n", pos);
	}
}

void deleteAtAny(int key)
{
	struct Node *prev, *ptr = header;
	int pos = 1;
	if (header == NULL)
		printf("List is Empty\n");
	else if (ptr->data == key)
	{
		header = ptr->Rlink;
		if (header != NULL)
			header->Llink = NULL;
		free(ptr);
		printf("Deleted from position : %d\n", pos);
	}
	else
	{
		while (ptr != NULL && ptr->data != key)
		{
			prev = ptr;
			ptr = ptr->Rlink;
			pos++;
		}
		if (ptr == NULL)
			printf("Key Not Found\n");
		else
		{
			prev->Rlink = ptr->Rlink;
			if (ptr->Rlink != NULL)
				ptr->Rlink->Llink = prev;
			free(ptr);
			printf("Deleted from position: %d\n", pos);
		}
	}
}

void search(int key)
{
	struct Node *ptr = header;
	int pos = 0;
	if (header == NULL)
		printf("List is Empty\n");
	else
	{
		while (ptr != NULL)
		{
			if (ptr->data == key)
			{
				printf("Position is %d\n", pos + 1);
				return;
			}
			else
			{
				ptr = ptr->Rlink;
				pos++;
			}
		}
		printf("Key Not found\n");
	}
}

void traversal()
{
	struct Node *ptr;
	ptr = header;
	while (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->Rlink;
	}
	printf("\n");
}

int main()
{
	int choice, data, key;
	while (choice != 9)
	{
		printf("1.Insert at Front\n2.Insert at End\n3.Insert at Any\n4.Delete at End\n5.Delete at First\n6.Delete at Any\n7.Traverse\n8.Search\n9.Exit\n");
		printf("\nEnter your Choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the data:");
			scanf("%d", &data);
			insertAtFront(data);
			break;
		case 2:
			printf("Enter the data:");
			scanf("%d", &data);
			insertAtEnd(data);
			break;
		case 3:
			printf("Enter where do you want to add data:");
			scanf("%d", &key);
			printf("Enter the data:");
			scanf("%d", &data);
			insertAtAny(data, key);
			break;
		case 4:
			deleteAtEnd();
			break;
		case 5:
			deleteAtFront();
			break;
		case 6:
			traversal();
			printf("What element you want to delete:");
			scanf("%d", &key);
			deleteAtAny(key);
			break;
		case 7:
			traversal();
			break;
		case 8:
			traversal();
			printf("Enter key to search:");
			scanf("%d", &key);
			search(key);
			break;
		case 9:
			return 0;
		default:
			printf("Wrong Choice!!");
		}
	}

	return 0;
}