
int main()
{
    int n;
    scanf("%d",&n);
    char a[n],b[n];
    scanf("%s",&a);
    scanf("%s",&b);
    int count[26]={0};
    for(int i=0;i<n;i++)
    {
        count[a[i]-97]++;
    }
    for(int i=0;i<n;i++)
    {
        count[b[i]-97]--;
    }
    for(int i=0;i<26;i++)
        printf("%d ",count[i]);
    int check=0;
    while(check<26&&count[check]==0)
        check++;
    if(check==26)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
