
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	
	char c[100];
}word;
word words[20];

int comp(void const *A, void const *B);

void main()
 {	
	int n,i;
	
	while( scanf("%d",&n)==1)
	 {
		for(i=0;i<n;i++)
		scanf (" %s",words[i].c);

		qsort(words,n,sizeof(word),comp);

		for(i=0;i<n;i++)
		printf("%s\n",words[i].c);

	 }

}




int comp(void const *A, void const *B)
{

	word *a = (word*)A;
	word *b = (word*)B;

	return (strcmp(a->c,b->c));

}