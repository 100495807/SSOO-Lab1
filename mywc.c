//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	/*cuando haya unn número de elementos diferente a 2 devolver un error y return -1*/
	if(argc!= 2)
	{
		if (argc<2){
			printf("Too few arguments\n");}
		if (argc>2){
			printf("Too many arguments\n");}
		return -1;
	}
	/*declaramos las variables*/
	int fd1;
	int contador_palabra = 0;
	int contador_linea = 0;
	int contador_byte = 0;
	char ch;								//declaramos una variable para almacenar el caracter actual
	
	/*comprobamos q se abra el fichero*/
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0){
		printf("no se puede abrir el fichero %s", argv[1]);
		return -1;
	}

	while(read(fd1, &ch, 1) > 0){			 /*creamos bucle que realice el conteo de lineas palabras y bytes, mientras que siga habiendo caracteres seguir el bucle*/
        contador_byte++; 					/*en cualquier caso se sumara los bytes*/
		ant = ch;							//guardamos el valor actual en anterior
        if ((ch == ' ') | (ch == '\t') | (ch == '\n')){ /*si el char es un espacio, tabulador o salto de linea añades una palabra*/
            contador_palabra++;
        }

        if (ch == '\n'){
            contador_linea++; 				/*si hay un salto de linea se añade una linea*/
        }
	}

	if (contador_byte==0){											//si el archivo esta vacio establecemos el contador de palabras a 0 y asi no cuente 1
		contador_palabra = 0;
	}

    close(fd1);								/*cerramos el fichero e immprimimos el resultado por pantalla*/
    printf("%d %d %d %s\n", contador_linea, contador_palabra, contador_byte, argv[1]);
	return 0;
}
