#ifndef CCL_TYPE_H
#define CCL_TYPE_H

#include <stdint.h>
#include <stddef.h>

typedef unsigned long long ccl_hash_t;
typedef uint8_t ccl_byte_t;
typedef int8_t  ccl_sign_t;

#define ccl_vec_t(type, dim) type __attribute__ ((vector_size(sizeof(type)*dim)))

#endif /*!CCL_TYPE_H*/
