#include <stdio.h>
#include <stdlib.h>

void main() {
	#pragma omp parallel for
	for(int i=0; i<15; i++) {
		printf("[%d] Print from thread %d\n", i, i);
	}
}
