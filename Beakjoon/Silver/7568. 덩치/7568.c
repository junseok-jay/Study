#include<stdio.h>
#include<stdlib.h>

int com(int* arr1, int* arr2){
    if(arr1[0]<arr2[0]&&arr1[1]<arr2[1]){
        return 1;
    }
    else if(arr1[0]>arr2[0]&&arr1[1]>arr2[1]){
        return -1;
    }
    else return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int **arr=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(sizeof(int)*3);
    }
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    for(int i=0;i<n;i++){
        int cnt=1;
        for(int k=0;k<n;k++){
            if(com(arr[i],arr[k])==1){
                cnt++;
            }
        }
        arr[i][2]=cnt;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i][2]);
    }
    return 0;
}
