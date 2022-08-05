#ifndef CCL_SORT_H
#define CCL_SORT_H

#include  "type.h"

/*
 * algorithm: half-recursive quicksort
 */

void ccl_sort_hash (
    ccl_hash_t* begin,
    ccl_hash_t* end
);

void ccl_sort (
    void*  begin,
    void*  end,
    size_t key_size
);

#endif /*!CCL_SORT_H*/
