#include<stdio.h>

#define cse_1 120

struct jony
{
     long arr[cse_1];
 long N;
 long res;
}; 

jony inp,temp[100];
long c[4],a[cse_1],test,tcount;

void process_soln(long k)
{
     long cnt,index[cse_1],sum=0,count=0,i,j;

 
 for(i=1;i<=k;i++)
 {
      if(a[i] == 1)
  {
      index[++count]=i;
  sum+=inp.arr[i];
  }
 }
 cnt=0;
 if(sum == inp.res)
 {
  for(j=1;j<tcount;j++)
  {
      if(temp[j].N == count)
  {
         for(i=1;i<=temp[j].N;i++)
 {
     if(temp[j].arr[i] == inp.arr[index[i]])
 {
     cnt++;
 }
 if(cnt == count)
 {
      return;
 }
 }
  }
  }
      for(i=1;i<=count;i++)
  {
       if(i>1)
   {
     printf("+");
   }
   printf("%ld",inp.arr[index[i]]);
   temp[tcount].arr[i]=inp.arr[index[i]];
   }
   temp[tcount].N=count;
   
   printf("\n");

   test++;
   tcount++;
 }

 return;
}

void backtrack(long k)
{
     long i;

 if(k == inp.N)
 {
     process_soln(k);
 }
 else
 {
     k++;

 for(i=0;i<2;i++)
 {
     a[k]=c[i];

 backtrack(k);
 }
 }
}

int main()
{
long i;

c[0]=1;
c[1]=0;

while(1)
{
    
scanf("%ld",&inp.res);

  
          
  test=0;
  
  tcount=1;

  scanf("%ld",&inp.N);

  if(inp.N == 0)
  {
       break;
  }
          
  printf("Sums of %ld:\n",inp.res);

  for(i=1;i<=inp.N;i++)
  {
       scanf("%ld",&inp.arr[i]);
  }
  

  backtrack(0);
  if(test == 0)
  {
       printf("NONE\n");
  }
}

return 0;
}
