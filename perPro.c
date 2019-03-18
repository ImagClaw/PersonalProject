#include <stdio.h> 
#include <string.h>

void predigit(char num1, char num2);
void postdigit(char c, int n);

// global variables declared
char romanout[1000];
int i = 0;

int main() {
    int decNum;
    char password[32];

    // prompt for users to enter decimal digit bw 1 - 100
    printf("Enter a decimal number between 1 - 100: ");
    scanf("%d", &decNum);

    // if 0 or a negative decNum, if it is, remind user
    if (decNum <= 0) {
        printf("Invalid Input.\n");
        return 0;
    } while (decNum != 0) {  // while decNum is not 0 do the following
        // greater than 100 remind user
        if (decNum >= 100) { // greater than or equal to 100
            if (decNum > 100) {
                printf("Input must be less than 100.\n");
                return 0;
            } else {
                postdigit('C', decNum / 100);
                decNum = decNum - 100;
            }
        } else if (decNum >= 50 ) { // greater than or equal to 50
            if (decNum < (50 + 4 * 10)) {
                postdigit('L', decNum / 50);
                decNum = decNum - (decNum / 50) * 50;
            } else {
                predigit('X','C');
                decNum = decNum - (100-10);
            }
        } else if (decNum >= 10) { // greater than or equal to 10
            if (decNum < (10 + 3 * 10)) {
                postdigit('X', decNum / 10);
                decNum = decNum - (decNum / 10) * 10;
            } else {
                predigit('X','L');
                decNum = decNum - (50 - 10);
            }
        } else if (decNum >= 5) { // greater than or equal to 5
            if (decNum < (5 + 4 * 1)) {
                postdigit('V', decNum / 5);
                decNum = decNum - (decNum / 5) * 5;
            } else {
                predigit('I', 'X');
                decNum = decNum - (10 - 1);
            }
        } else if (decNum >= 1) {
            if (decNum < 4) { // if number is less than 4
                postdigit('I', decNum / 1);
                decNum = decNum - (decNum / 1) * 1;
            } else { 
                predigit('I', 'V');
                decNum = decNum - (5 - 1);
            }
        }
    }
    printf("\nPlease enter the password: ");
    scanf("%s", password);

    if (strcmp(password, "idf") == 0) {
        printf("\nI suppose I can trust you now... >_>\n");
        printf("100 == C\n");
        printf("50 == L\n");
        printf("10 == X\n");
        printf("5 == V\n");
        printf("1 == I\n");
        printf("\nThe Roman Numeral equivelant is: ");
        for(int j = 0; j < i; j++)
            printf("%c", romanout[j]);
    } else {
        printf("\nWrong password.\n");
    } 
}

     

void predigit(char num1, char num2) {
    romanout[i++] = num1;
    romanout[i++] = num2;
}

void postdigit(char c, int n) {
    int j;
    for (j = 0; j < n; j++)
        romanout[i++] = c;
}