
void swap(int * x, int * y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int t,a,b,c,x,y,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        ans=0;
        if(a<b)
            swap(&a,&b);
        for(x=(b-c)/a;x<(c-b)/a && ans==0;x++)
            if((c-a*x)%b==0)
                ans=1;
        if(ans==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
