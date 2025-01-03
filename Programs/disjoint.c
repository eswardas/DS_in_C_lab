#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *representative;
    struct Node *next;
    int data;
    int rank;
};

struct Node *headNodes[50], *tailNodes[50];
int rootCount = 0;

void createSet(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->representative = newNode;
    newNode->next = NULL;
    newNode->data = value;
    newNode->rank = 0; // Initialize rank
    headNodes[rootCount] = newNode;
    tailNodes[rootCount++] = newNode;
}

struct Node *findSet(int value)
{
    for (int i = 0; i < rootCount; i++)
    {
        struct Node *temp = headNodes[i];
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return temp->representative;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

void unionSetByRank(struct Node *rep1, struct Node *rep2)
{
    if (rep1->rank > rep2->rank)
    {
        rep2->representative = rep1;
        rep1->next = rep2;
    }
    else if (rep1->rank < rep2->rank)
    {
        rep1->representative = rep2;
        rep2->next = rep1;
    }
    else
    {
        rep2->representative = rep1;
        rep1->next = rep2;
        rep1->rank++;
    }
}

void unionSet(int value1, int value2)
{
    struct Node *rep1 = findSet(value1);
    struct Node *rep2 = findSet(value2);

    if (rep1 == NULL || rep2 == NULL)
    {
        printf("\nElement not present in the disjoint set\n");
        return;
    }

    if (rep1 != rep2)
    {
        unionSetByRank(rep1, rep2);
    }
}

int isPresent(int value)
{
    for (int i = 0; i < rootCount; i++)
    {
        struct Node *temp = headNodes[i];
        if (temp->data == value)
        {
            return 1;
        }
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

int main()
{
    int choice, x, y;
    do
    {
        printf("\n.......MENU.......\n\n1. Create Set\n2. Display set representatives\n3. Union\n4. Find Set\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter new element: ");
            scanf("%d", &x);
            if (isPresent(x) == 1)
            {
                printf("\nElement already present in the disjoint set\n");
            }
            else
            {
                createSet(x);
            }
            break;

        case 2:
            printf("\n");
            for (int i = 0; i < rootCount; i++)
            {
                printf("%d ", headNodes[i]->data);
            }
            printf("\n");
            break;

        case 3:
            printf("\nEnter first element: ");
            scanf("%d", &x);
            printf("\nEnter second element: ");
            scanf("%d", &y);
            unionSet(x, y);
            break;

        case 4:
            printf("\nEnter the element: ");
            scanf("%d", &x);
            struct Node *rep = findSet(x);
            if (rep == NULL)
            {
                printf("\nElement not present in the disjoint set\n");
            }
            else
            {
                printf("\nThe representative of %d is %d\n", x, rep->data);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("\nWrong choice\n");
            break;
        }
    } while (1);

    return 0;
}