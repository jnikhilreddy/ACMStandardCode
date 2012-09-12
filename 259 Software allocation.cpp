#include<stdio.h>
#include<string.h>

long g[11][11],gv[11][11],v[11],arr[11],mat[11][11],flg;
bool flag[11];
char ver[30];

int bpm(long i)
{
	long j,t,k;
	for(j=1;j<=g[i][0];j++)
	{
		t=g[i][j];
		if(flag[t])continue;
		flag[t]=true;
		if(gv[t][0]<v[t])
		{
			arr[i]=t;
			gv[t][0]++;
			gv[t][gv[t][0]]=i;
			return 1;
		}
		else
		{
			for(k=1;k<=gv[t][0];k++)
			{
				if(bpm(gv[t][k]))
				{
					arr[i]=t;
					gv[t][k]=i;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	//freopen("259.in","r",stdin);
	char str[100];
	long i,tmp,j,t;
	while(gets(str))
	{
		for(i=0;i<10;i++)g[i][0]=0;
		i=0;
		tmp=0;
		flg++;
		while(str[0])
		{
			ver[i]=str[0];
			v[i]=str[1]-48;
			tmp+=v[i];
			for(j=2;str[j]!=';'&&str[j];j++)
			{
				t=str[j]-48;
				if(mat[i][t]==flg)continue;
				if(t<0||t>9)continue;
				mat[i][t]=flg;
				g[t][0]++;
				g[t][g[t][0]]=i;
			}
			i++;
			if(gets(str)==NULL)break;
		}
		if(tmp<=10)
		{
			memset(arr,-1,sizeof(arr));
			memset(gv,0,sizeof(gv));
			for(j=0;j<10;j++)
			{
				memset(flag,0,sizeof(flag));
				bpm(j);
			}
			for(j=0;j<10;j++)
			{
				printf("%ld ",v[j]);
			}printf("\n");
			for(j=0;j<i;j++)
				if(v[j]!=gv[j][0])break;
			if(i==j)
			{
				for(j=0;j<10;j++)
				{
					if(arr[j]>=0)
						printf("%c",ver[arr[j]]);
					else
						printf("_");
				}
				printf("\n");
			}
			else
				printf("!\n");;
		}
		else
			printf("!\n");
	}
	return 0;
}