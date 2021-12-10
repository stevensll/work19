#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>

#include <ctype.h>
#include <sys/wait.h>

#define MAX_BUFF_LEN 1000

int main(){
    int fd1 = open("w", O_RDONLY);
    int fd2 = open("r", O_WRONLY);

    while(1){
        char buff[MAX_BUFF_LEN];
        read(fd1, buff, sizeof(buff));
        buff[strlen(buff)-1] = '\0';
        int i = 0;
        for(i = 0; i < strlen(buff); i++){
            if (buff[i] >= 'a' && buff[i] <= 'z') buff[i] -= 32;
        }
        printf("%s\n", buff);
        write(fd2, buff, sizeof(buff));
    }
    return 0;
}