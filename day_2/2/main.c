#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* f;
    char buffer[100];
    
    f = fopen("input.txt", "r");
    if (f == NULL) {
        return 1;
    }

    int numberOfValid = 0;

    while (fgets(buffer, sizeof(buffer), f)) {
        int pos1, pos2;
        char letter;
        char password[100];
        int occurences = 0;

        sscanf(buffer, "%d-%d %c: %s", &pos1, &pos2, &letter, password);

        if((password[pos1-1] == letter || password[pos2-1] == letter)
            && !(password[pos1-1] == letter && password[pos2-1] == letter)) {
            numberOfValid++;
        }
    }

    printf("Valid passwords: %d\n", numberOfValid);

    fclose(f);
    return 0;
}