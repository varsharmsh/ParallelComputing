int n, k;
int *x;
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int *)b;
}
int getFirstValue()
{
	int i, j, answer = 0;
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
			answer += x[j] - x[i];
	}
	return answer;
}
int getFirstSum()
{
	int i = 1, sum = 0;
	for (; i < k; i++)
		sum += x[i];
	return sum;
}
int main()
{

	scanf("%d", &n);
	scanf("%d", &k);
	int i = 0;
	x = (int *)malloc(sizeof(int)*n);
	for (; i < n; i++)
		scanf("%d", &x[i]);
	qsort(x, n, sizeof(int), compare);
	int x0_k = getFirstValue();
	int sum = getFirstSum();
	printf("The first sum is %d ", sum);
	int min = x0_k, x1_k;
	int index = k;
	while (index < n)
	{
		x1_k = x0_k + (k - 1)*(x[index - k] + x[index]) - 2 * sum;
		if (x1_k < min)	
			min = x1_k;
		x0_k = x1_k;
		sum += (x[index] - x[index - k+1]);
		printf("%d \n", sum);
		index++;
	}
	printf("%d\n", min);
}