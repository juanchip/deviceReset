/* usbreset -- send a USB port reset to a USB device */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>


int main(int argc, char **argv)
{
    const char *filename;
    int fd;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "Error! Sin argumentos : resetusb device-filename\n");
        return 1;
    }
    filename = argv[1];

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Error Abriendo archivo de salida");
        return 1;
    }

    printf("Reseteando dispositivo USB: %s\n", filename);
    rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error en ioctl, dispositivo bien elegido?");
        return 1;
    }
    printf("Reset Conseguido con exito\n");

    close(fd);
    return 0;
}
