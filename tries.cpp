#include<stdio.h>
#include<string.h>
#define sz 27

struct Vertex{

	long totalWord,totalPrefix;
	Vertex *edges[sz];
};

Vertex *createNode()
{
	Vertex *v;
	long i;

	v = new Vertex;

	v->totalPrefix = 0;
	v->totalWord = 0;

	for(i=0;i<26;i++)
		v->edges[i] = NULL;

	return v;
} 

void insertWord(Vertex *ver,char str[],long len,long k)
{
	if(len==k){
		ver->totalWord++;
		return;
	}

	ver->totalPrefix++;

	if(!ver->edges[str[k]-'a']){

		ver->edges[str[k]-'a'] = createNode();				
	}

	insertWord(ver->edges[str[k]-'a'],str,len,k+1);	
}

long countWord(Vertex *ver,char str[],long len,long k)
{
	if(len==k)
		return ver->totalWord;

	if(!ver->edges[str[k]-'a'])
		return 0;

	return countWord(ver->edges[str[k]-'a'],str,len,k+1);
}

long countPrefix(Vertex *ver,char str[],long len,long k)
{
	if(len==k)
		return ver->totalPrefix;

	if(!ver->edges[str[k]-'a'])
		return 0;

	return countPrefix(ver->edges[str[k]-'a'],str,len,k+1);
}


int main()
{
	Vertex *start;
	char str[sz];
	long len;

	start = createNode();
	
	
	while(scanf("%s",str)==1 && strcmp(str,"end")){
		
		len = strlen(str);
		insertWord(start,str,len,0);
	}

	while(scanf("%s",str)==1 && strcmp(str,"end")){
		
		len = strlen(str);
		printf("%ld\n",countWord(start,str,len,0));
	}



	return 0;
}