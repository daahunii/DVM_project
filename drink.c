//22100661 정다훈
/* manager.c */
#include <stdio.h>
#include <string.h>
#include "drink.h"

int selectMenu(){
    int menu;
    printf("\n*** Product ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 음료이름 검색\n");
    printf("7. 음료가격 검색\n");
    printf("8. 음료 유형 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int selectDataNo(Drink *p, int count){
    int no;
    listDrink(p, count);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

int loadData(Drink *p){  // 파일에 저장된 데이터를 불러오는 함수
    
} 

int createDrink(Drink *p){  // 음료수를 추가하는 함수
    printf("음료수명 : ");
    scanf("%s", p->name);
    printf("회사명 : ");
    scanf("%s", p->company);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("음료수 종류(1: 이온 2: 탄산 3: 유제품 4: 과일) : ");
    scanf("%d", &p->type);
    return 1;
} 

void readDrink(Drink p){    // 하나의 음료수 출력 함수
    printf("%s  %d   %s      %d\n", p.name, p.price, p.company, p.type);
}

void listDrink(Drink *p, int count){   // 전체 등록된 음료수 리스트 출력
    printf("No  Name  price  company   type\n");
    printf("=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        printf("%2d", i+1);
        readDrink(p[i]);
    }
}

int updateDrink(Drink *p){
    printf("음료수명 : ");
    scanf("%s", p->name);
    printf("회사명 : ");
    scanf("%s", p->company);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("음료수 종류(1: 이온 2: 탄산 3: 유제품 4: 과일) : ");
    scanf("%d", &p->type);
    return 1;
}

int deleteDrink(Drink *p){  // 제품 정보 삭제
    p->price = -1;
    return 1;
} 

void saveDrink(Drink *p, int count){    // 제품 정보 저장

}

void searchDrink(Drink *p, int count){    // 음료수 이름 검색
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);
    
    printf("No  Name  price  company   type\n");
    printf("=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d", i+1);
            readDrink(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
}

void searchPrice(Drink *p, int count){ // 음료수 가격 검색
    int scnt = 0;
    char search[20];

    printf("검색할 가격? ");
    scanf("%s", search);
    
    printf("No  Name  price  company   type\n");
    printf("=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].weight, search)){
            printf("%2d", i+1);
            readDrink(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
}
void searchType(Drink *p, int count){ // 음료수 유형 검색
    int scnt = 0;
    int search;

    printf("검색할 음료수 유형? ");
    scanf("%d", &search);
    
    printf("No  Name  price  company   type\n");
    printf("=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(p[i].type == search){
            printf("%2d", i+1);
            readDrink(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
}