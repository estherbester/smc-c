
/*
Page 568/Prob. 1
Exercises and Programming Problems
The program cp.c makes a copy of a file. It uses getc () and putc () to do the input and output. Write four new versions of a file copy program. Each of the programs should have the same functionality as cp.c

In the first version, use fgetc () to do the input and fputc () to do the output.

In the second version, use fgets () to do the input and fputs () to do the output.

In the third version, use fread () to do the input and fwrite () to do the output.

In the fourth version, use fscanf () to do the input and fprintf () to do the output.

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
    int max_length = 79;
    char line[max_length];

    FILE * infile;
    FILE * outfile;


    if (argc < 3) {
        printf("ERROR: Please enter copy command, source filename to read from, and target file to copy into.\n");
        exit(1);
    }

    printf("Copying from: %s to %s\n", argv[1], argv[2]);
    printf("Using fgets() for input and fputs() for output.\n");

    infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(argv[2], "w");

    // gets reads each line at a time, up to the {max_length} number of characters
    while (fgets(line, max_length+1, infile) != NULL)
    {
        fputs(line, outfile);
    }


    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");
    return 0;


}
