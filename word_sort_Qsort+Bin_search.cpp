#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 100

struct jony
{
	char s1[22];
	//char s2[12];

};

jony store[CSE];

char str[50],str1[11],str2[11],t[11],inp[11];
long cnt;

int comp(const void *p,const void *q)
{
	jony *x,*y;

	x=(jony *)p;
	y=(jony *)q;
    return(strcmp(x->s1,y->s1));
	

}
/*
long Bsearch(long l, long r)
{
	long value;
	long m = (l + r) / 2;
	if( l > r ) 
	{
		return -1;
	}
	value = strcmp(inp, store[m].s2);
	if(!value) 
	{
		return m;
	}
    if( l == r ) 
    {
	   return -1;
    }
	if(value < 0)
	{
		return Bsearch(l, m-1);
	}
	else
	{
		return Bsearch(m+1, r);
	}
}
*/
int main()
{

	cnt=0;
	
	int pos,i;

	while(scanf("%s",str)==1 && strcmp(str,"END"))
	{
	    //sscanf(str,"%s",str1);
		
		strcpy(store[cnt++].s1,str);
		//strcpy(store[cnt++].s2,str2);

		memset(str,'\0',sizeof(str));
		//memset(str1,'\0',sizeof(str2));
		//memset(str2,'\0',sizeof(str2));
	}

	qsort(store,cnt,sizeof(jony),comp);

	for(i=0;i<cnt;i++)
	{
		printf("%s\n",store[i].s1);
	}

	/*while(scanf(" %s",inp) ==1)
	{
		
		pos=Bsearch(0,cnt);
		if(pos!=-1)
		{
			printf("%s\n",store[pos].s1);
		}
		else
		{
			printf("eh\n");
		}
		memset(inp,'\0',sizeof(inp));
	}*/

	return 0;
}