#pragma once
template<class tipo>
class Nodo
{
private:
	tipo el;
	bool existe;
public:
	Nodo() {
		existe = false;
	}
	bool getExiste() {
		return existe;
	}
	tipo getElem() {
		return el;
	}
	void setExiste(bool e) {
		existe = e;
	}
	void setElem(tipo e) {
		el = e;
	}
	~Nodo() {
	}
};

