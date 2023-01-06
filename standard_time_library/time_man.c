#include <stdio.h>
#include <time.h>
#include <unistd.h>

/**
 * main - Program entry point
 *
 * Description: To show the manipulations of standard librabry time in C
 * Return: Returns zero upon successful execution
 */
int main(void)
{
	time_t thisTime = time(NULL);

	printf("The total number of seconds since midnight Jan 1, 1970");
	printf(": %ld\n", thisTime);

	/*
	sleep(10);

	time_t timeAfter10Secs = time(NULL);

	printf("The total number of seconds since midnight Jan 1, 1970");
	printf(" after 10 seconds of sleep: %ld\n", timeAfter10Secs);

	double timeDifference = difftime(timeAfter10Secs, thisTime);
	printf("Time difference after 10 seconds of sleep: ");
	printf("%.1f\n", timeDifference);
	*/

	/* Converts time_t from secs to full time format */
	char *tailoredTime_t = ctime(&thisTime);

	printf("Full date and time format from time_t: %s\n", tailoredTime_t);

	struct tm *greenWichTime = gmtime(&thisTime);

	/*
	struct tm
	{
		int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_yday;
		int tm_wday;
		int tm_isdst;
	};
	*/

	printf("The current time in secs [0-59 secs]: ");
	printf("%d\n", greenWichTime->tm_sec);

	printf("The current time in min [0-59 mins]: ");
	printf("%d\n", greenWichTime->tm_min);

	printf("The current time in hour [0-23 hrs]: ");
	printf("%d\n", greenWichTime->tm_hour);

	printf("The current day of the month [1-31]: ");
	printf("%d\n", greenWichTime->tm_mday);

	printf("The current month of the year [0-11]: ");
	printf("%d\n", greenWichTime->tm_mon);

	printf("The current year [1900 + current return value]: ");
	printf("%d\n", greenWichTime->tm_year + 1900);

	printf("The current day of the year [0-365]: ");
	printf("%d\n", greenWichTime->tm_yday);

	printf("The current day of the week [0-60]: ");
	printf("%d\n", greenWichTime->tm_min);

	printf("Daily light saving time: ");
	printf("%d\n", greenWichTime->tm_isdst);

	putchar('\n');

	struct tm *regionalTime = localtime(&thisTime);

	printf("The current time in secs [0-59 secs]: ");
	printf("%d\n", regionalTime->tm_sec);

	printf("The current time in min [0-59 mins]: ");
	printf("%d\n", regionalTime->tm_min);

	printf("The current time in hour [0-23 hrs]: ");
	printf("%d\n", regionalTime->tm_hour);

	printf("The current day of the month [1-31]: ");
	printf("%d\n", regionalTime->tm_mday);

	printf("The current month of the year [0-11]: ");
	printf("%d\n", regionalTime->tm_mon);

	printf("The current year [1900 + current return value]: ");
	printf("%d\n", regionalTime->tm_year + 1900);

	printf("The current day of the year [0-365]: ");
	printf("%d\n", regionalTime->tm_yday);

	printf("The current day of the week [0-60]: ");
	printf("%d\n", regionalTime->tm_min);

	printf("Daily light saving time: ");
	printf("%d\n", regionalTime->tm_isdst);

	putchar('\n');

	char *tailoredStructTmInstance = asctime(regionalTime);

	printf("Full date and time format from struct tm instance: ");
	printf("%s\n", tailoredStructTmInstance);

	/* Converts struct tm instance to seconds */
	time_t structTmInstanceToSecs = mktime(regionalTime);

	printf("Struct tm instance converted to seconds: ");
	printf("%ld\n", structTmInstanceToSecs);

	putchar('\n');

	/* Converts struct tm instance to full time format */
	char timeString[100];

	int timeStrLen = strftime(timeString, 100, "%d %A, %Y", regionalTime);
	printf("%s || Time string length:  %d\n", timeString, timeStrLen);

	putchar('\n');

	/* To determine the number of clock ticks / CLOCKS_PER_SEC
	   taken to complete the for loop */
	clock_t start, end;

	int i;

	start = clock();

	while (i == 64 && i <= 89)
	{
		i++;
		putchar(i);
	}
	putchar('\n');

	end = clock();

	double timeTaken = (double) (end - start) / CLOCKS_PER_SEC;

	printf("Time taken to complete the 'for' loop: %f\n", timeTaken);
	return (0);
}
