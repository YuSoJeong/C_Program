# C_Program

  C 프로그래밍과 실습 수강하며 익힌 예제들입니다.

# worldtime.cpp

# randomnum.cpp

# PokerCard.cpp

1) 코드 설명
 
  포커카드 를 2명의 플레이어에서 7패씩 나눠주는 랜덤함수를 이용한 프로그램
  
  포커카드는 spaca,clover,heart,di  네 종류가 있고 숫자는 1부터 52까지 있다.
    
 2) 구체적인 설명
 
 [구현]
 
 플레이어 정보를 구조체로 관리하고 카드종류는 enum 으로 관리한다.
 
 플레이어의 패가 중복되지 않게 srand(time(NULL))와 rand()%52 함수를 사용하였고,

 생성한 번호와 매치되는 카드 종류를 구분하기 위해 아래와 같이 몫을 이용하였다.
 
   for(j=0;j<7;j++){
  if(a.player1[j]/13==0)
   p=0; //스페이스
  if(a.player1[j]/13==1)
   p=1; //클로버
  if(a.player1[j]/13==2)
   p=2; //하트
  if(a.player1[j]/13==3)
   p=3 ; //다이아

출력을 위해서 나누기의 나머지 부분을 이용하였다.

   if(p==SPACE)
    printf("스페이스 (%d) ",a.player1[j]%13+1);
   if(p==CLOVER)
    printf("클로버 (%d) ",a.player1[j]%13+1);
   if(p==HEART)
    printf("하트 (%d) ",a.player1[j]%13+1);
   if(p==DI)
    printf("다이아 (%d) ",a.player1[j]%13+1);
  
   
 
 3) 결과

![image](https://user-images.githubusercontent.com/44575829/48904463-cb22c900-eea1-11e8-804d-1974e30b0b80.png)



# MoveDate

 1) 코드 설명
  
  날짜 연,월,일 입력받고 이동할 수를 입력받아 이동한 날짜를 출력해주는 프로그램
  
    
 2) 구체적인 설명
 
  [입력조건]
  
        날짜 YYYY MM DD
        
        이동시키고픈 수 int move
        
  [구현]
  
         int date[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 로 각 월 마다의 마지막 일수를 배열로 저장해놓음
         
         if((year%4==0&&year%100!=0)|| year%400==0) { date[2] = 29; } 입력받은 연도가 윤년이면 data[2]=29 로 수정해준다. 

         입력받은 정수를 day에 더한 후 ,day > date[month] 를 비교해서 월, 일 을 수정해준다.
         
 
 3) 결과

![image](https://user-images.githubusercontent.com/44575829/48904246-19839800-eea1-11e8-9e4e-4af91439bf35.png)


