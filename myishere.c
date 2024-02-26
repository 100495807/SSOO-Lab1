//P1-SSOO-23/24

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>



int main(int argc, char *argv[])
{
	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
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
			printf("Demasiados argumento\n");
			return -1;
	}

	DIR *dir = opendir(buff);

	if (NULL == dir){
		printf("Fallo al abrir el directorio\n");
		return -1;
	}

	int no_esta=1;
	struct dirent *actual;
	while ((actual = readdir(dir)) != NULL){

		 if (strcmp(actual->d_name, argv[2]) == 0) {
            printf("File %s is in directory %s\n", argv[2], argv[1]);
            no_esta = 0;
            break;
		}
	}
	if (no_esta == 1){
		printf("File %s is not in directory %s\n", argv[2], argv[1]);
	}
	
	closedir(dir);

	return 0;
}
