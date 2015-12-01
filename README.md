# Split-C-Arduino
Clase para simular la función split en Javascript o explode de Php
Primero se tiene que importar como libreria eh invocarla: 

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
