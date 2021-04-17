typedef struct{
    char name[20]; // 제품의 이름
    int gram; // 제품의 무게
    int cost; // 제품의 가격
    int starpoint; // 제품의 평점
    int numberOfstars; // 제품의 평점 총 개수
} Product;


int selectMenu(void); // 메뉴를 정하는 함수
int addProduct(Product *p); // 제품 추가 함수
void readProduct(Product p); // 제품 하나를 읽고 출력하는 함수
int updateProduct(Product *p); // 제품의 내용을 수정하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수
void searchProduct(Product *p, int count); // 제품을 찾는 함수
void listProduct(Product *p, int count); // 제품 전체를 출력하는 함수
int selectDataNo(Product *p, int count); // 해당 제품의 번호를 찾는 함수

int loadData(Product *p); // 데이터를 불러오는 함수
int saveData(Product *p, int count); // 데이터를 저장하는 함수



