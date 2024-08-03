#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void print_current_seconds_since_the_Epoch() {
	time_t current_time = time(NULL);
	printf("%jd seconds since the Epoch\n", (intmax_t)(current_time));
}

void print_current_time_in_UTC() {
	time_t current_time_in_sec = time(NULL);
	struct tm *UTC_time_tm = gmtime(&current_time_in_sec);
	UTC_time_tm = localtime(&current_time_in_sec);
	char *UTC_time = asctime(UTC_time_tm);
	printf("Current time: %s", UTC_time);
}

void print_time_timespec() {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	char buff[128];
	strftime(buff, sizeof(buff), "%D %T", gmtime(&ts.tv_sec));
	printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
}

void struct_time_t() {
	time_t t = time(NULL);
	struct tm *tim = gmtime(&t);
	printf("%d\n", t);
	printf("%s", asctime(tim));

}

int main() {
	struct_time_t();
	// print_current_seconds_since_the_Epoch();
	// print_current_time_in_UTC();
	// print_time_timespec();
}
