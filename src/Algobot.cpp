#ifndef ALGOBOT_CPP
#define ALGOBOT_CPP

#include <vector>
#include <tuple>
#include <iostream>
#include <string>

using namespace std;

class LU {
 public:
  LU(string lu);
  int numero() const;
  int anio() const;

  bool operator==(LU o) const;

 private:
  int _num;
  int _anio;
};

class Algobot {
 public:
  class Grupo; // Forward declaration

  void entrega(LU i1, LU i2, string codigo);

  vector<Grupo> entregaron() const;
  string codigo(LU i) const;
  
  class Grupo {
   public:
    Grupo(LU i1, LU i2);

    vector<LU> integrantes() const;
    bool esIntegrante(LU i) const;
    bool operator==(Grupo o) const;

   private:
    vector<LU> _integrantes;
  };

 private:
  vector< tuple<Grupo, string> > _entregas;

};

LU::LU(string lu) : _num(-1), _anio(-1) {
  int idx = lu.find("/");
  string num_str = lu.substr(0, idx);
  string anio_str = lu.substr(idx + 1);
  _num = stoi(num_str);
  _anio = stoi(anio_str);
}

int LU::numero() const {
  return _num;
}

int LU::anio() const {
  return _anio;
}

bool LU::operator==(LU o) const {
  return _num == o.numero() and _anio == o.anio();
}

Algobot::Grupo::Grupo(LU i1, LU i2) : _integrantes() {
  _integrantes.push_back(i1);
  _integrantes.push_back(i2);
}

vector<LU> Algobot::Grupo::integrantes() const {
    return _integrantes;
}

bool Algobot::Grupo::esIntegrante(const LU i) const {
    return (_integrantes[0] == i) or (_integrantes[1] == i);
}

bool Algobot::Grupo::operator==(Algobot::Grupo o) const {
    return o.esIntegrante(_integrantes[0]) &&
           o.esIntegrante(_integrantes[1]);
}

void Algobot::entrega(LU i1, LU i2, string codigo) {
  Grupo g(i1, i2);
  for (int i = 0; i < _entregas.size(); i++) {
    if (get<0>(_entregas[i]) == g) {
      get<1>(_entregas[i]) = codigo;
      return;
    }
  }
  _entregas.push_back(make_tuple(g, codigo));
}

vector<Algobot::Grupo> Algobot::Algobot::entregaron() const {
  vector<Grupo> ret;
  for (int i = 0; i < _entregas.size(); i++) {
    ret.push_back(get<0>(_entregas[i]));
  }
  return ret;
}

string Algobot::codigo(LU integrante) const {
  for (int i = 0; i < _entregas.size(); i++) {
    if (get<0>(_entregas[i]).esIntegrante(integrante)) {
      return get<1>(_entregas[i]);
    }
  }
}

#endif // ALGOBOT_CPP
