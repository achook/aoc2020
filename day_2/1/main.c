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
        int min, max;
        char letter;
        char password[100];
        int occurences = 0;

        sscanf(buffer, "%d-%d %c: %s", &min, &max, &letter, password);

        for (int i = 0; i < strlen(password); i++) {
            if (password[i] == letter) {
                occurences++;
            }

            if (occurences > max) {
                break;
            }
        }

        if (occurences <= max && occurences >= min) {
            numberOfValid++;
        }
    }

    printf("Valid passwords: %d\n", numberOfValid);

    fclose(f);
    return 0;
}