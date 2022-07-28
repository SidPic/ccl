#ifndef CCL_HASH_H
#define CCL_HASH_H

/*
 * algorithm: FNV_64a
 */

#include <stddef.h>

#ifndef CCL_HASH_PRIME
#define CCL_HASH_PRIME 0x100000001b3ULL
#endif

#ifndef CCL_HASH_INIT
#define CCL_HASH_INIT  0xcbf29ce484222325ULL
#endif

typedef unsigned long long ccl_hash_t;

ccl_hash_t ccl_hash     (const char* data, const char* end_of_data);
ccl_hash_t ccl_hash_str (const char* str);

#endif /*!CCL_HASH_H*/
