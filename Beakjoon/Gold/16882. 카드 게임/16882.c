#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int cast_a = *(int *)a;
    int cast_b = *(int *)b;
    return cast_b - cast_a;
}

int main(){
    int n; 
    scanf("%d", &n);
    int* arr = (int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    int cnt=0; 
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==max) cnt++;
        else if(cnt%2==0){
            max=arr[i];
            i--;
        }
        
    }

    if(cnt%2==1){
        printf("koosaga\n");
    } else{ 
        printf("cubelover\n");
    }
    free(arr);
    return 0;
}
