
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

int main(int argc, char * argv[])
{
    int copy_command = (int) argv[1][0] - '0';

    char * source_file = argv[2];
    char * dest_file = argv[3];


    if (argc < 4) {
        printf("ERROR: Please enter copy command, source filename to read from, and target file to copy into.\n");
        exit(1);
    }

    switch(copy_command)
    {
        case 1:
            copy_file_v1(source_file, dest_file);
            break;
        case 2:
            copy_file_v2();
            break;
        case 3:
            copy_file_v3();
            break;
        case 4:
            copy_file_v4();
            break;
        default:
            printf("ERROR: Not a valid command number.\n");
            exit(1);
    }

    /*
    FILE * infile;

    infile = fopen("data.txt", "r");  // creates pointer to first char in that file
    if (infile == NULL)
    {
        printf("File not found\n");
        exit(0);
    }

    first = read_data_file(infile);

    fclose(infile);


    return 0;
*/

}

// use fgetc () to do the input and fputc () to do the output.

void copy_file_v1(char source_file[], char dest_file[])
{
    char character;

    FILE * infile;
    FILE * outfile;

    char source[255],
         dest[255];

    strcpy(source, source_file);
    strcpy(dest, dest_file);


    infile = fopen(source, 'r');
    outfile = fopen(dest, 'w');

    while ((character = fgetc(infile))!= EOF)
    {
        fputc(character, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("\nFinished copying.\n");


}


// use fgets () to do the input and fputs () to do the output.
void copy_file_v2()
{}
// use fread () to do the input and fwrite () to do the output.
void copy_file_v3()
{}

void copy_file_v4()
{}
