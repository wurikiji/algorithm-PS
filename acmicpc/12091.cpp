#include <cstdio>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

int main(void) {
	int n;
	clock_t start_time= clock();
	clock_t end_time = CLOCKS_PER_SEC+ start_time;
	scanf("%d", &n);
	while(clock() < end_time) {
	}
	srand(time(NULL));
	int r = rand() %3;
	if (r == 0) {
		printf("Vaporeon\n");
	} else if (r == 1) {
		printf("Jolteon\n");
	} else if (r == 2) {
		printf("Flareon\n");
	}
	return 0;
}
