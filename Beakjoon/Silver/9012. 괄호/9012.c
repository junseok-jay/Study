#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char arr[51]={0};
        int sp=-1;
        scanf("%s",arr);
        for(int j=0;j<sizeof(arr);j++){
            if(arr[j]=='('){
                sp++;
            }
            else if(arr[j]==')'){
                sp--;
                if(sp<-1) break;
            }
        }
        if(sp!=-1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
