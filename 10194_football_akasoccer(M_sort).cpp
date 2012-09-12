#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define CSE 40
#define PN 110

struct PACK
{
	char name[CSE] ;
	int game_played ;
	int points ;            
	int wins ;
	int ties ;
	int losses ;
	int goal_diff ;
	int goal ;
	int goal_against ;
	
}a[CSE];

char TN[PN],team1[CSE],team2[CSE];
long goal_1,goal_2;

void init(long N)
{
      long i;
	  for(i=0;i<=N;i++)
	  {
	      a[i].game_played=0;
		  a[i].goal=0;
		  a[i].goal_against=0;
		  a[i].goal_diff=0;
		  a[i].losses=0;
		  a[i].points=0;
		  a[i].ties=0;
		  a[i].wins=0;
	  }
}

int my_strcmp( char S1[], char S2[] )
{
	char str1[105], str2[105];
	long i, len ;

	strcpy(str1, S1);
	strcpy(str2, S2);

	len = strlen(str1);

	for(i=0;i<len;i++) 
	{
		str1[i]= tolower(str1[i]);
	}
	len = strlen(str2);

	for(i=0;i<len;i++ ) 
	{
		str2[i]  = tolower(str2[i]);
	}
	if( strcmp(str1, str2)>0 ) 
	{
		return 1;
	}
	if( strcmp(str1, str2)<0 ) 
	{
		return -1;
	}
	return  0;
}


int comp(const void *p,const void *q)
{
	PACK *x,*y;

	x=(PACK *)p;
	y=(PACK *)q;
	
	if(x->points == y->points)
	{
		if(x->wins == y->wins)
		{
		     if(x->goal_diff == y->goal_diff)
			 {
			      if(x->goal == y->goal)
				  {
				       if(x->game_played == y->game_played)
					   {
					        
						if(my_strcmp(x->name,y->name)>0)return 1;
						if(my_strcmp(x->name, y->name)<0) return -1;
						if(my_strcmp(x->name,y->name)==0) return 0;
					   }
					   else
					   {
					       return (x->game_played - y->game_played);
					   }
				  }
				  else
				  {
				       return (y->goal - x->goal);
				  }
			 }
			 else
			 {
			      return (y->goal_diff - x->goal_diff);
			 }
		}
		else
		{
		     return (y->wins - x->wins);
		}
	}
	else
	{
	     return (y->points - x->points);
	}

}

int main()
{
	//freopen("10194.out","w",stdout);

	long tcase,total_team,i,total_match,j,count=1,pik=1;

	scanf("%ld",&tcase);

	while(tcase--)
	{
	     if(pik == 2)
		 {
		      printf("\n");
		 }
		 pik = 2;

		 scanf(" %[^\n]",TN);
		 scanf("%ld",&total_team);
		 for(i=0;i<total_team;i++)
		 {
		       scanf(" %[^\n]",a[i].name);
		 }

		 init(total_team);
		 
		 scanf("%ld",&total_match);

		 for(i=0;i<total_match;i++)
		 {
		       scanf(" %[^#]#%d@%d#%[^\n]",team1,&goal_1,&goal_2,team2);
			   for(j=0;j<total_team;j++)
			   {
			        if(strcmp(a[j].name,team1) == 0)
					{
						a[j].game_played++;
						a[j].goal_against+=goal_2;
						a[j].goal+=goal_1;
						if(goal_1>goal_2)
						{
						     a[j].points+=3;
							 a[j].wins++;
							 a[j].goal_diff+=(goal_1-goal_2);
						}
						else if(goal_1<goal_2)
						{
						     a[j].losses++;
							 a[j].goal_diff+=(goal_1-goal_2);
						}
						else
						{
						     a[j].ties++;
							 a[j].points++;
						}
					}
					else if(strcmp(a[j].name,team2) == 0)
					{
						a[j].game_played++;
						a[j].goal_against+=goal_1;
						a[j].goal+=goal_2;
						if(goal_1<goal_2)
						{
						     a[j].points+=3;
							 a[j].wins++;
							 a[j].goal_diff+=(goal_2-goal_1);
						}
						else if(goal_1>goal_2)
						{
						     a[j].losses++;
							 a[j].goal_diff+=(goal_2-goal_1);
						}
						else
						{
						     a[j].ties++;
							 a[j].points++;
						}
					} 
			   }
		 }

		 qsort(a,total_team,sizeof(PACK),comp);
		 count=1;
		 printf("%s\n",TN);
		 for(i=0;i<total_team;i++)
		 {
		     printf("%ld) %s %ldp, %ldg (%ld-%ld-%ld), %ldgd (%ld-%ld)\n",count++,a[i].name,a[i].points,a[i].game_played,a[i].wins,a[i].ties,a[i].losses,a[i].goal_diff,a[i].goal,a[i].goal_against);
		 }
	}

	return 0;
}