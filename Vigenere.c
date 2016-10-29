#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char token, int key);

int main(int argc, string argv[]) {

    // Оголошення змінних
    bool keySuccessful = false;
    string keyword = "";
    int keylength = 0;
    string user_text = "";
    int user_text_length;
    int key_count = 0;

    do
    {
        // Перевірка правильного значення аргумента
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
                    // Тільки букви в якості вхідних даних. 
                    printf("Your input contains illegal characters.\n");
                    return 1;
                }
                else
                {
                    // Вхідні дані можуть бути прийняті в якості ключа.
                    keySuccessful = true;
                    keyword = argv[1];
                }
            }
        }
    } while(!keySuccessful);
    
    // Перевірка довжини ключового слова.Визначення масиву з цією довжиною.
    keylength = strlen(keyword);
    int keycodes[keylength];

    // Перетворення ключового слова масиву в числа.
    // starting from A = 0 to Z = 25 ignoring case.
    for(int i = 0; i < keylength;i++)
    {
        keycodes[i] = toupper(keyword[i]) - 65;
    }

    // Перевірка юзер-тексту і обчислення його довжини.
    user_text = GetString();
    user_text_length = strlen(user_text);

    for (int i = 0; i < user_text_length; i++)
    {
        // Якщо символ не буква, то відображати його дзеркально.
        if(!isalpha(user_text[i]))
        {
            printf("%c", user_text[i]);
        }
        // Процес введеня.
        else
        {
            printf("%c", caesar(user_text[i], keycodes[key_count]));

            // Лічильник положення для масиву .   
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

    // Відображення з нового рядка і закінчення.
    printf("\n");
    return 0;
}