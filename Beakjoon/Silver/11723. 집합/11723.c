#include<stdio.h>
#include<string.h>

int main(){
    int n,arr[21]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char temp[7];
        int x;
        scanf("%s %d",temp,&x);
        if(strcmp(temp,"add")==0){
            arr[x]=1;
        }
        else if(strcmp(temp,"remove")==0){
            arr[x]=0;
        }
        else if(strcmp(temp,"check")==0){
            printf("%d\n",arr[x]);
        }
        else if(strcmp(temp,"toggle")==0){
            arr[x]=(arr[x]==1) ? 0: 1; 
        }
        else if(strcmp(temp,"all")==0){
            for(int i=1;i<=20;i++){
                arr[i]=1;
            }
        }
        else if(strcmp(temp,"empty")==0){
            for(int i=1;i<=20;i++){
                arr[i]=0;
            }
        }
    }
    return 0;
}
