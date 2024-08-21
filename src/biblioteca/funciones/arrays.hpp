#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len++] = e;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   int posActual = len+1;
   while(posActual>p)
   {
      arr[posActual] = arr[posActual-1];
      posActual--;
   }
   len++;
   arr[p] = e;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret;
   ret = arr[p];
   int posActual = p;
   while(posActual<len)
   {
      arr[posActual] = arr[posActual+1];
      posActual++;
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   for(int i=0; i<len; i++)
   {
      if( cmpTK(arr[i], k)==0 )
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int pos;
   for(int i=0; i<len; i++)
   {
      T aComp = arr[i];
      int comparacion = cmpTT(e, aComp);
      if(comparacion <= 0)
      {
         insert<T>(arr, len, e, i);
         pos = i;
         break;
      }
   }
   return pos;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   int sortedLen=0;
   T sortedArr[len];

   for(int i=0; i<len; i++)
   {
      T elemento = arr[i];
      if(i==0)
      {
         add<T>(sortedArr, sortedLen, elemento);
      }
      else
      {
         bool agregado = false;
         for(int x=0; x<=sortedLen; x++)
         {
            T elementoComp = sortedArr[x];
            int comp = cmpTT(elemento, elementoComp);
            if(comp<=0)
            {
               insert<T>(sortedArr, sortedLen, elemento, x);
               agregado = true;
               break;
            }
         }
         if(agregado==false)
         {
            add<T>(sortedArr, sortedLen, elemento);
         }
      }
   }
   for(int i=0; i<len; i++)
   {
      arr[i] = sortedArr[i];
   }
   return;
}



#endif
