/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.

Compile:
g++ -o w_quick_union_main w_quick_union_main.c w_quick_union.c

Run:
./w_quick_union_main

 */

#include <stdio.h>


/* Made N smaller, so we can print all ids */
#define N 10
void print_array_int(int arr[], int size)
{
    int i;
    printf("  i: ");
    for (i = 0; i < size; i++)
        printf(" %d ", i);
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
  printf("   %d ", next_object);
  while (next_object != id[next_object])
  {	
    next_object = id[next_object];
	printf("   %d ", next_object);
  }

  return next_object;
}

/* unites the two sets specified by set_id1 and set_id2 */
void set_union(int set_id1, int set_id2, int id[], int size, int size_arr[])
{
  if (size_arr[set_id1] < size_arr[set_id2])
  {
	id[set_id1] = set_id2;
	size_arr[set_id2] = size_arr[set_id1]  + size_arr[set_id2];
  }
  else
  {
	id[set_id2] = set_id1;
	size_arr[set_id1] = size_arr[set_id1]  + size_arr[set_id2]; 
  }
}


main()
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
      continue;
    }
   
    set_union(p_id, q_id, id, N, size_arr);	    
    printf(" %d %d link led to set union\n", p, q);
	print_array_int(id, N);    
  }
}
