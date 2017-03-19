
void countingSort(int* a, int n)
{
	int count[n];
	int b[n];
	int i=0;
	int j=1;
	for(;i<n;i++)
		count[i]=0;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
				count[i]++;
			else
				count[j]++;
	//printf("The count array is \n");
	for(i=0;i<n;i++)
	{
		//printf("%d ",count[i]);
		b[count[i]]=a[i];
	}
	//printf("\n");
	for(i=0;i<n;i++)
		a[i]=b[i];
	//return b;
	
}

int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	int i=0;
	printf("Enter the elements\n");
	for(;i<n;i++)
		scanf("%d",&a[i]);
	countingSort(a,n);
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
