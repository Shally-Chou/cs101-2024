/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void print_space(int i , int n) {
    for(int space = 0 ; space <= n-i ; space++) {
        printf(" ") ;
    }
}

void print_number(int n) {
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",n) ;
    }
    printf("\n") ;
}


int main()
{
    int loop = 6 ;
    for(int i = 1 ; i <= loop ; i++) {
        print_space(i , loop) ;
        print_number(i) ;
    }
    


    return 0;
}
