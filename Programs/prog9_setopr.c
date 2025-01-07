#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 26 // Maximum number of elements in the set

// Function to perform union of two sets
int unionSets(int setA, int setB) 
{
    return setA | setB;
}

// Function to perform intersection of two sets
int intersectionSets(int setA, int setB) {
    return setA & setB;
}

// Function to perform complement of a set
int complementSet(int set) {
    return ~set & ((1 << MAX_ELEMENTS) - 1); // Mask to limit to MAX_ELEMENTS
}

// Function to print the character representation of the set
void printCharacterSet(int set) {
    printf("Characters: ");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (set & (1 << i)) {
            printf("%c ", 'a' + i); // Print the character corresponding to the bit
        }
    }
    printf("\n");
}

// Function to print the bit vector representation
void printBitVector(int set) {
    printf("Bit vector: ");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (set & (1 << i)) {
            printf("1"); // Element is present
        } else {
            printf("0"); // Element is not present
        }
    }
    printf("\n");
}

int main() {
    char universal[MAX_ELEMENTS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int univ_size = sizeof(universal) / sizeof(universal[0]);
    int set1_size, set2_size, choice;

    int set1 = 0, set2 = 0; // Bit vector representation of sets
    char val;

    printf("Enter the number of elements in set1 out of %d: ", MAX_ELEMENTS);
    scanf("%d", &set1_size);
    printf("Enter %d characters (a-z):\n", set1_size);
    for (int i = 0; i < set1_size; i++) {
        scanf(" %c", &val);
        set1 |= (1 << (val - 'a')); // Set the corresponding bit
    }

    printf("Enter the number of elements in set2 out of %d: ", MAX_ELEMENTS);
    scanf("%d", &set2_size);
    printf("Enter %d characters (a-z):\n", set2_size);
    for (int i = 0; i < set2_size; i++) {
        scanf(" %c", &val);
        set2 |= (1 << (val - 'a')); // Set the corresponding bit
    }

    do {
        printf("---------------------------\n");
        printf("Enter the operation number:\n\n1.Union\n2.Intersection\n3.Complement\n4.Exit\n\n");
        scanf("%d", &choice);
        printf("- - - - - - - - - - - - - -\n");
        switch (choice) {
            case 1: {
                int unionResult = unionSets(set1, set2);
                printf("Union of Set1 and Set2: ");
                printCharacterSet(unionResult);
                printBitVector(unionResult);
                break;
            }
            case 2: {
                int intersectionResult = intersectionSets(set1, set2);
                printf("Intersection of Set1 and Set2: ");
                printCharacterSet(intersectionResult);
                printBitVector(intersectionResult);
                break;
            }
            case 3: {
                int complementSet1 = complementSet(set1);
                int complementSet2 = complementSet(set2);
                printf("Complement of Set1: ");
                printCharacterSet(complementSet1);
                printBitVector(complementSet1);
                printf("Complement of Set2: ");
                printCharacterSet(complementSet2);
                printBitVector(complementSet2);
                break;
            }
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}