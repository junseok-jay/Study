#include<stdio.h>

int main(){
    int n,cnt=0,i;
    scanf("%d",&n);

    for(i=666;cnt<n;i++){
        int temp=i;
        while(temp!=0){
            if(temp%10==6 && (temp/=10)%10==6 && (temp/=10)%10==6){
                cnt++;
                break;
            }
            temp/=10;
        }
    }
    printf("%d",i-1);
    return 0;
}
