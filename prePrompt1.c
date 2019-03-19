/*
* name: Whelpley
* date: 19 March 2019
* project: Performance Prompt #1 - SearchforSubstring
*
*/

#include <string.h>
#include <stdio.h>

int main() {
    const char userInput[10001];
    const char searchStr[65];
    char *ret;
    char *ret2;
    char key[4];
    
    // Enter an initial string (max 10000 chars)
    printf("\n\t Enter an initial string: ");
    scanf("%[^\n]s", userInput);
    
    // Enter the search term (max 64 chars)
    printf("\n\t Enter a search string: ");
    scanf("%s", searchStr);
        
    // Enter the pass key to continue
    printf("\n\t Enter the password to continue: ");
    scanf("%s", key);

    if (strcmp(key, "idf") != 0) {
        printf("\n\t WRONG PASSWORD! Try again.");
        main();
    } else {
        ret = strstr(userInput, searchStr);
        printf("\n\t First Occurance: %s\n", ret);
    
        ret2 = strstr(ret + 1, searchStr);
        if (ret2 != NULL) {
            printf("\n\t Second Occurance: %s\n", ret2);
        } else {
            printf("\n\t There is no second occurance.");
        }
    }
}