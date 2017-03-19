
int main()
{
	int n,q,i,lb,ub;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&lb);
		scanf("%d",&lb);
		if(a[lb-1]%2==0)
			printf("Even\n");
		else
			printf("Odd\n");
	}
	return 0;
}