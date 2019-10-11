#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char command[1024], str1[1024];

int main(int argc, char *argv[]){
	
	FILE *fp = fopen(argv[1], "r");

	printf("-------------------Input file example.txt-----------------\n");


	while(fscanf(fp, "%s", command) == 1){

		if(strcmp(command, "reverse") == 0){

			fscanf(fp, "%s", str1);
			printf("reverse %s\n", str1);

			int i, len = strlen(str1);
			
			for(i=len-1; i>=0; i--){
				printf("%c", str1[i]);
			}printf("\n");
			
		}else if(strcmp(command, "split") == 0){
		
			fscanf(fp, "%s", str1);
			printf("split %s\n", str1);

			char *p = strtok(str1, argv[2]);

			while(p != NULL){
				printf("%s ", p);
				p = strtok(NULL, argv[2]);
			}
			printf("\n");
			
		}
		strcpy(str1,"\0");
		// else if(strcmp(command, "exit") == 0){
		// 	break;
		// }
	}
	printf("-------------------End of input file example.txt----------\n");
	printf("*******************User input*****************************\n");

	while(1){
		scanf("%s", command);

		if(strcmp(command, "reverse") == 0){

			scanf("%s", str1);

			int i, len = strlen(str1);
			
			for(i=len-1; i>=0; i--){
				printf("%c", str1[i]);
			}printf("\n");
			
		}else if(strcmp(command, "split") == 0){
			scanf("%s", str1);

			char *p = strtok(str1, argv[2]);
			// printf("%c\n", *argv[argc-1]);
			while(p != NULL){
				printf("%s ", p);
				p = strtok(NULL, argv[2]);
			}
			printf("\n");
		}else if(strcmp(command, "exit") == 0){
			break;
		}
		strcpy(str1,"\0");

	}

}