#ifndef CCL_FIND_H
#define CCL_FIND_H

#include  "type.h"

/*
 * algorithm: optimized binary search
 */

const void* ccl_find (
    const void* array,
      size_t    len,
    const void* key,
      size_t    key_size
);

const ccl_hash_t* ccl_find_hash (
    const ccl_hash_t* array,
            size_t    len,
          ccl_hash_t  key
);

/////////////////////////////////////////

#define _ccl_find( /*anytype[n]*/ array, /*size_t*/ len, /*anytype*/ key ) ({            \
      size_t    __len    = len;                                                          \
    typeof(key) __key    = key;                                                          \
    typeof(key) __array  = array;                                                        \
    typeof(key) __result = NULL;                                                         \
                                                                                         \
    while (__len/=2) {                                                                   \
        if (*(__array+=__len) == *__key) {__result = __array; break;}                    \
        if ( *__array         >  *__key) __array -= __len;                               \
    }                                                                                    \
                                                                                         \
    if (__result == NULL) {                                                              \
        if ( *__array     == *__key) __result = __array; else                            \
        if (*(__array+=1) == *__key) __result = __array;                                 \
    }                                                                                    \
                                                                                         \
    /*return*/ __result;                                                                 \
}) /*!_ccl_find*/

#endif /*!CCL_FIND_H*/
