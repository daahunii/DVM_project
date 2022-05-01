#include <stdio.h>
#include <string.h>
#include "drink.h"

int main(){
    Drink  d[20];
    int idx = 0, count = 0, menu;

    count = loadData(d);
    idx = count;

    while(1){
   	menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0) listDrink(d, idx);
        }
        else if (menu == 2) count += createDrink(&d[idx++]);
        else if (menu == 3){
            int no = selectDataNo(d, idx);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateDrink(&d[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(d, idx);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)" );
            scanf("%d", &delok);
            if(delok == 1){
                if(deleteDrink(&d[no-1])) count--;
                printf("=> 삭제됨!\n");
            }
        }
        else if(menu == 5) saveDrink(d, idx);
        else if(menu == 6) searchDrink(d, idx);
        else if(menu == 7) searchPrice(d, idx);
        else if(menu == 8) searchType(d, idx);
    }
    printf("종료됨!\n");
    return 0;
}
