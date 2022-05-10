#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num_of_case;
	int	*repeat_num;
	char **str;

	scanf("%d", &num_of_case);
	repeat_num = (int *) malloc(sizeof(int) * num_of_case);
	str = (char **) malloc(sizeof(char *) * (num_of_case));
	for (int i = 0; i < num_of_case; i++)
		*(str + i) = (char *) malloc(sizeof(char) * 22);
	for (int i = 0; i < num_of_case; i++)
		scanf("%d %s", repeat_num + i, *(str + i));
	for (int i = 0; i < num_of_case; i++)
	{
		if (i != 0)
			printf("\n");
		for (int j = 0; *(*(str + i) + j) != '\0'; j++)
			for (int k = 0; k < *(repeat_num + i); k++) {
				printf("%c", *(*(str + i) + j));
			}
	}
	for (int i = 0; i < num_of_case; i++)
		free(*(str + i));
	free(str);
	free(repeat_num);
	return 0;
}