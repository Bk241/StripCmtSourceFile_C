#include <stdio.h>
#include <string.h>


int main()
{
	char *RCV;
	char *SOME;
	int i = 0;
	char *DATA[1024];
	char *data;
	char *ok;
	

	char *ptr;
	char str1[1024];

	printf("Enter the Packet Information : \n");
	fgets(str1, 197, stdin);

	RCV = strtok_s(str1, "\r\nRCV", &ptr);
	while (str1 != NULL)
	{
		printf("Packet 1> %s\n", RCV);
		SOME = strtok_s(NULL, "\r\nSOME", &ptr);
		printf("size:  %s ", SOME);
		DATA[i] = strtok_s(NULL, "DATA[i]\r\n", &ptr);
		printf(" [i] data: %s ", DATA[i]);
		data = strtok_s(NULL, "\r\n", &ptr);
		printf(" [ %s ", data);
		ok = strtok_s(NULL, "OK\r\n", &ptr);
		printf(" [ %s ", ok);
	}
		
	return 0;
}