#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int potencia(int n, int m)
{
   //esta la necesite para un ejercicio. la invente yo
   int numero=n;
   if(m==0)
   {
      numero=1;
   }
   while(m>1)
   {
      numero=numero*n;
      m--;
   }
   return numero;
}

int length(string s)
{
   //contador de cadenas de texto
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }
   return i;
}

int charCount(string s,char c)
{
   //Cuenta la cantidad de veces que aparece un char en una palabra
   int i=0, cont=0;
   while(s[i]!='\0')
   {
      if(c==s[i])
      {
         cont++;
      }
      i++;
   }
   return cont;
}

string substring(string s,int d,int h)
{
   //Crea una cadena de texto a partir de dos posiciones dentro de una cadena
   string cadena="";
   while(d<h)
   {
      cadena = cadena + s[d];
      d++;
   }
   return cadena;
}

string substring(string s,int d) // ok
{
   //retorna la cadena desde la posicion d hasta el final
   string cadena="";
   while(s[d]!='\0')
   {
      cadena=cadena+s[d];
      d++;
   }
   return cadena;
}

int indexOf(string s,char c) // ok
{
   //retorna la posicion que ocupa la primera aparicion de c dentro de la cadena
   int i=0;
   while(s[i]!='\0')
   {
      if(s[i]==c)
      {
         return i;
      }
      else
      {
         i++;
      }
   }
   return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
   //retorna la posicion que ocupa la primera aparicion de c dentro de la cadena a
   //partir de una posicion
   while(s[offSet]!='\0')
   {
      if(s[offSet]==c)
      {
         return offSet;
      }
      else
      {
         offSet++;
      }
   }
   return -1;
}

int indexOf(string s,string toSearch)
{
   //Retorna la posición que ocupa la primera ocurrencia de toSearch dentro
   //de la cadena s.
   int pos=0;
   int i1=0, i2=0;
   int largoToS = length(toSearch);
   while(s[i1]!='\0')
   {
      if(s[i1]==toSearch[i2])
      {
         pos=i1;
         while(s[i1]==toSearch[i2])
         {
            if(i2+1==largoToS)
            {
               return pos;
            }
            i1++;
            i2++;
         }
         i1=pos;
         i2=0;
      }
      i1++;
   }
   return -1;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   //Retorna la posición que ocupa la primera ocurrencia de toSearch
   //dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-
   //miento inicial).
   int pos=0;
   int i1=offset, i2=0;
   int largoToS = length(toSearch);
   while(s[i1]!='\0')
   {
      if(s[i1]==toSearch[i2])
      {
         pos=i1;
         while(s[i1]==toSearch[i2])
         {
            if(i2+1==largoToS)
            {
               return pos;
            }
            i1++;
            i2++;
         }
         i1=pos;
         i2=0;
      }
      i1++;
   }
   return -1;
}

int lastIndexOf(string s,char c)
{
   //Retorna la posición de la última ocurrencia del carácter c dentro de s.
   int posAux;
   int pos=indexOf(s, c);
   if(pos<0)
   {
      return -1;
   }
   while(pos>=0)
   {
      posAux = indexOf(s, c, pos+1);
      if(posAux<0)
      {
         return pos;
      }
      pos=posAux;
   }
   return 0;
}

int indexOfN(string s,char c,int n)
{
   //Retorna la posición de la n-ésima ocurrencia de c dentro de s. Si n es 0
   //(cero) retorna -1; si n es mayor que la cantidad de ocurrencias de c retorna la longitud
   //de la cadena s.
   if(n==0)
   {
      return -1;
   }
   int i=1;
   int posAux, pos=indexOf(s, c);
   if(pos<0)
   {
      return -1;
   }
   while(i<n)
   {
      posAux=indexOf(s, c, pos+1);
      if(posAux>pos)
      {
         pos=posAux;
      }
      else if(posAux<0)
      {
         return length(s);
      }
      i++;
   }
   return pos;
}

int charToInt(char c)
{
   //Retorna el valor numérico que representa el carácter c.
   int num=0;
   if(c>=48 && c<=57)
   {
      num = c-48;
   }
   else if(c>=65 && c<=90)
   {
      num=c-55;
   }
   else if(c>=97 && c<=122)
   {
      num=c-87;
   }
   else
   {
      num=-1;
   }
   return num;
}

