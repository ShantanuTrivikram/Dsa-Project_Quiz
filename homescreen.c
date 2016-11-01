#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//#include <"functions.h">

//#include <'quiz_filereading1.c'>
//#include <'QuestionBank.c'>

typedef struct data {
	char username[128];	
	int score;
}data;

double average_score(data *n, int total);
int max_score(data *n, int total);
double percentile(data *n, int total, int a);
void quiz_filereading1(char *filename);
void QuestionBank(char *filename, float correct_ans, float wrong_ans);
void  compare();

//void QuestionBank();
//void Sample();

int main() {
	int i, type, single_mult, statistics, number = 0, total, max, score_percentile, j, number2 = 0, *percentage;
	float correct_ans, wrong_ans;
	char **answers, username[128], ch, **questions, *original_answerkey;	
	FILE *answer_key, *original_ans;
	char filename[32], *score_stats, *fp;
	double avg, percentile1;
	FILE *score_save;
	//	printf("***********************************************************\n") ;
	printf("\n\t\t\t\t\tThe Quiz\n\n\n\n");
	printf("1. Create a Quiz\n\n\n");
	printf("2. Try a Quiz\n\n\n");
	printf("3. Statistics\n\n\n");
	scanf("%d", &i);

	switch (i) {
		case 1 : 
			//			printf("saf");
			//			QuestionBank();
			printf("\n\nWhat type of questions do you want to add ?\n\n\n");	
			printf("1. Multiple choice questions.\n\n2. Match the following\n\n");
			printf("3. Numeric Answer Question\n\n");
			scanf("%d", &type);
			switch (type) {
				case 1 :
					printf("\n\n1.Single Correct Option\n\n");
					printf("2.Multiple correct Option\n\n");
					scanf("%d", &single_mult);
					if(single_mult == 1) {
						printf("\n\nEnter the file in which to save the question bank\n\n");
						scanf("%s", filename);
						printf("\nEnter the marking scheme\n");
						printf("Marks for the correct answer : ");
						scanf("%f", &correct_ans);
						printf("\nMarks deducted for the wrong answer : \n");
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


		case 3 :
			//		int i, number = 0, total, max, score_percentile;
			//		char *score_stats, *fp, ch, username[128];
			//		double avg, percentile1;
			//		FILE *score_save;
			//	score_stats = (char *)malloc(sizeof(char) * 128);
			score_save = fopen("score_save.txt", "r");
			while((ch = fgetc(score_save)) != EOF) {
				if(ch == '\t')
					number++;
			}
			fclose(score_save);
			score_save = fopen("score_save.txt", "r");
			//	printf("%d\n", number);
			data score1[number + 1];
			for(i = 0; i < number; i++) {
				fscanf(score_save, "%s", score1[i].username);
				fscanf(score_save, "%d", &(score1[i].score));
			}
			//	for(i = 0; i < number; i++) {
			//		printf("%s\n", score1[i].username);
			//		printf("%d\n", score1[i].score);

			//	}
			total = i;
//			avg = average_score(score1, total);
//			printf("Average score is %lf\n", avg);





			printf("1. Find the average marks scored in the quiz\n\n");
			printf("2. Find the maximum marks scored in the quiz\n\n");
			printf("3. Find the percentile of a given participant\n\n");
			printf("4. Find the number of participants who got a particular question correct\n\n");
			scanf("%d", &statistics);

			switch(statistics) {
				case 1 :
					avg = average_score(score1, total);
					printf("The average score is %lf\n", avg);
					break;
				case 2 :
					max = max_score(score1, total); 
					printf("The maximum score is  %d\n %d\n", (score1[max].score), max);
					break;
				case 3 :
					printf("Find the percentile of : ");
					scanf("%s", username);
					for(i = 0; i < total; i++) {
						if (strcmp(username, score1[i].username) == 0) 
							break;		
						else {
							printf("Enter Valid Username\n");
							//							break;
						}
					}
					score_percentile = score1[i].score;
					percentile1 = percentile(score1, total, score_percentile);
					printf("Percentile of %s is %lf\n", username, percentile1);
					//					fclose(score_save);
					break;

				case 4 :
					compare();
			}			

	}
			return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h> 2
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

double average_score(data *n, int total) {
	int i;
	double sum;
	for(i = 0; i < total; i++) {
		sum = sum + n[i].score;
	}
	return (sum / (total * (1.0)));
}

int max_score(data *n, int total) {
	int i, max = 0;
	for(i = 0; i < total; i++) {
		if(n[max].score < n[i].score) {
			max = i;
		}
	}
	return max;
}

double percentile(data *n, int total, int a) {
	int i, j, t, temp = 0, temp1, index = 0;
	char temp2;
	//	for(i = 0; i < total; i++) {
	//		for(j = 0; j < total - i; j++) {
	//			if(n[i].score > n[i + 1].score) {
	//				temp1 = n[i].score;
	//				n[i].score = n[i + 1].score;	
	//				n[i + 1].score = temp1;
	//			}
	//		}
	//	}
	for(i = 0; i < total - 1; i++) {
		for(j = i + 1; j < total; j++)
			if(n[i].score >= n[j].score)
			{
				t = n[i].score;
				n[i].score = n[j].score;
				n[j].score = t;
			}
	}
	for(i = 0; i < total; i++) {
		if(a == n[i].score) {
			break;	
			//		printf("%d\n", n[i].score);
		}
	}
	index = i;
	return ((index * 1.0)/ (total * 1.0)) * 100;

}
					


void compare() {
						int i, j, number = 0, number2 = 0, *percentage ;
					char **answers, username[128], ch, **questions, *original_answerkey;
					FILE *answer_key, *original_ans;
	answer_key = fopen("AnswerMatch.txt", "r");
	while((ch = fgetc(answer_key)) != EOF) {
		if(ch == '\n')
			number++;
	}
	original_ans = fopen("AnswerKey.txt", "r");
	original_answerkey = (char *)malloc(sizeof(char) * number2);

	i = 0;	
	while(fscanf(original_ans, "%s", &original_answerkey[i]) != EOF)
		i++;
	number2 = i;
	//	printf("%d\n", number2);

	answers = (char **)malloc(sizeof(char) * number2);

	questions = (char **)malloc(sizeof(char) * number2);

	fclose(answer_key);
	answer_key = fopen("AnswerMatch.txt", "r");
	for(i = 0; i < number ; i++) {
		answers[i] = (char *)malloc(sizeof(char) * 128);

		//	for(j = 0; j < i ; j++) {
		//		fscanf(answer_key, "%c", &answers[i][j]);
		//	}
		j = 0;
		while(1) {
			ch = fgetc(answer_key);	
			if(ch == '\n')
				break;
			answers[i][j] = ch;
			j++;
		}
	}
	//	for(i = 0; i < number; i++)
	//		printf("%s\n", answers[i]);



	percentage = (int *)malloc(sizeof(int) * number2);

	for(i = 0; i < number2; i++) {
		percentage[i] = 0;
	}


	for(i = 0; i < number2; i++) {
		//		questions[i] = (char *)malloc(sizeof(char) * number);
		//		questions[i] = answers[i][1];		
		for(j = 0; j < number; j++) {
			if(original_answerkey[i] == answers[j][i])
				percentage[i]++;
		}
	}

	for(i = 0; i < number2; i++) {
		printf("%lf%% people got question %d correct\n", ((percentage[i]) * (1.0) / (number * 1.0)) * 100, i + 1);
	}


}
