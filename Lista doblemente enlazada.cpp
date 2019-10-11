#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	struct Nodo *siguiente;
	struct Nodo *anterior;
}*primero,*ultimo;

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
	delete ultimo;
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

void menu(){
    cout<<"\nMenú de opciones \n"<<endl;
    cout<<"1 Insertar nodo \n"<<"2 Mostrar listas \n"<<endl;
    cout<<"Elige una opción del menú: \n"<<endl;
}
Nodo l1;
int main(){
	char *locale;
    locale=setlocale(LC_ALL,"");
	int opcion;
	int repetir=true;
	while(repetir){
		system("CLS");
		menu();
		cin>>opcion;
		if(opcion==1){
            system("CLS");
			insertarNodo();	
		}else if(opcion==2){
			system("CLS");
			cout<<"Lista del primer a ultimo elemento"<<endl;
			desplegarListaPU();
			cout<<"\n\nLista del ultimo al primer elemento"<<endl;
			desplegarListaUP();
			system ("pause");
		}else {
			break;
		}
	}
	return 0;
}
