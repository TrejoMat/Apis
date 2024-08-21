#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   //Cuenta la cantidad tokens que el separador sep genera en s.
   if(s=="")
   {
      return 0;
   }
   int cantSep = charCount(s, sep);
   int i = cantSep+1;
   return i;
}

void addToken(string& s,char sep,string t)
{
   //Agrega el token t al final de la cadena s.
   if(s!="")
   {
      s=s+sep+t;
   }
   else
   {
      s=t;
   }
}

string getTokenAt(string s,char sep, int i)
{
   //Retorna el i-ésimo token de la cadena tokenizada s.
   string t;
   int posFinal,posInicio;
   if(indexOf(s, sep)<0)
   {
      return s;
   }
   else if(i==0)
   {
      posInicio=0;
      posFinal=indexOf(s,sep);
      t = substring(s, posInicio, posFinal);
   }
   else
   {
      posInicio = indexOfN(s,sep,i);
      posFinal = indexOfN(s,sep,i+1);
      t = substring(s, posInicio+1, posFinal);
   }
   return t;
}

void removeTokenAt(string& s,char sep, int i)
{
   //Remueve de s el token ubicado en la posición i.
   int posInicio, posFinal;
   if(indexOf(s, sep)<0 && i==0)
   {
      s="";
      return;
   }
   else if(i!=0)
   {
      posInicio = indexOfN(s,sep,i);
      posFinal = indexOfN(s,sep,i+1);
   }
   else
   {
      posInicio = 0;
      posFinal = indexOf(s,sep);
   }
   while(posFinal>posInicio)
   {
      if(posInicio+1!=posFinal)
      {
         s=removeAt(s,posInicio+1);
         posFinal = indexOfN(s,sep,i+1);
      }
      else
      {
         s=removeAt(s,posInicio+1);
         posFinal--;
      }
   }
   if(i==0)
   {
      s=removeAt(s, 0);
   }
   if(endsWith(s, "|"))
   {
      s=removeAt(s,length(s)-1);
   }
}

void setTokenAt(string& s,char sep, string t,int i)
{
   //Reemplaza por t el token de s ubicado en la posición i.
   removeTokenAt(s,sep,i);
   if(i==0)
   {
      addToken(t,sep,s);
      s=t;
   }
   else if(i==1 && i==tokenCount(s, sep))
   {
      addToken(s, sep, t);
   }
   else
   {
      string principio = substring(s, 0, indexOfN(s,sep,i));
      string final = substring(s, indexOfN(s,sep,i), length(s));
      addToken(principio, sep, t);
      s=principio+final;
   }
}

int findToken(string s,char sep, string t)
{
   //Determinar la posición que el token t ocupa dentro de la cadena s.
   int i=0;
   if(t=="")
   {
      return -1;
   }
   while(i<=tokenCount(s,sep))
   {
      string tok = getTokenAt(s,sep,i);
      if(tok==t)
      {
         return i;
      }
      i++;
   }
   return -1;
}

#endif
