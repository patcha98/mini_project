#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "product.h"



int selectMenu(){
    int menu;
    printf("\n\n-------------------\n");
    printf("1. 상품조회\n");
    printf("2. 상품추가\n");
    printf("3. 상품수정\n");
    printf("4. 상품삭제\n");
    printf("5. 상품 리스트 파일로 저장\n");
    printf("6. 상품 이름으로 찾기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *p){
    printf("제품명은? = ");
    scanf("%s", p->name);
    printf("제품의 가격은? = ");
    scanf("%d", &p->cost);
    printf("제품의 무게는? (g) = ");
    scanf("%d", &p->gram);
    printf("제품의 별점은? = ");
    scanf("%d", &p->starpoint);
    printf("제품의 총 평가 수? = ");
    scanf("%d", &p->numberOfstars);
    return 1;
}

void readProduct(Product p){
  printf("    %s    %d     %d       %d       %d\n", p.name, p.cost, p.gram, p.starpoint, p.numberOfstars);
}

void listProduct(Product *p, int count){
    printf("번호  |  이름 | 가격 | 무게(g) | 별점 | 총 평가 수\n");

    printf("----------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(p[i].cost == -1) continue;
            printf("%2d  ",i+1);
        readProduct(p[i]);
    }
}

void searchProduct(Product *p, int count){
    int num = 0;
    char search[20];

    printf("검색할 제품의 이름은? ");
    scanf("%s", search);
    printf("\n================================\n");
    for(int i = 0; i < count; i ++){
        if(p[i].cost == -1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d ",i+1);
            readProduct(p[i]);
            num ++;
        }
    }
    if(num == 0){
        printf("\n=> 검색된 데이터가 없습니다! \n");
    }
}

int updateProduct(Product *p){
    printf("제품명은? = ");
    scanf("%s", p->name);
    printf("제품의 가격은? = ");
    scanf("%d", &p->cost);
    printf("제품의 무게는? (g) = ");
    scanf("%d", &p->gram);
    printf("제품의 별점은? = ");
    scanf("%d", &p->starpoint);
    printf("제품의 총 평가 수? = ");
    scanf("%d", &p->numberOfstars);
    printf("수정성공!\n");
    return 1;
}

int selectDataNo(Product *p, int count){
  listProduct(p, count);
  int no;
  printf("번호는(취소:0)?");
  scanf("%d",&no);
  return 
  no;
}

int deleteProduct(Product *p){
  p->name[0] = '\0';
  p->cost = -1;
  p->gram = -1;
  p->starpoint = -1;
  p->numberOfstars = -1;
  printf("=> 삭제됨!\n");
  return 1;
}

int saveData(Product *p, int count){
    FILE *fp;
      fp = fopen("product.txt", "wt");
      for(int i = 0; i < count; i ++){
            if(p[i].cost == -1) continue;
            fprintf(fp, "%s %d %d %d %d\n",p[i].name, p[i].cost, p[i].gram, p[i].starpoint, p[i].numberOfstars);
      }
      fclose(fp);
      printf("=> 저장됨! ");
}

int loadData(Product *p){
    int count = 0, i = 0;
    int r = 0;
    r = access("product.txt", F_OK);
    if(r == 0){
        FILE *fp;
        fp = fopen("product.txt", "rt");
        for(i = 0; i < 100; i++){
            fscanf(fp, "%s", p->name);
            if(feof(fp)) break;
            fscanf(fp, "%d", &p->cost);
            fscanf(fp, "%d", &p->gram);
            fscanf(fp, "%d", &p->starpoint);
            fscanf(fp, "%d", &p->numberOfstars);
            count++;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    else{
        printf("=> 파일 없음 \n");
    }
    return count;
}


int main(void){
    Product plist[100];
    
    int index = 0;
    int count = 0, menu;
    count = loadData(plist);
    index = count;


    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
          listProduct(plist, index);
        }
        else if (menu == 2){
          count += addProduct(&plist[index++]);
        }

        else if (menu == 3){
          int no = selectDataNo(plist, index);
          if(no > 0)
            updateProduct(&plist[no-1]);
          else
            printf("취소됨!\n");
        }

        else if (menu == 4){
          int no = selectDataNo(plist, index);
          if(no > 0){
            printf("정말로 삭제하시겠습니까? (삭제:1) ");
            int delok;
            scanf("%d", &delok);
            if(delok == 1){
              deleteProduct(&plist[no-1]);
              count--;
            }
          }
          else
            printf("취소됨!\n");
        }
        else if (menu == 5){

            saveData(plist, index);
        
        }
        else if (menu == 6){
            searchProduct(plist,index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
