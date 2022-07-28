#ifndef CCL_FIND_H
#define CCL_FIND_H

#include <stddef.h>
#include "hash.h"

/*
 * algorithm: modified binary search (sorted array only)
 */

size_t ccl_find      (void* array, size_t array_size, void* key, size_t key_size);
ccl_hash_t* ccl_find_hash (ccl_hash_t* array, size_t array_size, ccl_hash_t key);

#endif
