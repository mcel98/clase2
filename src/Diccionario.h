#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

class Diccionario {
private:
	struct Asociacion;

public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	
private:
	// Completar para el ejercicio 3 ---> no sera 4?
	struct Asociacion{
	public:
		Asociacion();

	private:
		Clave clave;
		Valor valor;

	};
};

#endif /*__DICCIONARIO_H__*/
