
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

void copy_file_v1();  // use fgetc () to do the input and fputc () to do the output.
void copy_file_v2();  // use fgets () to do the input and fputs () to do the output.
void copy_file_v3();  // use fread () to do the input and fwrite () to do the output.
void copy_file_v4();  // use fscanf () to do the input and fprintf () to do the output.


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


/*
    Required arguments:
    {int} Version of copy command we want to run
    {string} filename of source file to read from
    {string} filename of target file to write to.

*/
int main(int argc, char * argv[])
{
    int copy_command = (int) argv[1][0] - '0';


    if (argc < 4) {
        printf("ERROR: Please enter copy command, source filename to read from, and target file to copy into.\n");
        exit(1);
    }

    printf("Copying from: %s to %s\n", argv[2], argv[3]);

    // based on argv[1] we call whichever version of the copy command we want to run.
    switch(copy_command)
    {
        case 1:
            copy_file_v1(argv[2], argv[3]);
            break;
        case 2:
            copy_file_v2(argv[2], argv[3]);
            break;
        case 3:
            copy_file_v3(argv[2], argv[3]);
            break;
        case 4:
            copy_file_v4(argv[2], argv[3]);
            break;
        default:
            printf("ERROR: Not a valid command number.\n");
            exit(1);
    }

    return 0;


}

// use fgetc () to do the input and fputc () to do the output.

void copy_file_v1(char source_file[], char dest_file[])
{
    char character;

    FILE * infile;
    FILE * outfile;

    printf("Using fgetc() for input and fputc() for output.\n");

    infile = fopen(source_file, "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(dest_file, "w");
    while ((character = fgetc(infile))!= EOF)
    {
        fputc(character, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");

}


// use fgets () to do the input and fputs () to do the output.
void copy_file_v2(char source_file[], char dest_file[])
{
    int max_length = 79;
    char line[max_length];

    FILE * infile;
    FILE * outfile;

    printf("Using fgets() for input and fputs() for output.\n");

    infile = fopen(source_file, "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(dest_file, "w");

    while (fgets(line, max_length+1, infile) != NULL)
    {
        fputs(line, outfile);
    }


    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");

}


// use fread() to do the input and fwrite() to do the output.
void copy_file_v3(char source_file[], char dest_file[])
{

    int max_file_size = 6400,
        i=0;
    char filestream[max_file_size];

    FILE * infile;
    FILE * outfile;

    printf("Using fread() for input and fwrite() for output.\n");

    infile = fopen(source_file, "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(dest_file, "w");

    fread(filestream, sizeof(char), max_file_size, infile);
    while (filestream[i] != '\0' && i < max_file_size)
    {
        fwrite(&filestream[i], sizeof(char), 1, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");

}


//use fscanf () to do the input and fprintf () to do the output.
void copy_file_v4(char source_file[], char dest_file[])
{


    FILE * infile;
    FILE * outfile;

    printf("Using fscanf() for input and fprintf() for output.\n");

    infile = fopen(source_file, "r");
    if (infile == NULL)
    {
        printf("Error: Source file does not exist.\n");
        exit(1);
    }

    outfile = fopen(dest_file, "w");



    while (fscanf(infile, "")!= EOF);
    {
        fprintf(outfile, "");
    }




    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");

}
