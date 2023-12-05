int main(){
    printf("start1個目"); 
    int x;
    printf("end1個目");
    for(i=0;i < N;i++){
        printf("start2個目");
        int t;
        printf("end2個目");
        for(j=0;j<N;j++){
            printf("startとend同じ3個目");
        }
        printf("start4個目");
        printf("end4個目");
    }
    printf("betweenFor_If");
    if(i==0){
        printf("start5個目");
        printf("end5個目");
    }else{
        printf("start6個目");
        printf("end6個目");
    }
    printf("start7個目");
    printf("end7個目");
}