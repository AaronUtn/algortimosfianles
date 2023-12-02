#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Nodo{
    int info;
    Nodo*sig;
    Nodo*ant;
};
void insertarOrdenado(Nodo *& lista, char v);
void recorreArchivo(FILE* archivo);
void mostrar(Nodo * lista);

int main(){

    Nodo * lista = NULL;
    insertarOrdenado(lista, 'a');
    insertarOrdenado(lista, 'b');
    insertarOrdenado(lista, 'c');
    insertarOrdenado(lista, 'd');
    insertarOrdenado(lista, 'e');

    mostrar(lista);
    cout<<sizeof(Nodo)<<endl;
    char vec[]="hola";
    //int i =0;
    cout<<sizeof(vec)<<endl;
    int tamnio=sizeof(vec);
    //while(vec[i] != '\0'){
        
    //   cout<<"vec "<<vec[i]<<endl;
    //    i++;
    //}
    //cout<<i<<endl;
    for(int recorrer = 0; recorrer < tamnio;recorrer++){
        cout<<vec[recorrer]<<endl;
    }

    for(int i= tamnio-1;i>=0;i--){
        cout<<vec[i]<<endl;
    }
    
   /* FILE * archivo = fopen("archivo.dat","wb+");
    char caracter;
    cout<<"ingrese un caracter termina la carga con 0"<<endl;
    cin>>caracter;

    

    while(caracter != '0'){
        fputc(caracter,archivo);
        cout<<"ingrese un caracter termina la carga con 0"<<endl;
        cin>>caracter;
    }
    rewind(archivo);

    fread(&caracter,sizeof(char),1,archivo);
    cout<<"recorrido normal"<<endl;
    while(!feof(archivo)){
        cout<<"caracter:  "<<caracter<<endl;
       fread(&caracter,sizeof(char),1,archivo); 
    }
    fclose(archivo);

    recorreArchivo(archivo);*/
    return 0;
}


void recorreArchivo(FILE* archivo){
    archivo = fopen("archivo.dat","rb");
    fseek(archivo,0,SEEK_END);
    long tamanoArchivo = ftell(archivo);

    cout<<"tamanio arhcivo: "<<tamanoArchivo<<endl;
    char cadena;
    cout<<"recorrido inverso"<<endl;
    for(long i = (tamanoArchivo-1); i >= 0; i--){
       fseek(archivo,i,SEEK_SET);
        
        fread(&cadena,sizeof(char),1,archivo);
        cout<<"lo que tiene es: "<<cadena<<endl;
   }
    fclose(archivo);


}

void insertarOrdenado(Nodo *& lista, char v){
    cout<<"entra al insertar ordenado"<<endl;
    Nodo * nuevo = new Nodo();
    nuevo->info=v;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    Nodo* aux = lista;
    Nodo* ant=NULL;
    while(aux != NULL && aux->info < v){
        ant = aux;
        aux = aux->sig;
    }

    if(ant == NULL){
        lista = nuevo;
    }else if(aux==NULL){
       nuevo->ant=ant;
       nuevo->sig=aux;
       ant->sig=nuevo;

    }else{
       nuevo->ant=ant;
       nuevo->sig=aux;
       ant->sig=nuevo;
       aux->ant=nuevo;

    }
}

void mostrar(Nodo * lista){
    cout<<"entra al mostrar"<<endl;
    Nodo* aux = lista;
    Nodo*ant=NULL;
    while(aux != NULL){
        cout<<" "<<aux->info<<" "<<endl;
        ant=aux;
        aux=aux->sig;
    }
    while(ant != NULL){
        cout<<" "<<ant->info<<endl;
        ant=ant->ant;
    }
}