#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		num_of_case;
	char	**str;
	int		total_score;
	int 	current_score;

	scanf("%d", &num_of_case);
	str = (char **) malloc(sizeof(char *) * (num_of_case));
	for (int i = 0; i < num_of_case; i++)
		*(str + i) = (char *) malloc(sizeof(char) * 82);
	for (int i = 0; i < num_of_case; i++)
		scanf("%s", *(str + i));
	for (int i = 0; i < num_of_case; i++)
	{
		total_score = 0;
		current_score = 0;
		if (i != 0)
			printf("\n");
		for (int j = 0; *(*(str + i) + j) != '\0'; j++)
		{
			if (*(*(str + i) + j) == 'O')
				current_score++;
			else if (*(*(str + i) + j) == 'X')
				current_score = 0;
			total_score += current_score;
		}
		printf("%d", total_score);
	}
	for (int i = 0; i < num_of_case; i++)
		free(*(str + i));
	free(str);
	return 0;
}