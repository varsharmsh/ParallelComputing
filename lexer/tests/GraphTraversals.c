
typedef struct node
{
	int ver_no;
	struct node *next;
}node;
const int n=5;
node list[10];

node * create_graph()
{
	
	int i=0;
	for(;i<n;i++)
		list[i].next=NULL;
	int wish=1,start,end;
	while(wish==1)
	{
		printf("Enter the start vertex and the end vertex\n");
		scanf("%d %d",&start,&end);
		node * temp=(node*) malloc(sizeof(node));
		temp->ver_no=end;
		temp->next=NULL;
		if(list[start].next==NULL)
			list[start].next=temp;
		else
		{
			node *t= list[start].next;
			while(t->next!=NULL)
				t=t->next;
			t=temp;
		}
	printf("press 1 to continue");
	scanf("%d",&wish);
	}
	
	
}
void display_graph()
{
	int i=0;
	for(;i<n;i++)
	{
		printf("%d ----->",i);
		node * temp=list[i].next;
		while(temp!=NULL)
			printf("%d ",temp->ver_no);
		printf("\n");
	}	
}
int main()
{
	//n=5;
	create_graph();
	display_graph();
	return 0;
}

