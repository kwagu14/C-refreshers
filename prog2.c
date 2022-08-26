#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/********************* Structs **********************/

typedef struct funcs {
    int (*openit) (char *name, int prot);
    void (*closeit) (int fd);
} funcs;

/******************* Function Prototypes ******************/

int openIt(char* name, int prot);

void closeIt(int fd);

void f(funcs* myFuncs);


/******************** Main *********************/

static funcs myFuncs = {&openIt, &closeIt};

int main(){

    int fd = myFuncs.openit("testFile.txt", O_APPEND);
    myFuncs.closeit(fd);

    funcs myFuncs2;
    f(&myFuncs2);
    int fd2 = myFuncs2.openit("testFile.txt", O_APPEND);
    myFuncs.closeit(fd);

    return 0;
}

/*************** Function Definitions *******************/

void f(funcs *myFuncs){
    myFuncs -> openit = &openIt;
    myFuncs -> closeit = &closeIt;
}



int openIt(char* name, int prot){
    int fd = open(name, prot);
    if(fd == -1){
        printf("Error in opening the file. Exiting.\n");
        exit(1);
    }else{
        printf("File opened successfully\n");
    }
    return fd;

}


void closeIt(int fd){
    if(close(fd) < 0){
        printf("Error in closing the file. Exiting.\n");
        exit(1);
    }else{
        printf("File closed successfully.\n");
    }
}