#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>

int number=0;
int main(void){
 int sol;
 srand(time(NULL));
 number = rand()%(100-1)+1;

 printf("1���� 100������ �ϳ��� ������ �����Ǿ����ϴ�.\n");
 scanf("%d",&sol);

 while(sol !=number){
    
  if(sol>number)
   printf("�� ���ں��� ���� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
  else if(sol<number)
   printf("�� ���ں��� ū �����Դϴ�. �ٽ� �Է��ϼ���.\n");
  
 scanf("%d",&sol);
 
 }

   printf("�¾ҽ��ϴ� . ������ %d �Դϴ�.\n",sol);
    

return 0;
}
