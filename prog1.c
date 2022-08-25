/*
    Write a C program prog1.c that prompts a user for an integer n, then accepts n strings from 
    standard input (one per line). Use fgets() to read each string. If the input is longer than 1024 
    characters, truncate it to 1024 characters. Remove the newline from the string that fgets() 
    appends, unless truncation already removed it. All the strings should be stored in a dynamically 
    allocated array (with exactly n elements), with each element containing exactly the right number 
    of characters to hold the string and the terminating null character. malloc()should be used to 
    create the array of strings. Once the input is processed, use the standard library function 
    qsort() to sort the strings and then output the sorted list using printf()
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ARRAY_SIZE = 1000;
const int MAX_STR_LEN = 1024;



//accepts a pointer to a char array and a pointer to an int variable called numStrings
void getInput(char** strArr, int* numStrings){
    //stores raw string before processing
    char buf[1025] = "";

    printf("How many words do you wish to enter? \n");
    int numInputs = scanf("%d\n", &numStrings);

    if(numStrings < 0 || numStrings > MAX_ARRAY_SIZE){
        printf("The number of words must be between 0 and 1000.\n");
        getInput(strArr, &numStrings);
    }

    printf("Enter %d words:\n", numStrings);

    for(int i = 0; i < numStrings; i++){
        //put the string in buf
        fgets(buf, 1024, stdin);
        //remove the newline character
        buf[strcspn(buf, "\n")] = 0;
        //store in the string array
        strcpy(strArr[i], buf);
        //resize the string array; +1 for \0
        strArr[i] = realloc(strArr[i], strlen(strArr[i])+1);
        //reset the buffer for the next string
        memset(buf, 0, 1025);
    }

}


//function for comparing two characters
int cmp(const void *str1, const void *str2){
    return strcmp(*(char**)str1, *(char**)str2);
}


void printStrings(char** strArr, int numStrings){
    for(int i = 0; i < numStrings; i++){
        printf("%s\n", strArr[i]);
    }
}



int main(){

    int numStrings;
    char** stringArr = (char**) malloc(MAX_ARRAY_SIZE * sizeof(char*));
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        stringArr[i] = (char*) malloc((MAX_STR_LEN+1) * sizeof(char));
    }

    //fill in the array with perfectly sized strings
    getInput(stringArr, &numStrings);
    //resize the string array to exactly the number of strings
    stringArr = realloc(stringArr, numStrings);
    //sort the string array using qsort
    qsort(stringArr, numStrings, sizeof(char*), cmp);
    //print the strings
    printStrings(stringArr, numStrings);



    return 0;
}