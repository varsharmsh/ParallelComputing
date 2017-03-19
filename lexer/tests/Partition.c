
int min(int* a, int n)
{
	int min=-1,i;
	for(i=0;i<n;i++)
	{
		if(a[i]<min || min==-1)
			min=a[i];
	}
	return min;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i=0;
	for(;i<n;i++)
		scanf("%d",&a[i]);
	int diff[n-1];
	for(i=0;i<n-1;i++)
		diff[i]=abs(a[i+1]-a[i]);

}