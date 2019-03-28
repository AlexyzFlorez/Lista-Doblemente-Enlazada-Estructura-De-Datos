#include <iostream>

struct nodo  //Es la estructura del nodo, guarda el dato y la direccion siguiente 
{
	int dato;
	nodo *sig;
	nodo *ant;
}
;

using namespace std;
class ClaseLista
{
	private:
		nodo *final;
		nodo *frente;
		
	
	public:
		ClaseLista();
		void agregar_frente(int);
		void agregar_final(int);
		void mostrar();
		void sacar_especifico(int);
		void sacar_frente();
		void sacar_final();
		bool vacia();
	    ~ClaseLista();	
};
//--------------------------------------------------
ClaseLista::ClaseLista()
{
	final=new nodo;
	frente=final;
	final->ant=NULL;
	final->sig=NULL;
}
//--------------------------------------------------------
ClaseLista::~ClaseLista()
{
	nodo *tem;
	
	do{
		tem=frente->sig;
		delete frente;
		frente=tem;
		
	}while(frente!=final);
	
	delete tem;
}
//--------------------------------------------------
bool ClaseLista::vacia()
{
   if((frente->ant==NULL) && (frente->sig==NULL))
   {
   	return 1;
   }
   else
   {
   	return 0;
   }
}
//-------------------------------------------------------
void ClaseLista::agregar_final(int elemento)
{
	nodo *temp;

	temp=new nodo;
	final->dato=elemento;
	final->sig=temp;
	temp->ant=final;
	temp->sig=NULL;
	final=temp;
}
//-------------------------------------------------------
void ClaseLista::agregar_frente(int elemento)
{
	nodo *temp;
	
	temp=new nodo;
	temp->dato=elemento;
	temp->sig=frente;
	temp->ant=NULL;
	frente->ant=temp;
	frente=temp;
}
//-----------------------------------------------------
void ClaseLista::sacar_especifico(int ele)
{
	nodo *t=frente;
	nodo *te=frente;
	nodo *tempo;
	
   if(vacia()==1)
   {
   	cout<<"No Es Posible Sacar Este Elemento, La Lista Esta Vacia\n"<<endl;
   }
   else
   {
   	  do{
   	  	   if((t->dato==ele) && (frente->ant==NULL))
   	  	   {
   	  	   	frente=t->sig;
   	  	   	delete t;
   	  	   	frente->ant=NULL;
   	  	   	t=final;
		   }
		   else
		   {
		      t=t->sig;
		      tempo=t->sig;
		      
		      if(t==final)
		      {
		      	cout<<"Este Dato No Existe En La Lista\n"<<endl;
			  }
		      if(t->dato==ele)
		      {
		      	te->sig=t->sig;
		      	tempo->ant=t->ant;
		      	delete t;
		      	t=final;
		      	cout<<"Dato Sacado\n"<<endl;
		      }
			  else
			  {
			  
		      	te=te->sig;
		      }
			}
	
		}while(t!=final);
		
}
   
}
//----------------------------------------------------
void ClaseLista::sacar_final()
{
	nodo *t;
	nodo *te;
if(vacia()==1)
{
	cout<<"La Lista Esta Vacia\n"<<endl;
}
else
{


	if(frente->sig==final)
	{
		final->ant=NULL;
		delete frente;
		frente=final;
		
		cout<<"El Dato Fue Sacado De La Lista\n"<<endl;
	}
	else
	{
	    t=final->ant;
	    te=t->ant;
	    final->ant=te;
        te->sig=final;
	    delete t;
	
	    cout<<"El Dato Fue Sacado De La Lista\n"<<endl;
    }
}
}
//-----------------------------------------------------
void ClaseLista::sacar_frente()
{
	nodo *tem;
if(vacia()==1)
{
	cout<<"La Lista Esta Vacia\n"<<endl;
}	
else
{

	if(frente->sig==final)
	{
		final->ant=NULL;
		delete frente;
		frente=final;
		
		cout<<"El Dato Fue Sacado De La Lista\n"<<endl;
	}
	else
	{
		tem=frente->sig;
		tem->ant=NULL;
		frente=tem;
		
		cout<<"El Dato Fue Sacado De La Lista\n"<<endl;
		
	}
}
}
//-----------------------------------------------------
void ClaseLista::mostrar()
{
	if(vacia()==1)
	{
		cout<<"La Lista Esta Vacia\n"<<endl;
	}
	else
	{
		nodo *temporal=frente;
		
		cout<<"La Lista Actualmente Se Encuentra De La Siguiente Manera\n"<<endl;
		do{
			
			cout<<temporal->dato<<"|";
			temporal=temporal->sig;
			
		}while(temporal!=final);
		
		cout<<"\n"<<endl;
	}
}



int main(int argc, char** argv)
{
	int opc,a,s;
	ClaseLista lis;
	
	do
	{
	
	cout<<"Lista Doblemente Enlazada\n"<<endl;
	
	cout<<"MENU\n"<<endl;
	
    cout<<"1°Agregar Dato Al Final"<<endl;
    cout<<"2°Agregar Dato Al Inicio"<<endl;
	cout<<"3°Sacar Dato Final"<<endl;
	cout<<"4°Sacar Dato Inicial"<<endl;
	cout<<"5°Sacar Dato Especifico"<<endl;
	cout<<"6°Mostrar Lista"<<endl;
	cout<<"7°Salir"<<endl;
	
	cout<<"\nElije una opcion"<<endl;
	cin>>opc;
	
	system("cls");
	
	switch(opc)
	{
		case 1:
			{
				cout<<"Inserta El Dato"<<endl;
			    cin>>a;
			
			    lis.agregar_final(a);
			    cout<<"\n";
			    
			    system("pause");
			    break;
			}
		case 2:
		    {
		    	 cout<<"Inserta El Dato"<<endl;
				 cin>>a;
				 
				 lis.agregar_frente(a);
				 cout<<"\n"; 
		         system("pause");	
		         break;	
		    }
		case 3:
		    {
		        lis.sacar_final();
		        
		 	    system("pause");
		 	    break;	 
		    }
		 case 4:
		    {
		    	lis.sacar_frente();
		    	system("Pause");
		    	break;
			}   
		case 5:
		    {
		    	cout<<"Inserta El Elemento Que Deseas Sacar"<<endl;
		    	cin>>s;
		    	
		    	cout<<"\n";
		    	
		        lis.sacar_especifico(s);
		        
		    	system("pause");
		    	break;
			}
		case 6:
		    {
		    	lis.mostrar();
		    	system("pause");
		    	break;
			}		
		    
}
system("cls");
}while(opc<7);
	return 0;
}
