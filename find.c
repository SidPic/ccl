#include "find.h"
#include <string.h>

/*
 * algorithm: binary search (sorted array only)
 */

ccl_hash_t* ccl_find_hash (ccl_hash_t* array, size_t len, ccl_hash_t key) {
    len /= 2;

    while (len) {
        if (array[len] == key) return array + len;
        if (array[len] <  key) array += len;
        len /= 2;
    }

    if (*array   == key) return array;
    if (array[1] == key) return array + 1;

    return NULL;
}

void* ccl_find (void* array, size_t len, void* key, size_t key_size) {
    len /= 2;
    len *= key_size;

    while (len) {
        if (memcmp(array + len, key, key_size) == 0) return array + len;
        if (memcmp(array + len, key, key_size) <  0) array += len;
        len /= key_size;
        len /= 2;
        len *= key_size;
    }

    if (memcmp(array,            key, key_size) == 0) return array;
    if (memcmp(array + key_size, key, key_size) == 0) return array + key_size;

    return NULL;
}
