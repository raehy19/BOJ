#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_compare(const void *a, const void *b)
{
	char *str1 = *((char **)a);
	char *str2 = *((char **)b);

	if (strlen(str1) > strlen(str2))
		return 1;
	else if (strlen(str1) < strlen(str2))
		return -1;
	else if (strcmp(str1, str2) > 0)
		return 1;
	else if (strcmp(str1, str2) < 0)
		return -1;
	else
		return 0;
}

int main()
{
	int		size;
	char	**words;

	scanf("%d", &size);
	words = (char **) malloc(sizeof (char *) * size);
	for (int i = 0; i < size; i++)
	{
		*(words + i) = (char *) malloc(sizeof(char) * 52);
		scanf("%s", *(words + i));
	}
	qsort(words, size, sizeof(char *), ft_compare);
	printf("%s", *(words));
	for (int i = 1; i < size; i++)
	{
		if (strcmp(*(words + i - 1), *(words + i)) != 0)
			printf("\n%s", *(words + i));
	}
	for (int i = 0; i < size; i++)
		free(*(words + i));
	free(words);
	return 0;
}