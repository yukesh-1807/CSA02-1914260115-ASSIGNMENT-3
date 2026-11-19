#include <stdio.h>
#include <ctype.h>

int word_count(const char s[])
{
    int i, count = 0, inside = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' &&
            s[i] != '\n')
        {
            if (inside == 0)
            {
                count++;
                inside = 1;
            }
        }
        else
        {
            inside = 0;
        }
    }

    return count;
}

int is_palindrome(const char s[])
{
    int left = 0, right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right)
    {
        while (left < right &&
               !isalpha((unsigned char)s[left]))
            left++;

        while (left < right &&
               !isalpha((unsigned char)s[right]))
            right--;

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

void uppercase(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        s[i] = toupper((unsigned char)s[i]);
}

void reverse(char s[])
{
    int left = 0, right = 0;
    char temp;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    char message[] = "Hello World";
    char copy[] = "Hello World";

    printf("Words: %d\n",
           word_count(" Meet at the library at 5 PM "));

    printf("%d %d\n",
           is_palindrome("Madam, I'm Adam"),
           is_palindrome("Hello"));

    uppercase(message);
    printf("Uppercase: %s\n", message);

    reverse(copy);
    printf("Reversed: %s\n", copy);

    return 0;
}
