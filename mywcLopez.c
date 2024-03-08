//P1-SSOO-23/24

#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>

#define SIZE 1



int main(int argc, char *argv[])

{

	/*si hay mas o menos elementos que 2, devolver un error y return -1*/

	if(argc!= 2)

	{

		if (argc<2){

			printf("Too few arguments\n");}

		if (argc>2){

			printf("Too many arguments\n");}

		return -1;

	}

	/*declaramos variables*/

	int fich = 0;

	int numlin=0, numword=0, numbytes=0;

	int n = 0;

	char buffer[SIZE], car_ant= 0;

	int inicio = 1;

	

	if ((fich = open(argv[1], O_RDONLY))< 0){

		return -2;

	}

	while ((n =read(fich, buffer, SIZE)) > 0){

		numbytes++;

		if (buffer[0] == ' '){

			if ((car_ant != '\n')&(car_ant != '\t')&(car_ant != ' ')&(inicio== 0)){

				numword ++;}

			inicio=0;

		}

		if (buffer[0] == '\t'){

			if ((car_ant != '\n')&(car_ant != '\t')&(car_ant != ' ')&(inicio== 0)){

				numword ++;}

			inicio=0;

		}

		if (buffer[0] == '\n'){

			if ((car_ant != '\n')&(car_ant != '\t')&(car_ant != ' ')&(inicio== 0)){

				numword ++;}

			numlin++;

		}

		if ((buffer[0] != '\n')&(buffer[0] != '\t')&(buffer[0] != ' ')){

			if (inicio==1){

				inicio =0;

				numword = 1;}

			if(numword==0){

				numword++;}

		}

		car_ant=buffer[0];

	}

	/*error cierre fichero*/

	if ((n = close(fich))<0){

		return -3;}

		

	printf("%d %d %d %s\n", numlin, numword, numbytes, argv[1]);

	return 0;

	

}