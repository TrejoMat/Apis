#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   char separador='|';
   int tamanio = 0;
   bool existeProximo = false;
   string coleccion="";
   int coleccion_i=0;

};

template<typename T>
Coll<T> coll(char sep)
{
   //retorna una coleccion lista para usarse con el tipo de dato T y con un separador especifico
   Coll<T> c;
   c.separador=sep;
   return c;
}

template<typename T>
Coll<T> coll()
{
   //retorna una coleccion lista para usarse con el tipo de dato T
   Coll<T> c;
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   //retorna la cantidad de elementos dentro de la coleccion
   return c.tamanio;
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   //limpia una coleccion
   c.coleccion = "";
   c.tamanio=0;
   c.existeProximo=false;
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   //remueve cierto elemento de la coleccion c que se encuentre en la pos p
   removeTokenAt(c.coleccion, c.separador, p);
   c.tamanio--;
   c.existeProximo=collHasNext(c);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   //agrega un elemento al final de la coleccion y devuelve la posicion
   addToken(c.coleccion, c.separador, tToString(t));
   c.tamanio++;
   c.existeProximo = true;
   return c.tamanio;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   //cambia un elemento de la coleccion por otro
   setTokenAt(c.coleccion, c.separador, tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   //devuelve un elemento de la coleccion en la pos p
   string tk=getTokenAt(c.coleccion, c.separador, p);
   T t = tFromString(tk);
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   //TODAVIA NO LA PROBÉ NO SE SI FUNCIONA
   //Determina si la colección c contiene al elemento k. Retorna la pos de la primera
   // ocurrencia o -1 en caso de que k no este incluida en c
   for(int i=0; i<collSize(c); i++)
   {
      T t = collGetAt(c, i, tFromString);
      if(cmpTK(t, k)==0)
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   //Retorna True o False dependiendo de si tiene una proxima entidad o no
   if(c.coleccion_i < c.tamanio)
   {
      c.existeProximo=true;
   }
   else
   {
      c.existeProximo=false;
   }
   return c.existeProximo;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   //retorna el proximo valor de tipo T que sigue en la coleccion
   T t;
   if(collHasNext(c))
   {
      t = collGetAt(c, 0, tFromString);
      c.coleccion_i++;
   }
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   //retorna el proximo valor de tipo T que sigue en la coleccion y si existe un prox numero
   T t = collNext(c, tFromString);
   endOfColl = collHasNext(c);
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.coleccion_i=0;
}

template<typename T>
void collShow(Coll<T> c, T tFromString(string), string tToString(T))
{
   //La agregue yo, muestra por pantalla todos los elementos de c
   for(int i=0; i<collSize(c) ; i++)
   {
      string t = tToString(collGetAt(c, i, tFromString));
      cout<<t<<endl;
   }
}


template<typename T>
string collToString(Coll<T> c)
{
   return c.separador='|'+c.coleccion="";
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.separador='|'=s[0];
   c.coleccion=""=substring(s,1);
   return c;
}


#endif
