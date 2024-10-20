#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b){
    int a1=*(int *)a;
    int b1=*(int *)b;

    if(a1>b1){
        return 1;
    }
    else if(a1<b1){
        return -1;
    }
    else return 0;
}

int bin_search(int *arr,int size,int target){
    int low=0,high=size-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(target>arr[mid]){
            low=mid+1;
        }
        else if(target<arr[mid]){
            high=mid-1;
        }
        else break;
    }
    if(target==arr[mid]) return 1;
    return 0;
}

int main(){
    int n,m;
    scanf("%d",&n);
    int *arr1=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    qsort(arr1,n,sizeof(int),compare);

    scanf("%d",&m);
    int *arr2=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    
    for(int i=0;i<m;i++){
        printf("%d\n",bin_search(arr1,n,arr2[i]));
    }
    free(arr1);
    free(arr2);
    return 0;
}
