#include "max_seq_multiproc.h"
#include "max_seq_singleproc.h"


int main() {
    Array *arr = create_array(0);

    printf("Enter elements\n");

    size_t x = 0;
    while (scanf("%zu", &x) != -1) {
        if (push_back(arr, x)) {
            printf("Add error");
            return -1;
        }
    }

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);

    size_t max_length = find_max_incr_sequence(arr);    
    printf("%zu\n", max_length);
    
    max_length = find_max_incr_sequence_multiproc(arr, num_cpu);
    if (max_length == 0) {
        free_array(arr);
    }    

    printf("%zu\n", max_length);

    free_array(arr);
    return 0;
}