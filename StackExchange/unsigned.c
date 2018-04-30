#include <stdio.h>
int main() {
	unsigned char a = -127;
	char b = 129;
	printf("%d %d %d\n", a, b, a & b);
}

