
void insertionSort(int *a,int n)
{
	int temp;
	int i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 &&a[j]>temp;j--)
			a[j+1]=a[j];
		a[j+1]=temp;
	}
}
int main()
{
	int n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	int i=0;
	for(;i<n;i++)
		scanf("%d",&a[i]);
	insertionSort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
