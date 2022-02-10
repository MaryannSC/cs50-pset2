#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calc_CL_index(int letters, int words, int sentences);


// readability.c prompts the user for text and computes the approximate
// grade level using the Coleman-Liau index needed to comprehend the text.

int main(void)
{
    int letters, words, sentences;

    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    int index = calc_CL_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// returns the the number of letters in the provided text.

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

// returns the number of words in the provided text.

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

// returns the number of sentences in the provided text.
// only counts sentences that end with '.', '?', or '!'.

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


// calculate the Coleman-Liau index, given the number of letters,
// words and sentences in the provided text.  Returns the rounded
// integer value of the index.

int calc_CL_index(int letters, int words, int sentences)
{
    float av_letters, av_sent, index;

    av_letters = (float)letters / words * 100;
    av_sent = (float)sentences / words * 100;

    index = 0.0588 * av_letters - 0.296 * av_sent - 15.8;

    return (int)round(index);
}
