#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//#include <"functions.h">

//#include <'quiz_filereading1.c'>
//#include <'QuestionBank.c'>

void quiz_filereading1(char *filename);
void QuestionBank(char *filename, float correct_ans, float wrong_ans);

//void QuestionBank();
//void Sample();

int main() {
	int i, type, single_mult;
	float correct_ans, wrong_ans;
	char filename[32];
	printf("***********************************************************\n")
;	printf("The Quiz\n");
	printf("1.Create a Quiz\n");
	printf("2.Try a Quiz\n");
	scanf("%d", &i);
	switch (i) {
		case 1 : 
			printf("saf");
//			QuestionBank();
			printf("What type of questions do you want to add ?\n");	
			printf("1. Multiple choice questions.\n2. Match the following\n");
			printf("3. Numeric Answer Question\n");
			scanf("%d", &type);
			switch (type) {
				case 1 :
					printf("1.Single Correct Option\n");
					printf("2.Multiple correct Option\n");
					scanf("%d", &single_mult);
					if(single_mult == 1) {
						printf("Enter the file in which to save the question bank\n");
						scanf("%s", filename);
						printf("Enter the marking scheme\n");
						printf("Marks for the correct answer : ");
						scanf("%f", &correct_ans);
						printf("\nMarks deducted for the wrong answer : ");
						scanf("%f", &wrong_ans);
						QuestionBank(filename, correct_ans, wrong_ans);
		//				quiz_filereading1(filename, correct_ans, wrong_ans);
						break;
					}
			//	case 2 :
			//		match();
		//	break;
			}
		case 2 : 
			printf("Enter the name of the file\n");
			scanf("%s", filename);
			quiz_filereading1(filename);
			break;
			}
	
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main (int argc, char *argv[]) {


void quiz_filereading1(char *filename) {
	char   *buffer,  answer[128];        
	size_t  i;             
	size_t  buffer_size;   
	char   *temp, *username;          
	char    c, Answerkey[128];             
	FILE   *input_ques, *input_ans, *savescore, *save_answer, *marking_scheme;         
	static int j = 0;
	int score = 0, k;
	float correct_ans1, wrong_ans1;
//	if (argc == 1) {
//		fprintf(stderr, "Invalid Argument\n");
//		exit(EXIT_FAILURE);
//	}

	if ((input_ques = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "File %s does not exist\n", filename);
		exit(EXIT_FAILURE);
	}

	i = 0;
	buffer_size = BUFSIZ;
	if ((buffer = malloc(buffer_size)) == NULL) {
		fclose(input_ques);
	}

	username = (char *)malloc(sizeof(char) * 128);
	printf("Enter your Quiz_ID\n");
	scanf("%s", username);

	while ((c = fgetc(input_ques)) != EOF) {
		if (i == buffer_size) {
			buffer_size += BUFSIZ;
			if ((temp = realloc(buffer, buffer_size)) == NULL) {
				exit(EXIT_FAILURE);
			}

			buffer = temp;
		}
		buffer[i++] = c;
		if(buffer[i - 1] == '*'){
			printf("%s", buffer);
//			puts(buffer);
			getchar();
			scanf("%c", &answer[j]);
//			printf("Answer String %c\n ", answer[j]);
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
		//		printf("%c\n",*(answer + j - 1));
		j--;
	}
	//	puts(buffer);
	//	scanf("%s", &ans);
	//	if(ans == 'A')
	//		printf("sdf");
	free(buffer);
	fclose(input_ques);
	
	int total = strlen(answer);	
	save_answer = fopen("AnswerMatch.txt", "a");
	fprintf(save_answer, "%s", username);
//	for(i = 0; i < total; i++) {
		fprintf(save_answer, "\t%s\n",  answer);
		

		input_ans = fopen("AnswerKey.txt", "r");
		i = 0;
		while(fscanf(input_ans,"%s", &Answerkey[i]) != EOF) {
			//		printf("Answer key %c \n", Answerkey[i]);
			//		printf("Answer String %c\n ", answer[i]);
			i++;

		}
		j = 0;	
		int correct = 0;
		
		marking_scheme = fopen("Marking.txt", "r");
		fscanf(marking_scheme, "%f%f", &correct_ans1, &wrong_ans1);		

		for(k = 0; k < i; k++) {
		//	printf("Answer String %c\n ", answer[k]);
//			if(strcmp(&Answerkey[k], &answer[k]) == 0) {
			if(Answerkey[k] == answer[k]) {
				score = score + correct_ans1;
				correct++;
			}
			else 
				score = score - wrong_ans1;
			j++;
		}

		printf("\n\nYour score is %d\n", score);
		printf("You answered %d correctly\n\n\n", correct);
		savescore = fopen("score_save.txt", "a");
		fprintf(savescore, "%s\t%d\n",username, score);
		fclose(savescore);
		fclose(marking_scheme);	
}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <errno.h>

//int main(int argc, char* argv[]) {


void QuestionBank(char *filename, float correct_ans, float wrong_ans) {
	int i = 0, j = 0, k = 0, l = 0, number ;
	char *ques, *options, ans[128], ch, **questions, **opt ;
	FILE *fp1, *fp2, *fp3;

	fp1 = fopen(filename, "w");
	fp2 = fopen("AnswerKey.txt", "w");
	fp3 = fopen("Marking.txt", "a");
//	if(argc != 2) {
//		printf("Invalid Argument Type\n");
//		return errno;
//	}

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
//	for(i = 0; i < number; i++) {
//		printf("%s", questions[i]);
//		printf("%s", opt[i]);
//	}
//	printf("\n");

//	for(j = 0; j < number; j++) {
//		printf("%s", opt[j]);
//	}
//	printf("\n");
//	for(k = 0; k < number; k++) {
//		printf("%c", ans[k]);
//		printf("\n");
//	}

	for(i = 0; i < number; i++) {
		fprintf(fp1, "%s\n%s", questions[i], opt[i]);
		fprintf(fp1, "\n*\n");
	}
	fclose(fp1);

	for(i = 0; i < number; i++) {
		fprintf(fp2, "%c\n", ans[i]);
	}
	
	fprintf(fp3, "%f\n%f", correct_ans, wrong_ans);
	
	
//	return 0;

}
