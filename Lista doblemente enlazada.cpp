#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
	int dato;
	struct Nodo *siguiente;
	struct Nodo *atras;
}*primero,*ultimo;

void insertarNodo(){
	Nodo *nuevo= new Nodo();
	cout<<"Ingresa el valor del Nodo: ";
	cin>>nuevo->dato;
	
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		primero->atras=NULL;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		nuevo->atras=ultimo;
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
			actual=actual->atras;
		}	
	}else{
		cout<<"\nLa lista se encuentra vacia\n\n";
	}
}

void eliminar(){
	Nodo *actual=new Nodo();
	actual=primero;
	Nodo *anterior=new Nodo();
	anterior=NULL;
	int buscar=0;
	bool encontrado=false;
	cout<<"Ingrese el nodo a eliminar: ";
	cin>>buscar;
	if(primero!=NULL){
		while(actual!=NULL && encontrado==false){
			if(actual->dato==buscar){
				if(actual==primero){
					primero=primero->siguiente;
					primero->atras=NULL;
				}else if(actual==ultimo){
					anterior->siguiente=NULL;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
					actual->siguiente->atras=anterior;
				}
				encontrado=true;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(!encontrado){
			cout<<"\nEl nodo a eliminar no existe en la lista\n";
		}
	}else{
		cout<<"\nLa lista se encuentra vacia\n\n";
	}
}

void menu(){
    cout<<"\nMenú de opciones \n"<<endl;
    cout<<"1 Insertar nodo \n"<<"2 Mostrar listas \n"<<"3 Eliminar nodo \n"<<"4 Salir \n"<<endl;
    cout<<"Elige una opción del menú: \n"<<endl;
}

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
			cout<<"\n\n"<<endl;
			system("pause");
		}else if(opcion==3){
			system("CLS");
			eliminar();
			cout<<"\nNodo eliminado\n"<<endl;
			system("pause");
		}else {
			break;
		}
	}
	return 0;
	getch();
}
