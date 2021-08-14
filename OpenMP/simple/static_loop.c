#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int num_loops = 15;
  if(argc == 2) {
    // An argument was supplied, use that as the number of loops
    num_loops = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Usage: ./%s [num_loops]\n", argv[0]);
    return 1;
  }
  
	#pragma omp parallel for schedule(static)
	for(int i=0; i<num_loops; i++) {
		printf("[%d] Print from thread %d\n", i, i);
	}
  return 0;
}
