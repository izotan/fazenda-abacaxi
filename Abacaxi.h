#pragma once
#include "Loja.h"
class Abacaxi
{
public:
	Abacaxi();
	~Abacaxi();

	void plantar(double tempoAtual);
	int crescer(double tempoAtual);
protected:
	double tempoPlantou;
	float custo;

};

