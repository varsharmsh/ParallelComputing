

int max(int a,int b)
{
	return a>b?a:b;
}
int coin_row(int * a, int n)
{
	int f[n];
	f[0]=0;
	f[1]=a[1];
	int i=2;
	for(;i<n;i++)
	{
		f[i]=max(a[i]+f[i-2],f[i-1]);
	}
	/*
	for(i=0;i<n;i++)
		printf("%d ",f[i]);
	printf("\n");
	*/
	return f[n-1];

}

int main()
{
	int n;
	printf("Enter the number of coins\n");
	scanf("%d",&n);
	int a[n+1];
	printf("Enter the values of the coins\n");
	int i=1;
	for(;i<=n;i++)
		scanf("%d",&a[i]);
	int value=coin_row(a,n+1);
	printf("The maximum value that can be obtained is %d\n",value);
	
	return 0;
}


