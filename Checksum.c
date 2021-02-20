/********************************/
/* Program Name: Checksum.c                */
/* Author: John Cruz                      */
/* Date: 02/24/93                        */
/********************************/
/* Description: Calculates Checsum but in C                */
/* Validation Checks: no          */
/* Enhancements: The best ones                */
/********************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Will Erase to comment on next Commit

#define max_int (255)
#define byte unsigned char

int main(int argc, char *argv[], char **envp)
{

    int count = 10;
    int sum = 0;
    byte checksum;
    byte complement;
    byte header[10];
    int quotient;
    int remainder;
    int retval;

    retval = read(STDIN_FILENO, &header, 10);

    for (int i = 0; i < count; i++)
    {
        if (i == 5)
        {
            checksum = header[i];
            header[i] = 0;
        }
        sum += header[i];
    }

    quotient = (sum / (max_int + 1));
    remainder = sum % (max_int + 1);
    sum = quotient + remainder;
    complement = max_int - sum;

    /* the following is the prototype for the read system call /
  / int read(int fildes, void *buf, size_t nbyte);  */

    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement)
    {
        fprintf(stderr, "Error Detected!\n");
        return 1;
    }
    return 0;
}
