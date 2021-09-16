#pragma once
template <class t>
class Nodo
{
private:
	t valor;
	Nodo *sig;
	Nodo *ant;
public:
	Nodo();
	void setValor(t v);
	t getValor();
	void setSig(Nodo *s);
	Nodo *getSig();
	void setAnt(Nodo *s);
	Nodo *getAnt();
};

