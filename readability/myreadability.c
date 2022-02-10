#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calc_CL_index(int letters, int words, int sentences);

int main(void)
{
    int letters, words, sentences;

    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    printf("Input: %s\n", text);
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);

    calc_CL_index(letters, words, sentences);

}


int count_letters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }

    // add 1 to count since get_string removes trailing line ending
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }

    return count;
}

int calc_CL_index(int letters, int words, int sentences)
{
    float av_letters, av_sent, index;

    av_letters = (float)letters / words * 100;
    av_sent = (float)sentences / words * 100;

    index = 0.0588 * av_letters - 0.296 * av_sent - 15.8;
    printf("Index: %f\n", index);
    printf("Rounded Index: %f\n", round(index));

    return 0;
}
