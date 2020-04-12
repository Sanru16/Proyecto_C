/*Este es el proyecto de Ra�l Gonz�lez y Santiago gonz�lez de 2�BACH B del IES MAR�A MOLINER.*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
void escribir();//mencionamos las funciones que tendr� el men�
void leer();
using namespace std;



class Alumno{ //creamos la clase alumno

	private://caracter�sticas privadas de la clase alumno 
		string nombre;
		string apellido;
	public://caracter�sticas p�blicas de la clase alumno 
		Alumno(string,string);
		void mostrarAlumno();	
};

Alumno::Alumno(string _nombre,string _apellido){//utilizamos el contructor
	nombre = _nombre;
	apellido = _apellido; 
	
}

void Alumno::mostrarAlumno(){//definimos la funci�n mostrarAlumnos que est� definida dentro de la clase Alumno
	
	cout << "Nombre completo: " << nombre << apellido << endl;
	
	
}


int main(){

		int n;
	
	do{    //men� con 3 opciones
		cout<<"\n";
		cout<<"*Clases IES MARIA MOLINER*"<< endl;
		cout<<" 1.- crear y escribir en un archivo nuevo por cada clase que haya en tu instituto "<< endl;
		cout<<" 2.- leer el listado de alumnos de la clase que elijas							 "<< endl;
		cout<<" 3.- salir del menu								 					  			 "<< endl;
		cout<<"Selecciona una opcion: ";
		cin>>n;
		cin.ignore(256, '\n');
		
		switch(n){
			case 1: escribir();//la primera opcion est� definida por la funci�n escribir con la que podr�s crear y escribir un nuevo archivo/fichero
				break;
			case 2: leer();//la segunda opcion est� definifda por la funci�n leer con la que pordr�s ver un fichero/archivo antes creado
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

void escribir(){//definimos la funci�n escribir

	int num = 0;//nombramos todas las variables que vayamos a utilizar
	string nombre;
	string apellido;
	ofstream archivo;
	string nombreArchivo;
	string linea;
	
	cout<<"Nombre del archivo que quieres crear:";
	
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::out);
	
	if(archivo.fail()){//funci�n a utilizar en el caso de que falle a la hora de crear el archivo
		cout<<"No se puede abrir el archivo";
		exit(1);
		
	}
cout<<"***Si quieres acabar de escribir, pon: ' *fin ' en el nombre, lo que quieras en el apellido y cuando no te pregunte nada pones *fin para cerrar el archivo.***" <<endl;
cout<<"***Importante que los apellidos no tengan espacios***"<<endl;



do{//m�todo para introducir el nombre y apellido de los alumnos que quieras hasta escribir ' *fin ', en el archivo, para m�s tarde leerlo
	
	string nombreArchivo;
	
	


	
	if(nombre!="*fin")//m�todo para que te pregunte por el nombre y apellido de los alumnos hasta poner ' *fin ' en el nombre
num = num+1;
cout<< "Dime el nombre de un alumno de esta clase:";
cin>> nombre;
cout<< "Dime el apellido de un alumno de esta clase:";
cin>> apellido;


Alumno anum(nombre,apellido);
anum.mostrarAlumno();//utilizamos la funci�n mostrarAlumno de la clase Alumno

archivo<<nombre<<apellido<<endl;

}while(nombre!="*fin");





do{//m�todo para cerrar el archivo utilizando ' *fin '
getline(cin,linea);
	if(linea!="*fin")
	archivo<<linea<<endl;
}while(linea!="*fin");


archivo.close();

	
}
void leer(){//definimos la funci�n leer

	string nombre;
	string apellido;//nombramos todas las variables que vayamos a utilizar
	int num = 0;
	ifstream archivo;
	string nombreArchivo;
	string linea;
	
	cout << "Nombre del archivo que quieres leer: ";

	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);//funci�n mediante la cual abrimos un archivo ya creado para leer su contenido


	if(archivo.fail()){//funci�n a utilizar en el caso de que falle a la hora de leer el archivo
		cout<< "No se puede abrir el archivo";
		exit(1);	
	}
		

	while(!archivo.eof()){
		getline(archivo,linea);//mediante esta funci�n, conseguimos leer lo que pone dentro de una archivo antes creado
		cout<< linea<< endl;

	}
	archivo.close();
	
}


