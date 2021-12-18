#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

long nanosec (struct timeval t) { /* Calculate nanoseconds in a timeval structure */
	return ((t.tv_sec * 1000000 + t.tv_usec) * 1000);
}

int main(int argc, char *argv[]) {
	
	long N_iterations = 1000000;
	struct timeval t1, t2;

	int res;

	// get the system call cost
	res = gettimeofday(&t1, NULL); assert(res == 0);
	for (int i = 0; i < N_iterations; i ++) {
		int j = read(0, NULL, 0);
	}
	res = gettimeofday(&t2, NULL); assert(res == 0);

	float avgSystemCallCost = (nanosec(t2) - nanosec(t1)) / (N_iterations * 1.0);

	printf("Average read 0 bytes system call cost is: %f\n", avgSystemCallCost);

	return 0;	
}
