/*
* name: Whelpley
* date: 19 March 2019
* project: Performance Prompt #1 - SearchforSubstring
*
*/

#include <string.h>
#include <stdio.h>

int main() {
    const char userInput[10000];
    const char searchStr[64];
    char *ret;
    char *ret2;

    printf("Enter an initial string: ");
    scanf("%[^\n]s", userInput);

    printf("Enter a search string: ");
    scanf("%s", searchStr);

    ret = strstr(userInput, searchStr);
    printf("\n\n\nFirst Occurance: %s\n", ret);

    ret2 = strstr(ret + 1, searchStr);
    printf("\n\n\nSecond Occurance: %s\n", ret2);

    return 0;

}