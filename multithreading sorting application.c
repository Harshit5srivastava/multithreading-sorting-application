#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int ptr[10];
int b[10];
int c[5],d[5];
int low=0,high=9,high1=4;
void *runnable(void *c);
void *runnable1(void *ptr);



void merge1(int low, int mid, int high1) {
   int l, r, i;

   for(l = low, r = mid + 1, i = low; l <= mid && r <= high1; i++) {
      if(c[l] <= c[r])
        d[i] = c[l++];
      else
         d[i] = c[r++];
   }
   
   while(l <= mid)    
      d[i++] = c[l++];

   while(r <= high1)   
      d[i++] = c[r++];

   for(i = low; i <= high1; i++)
     {
	   c[i] = d[i];
  }
	  
}

void mergesort1(int low,int high1) {
   int mid;
   	int *elements = (int*)c; 
   	
   if(low < high1) {
      mid = (low + high1) / 2;
      mergesort1(low, mid);
      mergesort1(mid+1, high1);
      merge1(low, mid, high1);
   } else { 
      return;
   }   
}
void merge(int low, int mid, int high) {
   int l, r, i;

   for(l = low, r = mid + 1, i = low; l <= mid && r <= high; i++) {
      if(ptr[l] <= ptr[r])
        b[i] = ptr[l++];
      else
         b[i] = ptr[r++];
   }
   
   while(l <= mid)    
      b[i++] = ptr[l++];

   while(r <= high)   
      b[i++] = ptr[r++];

   for(i = low; i <= high; i++)
     {
	   ptr[i] = b[i];
  }
	  
}

void mergesort(int low,int high) {
   int mid;
   	int *elements = (int*)ptr; 
   	
   if(low < high) {
      mid = (low + high) / 2;
      mergesort(low, mid);
      mergesort(mid+1, high);
      merge(low, mid, high);
   } else { 
      return;
   }   
}

int main()
{
		int n = 10; 
printf(" enter 10 elements \n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&ptr[i]);
	}
	for(int i=0;i<5;i++)
	{
	c[i]=ptr[i];
	}
	
	  printf("\n 2 sorted subarray are:\n ");

	
		pthread_t t1,t2,t3;
		pthread_create(&t1, NULL, runnable, (void *)c);
 pthread_join( t1,NULL);

      for(int i=0;i<5;i++)
 {printf("%d\t",c[i]);
 }
  printf("\n");

 for(int i=0;i<5;i++)
	{
		c[i]=ptr[i+5];
	}
 	pthread_create(&t2, NULL, runnable, (void *)c);
 pthread_join( t2,NULL);
     for(int i=0;i<5;i++)
 {printf("%d\t",c[i]);
 }
 
 printf("\nafter merging\n");
 	pthread_create(&t3, NULL, runnable1,(void*)ptr);
 pthread_join( t3,NULL);
 for(int i=0;i<10;i++)
 {
 	printf(" %d\t",b[i]);
 }
 
 
}
void *runnable(void *c)
{
	mergesort1(low,high1);
}

void *runnable1(void * ptr)
{
	mergesort(low,high);
}



