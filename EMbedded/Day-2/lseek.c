#define _GNU_SOURCE  // Needed for SEEK_DATA and SEEK_HOLE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void show_seek_result(int fd, off_t offset, int whence, const char *label) {
    off_t result = lseek(fd, offset, whence);
    if (result == -1) {
        perror(label);
    } else {
        printf("%s: Offset now at %lld\n", label, (long long)result);
    }
}

int main() {
    int fd = open("sparsefile.stxt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // SEEK_SET: Move to byte 2
    show_seek_result(fd, 2, SEEK_SET, "SEEK_SET");

    // SEEK_CUR: Move 5 bytes ahead from current position
    show_seek_result(fd, 5, SEEK_CUR, "SEEK_CUR");

    // SEEK_END: Move 5 bytes before end of file
    show_seek_result(fd, -5, SEEK_END, "SEEK_END");

    // SEEK_DATA: Move to next data region
    show_seek_result(fd, 0, SEEK_DATA, "SEEK_DATA");

    // SEEK_HOLE: Move to next hole
    show_seek_result(fd, 0, SEEK_HOLE, "SEEK_HOLE");

    close(fd);
    return 0;
}
