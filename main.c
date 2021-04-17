#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "manager.h"

#define DEBUG_MODE

int main(void){
	#ifdef DEBUG_MODE
		printf("==> DEBUG MODE\n");
	#endif
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
    	else if(menu == 7){
		searchProductGram(plist,index);
	}
	else if (menu == 8){
		searchProductStarpoint(plist,index);
	}
    }
    printf("종료됨!\n");
    return 0;
}
