
void distSort(int * a, int l, int u,int n)
{
	int dist[u-l+1];
	int b[n];
	int i=0;
	int j;
	for(;i<u-l;i++)
		dist[i]=0;
	for(i=0;i<n;i++)
		dist[a[i]-l]++;
	printf("The distribution array is \n");
	for(i=0;i<u-l;i++)
		printf("%d ",dist[i]);
	for(i=1;i<u-l;i++)
		dist[i]=dist[i]+dist[i-1];
	printf("The distribution array after cumulating is \n");
	//for(i=0;i<u-l;i++)
		printf("%d %d",dist[0],dist[1]); 
	for(i=n-1;i>=0;i--)
	{
		j=a[i]-u;
		b[dist[j]-1]=a[i];
		dist[j]--;
	}
	printf("The final array is \n");
	for(i=0;i<n;i++)
		printf("%d ",b[i]); 
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
	distSort(a,10,20,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
	
}
