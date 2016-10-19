#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
	char   *buffer, *buffer2,  answer[128];        
	size_t  i;             
	size_t  buffer_size;   
	char   *temp;          
	char    c, ans, store, Answerkey[128];             
	FILE   *input_ques, *input_ans;         
	int j = 1, score, k;
	if (argc == 1) {
		fprintf(stderr, "Invalid Argument\n");
		exit(EXIT_FAILURE);
	}

	if ((input_ques = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File %s does not exist\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	i = 0;
	buffer_size = BUFSIZ;
	if ((buffer = malloc(buffer_size)) == NULL) {
		fclose(input_ques);
	}

	while ((c = fgetc(input_ques)) != EOF) {
		if (i == buffer_size) {
			buffer_size += BUFSIZ;
			if ((temp = realloc(buffer, buffer_size)) == NULL) {
				exit(EXIT_FAILURE);
			}
	
			buffer = temp;
			}
		buffer[i++] = c;
		if(c == '*'){
			printf("%s", buffer);
//			puts(buffer);
			scanf("%c",&answer[j]);
			getchar();
			j++;
//			buffer[i] = '\0';
			i = 0;
			free(buffer);
			buffer =(char *)calloc(sizeof(char), buffer_size);
			strcpy(buffer, "");
//			puts(buffer2);
			
		}
	//	puts(buffer);	
	}

	if (i == buffer_size) {
		buffer_size += 1;
		if ((temp = realloc(buffer, buffer_size)) == NULL) {
			exit(EXIT_FAILURE);
		}
		buffer = temp;
	}

	buffer[i] = '\0';
	while(j != 0) {
		printf("%c\n",*(answer + j - 1));
		j--;
	}
//	puts(buffer);
//	scanf("%s", &ans);
//	if(ans == 'A')
//		printf("sdf");
	free(buffer);
	fclose(input_ques);
	
//	input_ans = fopen("AnswerKey.txt", "r");
//while(fscanf(input_ans,"%s", Answerkey) != EOF) {
//		 ;
//	}
	
//	for(k = 0; k < 128; k++) {
//		if(strcmp(Answerkey[k], answer[k]) == 0) {
//			score++;
//		}
//	}
	return 0;

}
