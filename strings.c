#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memoryErrorHandler(char *str) {
    fprintf(stderr, "Error while assigne memory");
    return 1;
}

int main() {
    char *str;

    // Initial memory allocation
    str = (char *) malloc(12 * sizeof(char));
    if (str == NULL)
    {
        return memoryErrorHandler(str);
    }
    
    strcpy(str, "Hello Guys.");
    printf("String = %s, Address = %p\n", str, (void *)str); // explicit cast

    // Reallocating memory
    char *temp = (char *) realloc(str, 28 * sizeof(char));
    if (temp == NULL)
    {
        free(str);
        return memoryErrorHandler(str);
    }
    str = temp;
    strcat(str, " String exercise.");
    printf("String = %s, Address = %p\n", str, (void*)str); // explicit cast

    // Deallocate allocated memory
    free(str);

    return 0;
}