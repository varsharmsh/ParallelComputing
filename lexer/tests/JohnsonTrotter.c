
int findMaxMobile(int * a,int *dir,int n)
{
	int maxMobile=-1;
	int i=0;
	for(;i<n;i++)
	{
		//printf("The value at hand is %d\n",i+dir[i]);
		if(((i+dir[i])>=0)&&((i+dir[i])<n)&&(a[i]>a[i+dir[i]]))
		{
			//mobile element
			if(maxMobile==-1||a[i]>a[maxMobile])
				maxMobile=i;
			//printf("I entered the loop for %d\n",i);
		}
		
	}
	return maxMobile;
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int n;
	printf("Enter the number of digits\n");
	scanf("%d",&n);
	int a[n],dir[n];
	int i=0;
	for(;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)
			dir[i]=-1;
		else if(a[i]>a[i-1])
			dir[i]=-1;
		else
			dir[i]=1;
	}
	int j=0,temp1=0,temp2=0;
	int maxMobile;
	
	do
	{
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		maxMobile=findMaxMobile(a,dir,n);
		int k=0;
		for(;k<n;k++)
			if(a[k]>a[maxMobile])
				dir[k]*=-1;
		swap(&a[maxMobile],&a[maxMobile+dir[maxMobile]]);
		swap(&dir[maxMobile],&dir[maxMobile+dir[maxMobile]]);
	}while(maxMobile!=-1);
	return 0;
}

