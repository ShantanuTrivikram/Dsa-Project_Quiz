quiz:	quiz_filereading1.o QuestionBank.o
	gcc quiz_filereading1.o QuestionBank.o -o quiz
quiz_filereading1.o: quiz_filereading1.c
	gcc -c quiz_filereading1.c
QuestionBank.o: QuestionBank.c
	gcc -c QuestionBank.c
