
int main()
{
	int t;
	scanf("%d",&t);
	printf("%d",t);
	while(t--)
	{
		int n,m=0;
		scanf("%d",&n);
		//scanf("%d",&m);
		printf("%d %d",n,m);
		int fact=1,factN,factM;
		for(int i=1;i<=n+m-1;i++)
		{
			fact=fact*i;
			if(i==n)
				factN=fact;
			if(i==m-1)
				factM=fact;
		}
		printf("%d\n",fact/(factN*factM));
	}
}