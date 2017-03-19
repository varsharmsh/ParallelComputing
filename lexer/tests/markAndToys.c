
int compare(const void*a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,money;
	scanf("%d",&n);
	scanf("%d",&money);
	int ar[n];
	int i=0;
	for(;i<n;i++)
		scanf("%d",&ar[i]);
	qsort(ar,n,sizeof(int),compare);
	int cost=0;
	i=0;
	while(i<n&&ar[i]+cost<money)
	{
		cost+=ar[i];
		i++;
	}
	printf("%d\n",i);

}