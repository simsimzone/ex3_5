#include <stdio.h>
#include<limits.h>
#include<math.h>

#define MAX_CHARS 1000

void reverse(char s [])
{
	int i, j;
	char temp;
	for (j = 0; s[j] != '\0'; j++);
	if (s[--j] == '\n')
		s[j--] = '\0';

	for (i = 0; i < j; i++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j--] = temp;
	}
}

void itob(int n, char s [], int b)
{
	int i = 0, sign = n, rem;
	if (b < 2 || b>36)
		return;
	do
	{
		rem = abs(n % b);
		if (rem >= 10)
			s[i++] = 'A' + (rem - 10);
		else
			s[i++] = '0' + rem;
	} while (n /= b);
	if (sign < 0 && b == 10)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


//Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation 
//in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
void ex3_5()
{
	char s[MAX_CHARS];
	int n = INT_MIN;//-2147483648;
	int b;
	printf("Number = %d\n", n);
	for (b = 2; b <= 36; b++)
	{
		itob(n, s, b);
		printf("%2d\t%s\n", b, s);
	}
	itob(n, s, b);

}

main()
{
	ex3_5();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}