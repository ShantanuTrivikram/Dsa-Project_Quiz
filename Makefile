quiz1:	 QuestionBank.o
	gcc QuestionBank.o -o quiz1
quiz2: quiz_filereading1.o 
	gcc quiz_filereading1.o -o quiz2
quiz_filereading1.o: quiz_filereading1.c
	gcc -c quiz_filereading1.c
QuestionBank.o: QuestionBank.c
	gcc -c QuestionBank.c
