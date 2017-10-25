# Split-C-Arduino
Clase para simular la función split en Javascript o explode de Php
Primero se tiene que importar como libreria he invocarla: 

    #include<Split.h>
    
Para mandar llamar la clase desde Arduino: 
    
    String aux="A,B,C,D,E,F,G,H,I,J";
    Split m(aux,',');
    String * elementos=new String[m.getNumeroElementos()];
    m.split(&elementos);
    for(int j=0;j<m.getNumeroElementos();j++)
    {
      Serial.println(elementos[j]);    
    }    


Nuevo Split

    
    #include<NuevoSplit.h>
    
    String aux="A,B,C,D,E,F,G,H,I,J";
    char buf[aux.length()];
  	aux.toCharArray(buf,aux.length()+1);
	buf[aux.length()]='\0';
  	NuevoSplit s(buf,aux.length(),',');
	char **arreglo=(char**) calloc(s.getNumeroElementos(), sizeof(char*));
  	s.split(buf,arreglo);
  	for(unsigned i=0;i<s.getNumeroElementos();i++)
	{
		Serial.println(arreglo[i]);
	}
