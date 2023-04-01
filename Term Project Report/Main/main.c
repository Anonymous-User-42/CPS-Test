

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*  Defining program macros */

#define ARRAY_SIZE 500
#define LINE_SIZE 250
#define STRING_SIZE 50

/*  Initializing UDF's in program use   */

FILE* file_o(void);
void file_c(FILE* file);

/*  Initializing struct datatypes for CSV data  */

typedef struct {    /*  Struct to store every Parameter in a line as an array of tokens with respect to their induvidual fields */
  char year[10];
  char province[35];
  char age_group[20];
  char sex[10];
  char values[10];
  char temp_str[10];
} datatypes;    /*  Struct DataType Variable name defined as "datatypes"    */

void main(void)
{
    FILE* f = file_o(); /*  Initializing File Operations    */

    datatypes data_set[ARRAY_SIZE];
    char line[LINE_SIZE];

    int line_count = 0; /*  Initializing Line Counter Variable to count Lines in the File   */

    while (!feof(f))    /*  Initializing start of CORE program base function    */
    {
        if (line_count == 0)
        {
            fgets(line, LINE_SIZE, f);
            line_count++;
            continue;   /*  Parsing the first line as line 1 encompasses labels and headers which are of no relavance   */
        }
        fgets(line, LINE_SIZE, f);
        line_count++;   /*  Line Counter Variable Update    */

        int token_count = 0;    /*  Initializing Token Counter Variable to count the tokens after String Tokenization   */
        char* token = strtok(line, ",");    /*  Seperating the line string into subsequent smaller string based on Comma Seperation & Tokenizing a slice of string after "," delimiter as a parameter   */
        strcpy(data_set[line_count].year, token);   /*  Assigning a string value for the Year from this base iteration of Var(token) [NO CONDITION REQUIRED - FIRST FIED ENTRY IN FILE] */
        //token_count++;  /*  Token Counter Variable Update   */

        while(token != NULL)
        {
            token = strtok(NULL, ",");
            token_count++;  /*  Token Counter Variable Update   */

            /*if (token_count == 1)
            {
                strcpy(data_set[line_count].province, token);   //  Assigning a string value for Province from this iteration of Var(token) if conditional satisfied
            }*/
            if (token_count == 3)
            {
                strcpy(data_set[line_count].age_group, token);  /*  Assiging a string value of Age Goup from this iteration of Var(token) if conditional is satisfied   */
            }
            else if (token_count == 4)
            {
                strcpy(data_set[line_count].sex, token);    /*  Assigning a string value of Sex from this iteration of Var(token) if conditional is satisfied   */
            }
            else if (token_count == 13)
            {
                strcpy(data_set[line_count].values, token); /*  Assigning a string value of Values (Raw Percentage Floats) from this iterationm of Var(token) if condition is satisfied */
            }
            else if (token_count == 14)
            {
                strcpy(data_set[line_count].temp_str, token);   /*  Assigning a string temp trash value of string literal's after Var(values) to disregard "\"" delimiter from being concatenated into Values string [CONDITION IS ALWAYS SATISFIED - TOTAL TOKEN COUNT IS 19 - temp_str HAS FREE malloc(20) per cycle allocation]  */
            }
        }
    }   /*  End of CORE program base function   */

    file_c(f);  /*  Terminating File Operations */

    /*          Question 1          */printf("|--------------------Question 1--------------------|\n");

    /*  Initializing Sum & Iterating Counter Variables for Averages Calculation */

    //  float sum_province - Variable to store the sum of the Value data Points subsequently in every iteration
    //  province_iterator_counter - Variable to calculate the number of iterations performed in the for loop

    /*  Federal Variables   */

    float sum_federal = 0;
    int federal_iterator_counter = 0;

    /*  Quebec Variables    */

    float sum_quebec = 0;
    int quebec_iterator_counter = 0;

    /*  Ontario Variables   */

    float sum_ontario = 0;
    int ontario_iterator_counter = 0;

    /*  Alberta Variables   */

    float sum_alberta = 0;
    int alberta_iterator_counter = 0;

    /*  British Columbia    */

    float sum_british_columbia = 0;
    int british_columbia_iterator_counter = 0;

    /*  Federal Average Calculator  */

    for (int i = 2; i < 44; i++, federal_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_federal = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_federal == 0)
      {
        federal_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_federal);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_federal += values_federal;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_federal = (sum_federal) / (federal_iterator_counter); printf("Federal Average: %.2lf\n", avg_federal); /*  Calculation of the Average function from the previous Summa function and iterator counter function as inputs    */

    /*  Quebec Average Calculator   */

    for (int i = 44; i < 86; i++, quebec_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_quebec = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_quebec == 0)
      {
        quebec_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_quebec);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_quebec += values_quebec;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_quebec = (sum_quebec) / (quebec_iterator_counter); printf("Quebec Average: %.2lf\n", avg_quebec);

    /*  Ontario Average Calculator  */

    for (int i = 86; i < 128; i++, ontario_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_ontario = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (sum_ontario == 0)
      {
        ontario_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_ontario);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_ontario += values_ontario;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_ontario = (sum_ontario) / (ontario_iterator_counter); printf("Ontario Average: %.2lf\n", avg_ontario);

    /*  Alberta Average Calculator  */

    for (int i = 128; i < 170; i++, alberta_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_alberta = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_alberta == 0)
      {
        alberta_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_alberta);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_alberta += values_alberta;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_alberta = (sum_alberta) / (alberta_iterator_counter); printf("Alberta Average: %.2lf\n", avg_alberta);

    /*  British Columbia Average Calculator */

    for (int i = 170; i < 212; i++, british_columbia_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_british_columbia = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_british_columbia == 0)
      {
        british_columbia_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_british_columbia);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_british_columbia += values_british_columbia;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_british_columbia = (sum_british_columbia) / (british_columbia_iterator_counter); printf("British Columbia Average: %.2lf\n", avg_british_columbia);



}

/*  Defining all subsequent UDF's utilized in the program   */

FILE* file_o(void)   /*  UDF for file opening    */
{
    char temp[100];
    FILE* file; /*  Initializing file storage variable  */
    file = fopen("statscan_diabetes.csv", "r"); /*  Defining the address path of file to be opened and read    */
    if (NULL == file)   /*  Fail Safe mechanism for program file opening    */
    {
        printf("Error: File Open cannot proceed\n");
        exit;   /*  Program exits and ends if the fail-safe breaks  */
    }
    fscanf(file, "%s", temp);  /*  Scanning the defined file and storing it at address of Var(temp)    */
    return file;    /*  Returning the file type variable    */
}

void file_c(FILE* file) /*  UDF for file closing    */
{
    fclose(file);   /*  Closing the already opened file */
}

