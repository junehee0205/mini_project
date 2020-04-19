#include "product.h"


int selectmenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 무게검색\n");
    printf("8. 가격검색\n");
    printf("9. 별점검색\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *s){
    printf("이름은?");
    scanf("%s", s->name);
    printf("무게(g)는?");
    scanf("%d", &s->weight);
    printf("가격은?");
    scanf("%d", &s->price);
    printf("표준 가격은?");
    scanf("%d", &s->s_price);
    printf("별점은?");
    scanf("%d", &s->star);
    printf("=> 추가됨!\n");
    return 1;
}

void readProduct(Product s){
    if(s.weight == -1 && s.price == -1 && s.s_price == -1 
    && s.star == -1){
        return;
    }
    printf("%-8s   %5d   %6d   %6d   %d\n",
    s.name, s.weight, s.price, s.s_price, s.star);
}

int deleteProduct(Product *s){
    s->weight = -1;
    s->price = -1;
    s->s_price= -1;
    s->star = -1;
    return 1;
}

int updateProduct(Product *s){
    printf("새 이름은?");
    scanf("%s", s->name);
    printf("새 무게(g)는?");
    scanf("%d", &s->weight);
    printf("새 가격은?");
    scanf("%d", &s->price);
    printf("새 표준 가격은?");
    scanf("%d", &s->s_price);
    printf("새 별점은?");
    scanf("%d", &s->star);
    printf("=> 변경됨!\n");
}

void searchName(Product *s, int count){
    int scount =0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\n No Name      weight     price s_price  star\n");
    printf("================================================\n");
    for(int i=0; i<count; i++){
        if(s[i].price != -1){
            if(strstr(s[i].name, search)){
                printf("%2d ", i+1);
                readProduct(s[i]);
                scount++;
            }
        }
    }

    if(scount == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
