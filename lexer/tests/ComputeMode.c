

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int computeMode(int * a,int n)
{
	int mode=0;
	int frequency=0;
	int runvalue,runlength;
	int i=0;
	while(i<n)
	{
		runvalue=a[i];
		runlength=1;
		while(i+runlength<n && a[i+runlength]==runvalue)
			runlength++;
		if(runlength>frequency)
		{
			mode=runvalue;
			frequency=runlength;
		}
		i+=runlength;
	}
	return mode;
}
int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("eneter the elements\n");
	int i=0;
	for(;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	/*for(i=0;i<n;i++)
		printf("%d ",a[i]);
		*/
	printf("The mode is %d\n",computeMode(a,n));
	return 0;
}

