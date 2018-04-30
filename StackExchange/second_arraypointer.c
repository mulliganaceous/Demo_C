#include <stdio.h>
void func( char [2][3]);
void func2( char *ap[2][3]) {
	printf("%s", (*ap)[1]);
}

//main has a 2dim array and call a func
int main()
{
	char tst[2][3] = {"abc", "def"};
	func(tst);
	return 0;
}

//and some function take that array's pointer
void func( char ap[2][3])
{
	//func2(&ap);  // what can be inside ()..?
}

