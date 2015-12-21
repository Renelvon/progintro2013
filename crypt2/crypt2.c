/* NTUA ECE Progintro crypt2
 *
 * Reads a transposition of the english letters
 * If the transposition is not valid, prints "error" and exits
 * Then reads a line. If the line starts with d, then decrypts the text
 * If it starts with any other letter, then encrypts the text.
 * The text finishes with EOF
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Clears buffer */
void SKIP_LINE() {
    char c;
    while((c = getchar()) != '\n');
}

/* Checks transposition input */
int check_input(char transp[]) {
    int check[26];
    int i;

    for(i = 0; i < 26; i++) {
        check[i] = 0;
    }
    for(i = 0; i < 26; i++) {
        if(check[transp[i] - 'a'] != 0) {
            return 0;
        }
        check[transp[i] - 'a'] = 1;
    }
    return 1;
}

/* Encrypts a single character */
char encrypt(char transp[], char c) {
    if(islower(c))
        return transp[c - 'a'];
    else if(isupper(c))
        return toupper(transp[c - 'A']);
    else
        return c;
}

int main() {
    char encr[26], decr[26];
    char *transp;
    char c;
    int i;

    /* Reading */
    for(i = 0; i < 26; i++) {
        c = getchar();
        if(!islower(c)) {
            putchar(c);
            printf("error\n");
            exit(EXIT_FAILURE);
        }
        encr[i] = c;
        decr[c - 'a'] = i + 'a';
    }

    /* Check input */
    if(!check_input(encr)) {
        printf("error\n");
        exit(EXIT_FAILURE);
    }

    if((c = getchar()) == 'd')
        transp = decr;
    else 
        transp = encr;
    SKIP_LINE();

    /* Process text */
    while((c = getchar()) != EOF) {
        putchar(encrypt(transp, c));
    }
    exit(EXIT_SUCCESS);
}
