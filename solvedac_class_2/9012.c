#include <stdio.h>

void	ft_is_valid_ps(char *str)
{
	int	cnt;

	cnt = 0;
	for (int i = 0; *(str + i) != '\0'; ++i)
	{
		if (*(str + i) == '(')
			++cnt;
		else if (*(str + i) == ')')
			--cnt;
		if (cnt < 0)
			break;
	}
	if (cnt == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int 	num_of_case;
	char	parenthesis_str[51];

	scanf("%d\n", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%s", parenthesis_str);
		ft_is_valid_ps(parenthesis_str);
	}
	return (0);
}