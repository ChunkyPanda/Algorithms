/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.

Compile:
g++ -o w_quick_union_main w_quick_union_main.c w_quick_union.c

Run:
./w_quick_union_main

 */

#include <stdio.h>
#include "w_quick_union.h"  

/* Made N smaller, so we can print all ids */
#define N 10


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
  }
}
