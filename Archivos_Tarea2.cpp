//el programa logra guardar la informacion y el puntero de memoria, pero no sabe
//como interpretar dicha informacion y no muestra lo que debe en pantalla, por
//la misma razon no quise agregar el campo de actualizar y borrar ya que el programa 
//no logra hacer lo que debe
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void leer();
void crear();

const char *nom_arch="archivo.dat";

struct Estudiante{
	int *codigo;
	string *nombres;
	string *apellidos;
	string *direccion;
	string *telefono;
};
int cant=0;
main(){
	leer();
	crear();
}

void leer(){
	int id=cant;
	
	Estudiante estudiante;
	Estudiante estudiante1;

	estudiante1.codigo=new int[id];
	estudiante1.nombres=new string[id];
	estudiante1.apellidos=new string[id];
	estudiante1.direccion=new string[id];
	estudiante1.telefono=new string[id];

	system("cls");
	FILE* archivo=fopen(nom_arch,"rb");
	if(!archivo){
		archivo=fopen(nom_arch,"w+b");
	}
	
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"id"<<" | "<<"codigo"<<" | "<<"Nombres"<<" | "<<"Apellidos"<<" | "<<"Direccion"<<" | "<<"Telefonos"<<endl;
	do{
//		for(int i=0; i<cant;i++){
		cout<<"________________________________________________________________\n";
		cout<<id<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;	
		//leer el registro del archivo y asignarlo al puntero de memoria
/*        estudiante1.codigo[i] = estudiante.codigo;
        estudiante1.nombres[i] = estudiante.nombres;
        estudiante1.apellidos[i] = estudiante.apellidos;
        estudiante1.direccion[i] = estudiante.direccion;
        estudiante1.telefono[i] = estudiante.telefono;*/
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id++;
//		}

	}while(feof(archivo)==0);
	fclose(archivo);
	//leer el puntero de memoria y escribir los datos en la pantalla
/*
	for(int i=0; i<cant;i++){
		cout<<"________________________________________________________________\n";
		cout<<i<<" | "<<estudiante1.codigo[i]<<" | "<<estudiante1.nombres[i]<<" | "<<estudiante1.apellidos[i]<<" | "<<estudiante1.direccion[i]<<" | "<<estudiante1.telefono[i]<<endl;	
	}	
*/	
}                

void crear(){
	int dato=0;
	cout<<"cantidad: ";
	cin>>dato;
	cant=dato;
	Estudiante estudiante;
	estudiante.codigo=new int[dato];
	estudiante.nombres=new string[dato];
	estudiante.apellidos=new string[dato];
	estudiante.direccion=new string[dato];
	estudiante.telefono=new string[dato];
	
	FILE* archivo=fopen(nom_arch,"ab");
	char con;

	do{
		fflush(stdin);
		for(int i=0;i<dato;i++){
			cout<<"________________________________________________________________\n";
			cout<<"Ingrese el codigo del estudiante: ";
			cin>>estudiante.codigo[i];
			cin.ignore();
			cout<<"Ingrese los nombres del estudiante: ";
			getline(cin,estudiante.nombres[i]);
			cout<<"Ingrese los apellidos del estudiante: ";
			getline(cin,estudiante.apellidos[i]);
			cout<<"Ingrese la direccion del estudiante: ";
			getline(cin,estudiante.direccion[i]);
			cout<<"Ingrese el numero de telefono: ";
			cin>>estudiante.telefono[i];
			cin.ignore();
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		}
		cout<<"Desea agregar otro estudiante (s/n): ";
		cin>>con;
		//dato++;
	}while(con=='s'||con=='S');
	delete[] estudiante.codigo;
	delete[] estudiante.nombres;
	delete[] estudiante.apellidos;
	delete[] estudiante.direccion;
	delete[] estudiante.telefono;
	
	fclose(archivo);
	leer();
	
}













