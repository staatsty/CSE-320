proj07: proj07.driver.o proj07.support.o
	gcc proj07.driver.o proj07.support.o -o proj07 

proj07.driver.o: proj07.driver.c
	gcc -g  -c proj07.driver.c 

proj07.support.o: proj07.support.c
	gcc -g  -c proj07.support.c 
