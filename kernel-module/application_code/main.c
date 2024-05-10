#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardev" // Change this to your device file path

int main() {
    int fd;
    char buffer[256];
    ssize_t bytes_read;

    // Open the device file
    fd = open(DEVICE_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device file");
        exit(EXIT_FAILURE);
    }

    // Read data from the device file
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        perror("Failed to read from the device file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Display the data read from the device file
    printf("Data read from the device file: %s\n", buffer);

    // Close the device file
    close(fd);

    return 0;
}
