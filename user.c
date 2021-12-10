#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>

#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFF_LEN 1000

int main(){
    mkfifo("r", 0644);
    mkfifo("w", 0644);

    int fd_w = open("w", O_WRONLY);
    int fd_r = open("r", O_RDONLY);

    while(1){
        char buff[MAX_BUFF_LEN];
        printf("Please enter an input (no more than 1000 chars): ");
        fgets(buff, sizeof(buff), stdin);

        write(fd_w, buff, sizeof(buff));
        read(fd_r, buff, sizeof(buff));

        printf("Output: %s\n", buff);
    }
    return 0;
}