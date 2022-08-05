#include "sort.h"
#include <string.h>
#include <alloca.h>

/*
 * algorithm: half-recursive quicksort
 */

void ccl_sort_hash (
    ccl_hash_t* begin,
    ccl_hash_t* end
) {
    ccl_hash_t piv, tmp;
    ccl_hash_t *left, *right, *mid;

    while (begin < end) {
        mid   = begin + (end - begin) / 2;
        left  = begin;
        right = end;

        piv = *mid;

        while (1) {
            while (left <= right && *left <= piv) ++left;
            while (left <= right && *right > piv) --right;

            if (left > right) break;

             tmp   = *left;
            *left  = *right;
            *right =  tmp;

            if (mid == right) mid = left;

            ++left, --right;
        }

        *mid = *right;
        *right = piv;
        --right;

        if (right - begin < end - left) {
            ccl_sort_hash(begin, right);
            begin = left;
        } else {
            ccl_sort_hash(left, end);
            end = right;
        }
    }
}

void ccl_sort (
    void*  begin,
    void*  end,
    size_t key_size
) {
    void *tmp, *piv;
    void *left, *mid, *right;

    tmp = alloca(key_size);
    piv = alloca(key_size);

    while (begin < end) {
        mid   = begin + (end - begin) / 2;
        left  = begin;
        right = end;

        memcpy(piv, mid, key_size);

        while (1) {
            while (left <= right && memcmp(left, piv, key_size) <= 0) left += key_size;
            while (left <= right && memcmp(right, piv, key_size) > 0) right -= key_size;

            if (left > right) break;

            memcpy(tmp,   left,  key_size);
            memcpy(left,  right, key_size);
            memcpy(right, tmp,   key_size);

            if (mid == right) mid = left;

            left += key_size;
            right -= key_size;
        }

        memcpy(mid, right, key_size);
        memcpy(right, piv, key_size);
        right -= key_size;

        if (right - begin < end - left) {
            ccl_sort(begin, right, key_size);
            begin = left;
        } else {
            ccl_sort(left, end, key_size);
            end = right;
        }
    }
}
