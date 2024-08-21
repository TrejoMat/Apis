#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

//un archivo es un conjunto de bytes asociado a un nombre almacenados en el disco rigido
//FILE* f = fopen("K1030.x","w+b"); Crea un archivo o pisa
//FILE* f = fopen("K1030.x","r+b"); Toma un archivo existente
//Archivos de registro: cada dato es una ficha. Hay de *LONGITUD FIJA* y de longitud variable


template<typename T> void write(FILE* f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);

}

template<typename T> T read(FILE* f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t, sizeof(T), 1, f);
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   //Mueve el indicador de posición del archivo f al inicio del registro n.
   int elemento = sizeof(T);
   fseek(f, elemento*n, SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
   //Retorna la cantidad de registros tipo T que contiene el archivo.
   int l, i;
   i = ftell(f);
   fseek(f, 0, SEEK_END);
   l = ftell(f);
   fseek(f, i, SEEK_SET);

   return l / sizeof(T);
}

template<typename T> int filePos(FILE* f)
{
   //Retorna el número de registro que está siendo apuntado por el indicador
   //de posición del archivo f.
   int i = ftell(f) / sizeof(T);
   return i;
}

#endif
