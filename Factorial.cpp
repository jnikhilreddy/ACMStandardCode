#include<stdio.h>
#include<stdlib.h>
struct list{
     char q;
     struct list *f;
}*(l1[1002]),*l2,*l3;
void made(){
     int j,i,r,c,ac,l,n;
     char a[2600];
     a[0]=l=1;
     l1[0]=l1[1]=(list*)malloc(sizeof(list));
     l3=l1[0];
     l1[0]->q=1;
     l3->f=NULL;
     for(n=2;n<=1000;n++){
	  ac=c=0;
	  for(i=0;i<l;i++){
	       r=a[i]*n+c;
	       c=r/10;
	       a[i]=r%10+ac;
	       ac=a[i]/10;
	       a[i]%=10;
	  }
	  r=c+ac;
	  while(r){
		a[i++]=r%10;
		r/=10;
	  }
	  l=i;
	  l1[n]=(list*)malloc(sizeof(list));
	  l2=l1[n];
	  for(j=l-1;j>=0;j--){
	       l3=l2;
	       l2->q=a[j];
	       l2->f=(list*)malloc(sizeof(list));
	       l2=l2->f;
	  }
	  l3->f=NULL;
     }
}
void main(){
     int d;
     made();
     while(1==scanf("%d",&d)){
	  printf("%d!\n",d);
	  l3=l1[d];
	  while(l3){
	       printf("%d",l3->q);
	       l3=l3->f;
	  }
	  printf("\n");
     }
}
