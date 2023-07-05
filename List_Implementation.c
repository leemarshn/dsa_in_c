//
// Created by leen on 7/5/23.
//
#include <stdio.h>

int main() {
    int my_list[5] = {17, 15, 13, 21, 19};
    int i, size = 5;

    // i. Insert 10 at the start of the list.
    for (i = size - 1; i >= 0; i--) {
        my_list[i + 1] = my_list[i];
    }
    my_list[0] = 10;
    size++;

    // ii. Insert 12 at the end of the list.
    my_list[size] = 12;
    size++;

    // iii. Insert 11 after 17.
    int index_17 = -1;
    for (i = 0; i < size; i++) {
        if (my_list[i] == 17) {
            index_17 = i;
            break;
        }
    }
    for (i = size - 1; i > index_17; i--) {
        my_list[i + 1] = my_list[i];
    }
    my_list[index_17 + 1] = 11;
    size++;

    // iv. Replace 15 with 25.
    for (i = 0; i < size; i++) {
        if (my_list[i] == 15) {
            my_list[i] = 25;
            break;
        }
    }

    // v. Replace data on index 3 with 40.
    my_list[3] = 40;

    // vi. Delete elements stored at index 1, 3, 5, 7.
    int indices_to_delete[] = {7, 5, 3, 1};
    int num_indices = sizeof(indices_to_delete) / sizeof(indices_to_delete[0]);
    for (i = 0; i < num_indices; i++) {
        int index_to_delete = indices_to_delete[i];
        for (int j = index_to_delete; j < size - 1; j++) {
            my_list[j] = my_list[j + 1];
        }
        size--;
    }

    // Print the updated list
    for (i = 0; i < size; i++) {
        printf("%d ", my_list[i]);
    }
    printf("\n");

    return 0;
}
