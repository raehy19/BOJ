#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;
	int count;
	int i;

	str = (char*)malloc(sizeof(char) * 1000001);
	scanf("%[^\n]s", str);
	count = 0;
	i = 1;
	if (*str != ' ')
		count ++;
	while (*(str + i) != '\0')
	{
		if (*(str + i - 1) == ' '  && *(str + i) != ' ')
			count++;
		i++;
	}
	printf("%d",count);
	free(str);
	return 0;
}