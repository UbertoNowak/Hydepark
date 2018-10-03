#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Create fd
    int file_descriptor = open("test.txt", O_RDWR);
    if (file_descriptor == -1)
    {
        printf("Can't open file\n");
    }
    printf("Open file_descriptor: %i\n", file_descriptor);

    char buffer[50];

    // Read from fd
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("Read %zd bytes, msg: %s \n", bytes_read, buffer);

    // Write to fd
    const char *new_text = " add some info\0";
    write(file_descriptor, new_text, strlen(new_text));

    // Create new file
    if (argc > 1)
    {
        int new_file_fd = creat(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if (new_file_fd != -1)
        {
            printf("Open new_file_fd: %i\n", new_file_fd);
            write(new_file_fd, new_text, strlen(new_text));

            if (close(new_file_fd) == 0)
            {
                printf("File_descriptor: %i, close correctly\n", new_file_fd);
            }
        }
    }

    // Close fd
    if (close(file_descriptor) == 0)
    {
        printf("File_descriptor: %i, close correctly\n", file_descriptor);
    }

    return 0;
}
