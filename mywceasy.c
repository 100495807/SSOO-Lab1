//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Faltan argumentos\n");
		return -1;
	}

	int fd1;
	int contador_palabra = 0;
	int contador_linea = 0;
	int contador_byte = 0;
	
	fd1 = open(argv[1], O_RDONLY);

	if (fd1 < 0){
		printf("no se puede abrir el fichero %s", argv[1]);
		return -1;
	}

	char ch;
	char ant;

	while(read(fd1, &ch, 1) > 0){
        contador_byte++;
		ant = ch;
        if ((ch == ' ') | (ch == '\t') | (ch == '\n')){
            contador_palabra++;
        }

        if (ch == '\n'){
            contador_linea++;
        }
		

	}
	if ((ant != ' ') | (ant != '\t') | (ant != '\n')){
		contador_palabra++;
	}

    close(fd1);

    printf("%d %d %d %s\n", contador_linea, contador_palabra, contador_byte, argv[1]);
	return 0;
}

