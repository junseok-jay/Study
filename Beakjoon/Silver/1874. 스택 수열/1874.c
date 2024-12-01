#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current = 1;
    int top = -1;
    int* stack = (int*)malloc(n * sizeof(int));
    char* result = (char*)malloc(2 * n * sizeof(char));

    int resultIndex = 0;

    for (int i = 0; i < n; i++) {
        while (current <= arr[i]) {
            stack[++top] = current++;
            result[resultIndex++] = '+';
        }

        if (stack[top] == arr[i]) {
            top--;
            result[resultIndex++] = '-';
        } else {
            printf("NO\n");
            free(arr);
            free(stack);
            free(result);
            return 0;
        }
    }

    for (int i = 0; i < resultIndex; i++) {
        printf("%c\n", result[i]);
    }

    free(arr);
    free(stack);
    free(result);
    return 0;
}
