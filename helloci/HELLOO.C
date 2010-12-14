#include <stdio.h>
int main(){
	if (printf("Hello )") == EOF)
		return 1;
	return 0;
}