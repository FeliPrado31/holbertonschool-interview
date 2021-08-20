#include "substring.h"

/**
 * find_substring -  finds all the possible substrings containing a list of
 * words, within a given string.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

    int current, count, str_len, word_len, check_strs, i, j, k;
    int *match, *id_arr;

    if (!s || !words || !n || nb_words == 0)
        return (NULL);
    str_len = strlen(s);
    word_len = strlen(words[0]);
    id_arr = malloc(str_len * sizeof(int));
    if (!id_arr)
        return (NULL);
    match = malloc(nb_words * sizeof(int));
    if (!match)
        return (NULL);
    for (i = count = 0; i <= str_len - nb_words * word_len; i++)
    {
        memset(match, 0, nb_words * sizeof(int));
        for (j = 0; j < nb_words; j++)
        {
            for (k = 0; k < nb_words; k++)
            {
                current = i + j * word_len;
                check_strs = strncmp(s + current, *(words + k), word_len);
                if (!*(match + k) && !check_strs)
                {
                    *(match + k) = 1;
                    break;
                }
            }
            if (k == nb_words)
                break;
        }
        if (j == nb_words)
            *(id_arr + count) = i, count += 1;
    }
    free(match);
    *n = count;
    return (id_arr);
}