#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void divide(char *n, char *m, char *quotient, char *remainder) {
    int n_len = strlen(n);
    int m_len = strlen(m);
    int temp = 0;
    int q_index = 0;
    int r_index = 0;

    for (int i = 0; i < n_len; i++) {
        temp = temp * 10 + (n[i] - '0');
        
        if (temp < atoi(m)) {
            quotient[q_index++] = '0';
        } else {
            quotient[q_index++] = (temp / atoi(m)) + '0';
            temp %= atoi(m);
        }
    }
    quotient[q_index] = '\0';

    sprintf(remainder, "%d", temp);

    int start = 0;
    while (quotient[start] == '0' && quotient[start + 1] != '\0') {
        start++;
    }

    printf("%s\n", quotient + start);
    printf("%s\n", remainder);
}

int main() {
    char n[10001];
    char m[10001];
    char quotient[10001];
    char remainder[10001];

    scanf("%s %s", n, m);

    divide(n, m, quotient, remainder);

    return 0;
}
