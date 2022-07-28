#include "find.h"

/*
 * algorithm: modified binary search (sorted array only)
 */

ccl_hash_t* ccl_find_hash (ccl_hash_t* array, size_t size, ccl_hash_t key) {
    size /= 2;

    while (size) {
        if (array[size] == key) return array + size;
        if (array[size] <  key) array += size;
        size /= 2;
    }

    if (*array   == key) return array;
    if (array[1] == key) return array + 1;

    return NULL;
}
