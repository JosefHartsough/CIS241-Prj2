#include <stdio.h>
#include "list.h"
#include <string.h>


int main()
{
    void main(int argc, char *argv[]){
    FILE *load;
    //Makes the list empty at the start
    LINK list = makeEmpty();


        if (argc != 2) {
            printf("1 Command Line Argument");
            exit(0);
        }
        //Opens the specified file and reads the data
        load = fopen(argv[1], "r");



    }

}
