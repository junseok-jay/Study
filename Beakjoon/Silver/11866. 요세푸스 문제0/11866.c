#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m, point = 0, res_point = 0;
    scanf("%d %d", &n, &m);
    
    int* arr = (int*)malloc(sizeof(int) * n);
    int* res = (int*)malloc(sizeof(int) * n); 
    
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    while(res_point < n){
        int cnt = 0;

        while(cnt < m){
            if(arr[point] != 0) cnt++;
            if(cnt == m) break;
            point = (point + 1) % n;
        }

        res[res_point] = arr[point];
        arr[point] = 0;
        res_point++;

        point = (point + 1) % n;
    }

    printf("<");
    for(int i = 0; i < n - 1; i++){
        printf("%d, ", res[i]);
    }
    printf("%d>\n", res[n - 1]);

    free(arr);
    free(res);

    return 0;
}
