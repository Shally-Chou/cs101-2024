#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lotto_record {
    int receipt_id ;
    int receipt_price ;
    char receipt_time[32] ;
    int lotto_set[5][7] ;
} lotto_record_t ;

int check_recordbin(int record_num){
    int sold_series = 0 ;
    FILE* ptr = fopen("record.bin", "r+");
    if(ptr == NULL){
        return 0;
    }
    
    lotto_record_t tmp;
    while(fread(&tmp, sizeof(lotto_record_t), 1, ptr)){
        sold_series++;
    }
    
    fclose(ptr) ;
    return sold_series ;
}

lotto_record_t buy_lotto(int num , int sold_series){
    srand((unsigned)time(NULL)) ;
	int tm , same = 0 , lotto[5][7] , tmp[6] ;
	lotto_record_t lotto_r ;
	
	char file_name[23] ;
	printf("%d\n" , sold_series) ;
	sprintf(file_name , "lotto[%05d].txt" , sold_series) ;
	
	FILE* fp = fopen(file_name, "w+") ;
	fprintf(fp , "======== lotto649 ========\n") ;
	fprintf(fp , "=======+ No.%05d +=======\n" , sold_series) ;
	
	time_t curtime;
	time(&curtime);
	struct tm* info = localtime(&curtime);
	fprintf(fp, "= %s", asctime(info));
	
	for(int i = 0 ; i<num ; i++){
		same = 1 ;
		while(same){
			same = 0 ;
			for(int j = 0 ; j<6 ; j++){
				tmp[j] = (rand()% 69) + 1;
			}
			tmp[6] = (rand()% 9) + 1;
			for(int j = 0 ; j<=6-1 ; j++){
				for(int k = j+1 ; k<=6 ; k++){
					if(tmp[j] == tmp[k]){
						same = 1;
						break;
					}
				}
			}
		}
		
		for(int j = 0 ; j <= 4 ; j++){
		    for(int k = j+1 ; k<=5 ; k++){
		        if(tmp[j]>tmp[k]){
		            tm = tmp[k];
		            tmp[k] = tmp[j];
		            tmp[j] = tm;
		        }
		    }
		}
		
		for(int j = 0 ; j<=6 ; j++){
			lotto[i][j] = tmp[j];
			lotto_r.lotto_set[i][j] = tmp[j];
		}
	}
	
	for(int i = 0 ; i<num ; i++){
		fprintf(fp, "[%d]: ", i+1);
		for(int j = 0 ; j<=6 ; j++){
			if(lotto[i][j]<=9)
				fprintf(fp, "0");
			fprintf(fp, "%d ", lotto[i][j]);
		}
		fprintf(fp, "\n");
	}
	
	lotto[num][0] = -1;
	for(int i = num ; i<5 ; i++){
		fprintf(fp, "[%d]: __ __ __ __ __ __ __ \n", i+1) ;
	}
	fprintf(fp, "======== csie@CGU ========") ;
	lotto_r.receipt_id = sold_series ;
	lotto_r.receipt_price = 100*num ;
	
    strcpy(lotto_r.receipt_time, asctime(info)) ;
    fclose(fp) ; 
    
    return lotto_r;
}

void print_lotto(lotto_record_t lotto, int* code){
    printf("以下為中獎彩券 :\n彩券 NO.%d \n", lotto.receipt_id);
    printf("售出時間 : %s", lotto.receipt_time);
    for(int i = 0 ; i<5 ; i++){
        if(*code == 1){
            printf("號碼 : ");
            for(int j = 0 ; j<7 ; j++){
                if(lotto.lotto_set[i][j]<10)
                    printf("0");
                printf("%d ", lotto.lotto_set[i][j]);
            }
            printf("\n");
        }
        *code++;
    }
}

void pay_back(){
    char c;
    printf("請輸入中獎號碼 (最多三個) :");
    scanf("%c" , &c);
    char a[50];
    fgets(a , 50 , stdin);

    int i = 4;
    int j = 0 , k = 0 , tmp = 0 , start_index = 0, end_index = 0 ;
    
    int len = sizeof(a)/sizeof(char)-1;
    int arr[3];
    
    for (int j=0 ; j<=len ; j++) {
        if (a[j]>='0' && a[j]<='9') {
            tmp = (tmp*10) + (a[j]-'0');
        }
        else if (a[j] == ' ' || a[j] == '\n'){
            arr[end_index] = tmp;
            end_index += 1;
            tmp = 0;
        }
    }
    
    printf("輸入中獎號碼為 : ");
    for(i = 0 ; i<3 ; i++){
        if(arr[i] < 10)
            printf("0");
        printf("%d ", arr[i]);
    }
    
    int Win = 0, any = 0, code[5] = {0 , 0 , 0 , 0 , 0};
    FILE* ptr = fopen("record.bin", "r+");
    lotto_record_t tmpf;
    while(fread(&tmpf, sizeof(lotto_record_t), 1, ptr)){
        for(int qw = 0 ; qw<tmpf.receipt_price/100 ; qw++){
            for(int we = 0 ; we<7 ; we++){
                for(int er = 0 ; er<3 ; er++){
                    if(arr[er] == tmpf.lotto_set[qw][we]){
                        Win = 1;
                        code[qw] = 1;
                    }
                }
            }
        }
        
        if(Win == 1){
            if(any == 0){
                printf("以下為中獎彩券 :\n");
                any = 1;
            }
            print_lotto(tmpf , code);
            Win = 0;
            for(int qw = 0 ; qw<5 ; qw++){
                code[qw] = 0 ;
            }
        }
    }
    
    if(any == 0)
        printf("\n很遺憾您並未中獎");
    fclose(ptr);
}

void record(lotto_record_t lotto , int sold_series){
    FILE *fp = fopen("record.txt", "w+");
    fwrite(&lotto, sizeof(lotto_record_t), 1, fp);
    fclose(fp);
}

int main()
{
    int num , record_num = 1000 , sold_series;
	lotto_record_t lotto_;
	printf("請問您要買幾組樂透彩 : ");
	scanf("%d", &num);
	if(num == 0){
	    pay_back();
	}
	else{
	    sold_series = check_recordbin(record_num) ;
	    lotto_ = buy_lotto(num , sold_series+1);
	    printf("%s" , lotto_.receipt_time);
	    record(lotto_ , sold_series);
	}

    return 0;
}
