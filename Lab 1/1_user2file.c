#include<stdio.h>
#include<string.h>
int main(){
	char filename[25];
	scanf("%s",filename);
	getchar();
	FILE* file = fopen(filename,"a");
	char strinp[100];
//	scanf("%s",filename);
	fgets(strinp,sizeof(strinp),stdin);
//	for(int i=0;i<strlen(strinp);i++){
//	fputc(strinp[i],file);
//	}
//	fputs(strinp,file);
	fputs(strinp,file);
	fclose(file);
	return 0;	
}


