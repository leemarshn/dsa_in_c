//
// Created by leen on 7/5/23.
//

#include <stdio.h>

#define MAX 10
int V[MAX] = {1, 23, 17, 4, -5, 100};
int n = 6, j;

void list_insert(int listname[], int x, int i) {
    if (i > n || n > MAX - 2) {
        printf(" Overflow error \n");
        return;
    } else if (i < 0) {
        printf("\ninvalid position\n");
        return;
    }
    j = n - 1;
    while (j >= i) {
        listname[j + 1] = listname[j];
        j = j - 1;
    }
    listname[i] = x;
    n = n + 1;
}

int main(void) {
    int i = 0, x = 0, j = 0;
    printf("Enter your position <%d\n", MAX - 1);
    scanf("%d", &i);
    printf("Enter your element \n");
    scanf("%d", &x);
    printf("Position is %d\n", i);
    printf("Element is %d\n", x);
    printf("\n\n");
    printf("******** Before Insertion ********** \n");
    printf("\n\n");
    for (j = 0; j < n; j++) {
        printf("V[%d] = %d ", j, V[j]);
    }
// Call insert element function
    list_insert(V, x, i);
    printf("\n\n");
    printf("*********** After Insertion ************* \n");
    printf("\n\n");
    for (j = 0; j < n; j++) {
        printf("V[%d] = %d ", j, V[j]);
    }
    return 0;
}
