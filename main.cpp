#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Matriz.h"

#include <vector>
using std::vector;

#include <sstream>
using std::stringstream;

bool validarOperacion(char);
int matriz_by_sub(string, vector<Matriz*> );
char indicador_operacion(string);
string nombre1(string);
string nombre2(string );
Matriz* matriz_by_name(string, vector<Matriz*>&);
int** crearMatriz(int size);
bool validarOperaciones(string, string, char, vector<Matriz*>&);
bool validarNombre(string, vector<Matriz*>& );
bool validarOperacion(char);
void liberarMemoria(vector<Matriz*>&);



int main(){

    vector<Matriz*> matrices;
    int respuesta=1;
    while(respuesta>0 && respuesta<5){
        cout<<"1. Crear matrices\n2. Listar matrices\n3. Eliminar matrices\n4. Opererar matrices\n5. Salir"<<endl;
        int opcion;
        cin>>opcion;
        switch (opcion)
        {
            case 1:{
                string name;
                int size;
                cout<<"Ingrese el nombre de la matriz: "<<endl;
                cin>>name;
                cout<<"Ingrese el size de la matriz: "<<endl;
                cin>>size;
                while(size!=2 || size!=3){
                    cout<<"Ingrese el size nuevamente: "<<endl;
                    cin>>size;
                }
                int** matrix=NULL;
                matrix=crearMatriz(size);
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; i++)
                    {
                        int valor;
                        cout<<"Ingrese un valor: "<<endl;
                        matrix[i][j]=valor;
                    }
                    
                }
                matrices.push_back(new Matriz(matrix,size,name));
                cout<<"Matriz agregada exitosamente";
            }
            break;
            case 2:{
                for (int i = 0; i <matrices.size(); i++)
                {
                    matrices[i]->print();
                }
                
            }
            break;
            case 3:{
                int numero_matriz;
                cout<<"Ingrese el numero de la matriz que quiere borrar: "<<endl;
                cin>>numero_matriz;
                while(numero_matriz<0 || numero_matriz>=matrices.size()){
                    cout<<"Posicion incorrecta\nIngrese la posicion nuevamente: "<<endl;
                    cin>>numero_matriz;
                }
                matrices.erase(matrices.begin()+numero_matriz);
                cout<<"Matriz borrada exitosamente"<<endl;
            }
            break;
            case 4:{
                string operacion;
                cout<<"Ingrese la operacion que desea reazliar: "<<endl;
                cin>>operacion;
                string nombre_1, nombre_2;
                char op;
                nombre_2=nombre2(operacion);
                nombre_1=nombre1(operacion);
                op=indicador_operacion(operacion);
                while(validarOperaciones(nombre_1, nombre_2, op, matrices)==false){
                    cout<<"La operacion ingresada ha sido incorrecta. Ingresela nuevamente: "<<endl;
                    cin>>operacion;
                }
                if(op=='|'){
                    
                    Matriz* matrix=new Matriz();
                    Matriz* matrix_1=matriz_by_name(nombre_1, matrices);
                    Matriz* matrix_2=matriz_by_name(nombre_2, matrices);
                    matrix=matrix_1->operator+(matrix_2);
                    cout<<"Ingrese el nombre de su matriz: "<<endl;
                    string name;
                    cin>>name;
                    matrix->setNombre(name);
                    cout<<"Su nueva matriz es: "<<endl;
                    matrix->print();
                    matrices.push_back(matrix);
                }
                else if (op=='>'){
                    int numero=(int) nombre_1[0] - 48;
                    Matriz* matriz=new Matriz();
                    Matriz* matrix=matriz_by_name(nombre_2, matrices);
                    matriz=matrix->mutiplicacion_escalar(matrix, numero);
                    cout<<"Esa es su nueva matriz: "<<endl;
                    matriz->print();
                    matrices.push_back(matriz);
                    }
                 else if (op=='+' && nombre_2=="+"){
                        int sub;
                        sub=matriz_by_sub(nombre_1, matrices);
                        matrices[sub]->incremento();
                        cout<<"Su nueva matriz es: "<<endl;
                        matrices[sub]->print();
                    }  
                 else if (op=='+' && nombre_2=="+"){
                        int sub;
                        sub=matriz_by_sub(nombre_1, matrices);
                        matrices[sub]->incremento();
                        cout<<"Su nueva matriz es: "<<endl;
                        matrices[sub]->print();
                    }

                }
                break;
            }
        }
    if(respuesta==5){
        liberarMemoria(matrices);
    }

    return 0;
}

