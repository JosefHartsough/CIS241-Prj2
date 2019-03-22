//Project 2 Main
//Authors: Josef Hartsough, Chandler Scott

#include "list.h"

//Variable to track identifier type
int nch = '\n', lex = 5;
LINK head;

//Identifier function
void word(FILE *file) {

    char tx[40];
    char *p1;

    p1 = tx;
    while (isalpha(nch) || isdigit(nch) || nch == '_') {
        *(p1++) = nch;
        nch = fgetc(file);
    }

    *p1 = '\0';

    update(head, tx); /* searches the word in the list and update it */

}

// read tokens from the file
void get(FILE *file) {
    int finish = 1;
    while (!feof(file)) {
        nch = fgetc(file);
        //skip spacebars
        if (!isspace(nch)) {
            finish = 0;
            break;
        }
    }
    if (finish) {
        lex = EOF;
        return;
    }


    // find comments "//" or "/*" in the current line
    if (nch == '/') {
        if ((nch = fgetc(file)) == '/') { // find comments "//"
            do {

                nch = fgetc(file);
                if (nch == feof(file)) {
                    lex = EOF;
                    return;
                }
            } while (nch != '\n');

        } else if (nch == '*') { // find /* in current line
            char prev;
            do {
                prev = nch;
                nch = fgetc(file);
                if (nch == feof(file)) {
                    lex = EOF;
                    return;
                }
            } while (!((prev == '*' && nch == '/') || (nch == '*' && (nch = fgetc(file)) == '/')));

            //nch=fgetc(file);
        } else

            ungetc(nch, file);
    }

        // literal and symbol
    else if (nch == '\"') {

        do {
            nch = fgetc(file);
        } while (nch != '\"');


    } else if (nch == '\'') {

        do {
            nch = fgetc(file);
        } while (nch != '\'');

    }

        //Checks for words
    else if (isalpha(nch) || nch == '_') {
        word(file);
        ungetc(nch, file);
    } else if (nch == feof(file))
        lex = EOF;
    else {

    }
}

int main(int argc, char **args) {
    FILE *in, *out;
    if (argc != 3) {
        printf("Sample.c and than the name of the output file ");
        getchar();
        return 0; //could not open file

    }
    //In-Sample.c
    in = fopen(args[1], "r");
    //Out-output.txt
    out = fopen(args[2], "w");

    head = makeEmpty();

    if (in == NULL) {
        printf("Could not open file!\n");
        getchar();
        return 0; //could not open file
    }

    do {
        get(in);

    } while (lex != EOF);

    showList(head);
    list2file(head, out);

    clearList(head);

    if (isEmpty(head))
        printf("\nEnd of the list\n");

    fclose(in);
    fclose(out);

    getchar();
    return 0;
}

