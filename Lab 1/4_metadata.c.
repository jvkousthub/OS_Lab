#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    // Check if the user provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Retrieve file metadata
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    // Print file metadata
    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of Links: %ld\n", (long)fileStat.st_nlink);
    printf("File Owner: %d\n", fileStat.st_uid);
    printf("File Group: %d\n", fileStat.st_gid);
    printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last Modified: %s", ctime(&fileStat.st_mtime));
    printf("Last Accessed: %s", ctime(&fileStat.st_atime));
    printf("Last Status Change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

