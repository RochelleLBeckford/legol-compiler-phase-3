/*
& A simple Legol Compiler -> Phase 3 with while loop
~ include the libraries i will need
~ stdio.h -> input/output functions
    ~ will also use scanf to read input from a user
~ string.h -> compare strings
*/
#include <stdio.h>
#include <string.h>

/*
& Legol's idea is the same as planning building problem solving into programming languages
~ 4 relations -> door, wall, window, roof -> each is need to build a house
    ~ depend on each other to build a functional house
*/

//& Define my token types
//~ Token type for commands for the Legol Building Blocks: BUILD, STACK, END
#define tokword 1
//~ Token type for colors of the Legol Building Blocks: white, pink, mint, etc.
#define tokcolor 2
//~ Token type for sizes of the Legol Building Blocks: small, medium, large, etc.
#define toksize 3

//& The structure of the symbol table
//~ Will define what my new symbol table will look like -> how to remember each word
typedef struct {
    //~ The lexeme (word) -> "BUILD"
    char name[10];
    // ~ The type -> "tokword"
    int type;
    //~ the description -> Description of the symbol
    char description[50];
} Symbol;

//& Creates the symbol table (like a notebook that will keep record of all the words and their types)
//~ how many symbols we can store
#define MAX_SYMBOLS 50
Symbol symbol_table[MAX_SYMBOLS];
//~ The number of symbols written down
int symbol_count = 0;

//& Function that will add a symbol to the symbol table
void add_symbol(char *name, int type) {
    if (symbol_count < MAX_SYMBOLS) {
        strcpy(symbol_table[symbol_count].name, name);
        symbol_table[symbol_count].type = type;

        //~ Will add a description based on type
        if (type == tokword) {
            if (strcmp(name, "BUILD")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to build a Legol Block");
            } else if (strcmp(name, "STACK")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to stack a Legol Blocks");
            } else if (strcmp(name, "END")== 0) {
                strcpy(symbol_table[symbol_count].description, "Command to end the program");
            }
        } else if (type ==  tokcolor) {
            strcpy(symbol_table[symbol_count].description, "Color of the Legol Block");
        } else if (type ==  toksize) {
            strcpy(symbol_table[symbol_count].description, "Size of the Legol Block");
        } else {
            strcpy(symbol_table[symbol_count].description, "Unknown symbol type");
        }
        symbol_count ++;
    }
}

//& Function that will show the symbol table
void show_symbol_table() {
    printf("\nSYMBOL TABLE:\n");
    printf("-------------------------------------------------------------\n");
    printf("Word\t\tType\t\tDescription\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < symbol_count; i++) {
        printf("%s\t\t", symbol_table[i].name);
        //~ Will print the tokword, tokcolor, toksize
        if (symbol_table[i].type == tokword) {
            printf("Command\t\t");
        } else if (symbol_table[i].type == tokcolor) {
            printf("Color\t\t");
        } else if (symbol_table[i].type == toksize) {
            printf("Size\t\t");
        } else {
            printf("Unknown\t\t");
        }

        //~ This will print the description of the symbol
        printf("%s\n", symbol_table[i].description);
    }
    printf("-------------------------------------------------------------\n");
}

//& Function to get my token type
//~ Determines the token type of a lexeme(aka word)
int getTokenType(char *word) {
    //~ Check if the word is a command (BUILD, STACK, END)
    if (strcmp(word, "BUILD") == 0 || strcmp(word, "STACK") == 0 || strcmp(word, "END") == 0){
        //~ if it is a command will return tokword
        return tokword;
    }
    //~ Check if the word is a color (white, pink, mint)
    else if (strcmp(word, "white") == 0 || strcmp(word, "pink") == 0 || strcmp(word, "mint") == 0){
        //~ if it is a color return tokcolor
        return tokcolor;
    }
    //~ Check if the word is a size (small, medium, large)
    else if (strcmp(word, "small") == 0 || strcmp(word, "medium") == 0 || strcmp(word, "large") == 0){
        //~ if it is a size return toksize
        return toksize;
    }
    //~ Default case -> what will happen for an unknown token -> return -1
    return -1;
}

