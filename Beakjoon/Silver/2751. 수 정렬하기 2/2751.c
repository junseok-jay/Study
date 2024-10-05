#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int _a=*(int *)a;
    int _b=*(int *)b;
    if(_a<_b) return -1;
    else return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
