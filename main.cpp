#include<iostream>

using namespace std;

struct nodo {
    int id;
    nodo *sig;
};

typedef nodo *pnodo;
pnodo list;

void insert(int x) {
    pnodo new_node;
    new_node = new nodo;
    new_node->id = x;

    if(list==NULL){ // Caso lista vacía
        (*new_node).sig = list;
        list = new_node;
        return;
    }

    pnodo primer_nodo;
    primer_nodo = list;

    // Caso valor por ingresar es menor
    // al primero de la lista
    if(x < primer_nodo->id){
        (*new_node).sig = list;
        list = new_node;
        return;
    }

    pnodo p;
    pnodo previous;
    p= list;
    previous = list;

    while (p != NULL) {
        if (x < p->id) {
            (*new_node).sig = p;
            previous->sig = new_node;
            return;
        }
        previous = p;
        p = p->sig;
    }

    // Caso pertenece al ultimo elemento
    new_node->sig = NULL;
    previous->sig = new_node;
    return;
}

void print() {
    pnodo p;
    p = list;
    while (p != NULL) {
        cout << p->id << " ";
        p = p->sig;
    }
}

int main() {
    list = NULL;
    insert(4);
    insert(3);
    insert(1);
    insert(9);

    cout << "Imprimimos el estado actual despues de agregar: 4, 3, 1, 9" << endl;
    print();

    insert(66);
    insert(11);
    insert(4);
    insert(3);
    cout << endl << "Agregamos 66, 11 y luego repetimos 4 y 3" << endl;
    print();
}
