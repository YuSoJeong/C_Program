#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int Case(char input[]);

int main(void){

 

char nara[10];

int year;

int month;

int day;

int hour;

int min;

int i;

char change[10];

char j[10];

char Time[128];

char *ptr;

int gmt[]={9,0,8,3,4,11,-8,-5};

int Month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //달의 날짜수를 저장해놈

 

printf("원하는 시각을 입력하세요.\n ex)서울 20161112 0650pm 영국\n");

 gets_s(Time); //한줄로 입력받음 

 

 ptr = strtok (Time," ");

  strcpy(nara,ptr);//나눠서 nara 함수에 입력 나라를 받음

 

 ptr = strtok (NULL, " "); //년도월일을 입력받음 

 i=atoi(ptr);//atoi 를 써서 char 형이었던 ptr 을 정수형 i 에 저장

 

 ptr = strtok (NULL, " "); //시간을 입력받음

 strcpy(j,ptr);//char 형 배열에 복사함 시간을

 

 ptr = strtok (NULL, " ");

 strcpy(change,ptr);//바꿀나라를 복사함

 

 year=i/10000;

 

 if(year%4==0&&year%100!=0)

 Month[1]=29;//윤년처리

 

 month=(i%10000)/100;

 day=i%100;

 

 hour = (j[0]-'0')*10+(j[1]-'0');//j가 문자열이라서 -'0'을 통해 문자말고 정수로 표현

 min = (j[2]-'0')*10+(j[3]-'0');

 

  if (j[4]=='p')

 hour += 12;//pm일 경우 밑에서 시간계산을 하기 편리하게 하기위해 12를 더해줌

 

 //hour+=바꿀나라 gmt 값- 입력나라 gmt값

 hour+=gmt[Case(change)]-gmt[Case(nara)];

 

 if(hour>=24)
 {day+=1;
 hour-=24;

 }//24시간 넘어가면 하루 넘어가고 다시 시간 24시간 빼줌

  if (hour < 0) {

  day--;

  hour += 24;

 }//시간이 음수면 하루전으로 넘어가고 24시간을 다시 더해줌

  if(day>Month[month])

 {day-=Month[month];
 
 month+=1;
}//날짜가 그 달의 날짜보다 크면 다음달로 넘어가야하므로

  if(day<=0)

 { 
  if(month=1)
  day=Month[12]-day;
  else
   day=Month[month-1]-day;

  month-=1;}// 날짜가 음수면 그 전달로 넘어간다. 그리고 만약 그달이 1 월 이라면 달이 0달이 아니라 12월이므로 저 구문을 씀

  if(month>12)

 { year+=1;

 month-=12;}//달이 12월이 넘어가면 년도가 넘어간다

if(month<=0)

{year-=1;

month+=12;

}//달이 0인경우는 없으므로 그 전년도 12월으로 넘어간다.

 

 if (hour<22&&hour>12) {
 if(month<10&&day<10)
printf("%s %d0%d0%d 0%d%dpm\n",change,year,month,day,hour-12,min);
 if(month<10&&day>10)
 printf("%s %d0%d%d 0%d%dpm\n",change,year,month,day,hour-12,min);
 if(month>10&&day<10)
 printf("%s %d%d0%d 0%d%dpm\n",change,year,month,day,hour-12,min);
 else if(month>=10&&day>=10)
 printf("%s %d%d%d 0%d%dpm\n",change,year,month,day,hour-12,min);
 }

 else if(hour>=22) {
  

 if(month<10&&day<10)
printf("%s %d0%d0%d %d%dpm\n",change,year,month,day,hour-12,min);
 if(month<10&&day>10)
  printf("%s %d0%d%d %d%dpm\n",change,year,month,day,hour-12,min);
 if(month>10&&day<10)
  printf("%s %d%d0%d %d%dpm\n",change,year,month,day,hour-12,min);
 else if(month>=10&&day>=10)
  printf("%s %d%d%d %d%dpm\n",change,year,month,day,hour-12,min);
 }

 else if(0<hour&&hour<10){
 
 if(month<10&&day<10)
      printf("%s %d0%d0%d 0%d%dam\n",change,year,month,day,hour,min);
 if(month<10&&day>10)
  printf("%s %d0%d%d 0%d%dam\n",change,year,month,day,hour,min);
if(month>10&&day<10)
 printf("%s %d%d0%d 0%d%dam\n",change,year,month,day,hour,min);
 else if(month>=10&&day>=10)
 printf("%s %d%d%d 0%d%dam\n",change,year,month,day,hour,min);
 }

 else if(hour==0){
  hour=12;
 if(month<10&&day<10)
printf("%s %d0%d0%d %d%dam\n",change,year,month,day,hour,min);
 if(month<10&&day>10)
 printf("%s %d0%d%d %d%dam\n",change,year,month,day,hour,min);
 if(month>10&&day<10)
 printf("%s %d%d0%d %d%dam\n",change,year,month,day,hour,min);
 else if(month>=10&&day>=10)
  printf("%s %d%d%d %d%dam\n",change,year,month,day,hour,min);

 }
 else if(hour==12){
  if(month<10&&day<10)
printf("%s %d0%d0%d %d%dpm\n",change,year,month,day,hour,min);
 if(month<10&&day>10)
 printf("%s %d0%d%d %d%dpm\n",change,year,month,day,hour,min);
 if(month>10&&day<10)
 printf("%s %d%d0%d %d%dpm\n",change,year,month,day,hour,min);
 else if(month>=10&&day>=10)
  printf("%s %d%d%d %d%dpm\n",change,year,month,day,hour,min);

 
 }
 else {
  
 if(month<10&&day<10)
printf("%s %d0%d0%d %d%dam\n",change,year,month,day,hour,min);
 if(month<10&&day>10)
 printf("%s %d0%d%d %d%dam\n",change,year,month,day,hour,min);
 if(month>10&&day<10)
 printf("%s %d%d0%d %d%dam\n",change,year,month,day,hour,min);
 else if(month>=10&&day>=10)
  printf("%s %d%d%d %d%dam\n",change,year,month,day,hour,min);
 }

return 0;

}

int Case(char input[]) {

 int num;

 if (strcmp(input,"서울")==0) {

  num=0;

 }

 else if (strcmp(input,"영국")==0) {

  num=1;

 }

 else if (strcmp(input,"베이징")==0) {

  num=2;

 }

 else if (strcmp(input,"모스크바")==0) {

  num=3;

 }

 else if (strcmp(input,"두바이")==0) {

  num=4;

 }

 else if (strcmp(input,"시드니")==0) {

  num=5;

 }

 else if (strcmp(input,"LA")==0) {

  num=6;

 }

 else if (strcmp(input,"NY")==0) {

  num=7;

 }

 return num;

} 
