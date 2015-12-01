//Created on: 2015
//Author: Mizael Martinez
class Split{
	private: 
		int inicio;
		int fin;
		String cadena;
		char caracter_delimitador;
		int numero_de_datos;
		int arregloIndex[];
		int longitud;
	public: 
		Split(String cadena,char caracter_delimitador);
		int numeroDatos();
		String siguienteDato();
		void split(String **arreglo);
		int getNumeroElementos();
 
};
Split::Split(String cadena,char caracter_delimitador)
{

	this->inicio=0;
	this->fin=0;
	this->longitud=0;
	this->cadena=cadena;
	this->caracter_delimitador=caracter_delimitador;
	this->numeroDatos();
}
int Split::numeroDatos()
{
    int numero=0;
    for(unsigned i=0;i<this->cadena.length();i++)
    {
	   	 this->longitud++;
         if(this->cadena.charAt(i) == this->caracter_delimitador)
            numero++;
    }
	if(this->cadena.length()==0)
            numero=-1;
	this->numero_de_datos=numero+1;	
         return numero+1;
}
String Split::siguienteDato()
{
		String resultado="";
        this->fin=this->cadena.indexOf(this->caracter_delimitador,this->inicio+1);
        if(this->fin<0)
        {
         this->fin=this->longitud;
         resultado=this->cadena.substring(this->inicio,this->fin);
        }
        else 
        {
         resultado=this->cadena.substring(this->inicio,this->fin);
        }
        this->inicio=this->fin+1;   
        return resultado;                         
}
void Split::split(String **arreglo)
{
	
        if(this->longitud>0)
        {
            for(int i=0;i<this->longitud;i++)
            {
				(*arreglo)[i]=this->siguienteDato();
            }
        }
}
int Split::getNumeroElementos()
{
	return this->numero_de_datos;
}
