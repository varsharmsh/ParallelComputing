
int max(int a,int b)
{
	return a>b?a:b;
}

int knapSack(int *w, int * v, int n, int c)
{
	int i=0,j=0;
	int f[n+1][c+1];
	for(;i<=n;i++)
		for(j=0;j<=c;j++)
		{
			if(i==0 || j==0)
				f[i][j]=0;
			else
			{
				if(w[i]>j)
					f[i][j]=f[i-1][j];
				else
					f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]);
			}
			
		}
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<=c;j++)
				printf("%d ",f[i][j]);
			printf("\n");
		}
		*/
		return f[n-1][c];
		
}
int main()
{
	int n;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	int w[n+1], v[n+1];
	int i=1;
	for(;i<=n;i++)
	{
		printf("Enter the weight and value of item %d\n",i);
		scanf("%d %d", &w[i],&v[i]);
	}
	int capacity;
	printf("Enter the capacity of the knapsack\n");
	scanf("%d",&capacity);
	int maxValue=knapSack(w,v,n+1,capacity+1);
	printf("The maximum value that can be obtained is %d\n",maxValue);
	return 0;
	
}

