#include "Abacaxi.h"



Abacaxi::Abacaxi()
{
}


Abacaxi::~Abacaxi()
{
}

void Abacaxi::plantar(double tempoAtual)
{
	tempoPlantou = tempoAtual;
}

int Abacaxi::crescer(double tempoAtual)
{
	if ((int)tempoAtual - (int)tempoPlantou >= 40)
	{
		return 7;
	}
	else if ((int)tempoAtual - (int)tempoPlantou >= 30 && (int)tempoAtual - (int)tempoPlantou < 40)
	{
		return 6;
	}
	else if ((int)tempoAtual - (int)tempoPlantou >= 20 && (int)tempoAtual - (int)tempoPlantou < 30)
	{
		return 5;
	}
	else if ((int)tempoAtual - (int)tempoPlantou >= 10 && (int)tempoAtual - (int)tempoPlantou < 20)
	{
		return 4;
	}
	else
	{
		return 2;
	}

}

