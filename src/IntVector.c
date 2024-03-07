#include <stdlib.h>
#include <string.h>
#define VECTOR_INT_TYPE_SIZE 4
#define VECTOR_INT_EXPAND_COEFF 2

typedef struct 
{
    int *array;
    size_t used;
    size_t size;
} IntVector;


IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *vector = malloc(sizeof(IntVector));
    vector -> array = (int*)malloc((int)initial_capacity);
    if (vector == NULL || vector -> array == NULL)
        return NULL;

    vector -> size = initial_capacity;
    vector -> used = (size_t)0;
    return vector;
}

IntVector *int_vector_copy(const IntVector *v)
{
    // IntVector *new_vector = malloc(sizeof(IntVector));
    // int *new_array = malloc(v -> size);
    
    // memmove(new_array, v -> array, v -> size);
    
    // if (new_vector == NULL || new_vector -> array == NULL)
    //     return NULL;
    
    // new_vector -> size = v -> size;
    // new_vector -> used = v -> used;

    // return new_vector;

    // // --------------------------------------
    
    // IntVector *new_vector = malloc(sizeof(IntVector));
    // new_vector -> array = malloc(v -> size);
    // if (new_vector == NULL || new_vector -> array == NULL)
    //     return NULL;

    // new_vector -> size = v -> size;
    // new_vector -> used = v -> used;
    // for (int i = 0; i * VECTOR_INT_TYPE_SIZE < v -> used; i++)
    // {
    //     new_vector -> array[i] = v -> array[i];
    // }
    // return new_vector;

    // -------------------------------------------

    // IntVector *new_vector = int_vector_new(v -> size);
    // new_vector -> size = v -> size;
    // new_vector -> used = v -> used;
    // for (int i = 0; i * VECTOR_INT_TYPE_SIZE < v -> used; i++)
    // {
    //     new_vector -> array[i] = v -> array[i];
    // }
    // return new_vector;

    // -------------------------------------------

    // IntVector *new = malloc(sizeof(IntVector));
    // if (new == NULL)
    // {
    //     return NULL;
    // }

    // if (new->array == NULL)
    // {
    //     return NULL;
    // }
    // for (int i = 0; i < v->used; i++)
    // {
    //     (new->array)[i] = (v->array)[i];
    // }
    // new->size = v->size;
    // new->used = v->used;


    // return new;
    // ------------------------------------------
    IntVector *new = malloc(sizeof(IntVector));
    if (new == NULL)
        return NULL;
    new -> array = malloc(4);

    if (new -> array == NULL)
        return NULL;

    new -> array = realloc(new -> array, v -> size);

    if (new -> array == NULL)
        return NULL;

    new -> size = v -> size;
    new -> used = v -> used;
    return new;
}

void int_vector_free(IntVector *v)
{
    free(v -> array);
    v -> size = v -> used = (size_t)0;
}

int int_vector_get_item(const IntVector *v, int index)
{
    // if (v -> used > index * VECTOR_INT_TYPE_SIZE)
    return v -> array[index];
    // return NULL;
}

void int_vector_set_item(IntVector *v, int index, int item)
{
    // if (v -> used > index * VECTOR_INT_TYPE_SIZE)
    v -> array[index] = item;
    // return NULL;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v -> used;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v -> size;
}

int int_vector_expand(IntVector *v)
{
    if (v -> used < v -> size)
        return 0;
    
    if (v -> size == 0)
        v -> size = (size_t)4;

    int *tmp = v -> array;
    tmp = realloc(tmp, v -> size * VECTOR_INT_EXPAND_COEFF);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> size *= VECTOR_INT_EXPAND_COEFF;
    return 0;
}

int int_vector_push_back(IntVector *v, int item)
{
    if(int_vector_expand(v))
        return -1;
    
    int insert_index = (int)(v -> used / VECTOR_INT_TYPE_SIZE);

    v -> array[insert_index] = item;
    v -> used += VECTOR_INT_TYPE_SIZE;
    return 0;
}

void int_vector_pop_back(IntVector *v)
{
    if (v -> used == (size_t)0)
        return;
    
    v -> used -= VECTOR_INT_TYPE_SIZE;
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if (v -> used == v -> size)
        return 0;

    int *tmp = v -> array;
    tmp = realloc(tmp, v -> used);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> size = v -> used;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (v -> used >= new_size)
        return 0;
    int range_up = (new_size - v -> used)/VECTOR_INT_TYPE_SIZE;

    for (int i = 0; i < range_up; i++)
    {
        if (int_vector_push_back(v, 0))
            return -1;
    }
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (v -> size >= new_capacity)
        return 0;
    
    int *tmp = v -> array;
    tmp = realloc(tmp, new_capacity);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> size = new_capacity;
    if (v -> size < v -> used)
        v -> used = v -> size;
    return 0;
}
