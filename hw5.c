//
//  main.c
//  neil
//
//  Created by Emmanuel Lennix on 11/7/15.
//  Copyright © 2015 Emmanuel Lennix. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>


int distance (const char * s1, const char * s2)
{
    
    
    int count[strlen(s1) + 1][strlen(s2) + 1];
    
    
    int i,remove, enter,temp, lower,j;
    
    
    
    for (i = 0; i <= strlen(s1); i++)
        count[i][0] = i;
    
    
    
    for (i = 0; i <= strlen(s2); i++)
        
        
        count[0][i] = i;
    
    for (i = 1; i <= strlen(s1); i++)
    {
        
        
        char c1= s1[i-1];
        
        
        for (j = 1; j <= strlen(s2); j++)
        {
            
            
            char c2 = s2[j-1];
            
            
            if (c1 == c2) {
                
                
                count[i][j] = count[i-1][j-1];
           
            
            }
            
            
            
            else {
                
                temp = count[i-1][j-1] + 1;
                
                
                remove = count[i-1][j] + 1;
                
                
                enter = count[i][j-1] + 1;
                
                
                lower = remove;
                
                
                
                if (enter < lower)
                {
                    
                    lower = enter;
                
                }
                
                
                if (temp < lower)
                {
                   
                    
                    
                    lower = temp;
                
                    
                    
                }
                
                
                
                count[i][j] = lower;
            }
        }
    }
    return count[strlen(s1)][strlen(s2)];
}




int main(int argc, const char * argv[])
{
    int N=1000;
    char first[N],second[N];
    while(first[0]!='-' && second[0]!='-')
    {
        scanf("%s",first);
        scanf("%s",second);
        printf("The distence is %d\n",distance(first, second));
        
    }
    return 0;
}


