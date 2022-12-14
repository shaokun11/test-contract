/* Part of Cosmos by OpenGenus Foundation */
/*Added by arpank10 */
#include <stdio.h>
#include <stdbool.h>

/*
Cocktail Shaker Sort implementation in C
*/

void shaker_sort(int a[],int n)
{
	int i=0,j;
	bool swapped=false;
	for(i=0;i<n/2;i++)
	{
        /*
         * Indices of the inner loops result from an
         * invariant of the algorithm. In 'i'th execution
         * of the outer loop, it is guaranteed that the
         * leftmost and rightmost i elements will be sorted.
         * Hence, inner loops only check the others for
         * inversions. That is why, n/2 iterations of the
         * outer loop suffices to sort the array. After that
         * many iterations, left and right halves are sorted.
         */

        /* Traverse from left to right */
		for(j=i;j<n-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
                /* Inversion found - swap elements */
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=true;
			}
		}

        /* Traverse from right to left - hence, bidirectional */
		for(j=n-i-2;j>i;j--)	
		{
			if(a[j-1]>a[j])
			{
                /* Inversion found - swap elements */
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				swapped=true;
			}
		}

        /*If no elements are swapped in the iteration array is sorted */
		if(!swapped)
			break;
	}
}
int main()
{
	int n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	int a[n];
	int i;
	for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	shaker_sort(a,n);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
