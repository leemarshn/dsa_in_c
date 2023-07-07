//
// Created by leen on 7/7/23.
//
#include <stdio.h>

void arrayCopy(const int* src, int* dest, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int source[] = {1, 2, 3, 4, 5};
    int destination[5];

    arrayCopy(source, destination, sizeof(source) / sizeof(source[0]));

    // Print the elements in the destination array
    for (int i = 0; i < sizeof(destination) / sizeof(destination[0]); i++) {
        printf("%d\n", destination[i]);
    }

    return 0;
}
