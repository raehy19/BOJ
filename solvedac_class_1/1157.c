#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	int count[26];
	int max_count = 0;
	int check = 0;

	for (int i = 0; i < 26; i++)
		count[i] = 0;
	str = (char*)malloc(sizeof(char) * 1000001);
	if (str == NULL)
		return 1;
	scanf("%s", str);
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (*(str + i) == upper[j] || *(str + i) == lower[j])
			{
				count[j]++;
				break ;
			}
		}
	}
	for (int i = 0; i < 26; i++)
		if (count[i] > max_count)
			max_count = count[i];
	for (int i = 0; i < 26; i++)
	{
		if (count[i] == max_count)
			check++;
		if (check > 1)
		{
			printf("?");
			free(str);
			return 0;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (count[i] == max_count)
		{
			printf("%c",upper[i]);
			free(str);
			return 0;
		}
	}
	return 0;
}