/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 */

#include <stdio.h>


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

