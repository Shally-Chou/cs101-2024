/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp ;
    
    int a_w[3] = { 0 , 1 , 2 } ;
    int a_r[3] ;
    char b_w[3] = "ABC" ;
    char b_r[3] ;
    float c_w[3] = { 1.1 , 1.2 , 1.3 } ;
    float c_r[3] ;
    
    fp = fopen("a.bin" , "wb+") ;
    fwrite(a_w , sizeof(a_w) , 1 , fp) ;
    fseek(fp , 0 , SEEK_SET) ;
    fread(a_r , sizeof(a_r) , 1 , fp) ;
    
    fp = fopen("a.bin" , "wb+") ;
    fwrite(b_w , sizeof(b_w) , 1 , fp) ;
    fseek(fp , 0 , SEEK_SET) ;
    fread(b_r , sizeof(b_r) , 1 , fp) ;
    
    fp = fopen("a.bin" , "wb+") ;
    fwrite(c_w , sizeof(c_w) , 1 , fp) ;
    fseek(fp , 0 , SEEK_SET) ;
    fread(c_r , sizeof(c_r) , 1 , fp) ;
    
    for(int i = 0 ; i < 3 ; i++ ){
        printf("%d ", a_r[i]);
    }
    printf("\n") ;
    for(int j = 0 ; j < 3 ; j++ ){
        printf("%c ", b_r[j]);
    }
    printf("\n") ;
    for(int v = 0 ; v < 3 ; v++ ){
        printf("%f ", c_r[v]);
    }
    
    

    return 0;
}
