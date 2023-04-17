#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void count1();


void count1(void * arg){

    for(int i=1;i<=33;i++){

        printf("%d\n",i);

    }
    return NULL;
}

void count2(void * arg){

    for(int i=34;i<=66;i++){

        printf("%d\n",i);

    }
    return NULL;
}

void count3(void * arg){

    for(int i=67;i<=100;i++){

        printf("%d\n",i);

    }
    return NULL;
}

void counting(void * arg){

    for(int i=1;i<=100;i++){

        printf("%d\n",i);

    }
    return NULL;
}

int main(){

    pthread_t t_id[3];
    int total=100;
    int division=(total/3);
    int sum=0;

    for(int i=0;i<3;i++){

        if(i=1){
            pthread_create(&t_id[i],NULL,count1,NULL);
            pthread_join(t_id[i],NULL);

        }
        if(i=2){
            pthread_create(&t_id[i],NULL,count2,NULL);
            pthread_join(t_id[i],NULL);
        }
        if(i=3){
            pthread_create(&t_id[i],NULL,count3,NULL);
            pthread_join(t_id[i],NULL);
        }
    }

    for(int i=0;i<3;i++){

            pthread_create(&t_id[i],NULL,counting,NULL);
            pthread_join(t_id[i],NULL);

        }

    return 0;
}