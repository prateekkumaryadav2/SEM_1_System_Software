
// with system calls
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("filename.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[1024];
    ssize_t bytesRead;
    int i, start = 0;

    // Reading the file in chunks
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        start = 0;
        for (i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                // Print the line
                write(1, &buffer[start], i - start + 1);
                start = i + 1;
            }
        }
        // If there is leftover data (no newline at end), print it
        if (start < bytesRead) {
            write(1, &buffer[start], bytesRead - start);
        }
    }

    close(fd);
    return 0;
}