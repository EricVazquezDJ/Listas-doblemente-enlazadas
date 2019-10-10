#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	struct Nodo *siguiente;
	struct Nodo *anterior;
}*primero,*ultimo;

void insertarNodo();
void desplegarListaPU();
void desplegarListaUP();

int main(){
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	cout<<"Lista del primer a ultimo elemento"<<endl;
	desplegarListaPU();
	cout<<"\n\nLista del ultimo al primer elemento"<<endl;
	desplegarListaUP();

	return 0;
}

void insertarNodo(){
	Nodo *nuevo= new Nodo();
	cout<<"Ingresa el valor del Nodo: ";
	cin>>nuevo->dato;
	
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		primero->anterior=NULL;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
	cout<<"\nNodo agregado\n"<<endl;
}

void desplegarListaPU(){
	Nodo *actual=new Nodo();
	actual=primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout<<"\n"<<actual->dato; 
			actual=actual->siguiente;
		}
	}else{
		cout<<"\nLa lista se encuentra vacia\n\n";
	}
}

void desplegarListaUP(){
	Nodo *actual= new Nodo();
	actual=ultimo;
	if(primero!=NULL){
		while(actual!=NULL){
			cout<<"\n"<<actual->dato; 
			actual=actual->anterior;
		}	
	}else{
		cout<<"\nLa lista se encuentra vacia\n\n";
	}
}
