#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>

int number=0;
int main(void){
 int sol;
 srand(time(NULL));
 number = rand()%(100-1)+1;

 printf("1에서 100사이의 하나의 난수가 결정되었습니다.\n");
 scanf("%d",&sol);

 while(sol !=number){
    
  if(sol>number)
   printf("이 숫자보다 작은 숫자입니다. 다시 입력하세요.\n");
  else if(sol<number)
   printf("이 숫자보다 큰 숫자입니다. 다시 입력하세요.\n");
  
 scanf("%d",&sol);
 
 }

   printf("맞았습니다 . 정답은 %d 입니다.\n",sol);
    

return 0;
}
