
/*
Page 568/Prob. 1
Exercises and Programming Problems
The program cp.c makes a copy of a file. It uses getc () and putc () to do the input and output. Write four new versions of a file copy program. Each of the programs should have the same functionality as cp.c

In the fourth version, use fscanf () to do the input and fprintf () to do the output.

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
    char c;

    FILE * infile;
    FILE * outfile;

    if (argc < 3) {
        printf("ERROR: Please enter copy command, source filename to read from, and target file to copy into.\n");
        exit(1);
    }

    printf("Copying from: %s to %s\n", argv[1], argv[2]);
    printf("Using fscanf() for input and fprintf() for output.\n");

    infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(argv[2], "w");

    // We are going to read every character as a character, nothing else.
    while (fscanf(infile, "%c", &c) != EOF)
    {
        fprintf(outfile, "%c", c);
    }

    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");

    return 0;


}
