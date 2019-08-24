#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];
	int n;
	int i;
	char str[25];
	printf("Enter integer\n");
	scanf("%d",&n);
	printf("Enter the string");
	scanf("%[^EOF]",string);
	if(n>0)
	{
	//printf("%s",string);
	int len;
	int k;
	int j;
	int m;
	len=strlen(string);
	//printf("%d",len);
	m=len-1;
	for(i=len-1;i>=0;i--)
	{
		
		if(string[i]==' ' || string[i]=='\n')
		{
		//	str[k++]=string[i];
			k=0;
			while(k<n)
			{	
				j=m;
				while(j>i)
				{
					printf("%c",string[j]);
					j--;
				}
				printf(" ");
			k++;
			}
			printf("%c",string[i]);
			m=i-1;
		}
		else continue;

	}
}
	else 
	printf("Enter the positive");

}
