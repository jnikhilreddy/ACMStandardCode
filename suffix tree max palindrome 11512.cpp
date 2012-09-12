#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>


#include<algorithm>
using namespace std;

#define CSE 1009

void PL()
{
	printf("\n");
}

char s[CSE];
int len;

struct SSS
{
	int ln;
	char Suffix[CSE];
	int sa;
};

SSS arr[CSE];
int isa[CSE],lcp[CSE];

void Free()
{
}

int SORT(void const *p,void const *q)
{
	SSS *x,*y;
	x=(SSS *)p;
	y=(SSS *)q;
	return strcmp(x->Suffix,y->Suffix);

}

void build_suffix_array()
{
	int k,i,j,cnt;
	k=0;
	for(i=0;i<len;i++,k++)
	{
		for(j=k,cnt=0;j<len;j++,cnt++)
		{
			arr[k].Suffix[cnt]=s[j];
		}
		arr[k].Suffix[cnt]='\0';
		arr[k].sa=k;
		arr[k].ln=len-k;
	}
	qsort(arr,len,sizeof(SSS),SORT);

	
	printf("SA :\n");
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i].sa);
	}
	PL();
}

void build_inverse_suffix_array()
{
	int i;
	for(i=0;i<len;i++)
	{
		isa[arr[i].sa]=i;
	}
}

void build_lcp()
{
	int i,ln,j;
    
	for(i=0;i<=len;i++)
	{
		lcp[i]=0;
	}

	ln = 0;
    for(i=0;i<len;i++)
	{
		if(isa[i] >= 1)
		{          
			j=arr[isa[i]-1].sa;
			while( ((i+ln)<len && (j+ln)<len) && s[i+ln]==s[j+ln])
			{ 
				ln++;
			}
			lcp[isa[i]]=ln;
			ln=ln>1?ln-1:0;
		}
	}

	printf("lcp:\n");
	for(i=0;i<len;i++)
	{
		printf("%d ",lcp[i]);
	}
	PL();

}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);

	int t,i,j,k,cc;
	int mx,mx_loc;

	scanf("%d",&t);

	while(t--)
	{
		scanf(" %s",s);
		len=strlen(s);
		build_suffix_array();
		build_inverse_suffix_array();
		build_lcp();

		mx=mx_loc=0;
		for(i=0; i<len; i++)
		{
			if(lcp[i] > mx)
			{
				mx = lcp[i];
				mx_loc = i;
			}
		}
		printf("mx  %d  mx_loc %d\n",mx,mx_loc);

		if(!mx) 
		{
			printf("No repetitions found!\n");
		}
		else
		{
			cc=1;	
			i=mx_loc;
			while( lcp[i] == mx)
			{
				cc++;
				i++;
			}
			for(j=arr[mx_loc].sa,k=0;k<mx;j++,k++)
			{
				printf("%c",s[j]);
			}
			printf(" %d\n",cc);
	}


	}
	return 0;
}
/*
Input:
6
GATTACA
GAGAGAG
GATTACAGATTACA
TGAC
TGTAC
TTGGAACC

Output:
A 3
GAGAG 2
GATTACA 2
No repetitions found!
T 2
A 2

For calculate max palindrome:

CAABBAABBC#CBBAABBAAC
CABBBABC#CBABBBAC

*/