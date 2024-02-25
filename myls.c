//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	//buscamos el directorio

	char buff[PATH_MAX]; // buffer para guardar el directorio
	switch (argc){
		case 1:
			// si no se le pasa ningun argumento, usa directorio actual
			getcwd(buff, PATH_MAX);
			if (buff == NULL){
				printf("No se pudo encontrar el directorio\n");
				return -1;
			}
			break;
		case 2:
			strcpy(buff, argv[1]);     // copia en buff el argumento de argv[1]
			break;
		default:
			printf("Demasiados argumento\n");
			return -1;
	}

	//bucle para ir leyendo

	DIR *dir = opendir(buff); // puntero del directorio
	if (NULL == dir){
		printf("Fallo al abrir el directorio");
		return -1;
	}

	struct dirent *actual;
	while ((actual = readdir(dir)) != NULL){
		printf("%s\n", actual->d_name); // se usa la flecha en vez del punto por que current es un punteroy
	}

	//cerrar el directorio

	closedir(dir);

	return 0;
}

