
int main()
{
	int n;
	scanf("%d",&n);
	char a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf(" %c",&a[i][j]);
	for(int i=1;i<n-1;i++)
		for(int j=1;j<n-1;j++)
		{
			if(((a[i][j]-a[i-1][j])>0)&&((a[i][j]-a[i+1][j])>0)&&((a[i][j]-a[i][j-1])>0)&&((a[i][j]-a[i][j+1])>0))
				a[i][j]='X';
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}	

	return 0;
}