#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;
	char charset[] = "abcdefghijklmnopqrstuvwxyz";
	int location[26];

	for (int i = 0; i < 26; i++)
		location[i] = -1;
	str = (char*)malloc(sizeof(char) * 102);
	if (str == NULL)
		return 1;
	scanf("%s", str);
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (*(str + i) == charset[j] && location[j] == -1)
			{
				location[j] = i;
				break ;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", location[i]);
	}
	free(str);
	return 0;
}