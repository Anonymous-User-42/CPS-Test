

#include <stdio.h>
#include <stdlib>
#include <math.h>

void main(void)
{
    FILE* f = file_o();

    file_c(f);
}

void file_o(void)   /*  UDF for file opening    */
{
    FILE* file; /*  Initializing file storage variable  */
    file = fopen("statscan_diabetes.csv", "r"); /*  Defining the address path of file to be opened and read    */
    fscanf(file, "%d", &temp)   /*  Scanning the defined file and storing it at address of Var(temp)    */
    return file;    /*  Returning the file type variable    */
}

void file_c(FILE* file) /*  UDF for file closing    */
{
    fclose(file);   /*  Closing the already opened file */
}

