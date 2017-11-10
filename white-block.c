#include <stdio.h>
#include <string.h>


void main()
{
	char *pan;
	int size;
	int flag;
	char *result;
	char temp;
	int total=0;
	int place[1000] = { 0 };
	int move = 0;
	while (1)
	{
		printf("Input 1~12 ( 0 is exit) : ");
		scanf("%d", &size);
		if (size == 0)
			break;
		size = size * 2;
		pan = (char*)malloc(sizeof(char*)*size + 1);
		result = (char*)malloc(sizeof(char*)*size + 1);
		
		for (int i = 0; i < (size + 1); i++)
		{
			if (i < size / 2)
			{
				pan[i] = 'W';
				result[i] = 'B';
			}
			else if (i>size / 2)
			{
				pan[i] = 'B';
				result[i] = 'W';
			}
			else
			{
				pan[i] = ' ';
				result[i] = ' ';
			}
		}

		while (1)
		{
			for (int i = 0; i < (size + 1); i++)
			{
				if (pan[i] == ' ')
				{
					if (i == 0)
					{
						if (pan[i + 1] == 'B')
						{
							temp = pan[i + 1];
							pan[i + 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 1;
							place[move]++;
							move++;
						}
						else if (pan[i + 2] == 'B')
						{
							temp = pan[i + 2];
							pan[i + 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 2;
							place[move]++;
							move++;
						}

						break;
					}

					else if (i == size)
					{
						if (pan[i - 1] == 'W')
						{
							temp = pan[i - 1];
							pan[i - 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 1;
							place[move]++;
							move++;
						}
						else if (pan[i - 2] == 'W')
						{
							temp = pan[i - 2];
							pan[i - 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 2;
							place[move]++;
							move++;
						}

						break;
					}
					else if (pan[i - 1] == 'W' && pan[i + 1] == 'W')
					{
						if (pan[i + 2] == 'B')
						{
							temp = pan[i + 2];
							pan[i + 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 2;
							place[move]++;
							move++;
						}
						else if (pan[i - 2] == 'B')
						{
							temp = pan[i - 1];
							pan[i - 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 1;
							place[move]++;
							move++;
						}
						break;
					}
					else if (pan[i - 1] == 'B' && pan[i + 1] == 'B')
					{
						if (pan[i - 2] == 'W')
						{
							temp = pan[i - 2];
							pan[i - 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 2;
							place[move]++;
							move++;
						}
						else
						{
							temp = pan[i + 1];
							pan[i + 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 1;
							place[move]++;
							move++;
						}
						break;
					}
					else if (pan[i - 1] == 'W' && pan[i + 1] == 'B')
					{
						if (pan[i - 2] == 'W')
						{
							temp = pan[i - 1];
							pan[i - 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 1;
							place[move]++;
							move++;
						}
						else if (i == 1)
						{
							temp = pan[i - 1];
							pan[i - 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 1;
							place[move]++;
							move++;
						}
						else
						{
							temp = pan[i + 1];
							pan[i + 1] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 1;
							place[move]++;
							move++;
						}
						break;
					}
					else if (pan[i - 1] == 'B' && pan[i + 1] == 'W')
					{
						if (pan[i - 2] == 'W')
						{
							temp = pan[i - 2];
							pan[i - 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i - 2;
							place[move]++;
							move++;
						}
						else
						{
							temp = pan[i + 2];
							pan[i + 2] = pan[i];
							pan[i] = temp;
							total += 1;
							place[move] = i + 2;
							place[move]++;
							move++;
						}
						break;
					}
				}
			}
			for (int i = 0; i < (size + 1); i++)
			{
				if (pan[i] == result[i])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}

				if (flag == 0)
					break;
			}
			if (flag == 1)
				break;
		}

		printf("Total : %d\n", total);
		printf("move place: \n");
		for (int i = 0; i < move; i++)
		{
			if (place[i] != 0)
			{
				printf("%d ", place[i]);
				place[i] = 0;
			}
			if (i % 20 == 0 && i>0)
				printf("\n");
		}
		total = 0;
		move = 0;
		printf("\n");
	}
	
}