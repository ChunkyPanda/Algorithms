/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.

Compile:
g++ -o t9 task9_main.c task9_full.c

Run:
./t9

 */

#include <stdio.h>


#define N 10



#include <stdio.h>


void print_array_int(int arr[], int size)
{
    int i;
    printf("  i: ");
    for (i = 0; i < size; i++)
        printf("% d ", i);
    printf("\narr: ");
    for (i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}

/* returns the set id of the object. */
int find(int object, int id[])
{
    int next_object;
    next_object = id[object];
    
    printf("\nFind root of %d\n\t", object);
    printf("   %d\n ", next_object);
    while (next_object != id[next_object])
    {
        next_object = id[next_object];
        printf("   %d\n ", next_object);
    }
    
    return next_object;
}


void set_union(int set_id1, int set_id2, int id[], int size, int size_arr[], int p, int q)
{
    
    int root,temp,prev;
    if (size_arr[set_id1] < size_arr[set_id2])
    {   temp=p;
            root = set_id2;
        
        while(temp!=id[temp]){
            prev=temp;
             temp=id[temp];
              id[prev]=root;
               size_arr[set_id1]+=1;
        }
        id[set_id1] = set_id2;
        size_arr[set_id2] = size_arr[set_id1]  + size_arr[set_id2];
        
    }
    else{
        //added temp to store previous value
        temp=q;
        root = set_id1;
        
        
        while(temp!=id[temp]){
             prev=temp;
              temp=id[temp];
                id[prev]=root;//sets the previous position to root
            size_arr[set_id1]+=1;
        }
    
        id[set_id2] = set_id1;
        size_arr[set_id1] = size_arr[set_id1]  + size_arr[set_id2];
        
        
    }  
}





int main()
{ 
  int p, q, i, id[N], p_id, q_id, size_arr[N];
  // initialize ids and size
  for (i = 0; i < N; i++) 
  {
	  id[i] = i;
	  size_arr[i] = 1; 
  }
  
  // read pairs and keep/update connected components information
  printf("Enter pairs p q: \n");
  while (scanf("%d %d", &p, &q) == 2)
  { 
    p_id = find(p, id);
    q_id = find(q, id);

    if (p_id == q_id) 
    {
      printf(" %d and %d were on the same set\n", p, q);
	  print_array_int(id, N);
      continue;
    }
   
    set_union(p_id, q_id, id, N, size_arr, p, q);	    
    printf(" %d %d link led to set union\n", p, q);    
	print_array_int(id, N);
  }
}
