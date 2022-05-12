#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	char	*str;
	int		len;
	int 	flag;

	str = (char *) malloc(sizeof(char) * 6);
	scanf("%s", str);
	while (strcmp(str, "0") != 0)
	{
		len = strlen(str);
		flag = 0;
		for (int i = 0; i < len - 1 - i; i++)
		{
			if (*(str + i) != *(str + len - 1 - i))
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			printf("yes\n");
		else
			printf("no\n");
		scanf("%s", str);
	}
	free(str);
	return 0;
}