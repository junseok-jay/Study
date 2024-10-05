#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int* a1=*(int **)a;
    int* b1=*(int **)b;
    if(a1[0]==b1[0]){
        if(a1[1]<b1[1]){
            return -1;
        }
        else return 1;
    }
    else if(a1[0]<b1[0]){
        return -1;
    }
    else return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int **xy=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        xy[i]=(int*)malloc(sizeof(int)*2);
        scanf("%d %d",&xy[i][0],&xy[i][1]);
    }
    qsort(xy,n,sizeof(int*),compare);
    for(int i=0;i<n;i++){
        printf("%d %d\n",xy[i][0],xy[i][1]);
    }
    for(int i=0;i<n;i++){
        free(xy[i]);
    }
    free(xy);
    return 0;
}
