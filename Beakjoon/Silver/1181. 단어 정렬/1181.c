#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* a, const void* b) {
    int len_a = strlen(*(const char**)a);
    int len_b = strlen(*(const char**)b);

    if (len_a > len_b) {
        return 1;
    } else if (len_a < len_b) {
        return -1;
    } else {
        return strcmp(*(const char**)a, *(const char**)b);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char** arr=(char**)malloc(sizeof(char*)*n);
    
    for(int i=0;i<n;i++){
        arr[i]=(char*)malloc(sizeof(char)*50);
        scanf("%s",arr[i]);
    }
    qsort(arr,n,sizeof(char*),compare);
    for(int i=0;i<n-1;i++){
        if(strcmp(arr[i],arr[i+1])!=0){
            printf("%s\n",arr[i]);
        }
        free(arr[i]);
    }
    printf("%s",arr[n-1]);
    free(arr[n-1]);
    free(arr);
    return 0;
}
