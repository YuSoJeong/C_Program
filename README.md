# C_Program

  C 프로그래밍과 실습 수강하며 익힌 예제들입니다.

# worldtime.cpp

1) 코드 설명

  입력받은 나라와 날짜 , 현재 시각을 입력하면 원하는 나라에서의 대응하는 날짜,현재 시각을 출력해주는 프로그램
    
 2) 구체적인 설명
 
  [입력조건]
  
      ex) 서울 20161112 0650pm 영국 이렇게 입력해 주어야 한다.
        
  [구현]
       
     int gmt[]={9,0,8,3,4,11,-8,-5}; 

     int Month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //달의 날짜수를 미리 배열로 저장해주었다. 
     //
     
     나라, 년도, 월, 일 을 한번에 입력 받아서strtok (NULL, " ") 을 사용해서 각 변수에 저장해준다.
     //
     
     if(year%4==0&&year%100!=0) Month[1]=29; //윤년을 처리해준다.
     //
     
     hour = (j[0]-'0')*10+(j[1]-'0');//j가 문자열이라서 -'0'을 통해 문자말고 정수로 표현

     min = (j[2]-'0')*10+(j[3]-'0');
     //

     hour+=gmt[Case(change)]-gmt[Case(nara)]; //hour+=바꿀나라 gmt 값- 입력나라 gmt값 으로 시간차를 계산해준다.
     
     원하는 나라에 맞는 hour 로 수정된 후 날짜, 연, 월, 일 을 조정해준뒤 출력해준다.
     
 
 3) 결과

 ![image](https://user-images.githubusercontent.com/44575829/48905651-77b27a00-eea5-11e8-91b4-4a35855873ca.png) 

# randomnum.cpp

1) 코드 설명

랜덤으로 생성된 숫자 맞추기 게임 프로그램  
    
 2) 구체적인 설명
 
  [입력조건]
      
  1 ~ 100 이내에서 생성된 임의의 숫자를 맞추기 위해 여러번 입력할 수 있다.
  
  정답일 것 같은 숫자를 입력해주면 된다.
  
  [구현]
  
   srand(time(NULL));
   number = rand()%(100-1)+1;
   
   위 함수를 이용해서 1 ~ 100 사이의 임의의 수를 생성하여 number 변수에 저장한다.
   
   사용자로부터 숫자를 입력받아 number 값과 비교하여 입력한 수보다 큰 수 인지 작은 수 인지 알려준다.
       
 
 3) 결과
 
![image](https://user-images.githubusercontent.com/44575829/48905357-b09e1f00-eea4-11e8-8e37-e610daac8f3e.png)

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

![image](https://user-images.githubusercontent.com/44575829/48904979-97e13980-eea3-11e8-9d49-3b5e475a99e3.png)


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


