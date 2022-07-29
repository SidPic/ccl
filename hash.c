#include "hash.h"

/*
 * algorithm: FNV_64a
 */

ccl_hash_t ccl_hash_str (const char* str) {
    ccl_hash_t hval = CCL_HASH_INIT;

    while (*str) {
        hval ^= (ccl_hash_t)*str;
        hval *= CCL_HASH_PRIME;
        ++str;
    }

    return hval;
}

ccl_hash_t ccl_hash (const char* data, const char* end_of_data) {
    ccl_hash_t hval = CCL_HASH_INIT;

    while (data != end_of_data) {
        hval ^= (ccl_hash_t)*data;
        hval *= CCL_HASH_PRIME;
        ++data;
    }

    hval ^= (ccl_hash_t)*data;
    hval *= CCL_HASH_PRIME;

    return hval;
}
