#include "manager.h"

void listProduct(Product *s, int count){
    printf("\n No  Name       weight  price   s_price  star\n");
    printf("================================================\n");
    for(int i=0; i<count; i++){
        if(s[i].price == -1){continue;}
        printf("%2d  ", i+1);
        readProduct(s[i]);
    }
    printf("\n");
}


int selectDataNo(Product *s, int count){
    int no;
    listProduct(s,count);
    printf("번호는 (취소:0)? ");
    getchar();
    scanf("%d", &no);
    return no;
}

