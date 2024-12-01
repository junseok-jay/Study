#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int* arr=(int *)malloc(sizeof(int)*n);
    int* arr_app=(int *)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr_app[i]=0;
    }
    for(int i=0;i<m;i++){
        int row, high, app;
        scanf("%d %d %d",&row,&high,&app);
        arr_app[row-1]+=app;
        if(high<n) arr_app[high]-=app;
    }

    printf("%d ",arr[0]+arr_app[0]);
    for(int i=1;i<n;i++){
        arr_app[i]+=arr_app[i-1];
        printf("%d ",arr[i]+arr_app[i]);
    }
    free(arr);
    free(arr_app);
    return 0;
}
