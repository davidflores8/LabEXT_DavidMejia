#include <string>
using std::string;

#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{
    public:
        int** matriz;
        int size;
        int determinante;
        string nombre;

        Matriz(int**, int, string);
        Matriz();

        int getSize();
        void setSize(int);
        int getDeterminante();
        string getNombre();
        int** getMatriz();
        void setMatriz(int**);
        void setNombre(string);
        void print();


        Matriz* operator +( Matriz*& m);
        Matriz* mutiplicacion_escalar(Matriz*&, int);
        void incremento();
        void decremento();
        ~Matriz();
};

#endif