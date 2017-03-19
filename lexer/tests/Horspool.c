
void buildTable(char * pattern, int * table,int n)
{
	int i=0;
	for(;i<26;i++)
		table[i]=n;
	for(i=0;i<n-1;i++)
	{
	
		table[pattern[i]-97]=n-i-1;		
	}
	
}
int search(char * text, int n, char * pattern, int m, int * table)
{
	int i=m-1;
	int shift=0;
	int k;
	while(i<=n-1)		//as long as the text exits
	{
		printf("The number of shifts so far is%d\n",shift);
		k=0;		//Number of matched characters
		while(k<=m-1 && pattern[m-k-1]==text[i-k])
			k=k+1;
		if(k==m)
			return i-m+1;
		else
			i+=table[text[i]-97];
		shift++;
			
	}
	return -1;
}
int main()
{
	char pattern[80];
	char text[80];
	int table[26];
	printf("Enter the text\n");
	fgets(text,80,stdin);
	int n=strlen(text);
	n--;
	printf("Enter the pattern to be searched for\n");
	fgets(pattern,80,stdin);
	int m=strlen(pattern);
	m--;
	buildTable(pattern,table,m);
	int pos=search(text,n,pattern,m,table);
	printf("The pattern was found at position %d\n",pos+1);
	return 0;
}

