#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char token, int key);

int main(int argc, string argv[]) {

    // Announcements variables
    bool keySuccessful = false;
    string keyword = "";
    int keylength = 0;
    string user_text = "";
    int user_text_length;
    int key_count = 0;

    do
    {
        // Check the correct value argument
        if(argc != 2)
        {
            printf("You didn't enter the correct number of keywords.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    // Only letters as input. 
                    printf("Your input contains illegal characters.\n");
                    return 1;
                }
                else
                {
                    // Input can be taken as the key.
                    keySuccessful = true;
                    keyword = argv[1];
                }
            }
        }
    } while(!keySuccessful);
    
    // Check the length of the keyword. Defining this array length.
    keylength = strlen(keyword);
    int keycodes[keylength];

    // Convert keyword array in numbers.
    // starting from A = 0 to Z = 25 ignoring case.
    for(int i = 0; i < keylength;i++)
    {
        keycodes[i] = toupper(keyword[i]) - 65;
    }

    // Check the user-text and calculating its length.
    user_text = GetString();
    user_text_length = strlen(user_text);

    for (int i = 0; i < user_text_length; i++)
    {
        // If the character is not a letter, then display it mirror.
        if(!isalpha(user_text[i]))
        {
            printf("%c", user_text[i]);
        }
        // The process of administration.
        else
        {
            printf("%c", caesar(user_text[i], keycodes[key_count]));

            // Counter position for the array .   
            if(key_count < keylength - 1)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }

    // Displaying a new line and end.
    printf("\n");
    return 0;
}
