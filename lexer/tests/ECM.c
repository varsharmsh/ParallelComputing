
int findMax(int * a , int n)
{
	int max=-1;
	int i=0;
	for(;i<n;i++)
		if(max==-1||a[i]>max)
			max=a[i];
	return max;
}
int main()
{
	int n;
	scanf("%d",&n);
	int justice[n];
	int i=0;
	for(;i<n;i++)
		scanf("%d",&justice[i]);
	int boss[n-1];
	for(i=0;i<n-1;i++)
		scanf("%d",&boss[i]);
	int q;
	scanf("%d",&q);
	int c1,c2;
	while(q--)
	{
		scanf("%d",&c1);
		scanf("%d",&c2);
		int minBoss=min(boss[c1-2],boss[c2-2]);
		//printf("The boss is %d\n",minBoss);
		printf("%d\n",findMax(justice,minBoss));
	}
}