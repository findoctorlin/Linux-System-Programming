#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
//dont allow child born child
int main(int argc, char* argv[])
{
    int i;
    for(i=0; i<5; ++i) {
        if(fork() == 0) break;
    }
    if(i == 5) {
        sleep(5);
        printf("I am parent\n");
    }
    else{
        sleep(i);
        printf("I am %dth child\n", i+1);
    }
    return 0;
}