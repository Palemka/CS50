/* Vigenere's cipher. Encrypting message using a sequence of keys.
 * Code key is a command line argument */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{    
    if (argc == 2)
    {
        // Ensure that every character of key is alphabetic
        for (int i = 0; i < strlen(argv[1]); i++)
            if (isalpha(argv[1][i]) == 0)
            {
                // If some characters are numbers:
                printf("Usage: ./vigenere keyword \n");
                return 1;
            }
        
        //Get string that you want to code
        string s = get_string("Enter your string: ");
        printf("ciphertext: ");
        int counter = 0;
        
        for (int i = 0; i < strlen(s); i++)
        {   
            //Iterating over message you want to code
            int key = shift(argv[1][counter]);
            if (s[i] >= 'A' && s[i] <= 'Z') 
            {
                printf("%c", ((s[i] - 'A' + key) % 26) + 'A');
                //Increasing counter while count word 
                if (counter == strlen(argv[1]) - 1)
                {
                    counter = 0;
                }
                else 
                {
                    counter++;
                }
            } 
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", ((s[i] - 'a' + key) % 26) + 'a');
                //Increasing counter while count word 
                if (counter == strlen(argv[1]) - 1)
                {
                    counter = 0;
                }
                else 
                {
                    counter++;
                }
            } 
            else
            {
                // New line for aesthetics
                printf("%c", s[i]);
            }
        }
        printf("\n");
    } 
    else
    {
        //When user provides only one or more than two args
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}



int shift(char c) 
{
    // Transforming char into int
    if (c >= 'a' && c <= 'z')
    {
        return (c - 'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (c - 'A');
    }
    return 0;
}
