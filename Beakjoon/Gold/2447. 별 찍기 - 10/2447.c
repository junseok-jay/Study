#include<stdio.h>
#include<stdlib.h>

void make_star(char** arr, int size){
    int loop=3,x=0,y=0;
    while(loop<size){
        if(!(x==1&&y==1)){
            for(int i=0;i<loop;i++){
                for(int j=0;j<loop;j++){
                    arr[x*loop+i][y*loop+j]=arr[i][j];
                }
            }
        }
        
        x++;
        if(x==3){
            x=0;
            y++;
        }
        if(y==3){
            y=0;
            loop*=3;
        }
    }
}

int main(){
    int n;
    char **arr;
    scanf("%d",&n);
    if(n%3==0){
        arr=(char**)malloc(sizeof(char*)*n);
        for(int i=0;i<n;i++){
            arr[i]=(char*)malloc(sizeof(char)*n);
            for(int j=0;j<n;j++){
                arr[i][j]=' ';
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1&&j==1){
                    arr[i][j]=' ';
                    continue;
                }
                arr[i][j]='*';
            }
        }
        make_star(arr,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
    return 0;
}
