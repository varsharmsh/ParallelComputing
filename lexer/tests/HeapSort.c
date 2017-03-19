
/*
void create_heap(int * a, int n)
{
	int i=1,s,f,temp;
	for(;i<n;i++)
	{
		temp=a[i];
		s=i;
		f=(s-1)/2;
		while(f>=0&&a[f]<temp)
		{
			printf("I am in the loop\n");
			a[s]=a[f];
			s=f;
			f=(s-1)/2;
		}
		a[s]=temp;
	printf("This is the heap for %d\n",i);
	int k;
	for(k=0;k<n;k++)
		printf("%d ",a[k]);
	printf("\n");
	}
}
*/
void create_heap(int * a, int n)
{
	int i=n/2;
	int k,temp,j;
	int heap;
	while(i>=0)
	{
		k=i;
		heap=0;
		while(k<n&&heap==0)
		{
			temp=a[k];
			j=2*k+1;
			if(j>=n)
				break;
			if(j+1<n&&a[j+1]>a[j])
			{
				j=j+1;
				//printf("Son has changed to right son\n");
			}
			if(a[j]<a[k])
				heap=1;
			else
			{
				a[k]=a[j];
				a[j]=temp;
				k=j;
			}
				
		}
		i--;		
	}	
}
void heapSort(int * a,int n)
{
	int i=n-1;
	int f,s,temp,x;
	while(i>0)
	{
		temp=a[i];
		a[i]=a[0];
		f=0;
		if(i==1)
			s=-1;
		else 
			s=1;
		if(i>2&&a[2]>a[1])
			s=2;
		
		while(s<i && temp<a[s])
		{
			f=(s-1)/2;
			a[f]=a[s];
			s=2*s+1;
			if(s+1<i &&a[s+1]>a[s])
				s=s+1;
						
		}
		a[2*f+1]=temp;
		i--;
	printf("this is the heap for %d\n",i);
	for(x=0;x<n;x++)
		printf("%d ",a[x]);
	printf("\n");	
	}
}
int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	int i=0;
	for(;i<n;i++)
		scanf("%d",&a[i]);
	create_heap(a,n);
	printf("thhis is the heap\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	heapSort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

