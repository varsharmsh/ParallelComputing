

int main()
{
   int n;
   scanf("%d",&n);
   int a[n],b[n];
   for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
   for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
   int diff;
   
   for(int i=0;i<n-1;i++)
   {
       if(a[i]>b[i])
       {
           diff=a[i]-b[i];
           a[i]-=diff;
           a[i+1]+=diff;
       }
       
       else
       {
          diff=b[i]-a[i];
          a[i]+=diff;
          a[i+1]-=diff;
       }
       
   }
   
   if(a[n-1]==b[n-1])
    printf("YES\n");
   else
    printf("NO\n");
}
