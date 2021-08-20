#ifndef REGEX
#define REGEX

#include <stdio.h>
#include <string.h>
#include <stdlib.h>#ifndef SUBSTRING_H
#define SUBSTRING_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int *find_substring(char const *s, char const **words, int nb_words, int *n);
#endif /* _SUBSTRING_H_ */

int regex_match(char const *str, char const *pattern);
#endif