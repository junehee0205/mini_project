#include "manager.h"
Product plist[100];
#define DEBUG
    
    
int main(void){
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
   
#endif

    count = loadData(plist);  
    curcount = count;

    while (1){
        menu = selectmenu();
        if (menu == 0) break;
        
        if (menu == 1){
            if (count > 0){
                listProduct(plist,curcount);
            }
            else{ printf("데이터가 없습니다\n");
            }
        }
        else if (menu == 2){count += addProduct(&plist[curcount++]);}
        else if (menu == 3){
            int no = selectDataNo(plist, curcount);
            if(no ==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(plist, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            getchar();
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&plist[no-1])){
                count --;}
            }
	else if (menu ==5){
            if(count ==0){
                printf("데이터가 없습니다\n");
            }
            else{
                saveData(plist, curcount);
            }
        }
        else if (menu == 6){
            searchName(plist, curcount);
        }
        else if (menu == 7){
            searchWeight(plist, curcount);
        }
        else if (menu == 8){
            searchPrice(plist, curcount);
        }
        else if (menu == 9){
            searchStar(plist, curcount);
        }
	}
    printf("종료됨!\n");
    return 0;
}
