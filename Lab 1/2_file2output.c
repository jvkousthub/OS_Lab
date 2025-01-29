#include<stdio.h>
#include<string.h>
int main(){
	char filename[200];
	char ch;
	scanf("%s",filename);
	FILE* file=fopen(filename,"r");
	if(file==NULL) printf("No file found");
	while((ch=fgetc(file))!=EOF){
		putchar(ch);
	}
	fclose(file);
}
