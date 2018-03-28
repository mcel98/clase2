#include "Diccionario.h"/* Completar */

Diccionario::Asociacion::Asociacion(Clave _clave, Valor __valor) {
    clave = _clave;
    valor = __valor;

}

Diccionario::Diccionario() {
    vector<Asociacion> nuevo;
}
//TODO llevar esto a un header
int Diccionario::buscarPos(Clave k) const{
    int res=0;
    int i = 0;
    while(VecA[res].clave != k && res<VecA.size()){
        res+=1;

    }

    return res;

}
bool Diccionario::def(Clave k)const {
    bool res = false;
    int i = 0;
    while(i<VecA.size()){
        if(VecA[i].clave == k){
            res = true;


        }
        i++;
    }
    return res;
}

void Diccionario::definir(Clave k, Valor v) {
    if(def(k) == false){

        VecA.push_back(Asociacion(k,v));

    }
    else{

        VecA[buscarPos(k)]=Asociacion(k,v);

    }


}

Valor Diccionario::obtener(Clave k) const {
    int posicion = buscarPos(k);
    Valor res;
    if(def(k)) {
        res = VecA[posicion].valor;
    }
    else{
        res = 0;

    }
    return res;
}

void Diccionario::borrar(Clave k){
    vector<Asociacion> nuevo;
    int i = 0;
    if(def(k)) {
        while (i < VecA.size()) {
            if (VecA[i].clave != k) {
                nuevo.push_back(VecA[i]);
            }
            i++;
        }
        VecA = nuevo;
    }


}

