
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int i=0,j=0;
	int mode=a[i]%2==0?0:1;
	int count=0;
	while(i<n)
	{
		if(mode==0)
		{
			while(i<n&&a[i]%2==0)
				i++;
			
		}
		else
		{
			while(i<n&&a[i]%2!=0)
				i++;
			
		}
		int n=i-j;
		if(mode==0)
		{			
			count+=n*(n+1)/2;
		}
		else if(n>1)
		{
			if(n%2==0)
				count+=(n/2)*(n/2);
			else
				count+=n*(n+1)/2-((n/2)*(n/2));
		}
		printf("Mode is %d Count is %d change at %d\n",mode,count,i);
		j=i;
		mode=!mode;

	}
	printf("%d\n",count);
	return 0;

}