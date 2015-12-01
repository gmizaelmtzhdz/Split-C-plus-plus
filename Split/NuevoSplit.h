//Created on: 2015
//Author: Mizael Martinez

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

class NuevoSplit
{
	private: 
		int longitud;
		int inicio;
		int fin;
		int numero_de_datos;
		char caracter_delimitador;
	public: 
		NuevoSplit(char *cadena,int longitud,char caracter_delimitador);
		int numeroDatos(char *cadena);
		char * siguienteDato(char *cadena);
		void substring_t(char *cadena,char *nueva,int inicio,int fin);
		int indexOf_shift (char* base, char* caracter, int startIndex);
		int getNumeroElementos();
		void split(char *cadena,char **arreglo);
		
};
NuevoSplit::NuevoSplit(char *cadena,int longitud,char caracter_delimitador)
{
  this->longitud=longitud;
  this->caracter_delimitador=caracter_delimitador;
  this->numeroDatos(cadena);
  this->inicio=0;
  this->fin=0;
}
void NuevoSplit::split(char *cadena,char **arreglo)
{
	for(int i=0;i<this->numero_de_datos;i++)
	{
		arreglo[i]=this->siguienteDato(cadena);
	}
}
int NuevoSplit::numeroDatos(char *cadena)
{
         int numero=0;
         for(unsigned i=0;i<this->longitud;i++)
         {
             if(cadena[i] == this->caracter_delimitador)
                numero++;
         }
	this->numero_de_datos=numero+1;	
        return numero+1;
}
char * NuevoSplit::siguienteDato(char *cadena)
{
	char caracter[2];
	caracter[0]=this->caracter_delimitador;
	caracter[1]='\0';
	this->fin=this->indexOf_shift(cadena,caracter,this->inicio);	
	if(this->fin<0)
        	this->fin=this->longitud;
	char *resultado=(char*) malloc (fin-inicio+1);
	substring_t(cadena,resultado,this->inicio,this->fin);
	this->inicio=this->fin+1;  
	return resultado;                       
}
void NuevoSplit::substring_t(char *cadena,char *nueva,int inicio,int fin)
{
	int tamano=fin-inicio+1;
	int contador=0;
	char subcadena[tamano];
	int longitud=strlen(cadena);
	for(int i=inicio;i<fin;i++)
	{
		subcadena[contador]=cadena[i];
		nueva[contador]=cadena[i];
		contador++;
	}
	nueva[contador]='\0';
}

int NuevoSplit::indexOf_shift (char* base, char* caracter, int startIndex)
{
	int result;
	int baselen = strlen(base);
	if (strlen(caracter) > baselen || startIndex > baselen) {
		result = -1;
	} else {
		if (startIndex < 0 ) {
			startIndex = 0;
		}
		char* pos = strstr(base+startIndex, caracter);
		if (pos == NULL) {
			result = -1;
		} else {
			result = pos - base;
		}
	}
	return result;
}
int NuevoSplit::getNumeroElementos()
{
	return this->numero_de_datos;
}
