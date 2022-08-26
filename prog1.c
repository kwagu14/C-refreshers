
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ARRAY_SIZE = 1000;
const int MAX_STR_LEN = 1024;



//accepts a pointer to a char array and a pointer to an int variable called numStrings
int getInput(char** strArr){
    //stores raw string before processing
    char buf[1025] = "";
    int numStrings;

    printf("How many words do you wish to enter? \n");
    int numInputs = scanf("%d\n", &numStrings);

    for(int i = 0; i < numStrings; i++){
        //put the string in buf
        fgets(buf, 1024, stdin);
        //remove the newline character
        buf[strcspn(buf, "\n")] = 0;
        //store in the string array
        strcpy(strArr[i], buf);
        //resize the string array; +1 for \0
        strArr[i] = realloc(strArr[i], (strlen(strArr[i])+1) * sizeof(char));
        //reset the buffer for the next string
        memset(buf, 0, 1025);
    }

    return numStrings;

}


//function for comparing two characters
int cmp(const void *str1, const void *str2){
    return strcmp(*(char**)str1, *(char**)str2);
}


void printStrings(char** strArr, int numStrings){
    printf("\nSorted words:\n\n");
    for(int i = 0; i < numStrings; i++){
        printf("%s\n", strArr[i]);
    }
}



int main(){

    char** stringArr = (char**) malloc(MAX_ARRAY_SIZE * sizeof(char*));
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        stringArr[i] = (char*) malloc((MAX_STR_LEN+1) * sizeof(char));
    }

    //fill in the array with perfectly sized strings
    int arraySize = getInput(stringArr);
    //resize the string array to exactly the number of strings
    stringArr = realloc(stringArr, arraySize*sizeof(char*));
    //sort the string array using qsort
    qsort(stringArr, arraySize, sizeof(char*), cmp);
    //print the strings
    printStrings(stringArr, arraySize);

    //free the strings and string array
    for(int i = 0; i < arraySize; i++){
        free(stringArr[i]);
    }
    free(stringArr);



    return 0;
}