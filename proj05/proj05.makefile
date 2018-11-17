proj05: proj05.driver.o proj05.support.o
	gcc proj05.driver.o proj05.support.o -o proj05

proj05.driver.o: proj05.driver.c
	gcc -c proj05.driver.c

proj05.support.o: proj05.support.c
	gcc -c proj05.support.c
