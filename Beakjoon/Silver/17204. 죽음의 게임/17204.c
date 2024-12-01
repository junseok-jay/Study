#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int* arr=(int *)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int index=0, count=0;
    while(index!=m&&count<n){
        index=arr[index];
        count++;
    }   
    if(count>=n||index!=m){
        printf("-1");
    }
    else printf("%d", count);
    free(arr);
    return 0;
}
