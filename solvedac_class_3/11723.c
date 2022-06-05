#include <stdio.h>
#include <string.h>

int main()
{
	int 				m, x;
	unsigned long long	s;
	char				command[7];

	s = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", command);
		if (strcmp(command, "add") == 0)
		{
			scanf("%d", &x);
			s |= (1 << x);
		}
		else if (strcmp(command, "remove") == 0)
		{
			scanf("%d", &x);
			s &= ~(1 << x);
		}
		else if (strcmp(command, "check") == 0)
		{
			scanf("%d", &x);
			if ((s & (1 << x)) == 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(command, "toggle") == 0)
		{
			scanf("%d", &x);
			s ^= (1 << x);
		}
		else if (strcmp(command, "all") == 0)
			s = (1 << 21) - 1;
		else if (strcmp(command, "empty") == 0)
			s = 0;
	}
	return (0);
}