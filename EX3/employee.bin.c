
#include <stdio.h>
#include <string.h>

typedef struct employee {
    int id ;
    char name[10] ;
    int age ;
    float salary ;
} employee_t ;


int main()
{
    employee_t emp[3] ;
    emp[0].id = 1  ;
    emp[0].age = 20 ;
    emp[0].salary = 30000.000000 ;
    strcpy(emp[0].name , "IU") ;
    
    emp[1].id = 2 ;
    emp[1].age = 26 ;
    emp[1].salary = 36000.000000 ;
    strcpy(emp[1].name , "taylor") ;
    
    emp[2].id = 3 ;
    emp[2].age = 31 ;
    emp[2].salary = 90000.000000 ;
    strcpy(emp[2].name , "swift") ;
    
   FILE* fp = fopen("employee.bin" , "wb+") ;
    for(int n = 0 ; n < 3 ; n++){
        fwrite(emp+n , sizeof(employee_t) , 1 , fp) ;
        fread(emp+n , sizeof(employee_t) , 1 , fp);
        printf("[%d] %d %s\n" , n , emp[n].id , emp[n].name) ;
    }
    fclose(fp) ;

    for(int i = 0 ; i < 3 ; i++){
        printf("employee id = %d\n" , emp[i].id) ;
        printf("employee name = %s\n" , emp[i].name) ;
        printf("employee age = %d\n" , emp[i].age) ;
        printf("employee salary = %f\n" , emp[i].salary) ;
        printf("\n") ;
    }

    return 0;
}
