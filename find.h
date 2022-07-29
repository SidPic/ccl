#ifndef CCL_FIND_H
#define CCL_FIND_H

#include <stddef.h>
#include  "hash.h"

/*
 * algorithm: optimized binary search (sorted array only)
 */

   void*    ccl_find      (   void*    array, size_t len,    void*   key, size_t key_size);
ccl_hash_t* ccl_find_hash (ccl_hash_t* array, size_t len, ccl_hash_t key);

#endif /*!CCL_FIND_H*/
