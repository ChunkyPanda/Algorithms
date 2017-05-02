/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 */

#include <stdio.h>


void print_array_int(int arr[], int size)
{
    int i;
    printf("  i: ");
    for (i = 0; i < size; i++)
        printf("%3d ", i);
    printf("\narr: ");
    for (i = 0; i < size; i++)
        printf("%3d ", arr[i]);
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
        
        //starts modification of the code
        while(temp!=id[temp]){
            prev=temp;
            temp=id[temp];
            id[prev]=root;//sets the previous position to root for full path compression
            size_arr[set_id1]+=1;
        }
    
        id[set_id2] = set_id1;
        size_arr[set_id1] = size_arr[set_id1]  + size_arr[set_id2];
        
        
    }  
}




