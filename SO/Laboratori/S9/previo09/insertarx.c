#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void usage() {
    char msg[] = "./insertarx </PATH/TO/file>\n";
    write(1,msg,strlen(msg));
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) usage();
    int fd = open(argv[1], O_RDWR);
    char buff[256];
    int n;
    while ((n = read(fd,buff, sizeof(buff)))>0);
    char last_char = buff[strlen(buff)-1];
    sprintf(buff, "%c", last_char);
    lseek(fd,-1,SEEK_END);
    write(fd,"X",1);
    write(fd,buff,1);
    close(fd);
}