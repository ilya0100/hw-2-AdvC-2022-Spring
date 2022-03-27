#include <time.h>
#include "array.h"
#include "max_seq.h"


int main() {
    Array arr = {0};

    size_t n = 0;
    
    printf("Enter array size\n");
    scanf("%zu", &n);

    printf("Enter elements\n");

    srand(time(NULL));
    for (size_t i = 0; i < n; ++i) {
        // int x = rand() % 1000;
        int x = 0;
        scanf("%d", &x);
        add_elem(&arr, x);
    }

    print_array(arr);
    printf("\n");

    size_t index = 0;
    size_t length = find_max_incr_sequence(arr.data, arr.size, &index);

    printf("Index: %zu, Length: %zu\n", index, length);

    free_array(&arr);
    return 0;
}