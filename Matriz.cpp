#include "Matriz.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Matriz::Matriz(){

}

Matriz::Matriz(int** matrix, int tamano, string name){
    matriz=matrix;
    size=tamano;
    nombre=name;
    determinante=-1212;
}

void Matriz::setNombre(string name){
    nombre=name;
}

int Matriz::getSize(){
    return size;
}

int Matriz::getDeterminante(){
    if(determinante==-1212){
        if(size==2){
            determinante=(matriz[0][0]*matriz[1][1])-(matriz[0][1]* matriz[1][0]);
        }
        else if (size==3){
            int sumas;
            int restas;
            sumas=(matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[1][0]*matriz[2][1]*matriz[0][2]);
            restas=(matriz[0][2]*matriz[1][1]*matriz[2][0])-(matriz[0][1]*matriz[1][0]*matriz[2][2])-(matriz[1][2]*matriz[2][1]*matriz[0][0]);
            determinante=sumas-restas;
        }
    }
    else{
    }
    return determinante;
}

string Matriz::getNombre(){
    return nombre;
}

int** Matriz::getMatriz(){
    return matriz;
}

void Matriz::setSize(int tamano){
    size=tamano;
}

void Matriz::print(){
    for (int i = 0; i <size; i++)
    {
        for (int j = 0;  j< size; i++)
        {
            cout<<"[ "<<matriz[i][j]<<" ]";
        }
        cout<<endl;
        
    }
    
}

Matriz* Matriz::operator +(Matriz*& m){
    Matriz* matriz_=new Matriz();
    int** matrix=NULL;
 	matrix=new int*[m->getSize()];

    
 	for(int i=0; i<m->getSize();i++)
 	{
		matrix[i]=new int[m->getSize()];
 	} 

    for (int i = 0; i <m->getSize(); i++)
    {
        for (int j = 0; j <m->getSize(); j++)
        {
            matrix[i][j]=matriz[i][j]+m->getMatriz()[i][j];
        }
        
    }

    matriz_->setMatriz(matrix);
    matriz_->setSize(m->getSize());
    
    return matriz_;
    
}

void Matriz::setMatriz(int** matrix){
    matriz=matrix;
}

Matriz* Matriz::mutiplicacion_escalar(Matriz*&m, int number){
    Matriz* matriz_=new Matriz();
    int** matrix=NULL;
 	matrix=new int*[m->getSize()];
 	for(int i=0; i<m->getSize();i++)
 	{
		matrix[i]=new int[m->getSize()];
 	} 
     matriz_->setSize(m->getSize());

      for (int i = 0; i <m->getSize(); i++)
    {
        for (int j = 0; j <m->getSize(); j++)
        {
            matrix[i][j]=number*m->getMatriz()[i][j];
        }
        
    }
    matriz_->setMatriz(matrix);
    matriz_->setSize(m->getSize());
    return matriz_;

}

void Matriz::incremento(){
    int incremento;
    incremento=determinante-size;
    if(incremento<0){
        incremento=incremento*(-1);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matriz[i][j]=matriz[i][j]+incremento;
        }
        
    }
    
    
}

void Matriz::decremento(){
    int incremento;
    incremento=determinante-size;
    if(incremento<0){
        incremento=incremento*(-1);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matriz[i][j]=matriz[i][j]+incremento;
        }
        
    }
    
    
}

Matriz::~Matriz(){
    for(int g=0;g<size;g++)
        {
                if(matriz[g]!=NULL)
                {
                        delete[]matriz[g];
                        matriz[g]=NULL;
                }

        }
        if(matriz!=NULL)
        {
                delete[]matriz;
        }


}