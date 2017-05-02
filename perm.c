#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "perm.h"




int task1_rec(int N,int arr[]){
   
    if(arr[N]!=0)return arr[N];
    
    else if (N==0 ) return arr[N]= 1;
	
	else if(N==1) return arr[N]=1;
    
    if (N%2==1) {
    
        return arr[N]=task1_rec(N+1,arr)-2;
    
    
    }else return arr[N]=task1_rec(N/2,arr)+task1_rec(N-2,arr);
    
}


int task_1(int N){
    
    if(N==0){printf("You Wrong No Zero");return 0;}
    
    
    int *arr = (int*)malloc((N+1)*sizeof(int)),p;
    int i;
    for(i=0;i<N;i++)
    arr[i]=0;
 
    task1_rec(N, arr);
    
    p=arr[N];
    
    for(i=0;i<N;i++)
    printf("task(%d)=%d\n",i,arr[i]);
   
    //free mammary
    free(arr);
     
    return p;
}

void free_matrix_ptr(matrix_ptr my_matrix){
    
    int i;
    for( i=0;i<my_matrix->rows;i++)free(my_matrix->data_arr[i]);
    free(my_matrix);
}

void rec1_helper(int N, int nr_vals,int arr[],int pos){
    pos=pos+1;
    if(pos==N){
	int i;
        for( i=0;i<N;i++)printf("%d ",arr[i]);
        printf("\n");
        return;}
        
		
		int j;
    
    for(j = 0; j<nr_vals;j++){
        arr[pos]=j;
        rec1_helper(N,nr_vals, arr,pos);
    }
}

void rec2_helper(int nr_vals,int arr[],matrix_ptr a,int pos){
    pos=pos+1;
    if(pos==a->rows){
        a->data_arr=(int**)realloc(a->data_arr, (a->rows+1)*sizeof(int*));
        a->data_arr[a->rows]=(int*)malloc((a->rows)*sizeof(int));
        
		int i;
        for( i= 0;i<a->cols;i++)a->data_arr[a->rows][i]=arr[i];
        a->rows+=1;
        
        return;}
    int i;
    
	for( i = 0; i<nr_vals;i++){
        arr[pos]=i;
        rec2_helper(nr_vals,arr,a,pos);
    }
}

void perm_rec_1(int N, int nr_vals){
    int *Arr = (int*)malloc(N*sizeof(int));
    
rec1_helper(N,nr_vals,Arr,-1);
}

matrix_ptr perm_rec_2(int N, int nr_vals) {
    
    matrix_ptr m = (matrix_ptr)malloc(sizeof(matrix_ptr));
    m->rows=0;
    m->cols=N;
    int *Arr=(int*)malloc(N*sizeof(int));
    
    rec2_helper(nr_vals,Arr,m,-1);
    
    free(Arr);
    return m;
}


void perm_iter(int N, int nr_vals){
	/*
int count=0;
    int* arr =(int*)calloc(1, sizeof(int));
    while(arr[N-N]<nr_vals)
    {
        arr[N-1]= num[counter];
       
        for(int x=0;)
        
        
        }
        
        
            
        }
        
        if(arr[N-3]>nr_vals-1){
            arr[N-3]=0;
            arr[N-N]=arr[0]+1;
        }

	*/
    
}



