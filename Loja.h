#pragma once
class Loja
{
public:
	Loja();
	~Loja();

	void inicializar();
	void atualizar();
	void usarSementes() { qtdSementes--; }
	void usarCortador() { qtdCortador--; }
	void usarAbacaxi() { if (qtdAbacaxis > 0) { qtdAbacaxis--; } }
	void comprarSementes();
	void comprarCortador();
	void colherAbacaxi() { qtdAbacaxis++; }
	int getSementes() { return qtdSementes; }
	int getCortador() { return qtdCortador; }
	int getAbacaxi() { return qtdAbacaxis; }
	float getDinheiro() { return dinheiro; }
	void venderAbacaxi();
	void cheat() { qtdAbacaxis += 10; qtdCortador += 5; qtdSementes += 5; dinheiro += 200; }
protected:
	int  qtdSementes, qtdCortador, qtdAbacaxis;
	float dinheiro;
};

