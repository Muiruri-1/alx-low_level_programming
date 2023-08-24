#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 6

int main(void)
{
    srand(time(NULL)); // Initialize random number generator with current time

    // Define the set of characters from which the password can be formed
    const char valid_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int valid_chars_count = sizeof(valid_chars) - 1; // Exclude the null terminator

    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
    password[PASSWORD_LENGTH] = '\0';    // Null-terminate the password

    printf("Generated Passwords:\n");

    // Generate multiple passwords
    for (int i = 0; i < 10; i++)
    {
        // Generate a random password
        for (int j = 0; j < PASSWORD_LENGTH; j++)
        {
            int random_index = rand() % valid_chars_count;
            password[j] = valid_chars[random_index];
        }

        // Print the generated password
        printf("%s\n", password);
    }

    return 0;
}

