#include <stdio.h>
#include <stdlib.h>



int main(){

    int i,j,k;
    for(i=0; i < 5; i++){   
        if(i%2==0){for(j=0;j<10; j++){
            if(j%2==0)putc(' ',stdout);
            else putc('X',stdout);}
        }else{for(k=0;k< 10; k++){
            if(k%2==0)putc('X', stdout);
            else putc(' ', stdout);}}
        putc('\n', stdout);
    }

    return 0; 
}


