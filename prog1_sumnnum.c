#include<stdio.h>


int main()
{
	int elem,sum;
	printf("Enter the range:");
	scanf("%d",&elem);
	int num[elem];
	printf("Enter %d values:\n",elem);


	for(int i=0;i<elem;i++)
	{


		scanf("%d",&num[i]);


	}


	for(int i=0;i<elem;i++)
	{
		sum=sum+num[i];


	}


	printf("Sum of numbers is %d\n",sum);
	return 0;
}