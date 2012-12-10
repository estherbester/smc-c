
/*
Page 568/Prob. 1
Exercises and Programming Problems
The program cp.c makes a copy of a file. It uses getc () and putc () to do the input and output. Write four new versions of a file copy program. Each of the programs should have the same functionality as cp.c

In the third version, use fread () to do the input and fwrite () to do the output.

Compare the sizes of the object code from all five versions of the file copy programs. If the facilities for testing execution efficiency are available on your system, test the efficiency of each version. Report on your findings.

*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


/*
    Required arguments:
    {string} filename of source file to read from
    {string} filename of target file to write to.

*/

int main(int argc, char * argv[])
{

    int max_file_size = 6400,
        i=0;
    char * filestream = malloc((max_file_size)*(sizeof(int)));

    FILE * infile;
    FILE * outfile;

    if (argc < 3) {
        printf("ERROR: Please enter copy command, source filename to read from, and target file to copy into.\n");
        exit(1);
    }

    printf("Copying from: %s to %s\n", argv[1], argv[2]);
    printf("Using fread() for input and fwrite() for output.\n");

    infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(argv[2], "w");

    fread(filestream, sizeof(char), max_file_size, infile);
    while (filestream[i] != '\0' && i < max_file_size)
    {
        fwrite(&filestream[i], sizeof(char), 1, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");
    return 0;


}



