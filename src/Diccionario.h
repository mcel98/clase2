#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>
using namespace std;
typedef int Clave;
typedef int Valor;

class Diccionario {
private:
	struct Asociacion;

public:


	int buscarPos(Clave k)const;
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	
private:
	// Completar para el ejercicio 3 ---> no sera 4?
	struct Asociacion{
	Asociacion(Clave _clave, Valor _valor);
	Clave clave;
	Valor valor;

	};
	vector<Asociacion> VecA;
};

#endif /*__DICCIONARIO_H__*/
