#include <string.h>
#include <stdio.h>

#pragma warning(disable : 4996)

int get_operation_type(char* str)
{
	int operation_type = 0;

	if (NULL != strchr(str, '+'))
	{
		operation_type = 1;
	}
	else if (NULL != strchr(str, '-'))
	{
		operation_type = 2;
	}
	else if (NULL != strchr(str, '*'))
	{
		operation_type = 3;
	}
	else if (NULL != strchr(str, '/'))
	{
		operation_type = 4;
	}
	else {
		printf("no valid operation");
	}
	return operation_type;

}
int get_number(char* str,int *pos)
{
	int len = strlen(str);
	//printf("len = %d\n", len);
	int number = 0;
	int j = 0;

	for (int i = 0;i < len;i++)
	{
		if ((str[i] >= 0x30) && (str[i] <= 0x39))
		{
			number = (int)(str[i] - 0x30) + number*10;
			j++;
		}
		else
		{
			number = number * 10;	
			*pos = len -1 - i;
		}
		
		if (j == len)
		{
			*pos = 100;
		}

	}
	return number;
}
int get_power(int num)
{
	int number = 1;
	for (int i = 0;i < num;i++)
		number = number * 10;
	return number;
}

int compose_operation(int num1, int pos1, int num2, int pos2, int num3, int pos3,int operation_type,int *x, int *y)
{
	int i, j;
	int found = 0;
	if (pos3 == 100)
	{
		for (i = 0;i < 10;i++)
		{
			for (j = 0;j < 10;j++)
			{
				if (operation_type == 1)
				{
					if ((num1 + i * get_power(pos1)) + (num2 + j * get_power(pos2)) == num3)
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d + %d = %d\n", num1 + i * get_power(pos1), num2 + j * get_power(pos2), num3);
						found = 1;
						break;
					}
				}
				else if (operation_type == 2)
				{
					if ((num1 + i * get_power(pos1)) - (num2 + j * get_power(pos2)) == num3)
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d - %d = %d\n", num1 + i * get_power(pos1), num2 + j * get_power(pos2), num3);
						found = 1;
						break;
					}

				}
				else if (operation_type == 3)
				{
					if ((num1 + i * get_power(pos1)) * (num2 + j * get_power(pos2)) == num3)
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d * %d = %d\n", num1 + i * get_power(pos1), num2 + j * get_power(pos2), num3);
						found = 1;
						break;
					}

				}
				else //if (operation_type == 3)
				{
					if ((num1 + i * get_power(pos1)) == (num2 + j * get_power(pos2)) * num3)
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d / %d = %d\n", num1 + i * get_power(pos1), num2 + j * get_power(pos2), num3);
						found = 1;
						break;
					}
				}				
			}
			if (found == 1)
				break;
		}
	}
	else if (pos2 == 100)
	{
		for (i = 0;i < 10;i++)
		{
			for (j = 0;j < 10;j++)
			{
				if (operation_type == 1)
				{
					if (((num1 + i * get_power(pos1)) + num2) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d + %d = %d\n", num1 + i * get_power(pos1), num2, num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else if (operation_type == 2)
				{
					if (((num1 + i * get_power(pos1)) - num2) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d - %d = %d\n", num1 + i * get_power(pos1), num2, num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else if (operation_type == 3)
				{
					if (((num1 + i * get_power(pos1)) * num2) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d * %d = %d\n", num1 + i * get_power(pos1), num2, num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else
				{
					if ((num1 + i * get_power(pos1)) == num2* (num3 + j * get_power(pos3)))
					{
						//printf("i %d,j %d\n", i, j);
						printf("%d / %d = %d\n", num1 + i * get_power(pos1), num2, num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}				
			}
			if (found == 1)
				break;
		}
	}
	else if (pos1 == 100)
	{
		for (i = 0;i < 10;i++)
		{
			for (j = 0;j < 10;j++)
			{
				if (operation_type == 1)
				{
					if ((num1 + (num2 + i * get_power(pos2))) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d ,j %d\n", i, j);
						printf("%d + %d = %d\n", num1, num2 + i * get_power(pos2), num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else if (operation_type == 2)
				{
					if ((num1 - (num2 + i * get_power(pos2))) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d ,j %d\n", i, j);
						printf("%d - %d = %d\n", num1, num2 + i * get_power(pos2), num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else if (operation_type == 3)
				{
					if ((num1 * (num2 + i * get_power(pos2))) == (num3 + j * get_power(pos3)))
					{
						//printf("i %d ,j %d\n", i, j);
						printf("%d * %d = %d\n", num1, num2 + i * get_power(pos2), num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
				else
				{
					if (num1 = (num2 + i * get_power(pos2)) * (num3 + j * get_power(pos3)))
					{
						//printf("i %d ,j %d\n", i, j);
						printf("%d / %d = %d\n", num1, num2 + i * get_power(pos2), num3 + j * get_power(pos3));
						found = 1;
						break;
					}
				}
			}
			if (found == 1)
				break;
		}
	}
	*x = i;
	*y = j;

	return 0;
}


void findmissing(char* str)
{
	printf("str is %s\n", str);
	char newstr[80] = {'\0',};
	strncpy(newstr, str, strlen(str)>79?79:strlen(str));
	//printf("%s\n", newstr);
	int operation = 0;
	char operator[3][80] = { 0, };
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number1_pos = 0;
	int number2_pos = 0;
	int number3_pos = 0;

	int l = 0;
	char* p = NULL;
	char* pch = strtok(newstr, "+-*/= ");
	while (pch != NULL)
	{
		//printf("%s\n", pch);
		p = operator[l];
		strcpy(p, pch);
		l++;
		pch = strtok(NULL, "+-*/= ");
	}
	operation = get_operation_type(str);
	//printf("operation type = %d\n", operation);
	//for (int i = 0;i < 3;i++)
	//	printf("%s\n", operator[i]);

	number1 = get_number(operator[0], &number1_pos);
	number2 = get_number(operator[1], &number2_pos);
	number3 = get_number(operator[2], &number3_pos);

	//printf("num1 %d,num2 %d,num3 %d\n", number1, number2, number3);
	//printf("pos1 %d,pos2 %d,pos3 %d\n", number1_pos, number2_pos, number3_pos);

	int x, y;

	compose_operation(number1, number1_pos, number2, number2_pos, number3, number3_pos, operation,&x,&y);
	printf("x = %d, y = %d\n", x, y);

}

int main() 
{
	char* str = "1?3 + 45? = 579";
	//char* str = "?11 - 25 = 1?6";
	//char* str = "?11 * 25 = 527?";
	//char* str = "30? / 25 = 1?";

	findmissing(str);

	return 0;
}

