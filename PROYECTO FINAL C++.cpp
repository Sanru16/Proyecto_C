/*Este es el proyecto de Raúl González y Santiago gonzález de 2ºBACH B del IES MARÍA MOLINER.*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
void escribir();//mencionamos las funciones que tendrá el menú
void leer();
using namespace std;



class Alumno{ //creamos la clase alumno

	private://características privadas de la clase alumno 
		string nombre;
		string apellido;
	public://características públicas de la clase alumno 
		Alumno(string,string);
		void mostrarAlumno();	
};

Alumno::Alumno(string _nombre,string _apellido){//utilizamos el contructor
	nombre = _nombre;
	apellido = _apellido; 
	
}

void Alumno::mostrarAlumno(){//definimos la función mostrarAlumnos que está definida dentro de la clase Alumno
	
	cout << "Nombre completo: " << nombre << apellido << endl;
	
	
}


int main(){

		int n;
	
	do{    //menú con 3 opciones
		cout<<"\n";
		cout<<"*Clases IES MARIA MOLINER*"<< endl;
		cout<<" 1.- crear y escribir en un archivo nuevo por cada clase que haya en tu instituto "<< endl;
		cout<<" 2.- leer el listado de alumnos de la clase que elijas							 "<< endl;
		cout<<" 3.- salir del menu								 					  			 "<< endl;
		cout<<"Selecciona una opcion: ";
		cin>>n;
		cin.ignore(256, '\n');
		
		switch(n){
			case 1: escribir();//la primera opcion está definida por la función escribir con la que podrás crear y escribir un nuevo archivo/fichero
				break;
			case 2: leer();//la segunda opcion está definifda por la función leer con la que pordrás ver un fichero/archivo antes creado
				break;
			case : cout<<"Has salido del menu!";
				break;
			default: cout<<"\nEsa opcion no esta en el menu!!!\n";
				break;
		}
	}
		while(n !=4);
		system("pause");
		return 0;
				
	
}

void escribir(){//definimos la función escribir

	int num = 0;//nombramos todas las variables que vayamos a utilizar
	string nombre;
	string apellido;
	ofstream archivo;
	string nombreArchivo;
	string linea;
	
	cout<<"Nombre del archivo que quieres crear:";
	
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::out);
	
	if(archivo.fail()){//función a utilizar en el caso de que falle a la hora de crear el archivo
		cout<<"No se puede abrir el archivo";
		exit(1);
		
	}
cout<<"***Si quieres acabar de escribir, pon: ' *fin ' en el nombre, lo que quieras en el apellido y cuando no te pregunte nada pones *fin para cerrar el archivo.***" <<endl;
cout<<"***Importante que los apellidos no tengan espacios***"<<endl;



do{//método para introducir el nombre y apellido de los alumnos que quieras hasta escribir ' *fin ', en el archivo, para más tarde leerlo
	
	string nombreArchivo;
	
	


	
	if(nombre!="*fin")//método para que te pregunte por el nombre y apellido de los alumnos hasta poner ' *fin ' en el nombre
num = num+1;
cout<< "Dime el nombre de un alumno de esta clase:";
cin>> nombre;
cout<< "Dime el apellido de un alumno de esta clase:";
cin>> apellido;


Alumno anum(nombre,apellido);
anum.mostrarAlumno();//utilizamos la función mostrarAlumno de la clase Alumno

archivo<<nombre<<apellido<<endl;

}while(nombre!="*fin");





do{//método para cerrar el archivo utilizando ' *fin '
getline(cin,linea);
	if(linea!="*fin")
	archivo<<linea<<endl;
}while(linea!="*fin");


archivo.close();

	
}
void leer(){//definimos la función leer

	string nombre;
	string apellido;//nombramos todas las variables que vayamos a utilizar
	int num = 0;
	ifstream archivo;
	string nombreArchivo;
	string linea;
	
	cout << "Nombre del archivo que quieres leer: ";

	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);//función mediante la cual abrimos un archivo ya creado para leer su contenido


	if(archivo.fail()){//función a utilizar en el caso de que falle a la hora de leer el archivo
		cout<< "No se puede abrir el archivo";
		exit(1);	
	}
		

	while(!archivo.eof()){
		getline(archivo,linea);//mediante esta función, conseguimos leer lo que pone dentro de una archivo antes creado
		cout<< linea<< endl;

	}
	archivo.close();
	
}


