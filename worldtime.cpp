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

int Month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //���� ��¥���� �����س�

 

printf("���ϴ� �ð��� �Է��ϼ���.\n ex)���� 20161112 0650pm ����\n");

 gets_s(Time); //���ٷ� �Է¹��� 

 

 ptr = strtok (Time," ");

  strcpy(nara,ptr);//������ nara �Լ��� �Է� ���� ����

 

 ptr = strtok (NULL, " "); //�⵵������ �Է¹��� 

 i=atoi(ptr);//atoi �� �Ἥ char ���̾��� ptr �� ������ i �� ����

 

 ptr = strtok (NULL, " "); //�ð��� �Է¹���

 strcpy(j,ptr);//char �� �迭�� ������ �ð���

 

 ptr = strtok (NULL, " ");

 strcpy(change,ptr);//�ٲܳ��� ������

 

 year=i/10000;

 

 if(year%4==0&&year%100!=0)

 Month[1]=29;//����ó��

 

 month=(i%10000)/100;

 day=i%100;

 

 hour = (j[0]-'0')*10+(j[1]-'0');//j�� ���ڿ��̶� -'0'�� ���� ���ڸ��� ������ ǥ��

 min = (j[2]-'0')*10+(j[3]-'0');

 

  if (j[4]=='p')

 hour += 12;//pm�� ��� �ؿ��� �ð������ �ϱ� ���ϰ� �ϱ����� 12�� ������

 

 //hour+=�ٲܳ��� gmt ��- �Է³��� gmt��

 hour+=gmt[Case(change)]-gmt[Case(nara)];

 

 if(hour>=24)
 {day+=1;
 hour-=24;

 }//24�ð� �Ѿ�� �Ϸ� �Ѿ�� �ٽ� �ð� 24�ð� ����

  if (hour < 0) {

  day--;

  hour += 24;

 }//�ð��� ������ �Ϸ������� �Ѿ�� 24�ð��� �ٽ� ������

  if(day>Month[month])

 {day-=Month[month];
 
 month+=1;
}//��¥�� �� ���� ��¥���� ũ�� �����޷� �Ѿ���ϹǷ�

  if(day<=0)

 { 
  if(month=1)
  day=Month[12]-day;
  else
   day=Month[month-1]-day;

  month-=1;}// ��¥�� ������ �� ���޷� �Ѿ��. �׸��� ���� �״��� 1 �� �̶�� ���� 0���� �ƴ϶� 12���̹Ƿ� �� ������ ��

  if(month>12)

 { year+=1;

 month-=12;}//���� 12���� �Ѿ�� �⵵�� �Ѿ��

if(month<=0)

{year-=1;

month+=12;

}//���� 0�ΰ��� �����Ƿ� �� ���⵵ 12������ �Ѿ��.

 

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

 if (strcmp(input,"����")==0) {

  num=0;

 }

 else if (strcmp(input,"����")==0) {

  num=1;

 }

 else if (strcmp(input,"����¡")==0) {

  num=2;

 }

 else if (strcmp(input,"��ũ��")==0) {

  num=3;

 }

 else if (strcmp(input,"�ι���")==0) {

  num=4;

 }

 else if (strcmp(input,"�õ��")==0) {

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
