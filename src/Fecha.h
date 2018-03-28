//
// Created by jampuero on 28/03/18.
//

#ifndef SOLUCION_FECHA_H
#define SOLUCION_FECHA_H
#include "Periodo.h"
#include "meses.h"
#include "Funciones.h"

class Fecha {
public:
    // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
    Fecha(Anio anio, Mes mes, Dia dia);

    Anio anio() const;
    Mes mes() const;
    Dia dia() const;

    bool operator==(Fecha o) const;
    bool operator<(Fecha o) const;

    void sumar_periodo(Periodo p);

private:
    Anio _anio;
    Mes _mes;
    Dia _dia;

    void ajustar_fecha();
    void sumar_anios(Anio anios);
    void sumar_meses(Mes meses);
    void sumar_dias(Dia dias);
};
#endif //SOLUCION_FECHA_H
