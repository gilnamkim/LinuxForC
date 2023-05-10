#include <stdio.h>
//#include <string.h>

int strcmp(const char *s1, const char *s2);
size_t strlen(const char *s);


int main() {
	
	char str[20] = "abba";
	char str_c[20] = "abb";

	printf("%d\n", strcmp(str,str_c));

	return 0;
}


int strcmp(const char *s1, const char *s2) {
	
	int length;
	if(strlen(s1) > strlen(s2)) {
		length = strlen(s1);
	} else {
		length = strlen(s2);
	}

	int result = 0;

	for(int i = 0; i <= length ; i++) {
		if(*(s1+i) - *(s2+i) == 0) {
			continue;
		} else {
			result = *(s1+i) - *(s2+i);
			break;
		}
	}

	return result;
}



size_t strlen(const char *s) {
	size_t count = 0;
	if(s != NULL) {
		for(int i = 0; ; i++) {
			if(*(s+i) == 0) {
				break;
			} else {
				count++;
			}
		}
	} else {
		return -1;
	}
	return count;
}
