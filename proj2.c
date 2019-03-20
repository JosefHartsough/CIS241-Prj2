

#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

#define MAX 50
//Tracks identifier based on char
//0-Space
//1-Alphanumerical
//2-Comments
//3-String Quotes
//4-Newline
//5-Symbols
int main(int argc, char ** argv){

    //Global variables
    int identifier = 0;
    char ch, temp;
    int countTemp = 0;
    
    //Creates new list
    List * MyList = createList();

    //Reads in file
    FILE * fin = fopen(argv[1], "r");
    if(fin == NULL){
        fprintf(stderr, "File named sample.c not found\n\n");
        exit(1);
    }
    //Identifier changes based on new char
    while ( ch = fgetc(fin), ch != EOF){
        switch (identifier) {
            case 0:
                if (isalpha(ch)){
                    identifier = 1;
                    int count = 0;
                    char * identity = malloc(MAX * sizeof(char)); 
                    identity[count] = ch; // Add the first character
                    count++; //Add to the count
                    temp = fgetc(fin);
                    while ( isalnum(temp) ){
                        if ( (isalnum(temp))){
                            identity[count] = temp;
                            count++;
                        } else {
                            break;
                        }
                        temp = fgetc(fin);
                        if(isspace(temp)){
                            identifier = 0;
                            break;
                        }
                    }
                    //Space to space, space to comments, space to newLine
                    ID *id = &identity;
                    identifiers(MyList, id);
                    break;
                } else if (isspace(ch)){
                    identifier = 0;
                    break;
                } else if (ch == '/'){
                    identifier = 2;
                    temp = fgetc(fin);
                    while (temp != '\n'){
                        temp = fgetc(fin);
                        if (temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                    //Space to string, space to newLine, space to symbol
                } else if (ch == '"'){
                    identifier = 3;
                    temp = fgetc(fin);
                    while(temp != '"')
                        temp = fgetc(fin);
                    break;
                } else if(ch == '\n' || ch == '\t'){
                    identifier = 4;
                    break;
                } else {
                    identifier = 5;
                    break;
                }
                //Word to space, word to comments, word to newLine, word to comments, word to newLine
            case 1:
                if (isspace(ch)){
                    identifier= 0;
                } else if(ch == '"'){
                    identifier = 3;
                    temp = fgetc(fin);
                    while(temp != '"')
                        temp = fgetc(fin);
                    break;
                } else if(ch == '\n' || ch == '\t'){
                    identifier = 4;
                    break;
                } else if(ch == '/'){
                    identifier = 2;
                    temp = fgetc(fin);
                    while (temp != '\n'){
                        temp = fgetc(fin);
                        if (temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                } else {
                    if (isalpha(ch) ){
                        identifier = 1;
                        int count = 0;
                        char * identity = malloc(MAX * sizeof(char)); // Assume identity len < 50
                        identity[count] = ch; // Add the first character
                        count++; //Add to the count;
                        temp = fgetc(fin);
                        while ( isalnum(temp) ){
                            if ( (isalnum(temp))){
                                identity[count] = temp;
                                count++;
                            } else {
                                break;
                            }
                            temp = fgetc(fin);
                            if(isspace(temp)){
                                identifier = 0;
                                break;
                            }
                        }
                        // Process the identifier we found
                        ID *id = &identity;
                        identifiers(MyList, id);
                        break;
                    } else {
                        identifier = 5;
                        break;
                    }

                }
                //Comment to comment, comment to space, comment to newLine, comment to word,
            case 2:
                if (ch == '/'){
                    identifier = 2;
                    break;
                } else if (isspace(ch)){
                    identifier = 0;
                    break;
                } else if(ch == '\n' || ch == '\t'){
                    identifier = 4;
                    break;
                } else if(isalpha(ch)){
                    identifier = 1;
                    int count = 0;
                    char * identity = malloc(MAX * sizeof(char));
                    identity[count] = ch;
                    count++; //Add to the count
                    temp = fgetc(fin);
                    while ( isalnum(temp) ){
                        if ( (isalnum(temp) ) ){
                            identity[count] = temp;
                            count++;
                        } else {
                            break;
                        }
                        temp = fgetc(fin);
                        if(isspace(temp)){
                            identifier = 0;
                            break;
                        }
                    }
                    // Process the identity we have found
                    ID *id = &identity;
                    identifiers(MyList, id);
                    break;
                    //Comment to string, comment to symbol, string to comment, string to newLIne
                } else if(ch == '"'){ // identifier: comments to string
                    identifier = 3;
                    temp = fgetc(fin);
                    while(temp != '"')
                        temp = fgetc(fin);
                    break;
                } else {
                    identifier = 5;
                    break;
                }
            case 3:
                if(ch == '"'){
                    break;
                } else if(ch == '/'){
                    identifier = 2;
                    temp = fgetc(fin);
                    while(temp != '\n'){
                        temp = fgetc(fin);
                        if(temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                    //String to word,
                } else if(isalpha(ch)){
                    identifier = 1;
                    int count = 0;
                    char * identity = malloc(MAX * sizeof(char));
                    identity[count] = ch; // Add the first character
                    count++; //Add to the count;
                    temp = fgetc(fin);
                    while ( isalnum(temp) ){
                        if ( isalnum(temp) ){
                            identity[count] = temp;
                            count++;
                        } else {
                            break;
                        }
                        temp = fgetc(fin);
                        if(isspace(temp)){
                            identifier = 0;
                            break;
                        }
                    }

                    // Process the identity we have found
                    ID *id = &identity;
                    identifiers(MyList, id);
                    break;
                } else {
                    identifier = 5;
                    break;
                }
                //NewLine to word,
            case 4:
                if (isalpha(ch)){
                    identifier = 1;
                    int count = 0;
                    char * identity = malloc(MAX * sizeof(char));
                    identity[count] = ch; // Add the first character
                    count++; //Add to the count
                    temp = fgetc(fin);
                    while ( isalnum(temp) ){
                        if ( isalnum(temp) ){
                            identity[count] = temp;
                            count++;
                        } else {
                            break;
                        }
                        temp = fgetc(fin);
                        if(isspace(temp)){
                            identifier = 0;
                            break;
                        }
                    }

                    // Process the new identity we have found
                    ID *id = &identity;
                    identifiers(MyList, id);
                    break;
                    //Newline to space, newline to string, newline to comments, newline to newline
                } else if (isspace(ch)){
                    identifier = 0;
                    break;
                } else if (ch == '"'){
                    identifier = 3;
                    temp = fgetc(fin);
                    while(temp != '"')
                        temp = fgetc(fin);
                    break;
                } else if (ch == '/'){
                    identifier = 2;
                    temp = fgetc(fin);
                    while(temp != '\n'){
                        temp = fgetc(fin);
                        if(temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                    //Newline to symbol
                } else {
                    identifier = 5;
                    break;
                }
                //Symbol to word,
            case 5:
                if (isalpha(ch)){
                    identifier = 1;
                    int count = 0;
                    char * identity = malloc(MAX * sizeof(char));
                    identity[count] = ch; // Add the first character
                    count++; //Add to the count;
                    temp = fgetc(fin);
                    while ( isalnum(temp) ){
                        if ( isalnum(temp) ){
                            identity[count] = temp;
                            count++;
                        } else {
                            break;
                        }
                        temp = fgetc(fin);
                        if(isspace(temp)){
                            identifier = 0;
                            break;
                        }
                    }

                    // Process the identity we have found
                    ID *id = &identity;
                    identifiers(MyList, id);
                    break;
                } else if (isspace(ch)){ // identifier: symbol to space
                    identifier = 0;
                    break;
                } else if (ch == '/'){ // identifier: symbol to comments
                    identifier = 2;
                    temp = fgetc(fin);
                    while(temp != '\n'){
                        temp = fgetc(fin);
                        if(temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                } else if (ch == '"'){ // Symbol to string
                    identifier = 3;
                    temp = fgetc(fin);
                    while(temp != '"')
                        temp = fgetc(fin);
                    break;
                } else if (ch == '\n' || ch == '\t' ){ // Symbol to new line/tab
                    identifier = 4;
                    temp = fgetc(fin);
                    while(temp != '\n'){
                        temp = fgetc(fin);
                        if(temp == '\n'){
                            identifier = 4;
                            break;
                        }
                    }
                    break;
                } else {
                    break;
                }
        }
    }



// Close the file
    fclose(fin);

//Print result on original file Sample.c
    int countList = 0;
    Node * top = MyList->top;
    while( countList < MyList->size){
        printf("\nIdentifier: %s, Count: %d \n", top->identifier, top->count);
        top = top->next;
        countList++;
    }

    return 0;
}