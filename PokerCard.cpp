#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card{
 int player1[7];
 int player2[7];
};

int main(void){
 int i,k=0,j=0;
 int p;
 int temp=0,temp2=0;
 int check[4]={13,26,39,51};
 int s=0,c=0,h=0,d=0;
 enum pat{
     SPACE=0,
	 CLOVER,
	 HEART,
	 DI
}typedef pat;
 struct card a;
 srand((unsigned)time(NULL));

 for(i=0;i<7;i++)
 {
 a.player1[i]=rand()%52;
 
 for(k=0;k<i;k++){
  if(a.player1[i]==a.player1[k])
   i--;
 }
 }

  for(i=0;i<7;i++)
 {
 a.player2[i]=rand()%52;
 
 for(k=0;k<i;k++){
  if(a.player2[i]==a.player2[k]) {
   i--;
   break;
  }
 }
  for(k=0;k<7;k++){
  if( a.player1[k]==a.player2[i])
   i--;
  }
 }

 
  for(j=0;j<7;j++){
  if(a.player1[j]/13==0)
   p=0;
  if(a.player1[j]/13==1)
   p=1;
  if(a.player1[j]/13==2)
   p=2;
  if(a.player1[j]/13==3)
   p=3 ;
  
   if(p==SPACE)
    printf("�����̽� (%d) ",a.player1[j]%13+1);
   if(p==CLOVER)
    printf("Ŭ�ι� (%d) ",a.player1[j]%13+1);
   if(p==HEART)
    printf("��Ʈ (%d) ",a.player1[j]%13+1);
   if(p==DI)
    printf("���̾� (%d) ",a.player1[j]%13+1);
  
  }
  printf("\n");

  for(j=0;j<7;j++){
   if(a.player2[j]/13==0)
   p=0;
  if(a.player2[j]/13==1)
   p=1;
  if(a.player2[j]/13==2)
   p=2;
        if(a.player2[j]/13==3)
   p=3 ;
  
   if(p==SPACE)
    printf("�����̽� (%d) ",a.player2[j]%13+1);
   if(p==CLOVER)
    printf("Ŭ�ι� (%d) ",a.player2[j]%13+1);
   if(p==HEART)
    printf("��Ʈ (%d) ",a.player2[j]%13+1);
   if(p==DI)
    printf("���̾� (%d) ",a.player2[j]%13+1);
  

  }
  printf("\n");

 for(i=0;i<7;i++){
  if(0<=a.player1[i]&&a.player1[i]<13)
   s++;
  if(13<=a.player1[i]&&a.player1[i]<26)
   c++;
  if(26<=a.player1[i]&&a.player1[i]<39)
   h++;
  if(39<=a.player1[i]&&a.player1[i]<52)
   d++;
  
 }
 if((s>4)||(c>4)||(h>4)||(d>4))
   printf("player1�� �а� �÷��� �Դϴ�.\n");

  s=0,c=0,h=0,d=0;
 for(i=0;i<7;i++){
  if(0<=a.player2[i]&&a.player2[i]<13)
   s++;
  if(13<=a.player2[i]&&a.player2[i]<26)
   c++;
  if(26<=a.player2[i]&&a.player2[i]<39)
   h++;
  if(39<=a.player2[i]&&a.player2[i]<52)
   d++;
  
 }
 if((s>4)||(c>4)||(h>4)||(d>4))
   printf("player2�� �а� �÷��� �Դϴ�.\n");
 getchar();
return 0;
} 
