

int main() 
{
    int n;
    scanf("%d",&n);
    printf("yo%d\n",n);
    int a[n];
    int min,sum=0,i=0;
    for(;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0||a[i]<min)
            min=a[i];
        sum+=a[i];
    }
    printf("yo\n");
    
    for(int x=min;x<=sum;x++)
    {
        int index=0;
        int tempSum=0;
        while(a[index]+tempSum<=x)
        {
            index++;
            if(tempSum==x)
                tempSum=0;
        }
        if(index==n)
            printf("%d ",x);
    }
   
    return 0;
}
