int n,m;
int ** a;
int max(int a,int b,int c, int d)
{
  if(a>b&&a>c&&a>d)
    return a;
  else if(b>a&&b>c&&b>d)
    return b;
  else if(c>a&&c>b&&c>d)
    return c;
  return d;
}
int callingX;
int callingY;
int findMax(int* a, int n)
{
  int max=a[0];
  for(int i=1;i<n;i++)
    if(a[i]>max)
      max=a[i];
  return max;
}
int findDist(int i, int j)
{
  
  if(i>=0&&i<n&&j>=0&&j<m&&i!=callingX&&j!=callingY)
  {
    //printf("find distance called with %d %d\n",i,j);
    if(a[i][j]==1)
    {
      //printf("yo");
      return 1;
    }  
    return 1+max(findDist(i+1,j),findDist(i-1,j),findDist(i,j+1),findDist(i,j-1));
  }
 
}

int main()
{
    
    scanf("%d",&n);
    scanf("%d",&m);
    a=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*m);
        for(int j=0;j<m;j++)
        {
          scanf("%d",&a[i][j]);

        }
        
    }
    int dist[n*m];
    int len=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          if(a[i][j]==2)
          {
            callingX=i;
            callingY=j;
            dist[len++]=findDist(i,j);
            printf("%d %d %d\n",callingX,callingY,dist[len-1]);
          }
        }

    }
    

   //printf("%d\n",max(2,4,5,11)); 
   return 0;
}
