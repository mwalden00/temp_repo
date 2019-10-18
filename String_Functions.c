#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *s)
{
	int i = 0;
	while(*s) 
	{
		i++;
		s++;
	}
	return i;
}

char *my_strcpy(char *dest, char *src) 
{
	char *ptr = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return ptr;
}

char *my_strncat(char *dest, char *src, int n) 
{
	char *ptr = dest + strlen(dest);
	int i = n;
	while (*src && i) 
	{
		*ptr = *src;
		ptr++;
		src++;
		i--;
	}
	*ptr = '\0';
	return dest;
}

int my_strcmp(char *s1, char *s2)
{
	while(*s1)
	{
		if (*s1 != *s2) break;
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *my_strchr(char *s, char c)
{
	while(*s && *s != (char) c)
	{
		s++;
	}
	if (*s == (char) c)
	{
		return s;
	} else {
		return NULL;
	}
}

int main() {
	char s1[100] = "?\n?W?";
	char s12[100] = "?\n?W?";
	char s2[100] = "hello";
	char s22[100] = "hello";
	char s3[100] = "goodbye";
	char s32[100] = "goodbye";
	printf("s1: [%s]\ns2: [%s]\ns3: [%s]", s1,s2,s3);
	printf("\n\nTesting strlen(s2):\n[standard]: %lu\n[mine]: %d\n", strlen(s2), my_strlen(s2));
	printf("\nTesting strcpy(s1, s2):\n[standard]: [%s]\n[mine]: [%s]\n", strcpy(s1,s2), my_strcpy(s12,s22));
	printf("\nTesting strncat(s1, s3, 3):\n[standard]: [%s]\n[mine]: [%s]\n", strncat(s1, s3,3), my_strncat(s12,s32,3));
	printf("\nTesting strchr(s1, 'l'):\n[standard]: [%p]\n[mine]: [%p]\n", strchr(s1, 'l'), my_strchr(s1, 'l'));
	printf("\nTesting strchr(s1, 0):\n[standard]: [%p]\n[mine]: [%p]\n", strchr(s1, 0), my_strchr(s1, 0));
	printf("\nTesting strchr(s1, 'z'):\n[standard]: [%p]\n[mine]: [%p]\n", strchr(s1, 'z'), my_strchr(s1, 'z'));
	printf("\nTesting strcmp:\nComparting ab to abc:\n[standard]:[%d]\n[mine]:[%d]\n",strcmp("ab","abc"),my_strcmp("ab","abc"));
	printf("\nComparting abc to ab:\n[standard]:[%d]\n[mine]:[%d]\n", strcmp("abc","ab"),my_strcmp("abc","ab"));
	printf("\nComparting abc to abc:\n[standard]:[%d]\n[mine]:[%d]\n", strcmp("abc","abc"),my_strcmp("abc","abc"));
	return 0;
}

