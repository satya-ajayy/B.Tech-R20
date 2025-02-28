#include<stdio.h>
#include<conio.h>
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) 
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--)
	 {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int array[], int size) 
{
  int i;
  for (i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main()
{
  int arr[100], n,i;
  printf("enter n:");
  scanf("%d",&n);
  for (i = 0; i < n; ++i)
  scanf("%d",&arr[i]);
  printf("Unsorted Array\n");
  printArray(arr, n);
  heapSort(arr, n);
  printf("Sorted array in ascending order: \n");
  printArray(arr,n);
return 0;
}