char intToChar(int i)
{
   //Retorna el carácter que representa al valor de i, que debe estar com-
   //prendido entre 0 y 9, o en entre 10 y 35. Es la función inversa de charToInt.
   char c='0';
   if(i>=0 && i<=9)
   {
      c=(char)i+48;
   }
   else if(i>=10 && i<=35)
   {
      c=(char)i+55;
   }
   return c;
}

int getDigit(int n,int i)
{
   //Retorna el i-ésimo dígito del valor de n.
   int v=0;
   while(v<=i)
   {
      if(v==i || n==0)
      {
         n=n%10;
         return n;
      }
      else
      {
         n=n/10;
      }
      v++;
   }
   return n;
}

int digitCount(int n)
{
   //Retorna la cantidad de dígitos que contiene el valor de n.
   int i=0;
   while(n!=0)
   {
      n=n/10;
      i++;
   }
   return i;
}

string intToString(int i)
{
   //Retorna una cadena de caracteres representando el valor i.
   string s="";
   /*
   int largo = digitCount(i);
   int num;
   int div=10;
   while(largo>2)
   {
      div=div*10;
      largo--;
   }
   while(div!=0)
   {
      num=i/div;
      i=i%div;
      div=div/10;
      s=s+to_string(num);
   }
   */
   s=to_string(i);
   return s;
}

int stringToInt(string s,int b) // ok
{
   //Retorna el valoro numérico representado en la cadena s, conside-
   //rando que dicho valor está expresado en la base numérica b.
   int i=0;
   int resultado=0;
   int largo=length(s);
   int digito;

   while(s[i]!='\0')
   {
      digito=charToInt((char)s[i]);
      resultado=resultado+digito*potencia(b,largo-1);
      largo--;
      i++;
   }
   return resultado;
}

int stringToInt(string s) // ok
{
   //Retorna el valor numérico de la cadena s, que sólo debe contener dí-
   //gitos numéricos en base 10. Esta función es la función inversa de intToString.
   int i;
   i = stringToInt(s, 10);
   return i;
}

string charToString(char c)
{
   //Retorna una cadena cuyo único carácter es c.
   string cadena=" ";
   cadena[0]=c;
   return cadena;
}

char stringToChar(string s)
{
   //Retorna el único carácter que contiene la cadena s. Esta es la función
   //inversa de charToString.
   char c=' ';
   c=(char)s[0];
   return c;
}

string stringToString(string s)
{
   //Retorna la misma cadena que recibe
   return s;
}

string doubleToString(double d)
{
   //Retorna una cadena representando el valor contenido en d.
   return "";
}

double stringToDouble(string s)
{
   //Retorna el valor numérico representado en la cadena s.
   int pos = indexOf(s, '.');
   string entero = substring(s, 0, pos);
   string decimal = substring(s, pos+1, length(s));
   double numero = stringToInt(entero) + (double)stringToInt(decimal)/( potencia(10,length(decimal)) );
   return numero;
}

