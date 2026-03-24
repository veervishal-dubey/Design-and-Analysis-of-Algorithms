#include <stdio.h>

int findMobile(int nums[], int dir[], int n)
{
int mobile =0;
int index=-1; 

for (int i =0; i<n; i++)
	{
		if (dir[i]==-1 && i!=0 && nums[i]>nums[i-1] && nums[i]>mobile)
			{
				mobile=nums[i];
				index=i;
			}
		if (dir[i]==1 && i!=n-1 && nums[i]>nums[i+1] && nums[i]>mobile)
			{
				mobile=nums[i];
				index=i;
			}
		
	}
	return index;
}

void printPermutation(int nums[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf("%d",nums[i]);
	}
	printf(" ");
}

void swap(int *num1, int *num2)
{
	int temp=*num1;
	*num1=*num2;
	*num2=temp;
}

int main()
{

	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int nums[n];
	int direction[n];

	for (int i=0; i<n;i++)
	{
		nums[i]=i+1;
		direction[i]=-1;
	}
	
	printPermutation(nums, n);

	while (1)
	{
		int largest=findMobile(nums, direction, n);
		if (largest==-1)
			break;
		int mobile_num=nums[largest];	
		int swapIndex=largest+direction[largest];

		swap (&nums[largest], &nums[swapIndex]);
		swap (&direction[largest], &direction[swapIndex]);

		for (int i=0; i<n; i++)
		{
			if (nums[i]>mobile_num)
			{
				direction[i]=-direction[i];
			}
		}
		printPermutation(nums, n);
	}
	return 0;
}

