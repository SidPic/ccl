#include "map.h"
#include <string.h>
#include <stdio.h>

#include "util.h"
#include "hash.h"
#include "find.h"
#include "sort.h"

void main()
{
    const char* str = "Hello world";
    __auto_type a = ccl_hash(str, str + strlen(str)-1);
    __auto_type b = ccl_hash_str(str);
    printf("%llu\n%llu\n================\n", a, b);

    ccl_hash_t arr[9] = { 1, 32, 76, 123, 3232, 3234, 4501, 55000, 111111 };

    for (int i = 0; i < 9; ++i) {
        printf ("[%i] = %u\n", i, arr[i]);
    }

    ccl_hash_t x = 123;

    //~ ccl_hash_t* c = ccl_find_hash(arr, 9, x);
    //~ ccl_hash_t* c = ccl_find(arr, 9, &x, sizeof(ccl_hash_t));
    ccl_hash_t* c = _ccl_find(arr, 9, &x);

    if (c) {
    printf("Found: [%u] = %u\n", c-arr, *c); }
    else {
    printf("Not found: %u\n", x);
    }

    ccl_hash_t arr2[10] = { 123, 33, 1, 23, 41, 421, 11, 42, 22, 5};

    for (int i = 0; i < 10; ++i) printf("%i ", arr2[i]); puts("");

    ccl_sort(arr2, arr2 + 10, sizeof(ccl_hash_t));
    //~ ccl_vec_t( int8_t,  ) dsa;

    for (int i = 0; i < 10; ++i) printf("%i ", arr2[i]); puts("");
}
