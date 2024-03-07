//P1-SSOO-23/24

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>



int main(int argc, char *argv[])
{
	// si hay menos de 3 argumentos (argv[0] -> programa, argv[1] -> directorio a buscar, argv[2] -> archivo a encontrar)
	if(argc < 3)
	{
		printf("Too few arguments\n");
		return -1;
	}

	char buff[PATH_MAX]; // buffer para guardar el directorio
	switch (argc){
		case 3:
			strcpy(buff, argv[1]);     // copia en buff el argumento de argv[1]
			break;
		default:
			printf("Demasiados argumento\n");		//si se le han pasado argumentos de mas salta error
			return -1;
	}

	// abrimos el directorio
	DIR *dir = opendir(buff);

	if (NULL == dir){
		printf("Fallo al abrir el directorio\n");			//si hay fallo a la hora de abrir el directorio salta un error
		return -1;
	}


int no_esta=1;						//establecemo una variable para ver si esta o no esta el archivo inicializada a 1
	struct dirent *actual;							
	while ((actual = readdir(dir)) != NULL){					//vamos leyendo el directorio 1 a 1
		 if (strcmp(actual->d_name, argv[2]) == 0) {			//si el archivo es igual al que buscamos decimo que se ha encontrado, la variable no_esta cambia su valor a 0 y salimos del bucle
            printf("File %s is in directory %s\n", argv[2], argv[1]);
            no_esta = 0;
            break;
		}
	}
	if (no_esta == 1){														//si no_esta se ha mantenido a 1 significa que no estaba el archivo e imprimimos que no esta
		printf("File %s is not in directory %s\n", argv[2], argv[1]);
	}
	
	//cerramos el directorio
	closedir(dir);

	return 0;
}
