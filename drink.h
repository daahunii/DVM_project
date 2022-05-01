typedef struct{
    char name[30]; // 음료수 이름
    char company[50]; // 회사명
    int price, type; // 가격, 음료수 종류(1: 이온 2: 탄산 3: 유제품 4: 과일)
} Drink;

int selectMenu(); // 실행메뉴
int selectDataNo(Drink *p, int count);
int loadData(Drink *p); // 파일에 저장된 데이터를 불러오는 함수
int createDrink(Drink *p); // 음료를 추가하는 함수
void readDrink(Drink p); // 하나의 음료 출력 함수
void listDrink(Drink *p, int count); // 전체 등록된 음료 리스트 출력
int deleteDrink(Drink *p); // 음료 정보 삭제
void saveDrink(Drink *p, int count); // 음료 정보 저장
int updateDrink(Drink *p); // 음료 정보 수정
void searchDrink(Drink *p, int count); // 음료 이름 검색
void searchPrice(Drink *p, int count); // 음료 가격 검색
void searchType(Drink *p, int count); // 회사명 검색
