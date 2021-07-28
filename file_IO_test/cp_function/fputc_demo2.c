#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
//动态cp的实现，在terminal，用户可以指定复制对象
int main(int argc, char* argv[])
{
    FILE *fp, *fp_out;
    int n;

    fp = fopen(argv[1], "r");
    fp_out = fopen(argv[2], "w");

    while((n = fgetc(fp)) != EOF) {
        fputc(n, fp_out);
    }

    fclose(fp);
    fclose(fp_out);

    return 0;
}