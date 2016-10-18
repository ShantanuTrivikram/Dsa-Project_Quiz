#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int i = 0, j = 0, k = 0, l = 0, number ;
	char *ques, *options, ans[128], ch, **questions, **opt ;
	FILE *fp1, *fp2;

	fp1 = fopen("Question_Bank.txt", "w");
	fp2 = fopen("AnswerKey.txt", "w");

	printf("Enter the number of questions in the question bank\n");
	scanf("%d", &number);

	questions = (char **)malloc(sizeof(char *) * number);
	opt = (char **)malloc(sizeof(char *) * number);

	while(i < number) {

		printf("Enter the question\n");
		questions[i] = (char *)malloc(sizeof(char) * 512);
		j = 0;
		while(1) {

			ch = getc(stdin);
			questions[i][j] = ch;
			if(ch == '?')
				break;
			j++;
		}

		printf("Enter the options\n");
		opt[i] = (char *)malloc(sizeof(char) * 512);
		k = 0;
		while((ch = getc(stdin)) != EOF) {
			opt[i][k] = ch;
			k++;
		}
	//	opt[i][k] = '\0';

		printf("Enter the correct answer\n");
		scanf("%c", &ans[l]);
		l++;
		i++;
	}
	for(i = 0; i < number; i++) {
		printf("%s", questions[i]);
		printf("%s", opt[i]);
	}
	printf("\n");

//	for(j = 0; j < number; j++) {
//		printf("%s", opt[j]);
//	}
//	printf("\n");
	for(k = 0; k < number; k++) {
		printf("%c", ans[k]);
		printf("\n");
	}

	for(i = 0; i < number; i++) {
		fprintf(fp1, "%s\n%s", questions[i], opt[i]);
		fprintf(fp1, "\n*\n");
	}
	fclose(fp1);

	for(i = 0; i < number; i++) {
		fprintf(fp2, "%c\n", ans[i]);
	}

	return 0;
}
