#pragma once
#include "libUnicornio.h"
#include "Loja.h"
#include "Abacaxi.h"
#include <fstream>

enum Telas { tMenu, tCreditos, tTutorial, tJogo, tSair, tLoja };
enum Botoes { bComecar, bCreditos, bAjuda, bMenu, bSair, bVoltar, bCortador, bAbacaxi, bSemente, bMaquina, bVender };
enum Ferramentas { tMao, tPlantacao, tSemente, tRegador };
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void salvar();
	void executar();
protected:

	Vetor2D pTile, *tile;
	bool cheatDev, lojaAberta;
	ifstream arqConfig;
	string *nomeTiles, caminho;
	Sprite *spriteTiles;
	void telaMenu();
	void telaJogo();
	void telaCreditos();
	void telaTutorial();
	void telaLoja();
	int numTiles, numLinhas, numPlantado, numFrames, numColunas, numCamadas, ***mapa;
	Telas telaAtual;
	Ferramentas ferrementaAtual;
	BotaoSprite botoes[11];
	Som somBotao;
	Sprite telas, ferrementas[4], icone[4];
	Uint64 inicio;
	double tempoDecorrido, tempoPlantou;
	Loja loja;
	Abacaxi *abacaxi;
	Texto fonte1;
};

