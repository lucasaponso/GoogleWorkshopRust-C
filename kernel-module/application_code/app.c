#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/mychardev" // Change this to your device file path

int main() {
    int fd;
    char read_buffer[256];
    char write_buffer[256] = "New data to be written to the device file!\n"; // New data to be written
    ssize_t bytes_read, bytes_written;

    // Open the device file for reading
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        exit(EXIT_FAILURE);
    }

    // Read existing data from the device file
    bytes_read = read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read < 0) {
        perror("Failed to read from the device file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Display the existing data read from the device file
    printf("Existing data read from the device file: %s\n", read_buffer);

    // Write new data to the device file
    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        perror("Failed to write to the device file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Display the new data written to the device file
    printf("New data written to the device file: %s\n", write_buffer);

    // Close the device file
    close(fd);

    return 0;
}
