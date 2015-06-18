/*
 * memory limit exceeded.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STEP 8

static char **res;
int	maxp, p;

static int compar(const void *x, const void *y)
{
	return(strcmp(*(char **)x, *(char **)y));
}

static int comlen(const char *s1, const char *s2)
{
	int	i = 0;
	while (*s1 && *s1++ == *s2++)
		i++;
	return(i);
}

static void add_ans(const char *s)
{
	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char *));
	}
	res[p++] = strndup(s, 10);
}

char **findRepeatedDnaSequences(char *s, int *returnSize)
{
	int	len = strlen(s), i, clen;
	char	**post;

	if (len < 20) {
		*returnSize = 0;
		return(0);
	}

	res = 0;
	post = malloc(len * sizeof(char *));
	for (i = 0; i < len; i++)
		post[i] = &s[i];
	qsort(post, len, sizeof(char *), compar);

	for (i = 1; i < len; i++) {
		clen = comlen(post[i - 1], post[i]);
		if (clen < 10)
			continue;
		add_ans(post[i]);
	}

	free(post);
	if (!res) {
		*returnSize = 0;
		return(res);
	}
	*returnSize = p;
	return(res);
}

int main(int argc, char **argv)
{
	char	**res;
	int	n;
	res = findRepeatedDnaSequences(argv[1], &n);
	while (n-- > 0)
		printf("%s\n", res[n]);
	return(0);
}