//& Main Function -> where the program starts running
//~ Declare variables, get user inputs, get the tokens for each word,print it, can continue or end the program
int main () {
    //& Declare the variables
    //~ [10] -> each variable can hold up to 10 characters
    //~ variable to store the first word ("BUILD",....)
    char command[10];
    //~ variable to store the second word ("white",....)
    char color[10];
    //~ variable to store the third word ("small",....)
    char size[10];

    // //& Variables that will store token types
    // int token1;
    // int token2;
    // int token3;

    //~ Display welcome message and instructions to
    printf("Welcome to the Legol Mini Compiler!\n");
    printf("You can use these commands:\n");
    printf("  BUILD <color> <size> - to build a single Legol Building block\n");
    printf("  STACK <color1> <color2> - to stack one Legol Building block on another\n");
    printf("  END - to quit the program\n");

    //& Add while loop
    //~ Use a while loop that will keep going until the user types END
        //~ use while(1) -> the loop will keep going until use break to exit it
    while (1) {
        //~ Display a message to the user asking for inputs
        printf("Please enter a Legol command:\n");
        //~ Read the user input and store them in the declared variables
        scanf("%s", command);

        //~ Get the token type for the first word - command
        int token1 = getTokenType(command);
        //~ add the command to symbol table
        add_symbol(command, token1);

        //& Check what the command is
        if (strcmp(command, "BUILD") == 0){
            printf("Please enter a Legol color and size:\n");
            //~ get the color and size for the BUILD command
            scanf("%s %s", color, size);

            //~ get the token types for color and size
            int token2 = getTokenType(color);
            int token3 = getTokenType(size);

            //~ add the color to symbol table
            add_symbol(color, token2);
            //~ add the size to symbol table
            add_symbol(size, token3);

            //~ will print the word types for each
            printf("\nWORD TYPES:\n");
            printf("BUILD (token1 = %d) = command\n", token1);

            printf("%s (token2 = %d) = ", color, token2);
            if (token2 == tokcolor) {
                printf("color\n");
            } else {
                printf("unkown\n");
            }

            printf("%s (token3 = %d) = ", size, token3);
            if (token3 == toksize) {
                printf("size\n");
            } else {
                printf("unknown\n");
            }

            //~ print what is happening with the Legol Building blocks
            printf("\nRESULT: You built a %s Legol Building block of size %s!\n\n", color, size);

            //~ show the symbol table
            show_symbol_table();

        } else if (strcmp(command, "STACK") == 0) {
            //~ get the two colors of the Legol Building blocks for the STACK command
            //~ using the size variable for the second color
            scanf("%s %s", color, size);

            //~ get the token types for both colors
            //~ token for the first color
            int colorToken = getTokenType(color);
            //~ token for the second color
            int color2Token = getTokenType(size);

            //~ add first color to symbol table
            add_symbol(color,colorToken);
            //~ add second color to symbol table
            add_symbol(color,color2Token);

            //~ will then print the word types
            printf("\nWORD TYPES:\n");
            printf("STACK (token1 = %d) = command\n", token1);

            printf("%s (colorToken = %d) = ", color, colorToken);
            if (colorToken == tokcolor) {
                printf("color\n");
            } else {
                printf("unknown\n");
            }

            printf("%s (color2Token = %d) = ", size, color2Token);
            if (color2Token == tokcolor) {
                printf("color\n");
            } else {
                printf("unknown\n");
            }

            //~ print what is happening with the Legol Building blocks
            printf("\nRESULT: You stacked a %s Legol Building block on top of a %s Legol Building block!\n\n", color, size);

            //~ show the symbol table
            show_symbol_table();
        } else if (strcmp(command, "END") == 0) {
            //~ will print the word types
            printf("\nWORD TYPES:\n");
            printf("END (token1 = %d) = command\n", token1);

            //~ say goodbye
            printf("\nRESULT: All done! Bye bye!\n");

            //~ show the symbol table
            show_symbol_table();

            //~ exit the loop
            break;
        } else {
            //~ print that we do not know the word the user input
            printf("\nWORD TYPES:\n");
            printf("%s (token1 = %d) = unknown word\n", command, token1);

            //~ show this error message
            printf("\nRESULT: I do not know that word. try BUILD, STACK, or END.\n\n");
        }
    }
    //~ the end of the program
    return 0;
}

