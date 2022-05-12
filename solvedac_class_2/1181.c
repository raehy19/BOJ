#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
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
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if ((strlen(*(words + j)) > strlen(*(words + j + 1)))
				|| ((strlen(*(words + j)) == strlen(*(words + j + 1)))
					&& (strcmp(*(words + j), *(words + j + 1)) > 0)))
				ft_swap((words + j), (words + j + 1));
		}
	}
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