#include "Loja.h"



Loja::Loja()
{
}


Loja::~Loja()
{
}

void Loja::inicializar()
{
	qtdAbacaxis = 0;
	qtdCortador = 0;
	qtdSementes = 1;
	dinheiro = 0;
}

void Loja::atualizar()
{
}

void Loja::comprarSementes()
{
	if (dinheiro >= 1)
	{
		qtdSementes++;
		dinheiro--;
	}
}

void Loja::comprarCortador()
{
	if (dinheiro >= 125)
	{
		qtdCortador++;
		dinheiro--;
	}
}

void Loja::venderAbacaxi()
{
	if(qtdAbacaxis > 0)
		dinheiro += 2;
}
