#include <time.h>
#include "array.h"
#include "max_seq.h"


int main() {
    Array *arr = create_array(0);

    size_t n = 0;
    
    printf("Enter array size\n");
    scanf("%zu", &n);

    printf("Enter elements\n");

    // srand(time(NULL));
    for (size_t i = 0; i < n; ++i) {
        // int x = rand() % 1000;
        size_t x = 0;
        scanf("%zu", &x);
        if (add_elem(arr, x)) {
            printf("Add error");
            return -1;
        }
    }

    print_array(arr);
    printf("\n");

    size_t max_length = find_max_incr_sequence(arr, 3);    
    printf("%zu\n", max_length);
    
    free_array(arr);
    return 0;
}