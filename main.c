#include "map.h"
#include <string.h>
#include <stdio.h>

#include "hash.h"
#include "find.h"

void main()
{
    const char* str = "H";
    __auto_type a = ccl_hash(str, str + strlen(str));
    __auto_type b = ccl_hash_str(str);
    printf("%llu\n%llu\n================\n", a, b);

    ccl_hash_t arr[9] = { 1, 32, 76, 123, 3232, 3234, 4501, 55000, 111111 };

    for (int i = 0; i < 9; ++i) {
        printf ("[%i] = %u\n", i, arr[i]);
    }

    ccl_hash_t x = 55000;

    ccl_hash_t* c = ccl_find(arr, 9, &x, sizeof(ccl_hash_t));

    if (c) {
    printf("Found: [%u] = %u\n", c-arr, *c); }
    else {
    printf("Not found: %u\n", x);
    }

}
