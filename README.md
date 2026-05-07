# SSOO-Lab1

Primera practica de Sistemas Operativos centrada en programacion de utilidades basicas en C. El repositorio implementa versiones sencillas de comandos clasicos de Unix para practicar llamadas al sistema, manejo de ficheros y lectura de directorios.

## Objetivo

Recrear pequenas herramientas de terminal para comprender como trabajan internamente comandos habituales del sistema operativo.

## Programas Incluidos

| Archivo | Funcion |
| --- | --- |
| `mywc.c` | Cuenta lineas, palabras y bytes de un fichero, inspirado en `wc`. |
| `myls.c` | Lista el contenido de un directorio, inspirado en `ls`. |
| `myishere.c` | Comprueba presencia de archivos o rutas. |
| `Makefile` | Compilacion de las utilidades. |
| `probador_ssoo_p1.py` | Script de pruebas de la practica. |

## Tecnologias

- C
- Makefile
- Python para pruebas
- Llamadas al sistema: `open`, `read`, `close`, `opendir`, `readdir`, `closedir`, `getcwd`

## Como Compilar

```bash
make
```

## Como Ejecutar

Ejemplos:

```bash
./mywc fichero.txt
./myls
./myls ruta/directorio
```

## Aprendizajes

- Leer ficheros byte a byte con llamadas al sistema.
- Recorrer directorios desde C.
- Gestionar argumentos de linea de comandos.
- Controlar errores de apertura, lectura y parametros invalidos.
- Automatizar pruebas para programas de terminal.

## Estado

Proyecto academico finalizado. Se conserva como practica introductoria de programacion de sistemas en C.