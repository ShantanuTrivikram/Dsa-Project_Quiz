project : homescreen.o
	gcc homescreen.o -o project
homescreen.o : homescreen.c
	gcc -c homescreen.c
clean: 
	rm *.o project
	
