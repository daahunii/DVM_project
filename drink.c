#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drink.h"

int selectMenu(){
	int menu;
	printf("\n******메뉴******\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 음료 이름 검색\n");
	printf("7. 음료 가격대 검색\n");
	printf("8. 음료 종류 검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? : ");
        scanf("%d", &menu);
        printf("\n");
       return menu;
}; // 실행메뉴

int selectDataNo(Drink *p, int count){
	int no;
	listDrink(p, count);
	printf("\n수정/삭제 할 음료 번호를 입력 (취소: 0)\n");
	scanf("%d", &no);
	return no;
};

int loadData(Drink *p){
	FILE* fp;
	int num=0;

	if((fp=fopen("drink.txt","r"))){
		while(!feof(fp)){
			int r= fscanf(fp, "%d %d %[^\n] %[^\n]", &p->price, &p->type, p->name, p->company);
			if(r<=1) break;
			num++;
		}
		fclose(fp);
		printf("\n=>로딩성공!\n");
	}
	else printf("\n=> 데이터 없음!\n");
	return num;
} // 파일에 저장된 데이터를 불러오는 함수
int createDrink(Drink *p){
	printf("음료명 : ");
	getchar(); 
	scanf("%[^\n]", p->name);
	printf("음료 브랜드 : "); 
	getchar();
	scanf("%[^\n]", p->company);
	printf("가격 : ");
	scanf("%d", &p->price);
	printf("음료 종류 (1: 이온, 2: 탄산, 3: 과일, 4: 우유) : ");
	scanf("%d", &p->type);
	return 1;
}; // 음료를 추가하는 함수

void readDrink(Drink p){
	printf(" %-8s %-8s %-7d %-2d\n", p.name, p.company, p.price, p.type);
}; // 하나의 음료 출력 함수

void listDrink(Drink *p, int count){
	printf("No    Name   brand  price type\n");
	printf("===================================\n");
	for(int i=0; i<count; i++){
		if(p->price == -1 || p->type == -1) continue;
		printf("%-2d ", i+1);
		readDrink(*p);
		printf("\n");
	}
}; // 전체 등록된 음료 리스트 출력

int updateDrink(Drink *p){
	int num;
	printf("수정할 음료의 번호는? "); 
	scanf("%d", &num);
	printf("음료명 : ");
	getchar();
	scanf("%[^\n]", p->name);
	printf("음료 브랜드 : ");
	getchar();
	scanf("%[^\n]", p->company);
	printf("가격 : ");
	scanf("%d", &p->price);
	printf("음료 종류 (1: 이온, 2: 탄산, 3: 과일, 4: 우유) : ");
	scanf("%d", &p->type);

	printf("\n=> 수정 완료!\n");

	return 1;
}; // 음료 정보 수정

int deleteDrink(Drink *p){
	p->price= -1;
	p->type=-1;

	return 1;
}; // 음료 정보 삭제

void saveDrink(Drink *p, int count){
	FILE* fp;

	fp=fopen("drink.txt", "w");

	for(int i=0; i<count; i++){
		if(p->price==-1 || p->type==-1) break;

		fprintf(fp, "%d %d %s\n%s\n", p->price, p->type, p->name, p->company);
	}
	fclose(fp);
	printf("=>저장완료!\n");
}; // 음료 정보 저장
void searchDrink(Drink *p, int count){
	char search[30];
	int scnt=0;

	printf("\n검색할 음료 이름?\n");
	getchar();
	scanf("%[^\n]", search);

	for(int i=0; i<count; i++){
		if(p->price==-1 || p->type ==-1) continue;
		if(strstr(p->name,search)){
			printf("%-2d", i+1);
			readDrink(*p);
			printf("\n");
			scnt++;
		}
	}
	if(scnt==0) printf("\n=> 검색된 데이터 없음!\n");
	else printf("\n%d개의 데이터 검색!\n", scnt);
	printf("\n");
}; // 음료 이름 검색

void searchPrice(Drink *p, int count){
	int search;
	int scnt=0;
	
	printf("\n검색 가격대 선택\n\n0. 1000원 이하\n1. 1000원 대\n2. 2000원 대\n3. 3000원 이상\n");
       scanf("%d", &search);
       for(int i=0; i<count; i++){
             if(p->price==-1 || p->type==-1) continue;
             if(search==0){
                    if(p->price<1000){
                           printf("%-2d ", i+1);
                           readDrink(*p);
                           printf("\n");
                           scnt++;
                    }
             }else if(search==1){
		    if(p->price >= 1000 && p->price<2000){ 
			   printf("%-2d ", i+1);
                           readDrink(*p);
                           printf("\n");
                           scnt++;
                    }
             }else if(search==2){
		    if(p->price>=2000 && p->price<3000){ 
			   printf("%-2d ", i+1);
                           readDrink(*p);
                           printf("\n");
                           scnt++;
                    }
             }else if(search==3){
                    if(p->price>=3000){
                           printf("%-2d ", i+1);
                           readDrink(*p);
                           printf("\n");
                           scnt++;
		} 
	     }
	}
	if(scnt==0) printf("\n=>검색된 데이터 없음!\n");
	else printf("\n=> %d개의 데이터 검색!\n", scnt);
}; // 음료 가격 검색

void searchType(Drink *p, int count){
	int search;
        int scnt=0;

        printf("\n검색할 음료 종류? ( 1: 이온, 2: 탄산, 3: 과일, 4: 우유)\n");
        scanf("%d", &search);

        for(int i=0; i<count; i++){
                if(p->price==-1 || p->type ==-1) continue;
                if(p->type==search){
                        printf("%-2d", i+1);
                        readDrink(*p);
                        printf("\n");
                        scnt++;
                }
	}
        if(scnt==0) printf("\n=> 검색된 데이터 없음!\n");
        else printf("\n%d개의 데이터 검색!\n", scnt);
        printf("\n");
}; // 음료종류 검색
