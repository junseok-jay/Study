#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Info{
    int age;
    char name[101];
    int order;
}info;

int compare(const void* a,const void* b){
    info* arr1 = *(info**)a;
    info* arr2 = *(info**)b;
    if(arr1->age<arr2->age){
        return -1;
    }
    else if(arr1->age>arr2->age){
        return 1;
    }
    else if(arr1->order<arr2->order){
        return -1;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    info **info_arr=(info**)malloc(sizeof(info*)*n);
    for(int i=0;i<n;i++){
        info_arr[i]=(info*)malloc(sizeof(info));
        info_arr[i]->order=i;
        scanf("%d %s",&info_arr[i]->age,&info_arr[i]->name);
    }
    qsort(info_arr,n,sizeof(info*),compare);
    
    for(int i=0;i<n;i++){
        printf("%d %s\n",info_arr[i]->age,info_arr[i]->name);
        free(info_arr[i]);
    }
    free(info_arr);
    return 0;
}
