#define LINE_LENGTH 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* f;
    char buffer[10];
    int instructionCount = 0;
    char* instructions = malloc(instructionCount * sizeof(char));
    int* arguments = malloc(instructionCount * sizeof(int));
    
    f = fopen("input.txt", "r");
    if (f == NULL) {
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), f)) {
        char instruction[LINE_LENGTH], instructionCode;
        int argument;
        
        sscanf(buffer, "%s %d", instruction, &argument);

        instructionCount++;
        instructions = realloc(instructions, instructionCount*sizeof(char));
        if (strcmp(instruction, "acc") == 0) {
            instructions[instructionCount-1] = 'a';
        } else if (strcmp(instruction, "nop") == 0) {
            instructions[instructionCount-1] = 'n';
        } else if (strcmp(instruction, "jmp") == 0) {
            instructions[instructionCount-1] = 'j';
        }

        arguments = realloc(arguments, instructionCount*sizeof(int));
        arguments[instructionCount-1] = argument;
    }
    fclose(f);

    int acc = 0;
    int pos = 0;
    int stop = 0;

    while (!stop) {
        char op = instructions[pos];
        instructions[pos] = 0;
        switch (op) {
        case '0':
        case '\0':
            stop = 1;
            break;

        case 'n':
            pos++;
            break;

        case 'a':
            acc += arguments[pos];
            pos++;
            break;
        
        case 'j':
            pos += arguments[pos];
            break;
        
        default:
            return 1;
        }
    }

    printf("%d\n", acc);
    return 0;
}