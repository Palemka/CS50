/* Program that allows you to encrypt messages using Caesar's cipher. 
Key is provided as command line argument.
*/


#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{   
    // Checking number of args 
    if (argc == 2 && atoi(argv[1]) >= 1)
    {
        printf("Success\n");
        string s = get_string("Enter the message: \n");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(s); i++)
        {    
            // Iterating over characters in message
            if (s[i] >= 'A' && s[i] <= 'Z') 
            {
                printf("%c", (((s[i] - 'A') + atoi(argv[1])) % 26) + 'A');
            } 
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + atoi(argv[1])) % 26) + 'a');
            } 
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    // If the user is not cooperating
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
