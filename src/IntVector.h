#ifndef INTVECTOR_H

#define __need_size_t
#include <stddef.h>

#define INTVECTOR_H 1

typedef struct 
{
    int *array;
    unsigned int used;
    size_t size;
} IntVector;

extern IntVector *int_vector_new(size_t initial_capacity);

extern IntVector *int_vector_copy(const IntVector *v);

extern void int_vector_free(IntVector *v);

extern int int_vector_get_item(const IntVector *v, int index);

extern void int_vector_set_item(IntVector *v, int index, int item);

extern size_t int_vector_get_size(const IntVector *v);

extern size_t int_vector_get_capacity(const IntVector *v);

extern int int_vector_push_back(IntVector *v, int item);

extern void int_vector_pop_back(IntVector *v);

extern int int_vector_shrink_to_fit(IntVector *v);

extern int int_vector_resize(IntVector *v, size_t new_size);

extern int int_vector_reserve(IntVector *v, size_t new_capacity);

#endif