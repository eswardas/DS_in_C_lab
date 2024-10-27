#include <stdio.h>
#include <stdlib.h>


void sort(int arr[],int size)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void merge(int arr1[],int arr2[], int size1,int size2,int *merged)
{
	int size;
	for(int i=0;i<size1+1;i++)
	{
		merged[i] = arr1[i];
		size=i;
	}
	for(int j=0;j<size2+1;j++)
	{
		merged[size+j] = arr2[j];
	}	
}


int main()
{
//Array 1
	int arr1[4] = {34,6,3,17};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);


	printf("Unsored Array 1:\n");
	for(int i=0;i<size1;i++)
	{
		printf("%d,",arr1[i]);	
	}
	printf("\n");


	sort(arr1,size1);
	printf("Array 1 after sorting:\n");
	for(int i=0;i<size1;i++)
	{
		printf("%d,",arr1[i]);	
	}
	printf("\n");


// Array 2


	int arr2[5] = {100,89,56,61,2};
	int size2 = sizeof(arr2)/sizeof(arr2[0]);


	printf("Unsored Array 2:\n");
	for(int i=0;i<size2;i++)
	{
		printf("%d,",arr2[i]);	
	}
	printf("\n");


	sort(arr2,size2);
	printf("Array 2 after sorting:\n");
	for(int i=0;i<size2;i++)
	{
		printf("%d,",arr2[i]);	
	}
	printf("\n");




//Merge array
	int total = size1+size2;


	int* merged = (int*)malloc(total * sizeof(int));


	merge(arr1, arr2, size1, size2, merged);


	printf("Merged array before sorting:\n");


	for(int i=0;i<total;i++)
	{
		printf("%d,",merged[i]);	
	}
	printf("\n");


	sort(merged,total);


	printf("Merged array after sorting:\n");


	for(int i=0;i<total;i++)
	{
		printf("%d,",merged[i]);	
	}
	printf("\n");


	
	return 0;
}