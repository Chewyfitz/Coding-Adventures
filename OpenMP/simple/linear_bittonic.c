#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int len, char* array_name) {
  printf("%s", array_name);
  printf(": [");
  for(int i=0; i<len; i++) {
    printf("%d, ", array[i]);
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  int random_list_size = 100;
  if(argc == 2) {
    // An argument was supplied, use that as the number of loops
    random_list_size = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Usage: ./%s [num_loops]\n", argv[0]);
    return 1;
  }
  srand(random_list_size);

  int* array = malloc(random_list_size * sizeof(int));
  
  for(int i=0; i<random_list_size; i++) {
    array[i] = rand();
  }

  print_array(array, random_list_size, "Unsorted Array");

  // #pragma omp parallel for schedule(dynamic)


  free(array);

  return 0;
}

