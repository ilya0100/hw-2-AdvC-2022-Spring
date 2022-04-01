#include <time.h>
#include "array.h"
#include "max_seq_multiproc.h"


int main() {
    Array *arr = create_array(0);

    printf("Enter elements\n");

    size_t x = 0;
    // srand(time(NULL));
    while (scanf("%zu", &x) != -1) {
        // int x = rand() % 1000;
        if (push_back(arr, x)) {
            printf("Add error");
            return -1;
        }
    }

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);

    size_t max_length = find_max_incr_sequence(arr, num_cpu);    
    printf("%zu\n", max_length);
    
    free_array(arr);
    return 0;
}