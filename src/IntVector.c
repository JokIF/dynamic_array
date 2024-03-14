#include <stdlib.h>
#include <string.h>
#define VECTOR_INT_TYPE_SIZE 4
#define VECTOR_INT_EXPAND_COEFF 2

typedef struct 
{
    int *array;
    size_t size;
    size_t capacity;
} IntVector;


IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *vector = malloc(sizeof(IntVector));
    if (vector == NULL)
        return NULL;
    
    vector -> array = (int*)malloc(initial_capacity * VECTOR_INT_TYPE_SIZE);
    if (vector -> array == NULL)
    {
        free(vector);
        return NULL;
    }
        
    vector -> capacity = initial_capacity;
    vector -> size = (size_t)0;
    return vector;
}

IntVector *int_vector_copy(const IntVector *v)
{
    // IntVector *new_vector = malloc(sizeof(IntVector));
    // int *new_array = malloc(v -> capacity);
    
    // memmove(new_array, v -> array, v -> capacity);
    
    // if (new_vector == NULL || new_vector -> array == NULL)
    //     return NULL;
    
    // new_vector -> capacity = v -> capacity;
    // new_vector -> size = v -> size;

    // return new_vector;

    // // --------------------------------------
    
    // IntVector *new_vector = malloc(sizeof(IntVector));
    // new_vector -> array = malloc(v -> capacity);
    // if (new_vector == NULL || new_vector -> array == NULL)
    //     return NULL;

    // new_vector -> capacity = v -> capacity;
    // new_vector -> size = v -> size;
    // for (int i = 0; i * VECTOR_INT_TYPE_SIZE < v -> size; i++)
    // {
    //     new_vector -> array[i] = v -> array[i];
    // }
    // return new_vector;

    // -------------------------------------------

    // IntVector *new_vector = int_vector_new(v -> capacity);
    // new_vector -> capacity = v -> capacity;
    // new_vector -> size = v -> size;
    // for (int i = 0; i * VECTOR_INT_TYPE_SIZE < v -> size; i++)
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
    // for (int i = 0; i < v->size; i++)
    // {
    //     (new->array)[i] = (v->array)[i];
    // }
    // new->capacity = v->capacity;
    // new->size = v->size;


    // return new;
    // ------------------------------------------
    IntVector *new = malloc(sizeof(IntVector));
    if (new == NULL)
        return NULL;
    new -> array = malloc((v -> capacity * VECTOR_INT_TYPE_SIZE) - VECTOR_INT_TYPE_SIZE);

    if (new -> array == NULL)
    {
        free(new);
        return NULL;
    }

    new -> array = realloc(new -> array, v -> capacity * VECTOR_INT_TYPE_SIZE);

    if (new -> array == NULL)
    {
        free(new -> array);
        free(new);
        return NULL;
    }

    new -> capacity = v -> capacity;
    new -> size = v -> size;
    return new;
}

void int_vector_free(IntVector *v)
{
    free(v -> array);
    free(v);
}

int int_vector_get_item(const IntVector *v, int index)
{
    // if (v -> size > index * VECTOR_INT_TYPE_SIZE)
    return v -> array[index];
    // return NULL;
}

void int_vector_set_item(IntVector *v, int index, int item)
{
    // if (v -> size > index * VECTOR_INT_TYPE_SIZE)
    v -> array[index] = item;
    // return NULL;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v -> size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v -> capacity;
}

int int_vector_expand(IntVector *v)
{
    if (v -> size < v -> capacity)
        return 0;
    
    if (v -> capacity == 0)
        v -> capacity = 1;

    int *tmp = v -> array;
    tmp = realloc(tmp, v -> capacity * VECTOR_INT_TYPE_SIZE * VECTOR_INT_EXPAND_COEFF);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> capacity *= VECTOR_INT_EXPAND_COEFF;
    return 0;
}

int int_vector_push_back(IntVector *v, int item)
{
    if(int_vector_expand(v) == -1)
        return -1;
    
    int insert_index = (int)(v -> size);

    v -> array[insert_index] = item;
    v -> size++;
    return 0;
}

void int_vector_pop_back(IntVector *v)
{
    if (v -> size == 0)
        return;
    
    v -> size--;
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if (v -> size == v -> capacity)
        return 0;

    int *tmp = v -> array;
    tmp = realloc(tmp, v -> size * VECTOR_INT_TYPE_SIZE);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> capacity = v -> size;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (v -> size >= new_size)
        return 0;
    int range_up = (new_size - v -> size);

    for (int i = 0; i < range_up; i++)
    {
        if (int_vector_push_back(v, 0))
            return -1;
    }
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (v -> capacity >= new_capacity)
        return 0;
    
    int *tmp = v -> array;
    tmp = realloc(tmp, new_capacity);
    if (tmp == NULL)
        return -1;
    v -> array = tmp;
    v -> capacity = new_capacity;
    if (v -> capacity < v -> size)
        v -> size = v -> capacity;
    return 0;
}
