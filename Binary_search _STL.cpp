#include <stdio.h>
#include <stdlib.h>

int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int values[] = { 10, 20, 25, 40, 90, 100 };

int main ()
{
  int * pItem;
  int key = 90;
  pItem = (int*) bsearch (&key, values, 6, sizeof (int), compareints);
  if (pItem!=NULL)
    printf ("%d is in the array location %d.\n",*pItem,pItem-&values[0]);
  else
    printf ("%d is not in the array.\n",key);
  return 0;
}