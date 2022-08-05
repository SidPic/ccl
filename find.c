#include "find.h"
#include <string.h>

/*
 * algorithm: optimized binary search
 */

const ccl_hash_t* ccl_find_hash (
    const ccl_hash_t* array,
            size_t    len,
          ccl_hash_t  key
) {
    while (len/=2) {
        if (*(array+=len) == key) return array;
        if ( *array       >  key) array -= len;
    }

    if ( *array     == key) return array;
    if (*(array+=1) == key) return array;

    return NULL;
}

const void* ccl_find (
    const void* array,
      size_t    len,
    const void* key,
      size_t    key_size
) {
    while (len/=2) {
        if (memcmp(array+=len*key_size, key, key_size) == 0) return array;
        if (memcmp(array,               key, key_size) >  0) array -= len*key_size;
    }

    if (memcmp(array,           key, key_size) == 0) return array;
    if (memcmp(array+=key_size, key, key_size) == 0) return array;

    return NULL;
}
