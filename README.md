# Personal Projects

### Searching for SubStrings. perPrompt1.c

User will input a string followed by a search term.

- Ask user for input.
- Scan input into an integer capable of handling ~10000 chars
- Ask user for a search string to search through the users input
- Using strstr() find the first occurance and print out the rest of the string from that word.
- Loop to find the next occurance and print the remaining string from the second occurance using strstr(ret +1, searchStr)
- Print out the rest of the string from that second occurance of the word.
- exit_successful

### Decimal to Roman Numerals (and vice versa). perPrompt4.c

User will input a (positive) decimal number that will be converted to Roman Numeral equivalent.

| Decimal   |   Roman Numeral   |
| :-------: |:-----------------:|
| 100       | C                 |
| 50        | L                 |
| 10        | X                 |
| 5         | V                 |
| 1         | I                 |

- Ask user for a decimal input (bw 1 - 100) and store it in the variable decNum.
- If the number is less than 0, print the output as “Invalid Input”.
- If the number is greater than 100 print the output as "Must be less than 100".
- Check if the number is greater than 90 or 40 or 9 or 4. If it is, then call the function predigit() and subtract the variable decNum by its equivalent number and override the variable number with this new value.
- Else call the function postdigit() and divide the variable number by its equivalent number and get the quotient. Multiply the quotient with its equivalent number and decrement the variable number with this value, assign the equivalent roman number to the array romanval[] as the post digit for instance the I in XVI (16).
- If there is no post digit we use the function predigit() and assign the array romanval[] as the pre digit, for instance the I in XIV (14).
- Using a while loop we will repeat these steps until the variable decNum becomes zero.
- Before printing the conversion, ask user for the password.
- If password input matches the variable password, Print the array romanval[] as output. Else print out "wrong password".