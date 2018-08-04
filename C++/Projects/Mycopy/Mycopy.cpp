//mycopy.c:copy file to a specified destination file.
#include<stdio.h>
int main(int argCount, char* argValue[])
{
	FILE *srcFile = 0, *destFile = 0;
	int ch = 0;
	if (argCount != 3) {
		printf("Usage:%s src-file-name dest-file-name\n", argValue[0]);
	}
	else {
		if ((srcFile = fopen(argValue[1], "r")) == 0) {
			printf("Can not open source file \"%s\"!", argValue[1]);
		}
		else {
			if ((destFile = fopen(argValue[2], "w")) == 0) {
				printf("Can not open source file \"%s\"!", argValue[2]);
				fclose(srcFile);/*!!!*/
			}
			else {
				while ((ch = fgetc(srcFile)) != EOF) fputc(ch, destFile);
				printf("successful to copy a file!\n");
				fclose(srcFile);/*!!!*/
				fclose(destFile);/*!!!*/
				return 0;/*!!!*/
			}
		}
	}
	return 1;
}