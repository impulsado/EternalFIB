#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("salida.txt", O_CREAT|O_WRONLY|O_TRUNC, 0600);
    write(fd, "ABCD", 4);
    close(fd);
}