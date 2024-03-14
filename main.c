#include <stdio.h>
#include "src/IntVector.h"


int main()
{
    size_t vector_size = sizeof(int) * 4;
    IntVector *vector = int_vector_new(vector_size);
    if (vector == NULL)
    {
        printf("initialization error");
    }
    else
    {
        // printf("%ld %ld\n", int_vector_get_capacity(vector), int_vector_get_size(vector));
        printf("test push:\n");
        for (int i = 0; i <= 3; i++)
        {
            int_vector_push_back(vector, i);
            printf("push: %d\ncapacity: %ld\nsize: %ld\n", i, int_vector_get_capacity(vector), int_vector_get_size(vector));
        }
        printf("----------------------------\n");
        
        printf("\n");
        int_vector_push_back(vector, 100);
        printf("push: 100\ncapacity: %ld\nsize: %ld\nget_item(4): %d\n", int_vector_get_capacity(vector), int_vector_get_size(vector), int_vector_get_item(vector, 4));
        
        printf("----------------------------\n");
        
        int_vector_shrink_to_fit(vector);
        printf("after shrink_to_fit\ncapacity: %ld\nsize: %ld\nget_item(4): %d\n", int_vector_get_capacity(vector), int_vector_get_size(vector), int_vector_get_item(vector, 4));
        int_vector_push_back(vector, 101);
        printf("push: 101\ncapacity: %ld\nsize: %ld\nget_item(5): %d\n", int_vector_get_capacity(vector), int_vector_get_size(vector), int_vector_get_item(vector, 5));
        
        printf("----------------------------\n");
        
        int_vector_resize(vector, 45);
        printf("after resize 45\ncapacity: %ld\nsize: %ld\nget_item(3): %d\n", int_vector_get_capacity(vector), int_vector_get_size(vector), int_vector_get_item(vector, 3));
        
        printf("----------------------------\n");
        
        int_vector_reserve(vector, 36);
        printf("after reserve:\ncapacity: %ld\nsize: %ld\nget_item(3): %d\n", int_vector_get_capacity(vector), int_vector_get_size(vector), int_vector_get_item(vector, 3));
        
        printf("----------------------------\n");
        int_vector_set_item(vector, 3, 100);
        IntVector *second_vector = int_vector_copy(vector);
        int_vector_set_item(second_vector, 4, 101);
        printf("first vector:\ncapacity: %ld\nsize: %ld\n", int_vector_get_capacity(vector), int_vector_get_size(vector));
        printf("get_item(first_vector, 3): %d\nget_item(first_vector, 4): %d\nget_item(copy_vector, 3): %d\nget_item(copy_vector, 4): %d\n", int_vector_get_item(vector, 3), int_vector_get_item(vector, 4), int_vector_get_item(second_vector, 3), int_vector_get_item(second_vector, 4));
        printf("pointer on first vector's array: %p\npointer on copy vector's array: %p\n", vector -> array, second_vector -> array);

        printf("----------------------------\n");
        int_vector_free(vector);
        printf("after free: \ncapacity: %ld\nsize: %ld\n", int_vector_get_capacity(vector), int_vector_get_size(vector));
    }
}
