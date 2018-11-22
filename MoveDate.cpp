#include <stdio.h>

int main(void)

{

	int year;

	int month;

	int day;

	int date[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	int move;

 

	printf("날짜를 년, 월, 일 로 숫자로 입력하세요.\n");

	scanf("%d %d %d", &year, &month, &day);

	
	if(year<0 || (month<0 || month>13)||  day < 0 || day > date[month])

		{

			printf("날짜를 잘못 입력하셨습니다.\n");
			return 0;

		}

	printf("움직이고자 하는 일수를 입력하세요.\n");

	scanf("%d", &move);

	day += move;

 

	if((year%4==0&&year%100!=0)|| year%400==0)

	{

		date[2] = 29;

	}

 

	if(day>0)

	{

		while(day > date[month])

		{

			day -= date[month];

			++month;

 

			if(month==13)

			{

				++year;

				month = 1;

				if((year%4==0&&year%100!=0)|| year%400==0)

					date[2] = 29;

				else

					date[2] = 28;

			}

		}

	}

 

	else

		while(day<=0)

		{

			--month;

			if(month ==0)

			{

				--year;

				month = 12;

 

				if((year%4==0&&year%100!=0)|| year%400==0)

					date[2] = 29;

			

				else

					date[2] = 28;

				

			}

			day += date[month];

		}

 

		printf("%d %d %d", year, month, day);


		return 0;
}
