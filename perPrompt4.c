/*
* name: Whelpley
* date: 18 March 2019
* project: Performance Prompt #4 - Dec2RomanNumber
*
*/

#include <stdio.h> 
#include <string.h>

void predigit(char num1, char num2);
void postdigit(char c, int n);

// global variables declared
char romanout[1000];
int i = 0;
int digit(char);

int main() {
    int decNum;
    char romNum[128];
    char password[32];
    int choice;
    int num = 0;

    // prompt for users to enter decimal digit bw 1 - 100
    printf("\n\n\n\n\n Below you will see two options to convert decimal and roman numerals.\n");
    printf("\t1 - Convert a decimal number to a roman numeral\n");
    printf("\t2 - Convert a Roman Numeral to a decimal number (Valid Roman Chars are I, V, X, L, C)\n");
    printf(" Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // if 0 or a negative decNum, if it is, remind user
            printf("\n Enter Your Decimal Number: ");
            scanf("%d", &decNum);
            if (decNum <= 0) {
                printf("\nInvalid Input.\n");
                return 0;
            } while (decNum != 0) {  // while decNum is not 0 do the following
                // greater than 100 remind user
                if (decNum >= 100) { // greater than or equal to 100
                    if (decNum > 100) {
                        printf("\nInput must be less than 100.\n");
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
            printf("\n Please enter the password: ");
            scanf("%s", password);

            if (strcmp(password, "idf") == 0) {
                printf("\n I suppose I can trust you now... >_>\n");
                printf(" 100 == C\n");
                printf(" 50 == L\n");
                printf(" 10 == X\n");
                printf(" 5 == V\n");
                printf(" 1 == I\n");
                printf("\n The Roman Numeral equivelant is: ");
                for(int j = 0; j < i; j++)
                    printf("%c", romanout[j]);
            } else {
                printf("\nWrong password.\n");
            }
            break;
        case 2:
            printf("\n Enter any roman number (Valid digits are I, V, X, L, C): ");
            scanf("%s",romNum);
            while(romNum[i]){
                if(digit(romNum[i]) < 0){
                    printf(" Invalid roman digit : %c",romNum[i]);
                    return 0;
                }

                if((strlen(romNum) -i) > 2){
                    if(digit(romNum[i]) < digit(romNum[i+2])){
                        printf("Invalid roman number");
                        return 0;
                    }
                }

 

                if(digit(romNum[i]) >= digit(romNum[i+1]))
                    num = num + digit(romNum[i]);
                else{
                    num = num + (digit(romNum[i+1]) - digit(romNum[i]));
                    i++;
                }
                i++;
            }
            printf("\n Please enter the password: ");
            scanf("%s", password);
            if (strcmp(password, "idf") == 0) {
                printf("\n I suppose I can trust you now... >_>\n");
                printf(" 100 == C\n");
                printf(" 50 == L\n");
                printf(" 10 == X\n");
                printf(" 5 == V\n");
                printf(" 1 == I\n");
                printf(" Its decimal value is : %d", num);
            } else {
                printf("\nWrong password.\n");
            }
            break;
        default:
            printf("\n Enter a valid choice next time.\n");
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

int digit(char c){ 
    int value=0; 
    switch(c){
         case 'I': 
            value = 1; 
            break;
         case 'V': 
            value = 5; 
            break;
         case 'X': 
            value = 10; 
            break;
         case 'L': 
            value = 50; 
            break;
         case 'C': 
            value = 100; 
            break;
         case '\0': 
            value = 0; 
            break;
         default: 
            value = -1; 
    }
    return value;
}