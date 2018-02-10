#ifndef USUARIOVIEWER_H
#define USUARIOVIEWER_H

#include "queue.h"
#include <iostream>
#include <string>

using namespace std;

class UsuarioViewer
{
    public:
        UsuarioViewer();
        virtual ~UsuarioViewer();
        int menu();
        void listar(Queue*);
       // int buscar();
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void votar(string);
        void categoria();
        void fail();
        void info(string, int);
        //void cargar(Usuario*, string);
        //void mensaje(string);
    protected:
    private:
};

#endif
