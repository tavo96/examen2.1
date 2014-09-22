#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//////////////////////////////////////
////////////ARBOL TRINARIO////////////
//////////////////////////////////////
class NodoTrinario
{
public:
    NodoTrinario* hijo_izq;
    NodoTrinario* hijo_der;
    NodoTrinario* hijo_medio;
    int num;
    NodoTrinario(int num)
    {
        this->num=num;
        hijo_der=NULL;
        hijo_izq=NULL;
        hijo_medio=NULL;
    }
};

//////////////////////////////////////
////////////GRAFO PONDERADO///////////
//////////////////////////////////////

class NodoGrafo;
class AristaGrafo
{
public:
    int distancia;//peso
    NodoGrafo* destino;

    AristaGrafo(int distancia, NodoGrafo* destino)
    {
        this->distancia=distancia;
        this->destino=destino;
    }
};

class NodoGrafo
{
public:
    list<AristaGrafo*> aristas;
    int num;

    NodoGrafo(int num)
    {
        this->num=num;
    }
};

//////////////////////////////////////
//////////////EJERCICIOS//////////////
//////////////////////////////////////

//Imprime todos los numeros de un arbol trinario dada su raiz
//5pts
void imprimir(NodoTrinario* raiz)
{
    if (raiz==NULL)
            return ;
        cout<<raiz->num<<endl;
        imprimir(raiz->hijo_medio);
        imprimir(raiz->hijo_izq);
        imprimir(raiz->hijo_der);
    return;
}

//Devuelve el numero mayor de un arbol trinario dada su raiz
//5pts
/*int suma(NodoArbol* raiz)
{
    int TotalSuma=0;

    if(raiz==NULL)
        return 0;

        TotalSuma+= raiz->num;

        TotalSuma+=suma(raiz->hijo_der)+suma(raiz->hijo_izq)+suma(raiz->hijo_medio);
    return TotalSuma;
}
*/
int getMayor(NodoTrinario* raiz)
{
    int valor=0;
    if (raiz==NULL)
            return 0;
            if(valor<raiz->num){
                valor=raiz->num;
            }

            valor=getMayor(raiz->hijo_izq);

            if(valor<raiz->num){
                valor=raiz->num;
            }
            valor=getMayor(raiz->hijo_der);

            if(valor<raiz->num){
                valor=raiz->num;
            }




    return valor;
}

//Devuelve true si puedo llegar desde el nodo inicio hasta el nodo destino dada una distancia maxima del recorrido
//5pts
bool puedoLLegar(NodoGrafo* inicio, NodoGrafo* destino, int distancia_max)
{
    return false;
}

int main ()
{
//////////////////////////////////////
////////////ARBOL TRINARIO////////////
//////////////////////////////////////

    NodoTrinario *nt1 = new NodoTrinario(1);
    NodoTrinario *nt2 = new NodoTrinario(2);
    NodoTrinario *nt3 = new NodoTrinario(3);
    NodoTrinario *nt4 = new NodoTrinario(4);
    NodoTrinario *nt5 = new NodoTrinario(5);
    NodoTrinario *nt6 = new NodoTrinario(6);
    NodoTrinario *nt7 = new NodoTrinario(7);
    NodoTrinario *nt8 = new NodoTrinario(8);
    NodoTrinario *nt9 = new NodoTrinario(9);

    nt1->hijo_izq = nt2;
    nt1->hijo_medio = nt3;
    nt1->hijo_der = nt4;

    nt2->hijo_medio = nt5;
    nt2->hijo_der = nt6;

    nt4->hijo_izq = nt7;

    nt7->hijo_izq = nt8;
    nt7->hijo_medio = nt9;


//////////////////////////////////////
////////////GRAFO PONDERADO///////////
//////////////////////////////////////

    NodoGrafo *ng1 = new NodoGrafo(1);
    NodoGrafo *ng2 = new NodoGrafo(2);
    NodoGrafo *ng3 = new NodoGrafo(3);
    NodoGrafo *ng4 = new NodoGrafo(4);
    NodoGrafo *ng5 = new NodoGrafo(5);
    NodoGrafo *ng6 = new NodoGrafo(6);

    ng1->aristas.push_back(new AristaGrafo(5,ng2));
    ng1->aristas.push_back(new AristaGrafo(3,ng3));
    ng2->aristas.push_back(new AristaGrafo(1,ng3));
    ng2->aristas.push_back(new AristaGrafo(2,ng4));
    ng4->aristas.push_back(new AristaGrafo(6,ng5));

//////////////////////////////////////
//////////////EJERCICIOS//////////////
//////////////////////////////////////

    cout<<"Ejercicio1"<<endl;

    imprimir(nt1);

    cout<<"Ejercicio2"<<endl;

    cout<<getMayor(nt1)<<"\tSe espera: 9"<<endl;

    cout<<getMayor(nt2)<<"\tSe espera: 6"<<endl;

    cout<<getMayor(nt5)<<"\tSe espera: 5"<<endl;

    cout<<"Ejercicio3"<<endl;

    cout<<puedoLLegar(ng1,ng2,5)<<"\tSe espera: 1"<<endl;
    cout<<puedoLLegar(ng1,ng2,4)<<"\tSe espera: 0"<<endl;
    cout<<puedoLLegar(ng4,ng3,10000)<<"\tSe espera: 0"<<endl;
    cout<<puedoLLegar(ng1,ng5,12)<<"\tSe espera: 0"<<endl;
    cout<<puedoLLegar(ng1,ng5,13)<<"\tSe espera: 1"<<endl;

    return 1;
}