int matriz_by_sub(string name, vector<Matriz*> matrices){
    for (int i = 0; i < matrices.size(); i++)
    {
        if(matrices[i]->getNombre()==name){
            return i;
        }
    }
    
}

char indicador_operacion(string operacion){
    for (int i = 0; i <operacion.size(); i++)
    {
       if(operacion[i]=='>' || operacion[i]=='+' || operacion[i]=='-' || operacion[i]=='|' || operacion[i]=='>' || operacion[i]=='&' || operacion[i]=='*'){
            return operacion[i];
        }
        else{
            
        }
    }
    
}

string nombre1(string operacion){
    stringstream name;
    for (int i = 0; i <operacion.size(); i++)
    {
        if(operacion[i]=='>' || operacion[i]=='+' || operacion[i]=='-' || operacion[i]=='|' || operacion[i]=='>' || operacion[i]=='&' || operacion[i]=='*'){
            return name.str();
        }
        else{
            name<<operacion[i];
        }
    }
    
}

string nombre2(string operacion){
    stringstream name;
    int h;
    for (int i = 0; i <operacion.size(); i++)
    {
        if(operacion[i]=='>' || operacion[i]=='+' || operacion[i]=='-' || operacion[i]=='|' || operacion[i]=='>' || operacion[i]=='&' || operacion[i]=='*'){
            h=i;
        }
    }
    for (int k = h; k <operacion.size(); k++)
    {
        name<<operacion[k];
    }
    return name.str();
    
}




Matriz* matriz_by_name(string name, vector<Matriz*>& matrices){
    for (int i = 0; i <matrices.size();i++)
    {
        if(matrices[i]->getNombre()==name){
            return matrices[i];
        }
    }
    
}

int** crearMatriz(int size){
	int** matriz=NULL;
 	matriz=new int*[size];
 	for(int i=0; i<size;i++)
 	{
		matriz[i]=new int[size];
 	}
    return matriz;
}


void liberarMemoria(vector<Matriz*>& matrices){
    for (int i = 0; i < matrices.size(); i++)
    {
        matrices[i]->~Matriz();
    }
    matrices.clear();
    
}





bool validarOperaciones(string nombre1, string nombre2, char op, vector<Matriz*>&matrices){
    bool flag=false;
    if(validarNombre(nombre1, matrices)==true  && validarNombre(nombre2, matrices)==true && validarOperacion(op)==true){
        flag=true;
    }
    else{
        flag=false;
    }
    return flag;
}

bool validarNombre(string nombre, vector<Matriz*>& matrices){
    bool retorno=false;
    for (int i = 0; i <matrices.size(); i++)
    {
        if(matrices[i]->getNombre()==nombre){
            retorno=true;
        }
        else if (nombre=="1" || nombre=="2" || nombre=="3" || nombre=="4" || nombre=="5" || nombre=="6" || nombre=="7" || nombre=="8" || nombre=="9")
            retorno==true;
    }
    return retorno;
    
}


bool validarOperacion(char operacion)
{
    bool retorno=false;
    if(operacion=='|' || operacion=='+' || operacion=='-' || operacion=='&' || operacion=='>' || operacion=='*'){
        retorno=true;
    }
    else{
        retorno=false;
    }
    return retorno;
}