bool isEmpty(string s)
{
   //Retorna true o false según s sea o no la cadena vacía.
   if(s=="")
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool startsWith(string s,string x)
{
   //Determina si x es prefijo de s.
   if(s[0]==x[0])
   {
      if(indexOf(s, x)==0)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else
   {
      return false;
   }
}

bool endsWith(string s,string x)
{
   //Determina si x es sufijo de s.
   int largoS=length(s);
   int largoX=length(x);
   int inicioCoincidencia=largoS-largoX;
   if(s[largoS-1]==x[largoX-1] && inicioCoincidencia>=0)
   {
      if(indexOf(s, x, inicioCoincidencia)==inicioCoincidencia)
      {
         return true;
      }
   }
   return false;
}

bool contains(string s,char c)
{
   //Determinar si la cadena s contiene al carácter c.
   if(indexOf(s,c)>=0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

string replace(string s,char oldChar,char newChar)
{
   //Reemplaza en s todas las ocurrencias de oldChar por newChar.
   int offSet=0;
   int i=0;
   int pos=0;
   while(s[i]!='\0')
   {
      pos= indexOf(s, oldChar, offSet);
      if(pos>=0)
      {
         s[pos]=newChar;
         offSet=pos+1;
      }
      i++;
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   //Insertar el carácter c en la posición pos de la cadena s.
   string principio=substring(s,0,pos);
   string final=substring(s,pos,length(s));
   s=principio+c+final;
   return s;
}

string removeAt(string s,int pos)
{
   //Una cadena igual a s pero sin s[pos].
   string principio;
   principio=substring(s,0,pos);
   string final;
   final=substring(s,pos+1,length(s));
   s=principio+final;
   return s;
}

string ltrim(string s)
{
   //Recorta los espacios en blanco que se encuentren a la izquierda de s.
   while(s[0]==' ')
   {
      s=removeAt(s,0);
   }
   return s;
}

string rtrim(string s)
{
   //Recortar los espacios en blanco a la derecha de s.
   while(s[length(s)-1]==' ')
   {
      s=removeAt(s, length(s)-1);
   }
   return s;
}

string trim(string s)
{
   //Recortar los espacios en blanco ubicados a izquierda y derecha de s.
   s=rtrim(s);
   s=ltrim(s);
   return s;
}

string replicate(char c,int n)
{
   //Generar una cadena de caracteres compuesta por n caracteres c.
   int i=0;
   string s="";
   while(i<n)
   {
      s=s+c;
      i++;
   }
   return s;
}

string spaces(int n)
{
   //Genera una cadena compuesta por n caracteres ' '
   string s = replicate(' ', n);
   return s;
}

string lpad(string s,int n,char c)
{
   //Retorna una cadena idéntica a s, con longitud n completando, si fuese
   //necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
   while(n>length(s))
   {
      s=insertAt(s, 0, c);
   }
   return s;
}

string rpad(string s,int n,char c)
{
   //Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.
   while(n>length(s))
   {
      s=insertAt(s, length(s), c);
   }
   return s;
}

string cpad(string s,int n,char c)
{
   //Idem rpad pero distribuye los caracteres c a izquierda y derecha.
   while(n>length(s))
   {
      s=rpad(s,length(s)+1,c);
      if(length(s)<n)
      {
         s=lpad(s,length(s)+1,c);
      }
   }
   return s;
}

bool isDigit(char c)
{
   //Determinar si el valor de c corresponde o no a un dígito numérico.
   if(c>=48 && c<=57)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLetter(char c)
{
   //Determina si el valor de c corresponde o no a una letra.
   if((c>=65 && c<=90) || (c>=97 && c<=122))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isUpperCase(char c)
{
   //Determinar si el valor de c corresponde a una letra mayúscula.
   if(c>=65 && c<=90)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLowerCase(char c)
{
   //Determina si el valor de c corresponde a una letra minúscula.
   if(c>=97 && c<=122)
   {
      return true;
   }
   else
   {
      return false;
   }
}

char toUpperCase(char c)
{
   //Convertir el valor de c a mayúscula.
   if(isLowerCase(c))
   {
      c=c-32;
   }
   return c;
}

char toLowerCase(char c)
{
   //Convierte el valor de c a minúscula.
   if(isUpperCase(c))
   {
      c=c+32;
   }
   return c;
}

string toUpperCase(string s)
{
   //Retorna una cadena idéntica a s pero completamente en mayúsculas.
   int i=0;
   while(s[i]!='\0')
   {
      s[i]=toUpperCase((char)s[i]);
      i++;
   }
   return s;
}

string toLowerCase(string s)
{
   //Retorna una cadena idéntica a s pero completamente en minúsculas.
   int i=0;
   while(s[i]!='\0')
   {
      s[i]=toLowerCase((char)s[i]);
      i++;
   }
   return s;
}

int cmpString(string a,string b)
{
   //Compara alfabéticamente dos cadenas.
   int i=0;
   while(a[i]!='\0' && b[i]!='\0')
   {
      char cha=a[i], chb=b[i];
      if(charToString(cha)<charToString(chb))
      {
         return -1;
      }
      else if(charToString(cha)>charToString(chb))
      {
         return 1;
      }
      i++;
   }
   if(a[i]=='\0' && b[i]!='\0')
   {
      return -1;
   }
   else if(a[i]!='\0' && b[i]=='\0')
   {
      return 1;
   }
   return 0;
}

int cmpDouble(double a,double b)
{
   //Compara dos valores.
   if(a<b)
   {
      return -1;
   }
   else if(b<a)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#endif
