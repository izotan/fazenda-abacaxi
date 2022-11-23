#include "Jogo.h"
#include <ctime>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
	exit(0);
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false);

	cheatDev = false;
	lojaAberta = false;
	loja.inicializar();
	telaAtual = tMenu;
	ferrementaAtual = tMao;
	numPlantado = 0;
	inicio = gTempo.getTicks();
	gJanela.setIcone("assets/Artes/Icone/Icone.png");

	srand(time(0));

	if (!gRecursos.carregouAudio("somBotao"))
		gRecursos.carregarAudio("somBotao", "assets/Sons/Efeitos/Botao.wav");

	somBotao.setAudio("somBotao");

	if (!gRecursos.carregouSpriteSheet("tMenu"))
		gRecursos.carregarSpriteSheet("tMenu", "assets/Artes/Telas/menu1.png");

	if (!gRecursos.carregouSpriteSheet("tCreditos"))
		gRecursos.carregarSpriteSheet("tCreditos", "assets/Artes/Telas/creditos1.png");

	if (!gRecursos.carregouSpriteSheet("tTutorial"))
		gRecursos.carregarSpriteSheet("tTutorial", "assets/Artes/Telas/tutorial1.png");


	if (!gRecursos.carregouSpriteSheet("bMenu"))
		gRecursos.carregarSpriteSheet("bMenu", "assets/Artes/Botoes/Menu.png", 3, 1);
	botoes[bMenu].setSpriteSheet("bMenu");

	if (!gRecursos.carregouSpriteSheet("bComecar"))
		gRecursos.carregarSpriteSheet("bComecar", "assets/Artes/Botoes/Comecar.png", 3, 1);
	botoes[bComecar].setSpriteSheet("bComecar");

	if (!gRecursos.carregouSpriteSheet("bSair"))
		gRecursos.carregarSpriteSheet("bSair", "assets/Artes/Botoes/Sair.png", 3, 1);
	botoes[bSair].setSpriteSheet("bSair");

	if (!gRecursos.carregouSpriteSheet("bCreditos"))
		gRecursos.carregarSpriteSheet("bCreditos", "assets/Artes/Botoes/Creditos.png", 3, 1);
	botoes[bCreditos].setSpriteSheet("bCreditos");

	if (!gRecursos.carregouSpriteSheet("bAjuda"))
		gRecursos.carregarSpriteSheet("bAjuda", "assets/Artes/Botoes/Ajuda.png", 3, 1);
	botoes[bAjuda].setSpriteSheet("bAjuda");

	if (!gRecursos.carregouSpriteSheet("bVoltar"))
		gRecursos.carregarSpriteSheet("bVoltar", "assets/Artes/Botoes/Voltar.png", 3, 1);
	botoes[bVoltar].setSpriteSheet("bVoltar");

	if (!gRecursos.carregouSpriteSheet("bCortador"))
		gRecursos.carregarSpriteSheet("bCortador", "assets/Artes/Botoes/bcortador.png", 1, 1);
	botoes[bCortador].setSpriteSheet("bCortador");

	if (!gRecursos.carregouSpriteSheet("bSemente"))
		gRecursos.carregarSpriteSheet("bSemente", "assets/Artes/Botoes/bsementes.png", 1, 1);
	botoes[bSemente].setSpriteSheet("bSemente");

	if (!gRecursos.carregouSpriteSheet("bVender"))
		gRecursos.carregarSpriteSheet("bVender", "assets/Artes/Botoes/vender.png", 1, 1);
	botoes[bVender].setSpriteSheet("bVender");

	if (!gRecursos.carregouSpriteSheet("bMais"))
		gRecursos.carregarSpriteSheet("bMais", "assets/Artes/Botoes/mais.png", 1, 1);
	botoes[bAbacaxi].setSpriteSheet("bMais");

	if (!gRecursos.carregouMusica("musica"))
		gRecursos.carregarMusica("musica", "assets/Sons/Musicas/Jogo.wav");

	if (!gRecursos.carregouMusica("musicaCreditos"))
		gRecursos.carregarMusica("musicaCreditos", "assets/Sons/Musicas/Creditos.wav");

	if (!gRecursos.carregouMusica("musicaAbacaxi"))
		gRecursos.carregarMusica("musicaAbacaxi", "assets/Sons/Musicas/musicaAbacaxi.wav");

	if (!gRecursos.carregouMusica("musicaTutorial"))
		gRecursos.carregarMusica("musicaTutorial", "assets/Sons/Musicas/Tutorial.wav");

	if (!gRecursos.carregouFonte("fonte"))
		gRecursos.carregarFonte("fonte", "assets/fontes/fonte_padrao.ttf", 30);

	if (!gRecursos.carregouFonte("fonteJogo"))
		gRecursos.carregarFonte("fonteJogo", "assets/fontes/Cipitillo.otf", 22);

	if (!gRecursos.carregouSpriteSheet("mao"))
		gRecursos.carregarSpriteSheet("mao", "assets/Artes/ferramentas/mao.png");

	if (!gRecursos.carregouSpriteSheet("cortador"))
		gRecursos.carregarSpriteSheet("cortador", "assets/Artes/ferramentas/pikachu.png");

	if (!gRecursos.carregouSpriteSheet("semente"))
		gRecursos.carregarSpriteSheet("semente", "assets/Artes/ferramentas/semente.png");

	if (!gRecursos.carregouSpriteSheet("regador"))
		gRecursos.carregarSpriteSheet("regador", "assets/Artes/ferramentas/regador.png");

	if (!gRecursos.carregouSpriteSheet("tLoja"))
		gRecursos.carregarSpriteSheet("tLoja", "assets/Artes/Imagens/loja.png");

	if (!gRecursos.carregouSpriteSheet("iAbacaxi"))
		gRecursos.carregarSpriteSheet("iAbacaxi", "assets/Artes/Imagens/abacaxi3.png");
	icone[0].setSpriteSheet("iAbacaxi");

	if (!gRecursos.carregouSpriteSheet("iDinheiro"))
		gRecursos.carregarSpriteSheet("iDinheiro", "assets/Artes/Botoes/vender.png");
	icone[1].setSpriteSheet("iDinheiro");

	if (!gRecursos.carregouSpriteSheet("iCortador"))
		gRecursos.carregarSpriteSheet("iCortador", "assets/Artes/Botoes/bcortador.png", 1, 1);
	icone[2].setSpriteSheet("iCortador");

	if (!gRecursos.carregouSpriteSheet("iSemente"))
		gRecursos.carregarSpriteSheet("iSemente", "assets/Artes/Botoes/bsementes.png", 1, 1);
	icone[3].setSpriteSheet("iSemente");

	if (!gRecursos.carregouFonte("Cipitillo"))
		gRecursos.carregarFonte("Cipitillo", "assets/Fontes/Cipitillo.otf", 14);
	fonte1.setAncora(0, 0.5);
	fonte1.setFonte("Cipitillo");

	arqConfig.open("config.txt");
	if (arqConfig.is_open())
	{
		arqConfig >> numTiles;
		spriteTiles = new Sprite[numTiles];
		nomeTiles = new string[numTiles];
		abacaxi = new Abacaxi[numTiles];
		tile = new Vetor2D[numTiles];
		for (int t = 0; t < numTiles; t++)
		{
			arqConfig >> nomeTiles[t] >> caminho >> numFrames;
			if (!gRecursos.carregouSpriteSheet(nomeTiles[t]))
				gRecursos.carregarSpriteSheet(nomeTiles[t], caminho, 1, numFrames);
			spriteTiles[t].setSpriteSheet(nomeTiles[t]);

			tile[t].x = { 0 };
			tile[t].y = { 0 };
		}
		arqConfig >> numColunas >> numLinhas >> numCamadas;
		mapa = new int**[numCamadas]; //camadas

		for (int c = 0; c < numCamadas; c++)
		{
			mapa[c] = new int*[numColunas]; //colunas
			for (int l = 0; l < numColunas; l++)
			{
				mapa[c][l] = new int[numLinhas]; //linhas
			}
		}


		for (int c = 0; c < numCamadas; c++) //camadas
			for (int y = 0; y < numColunas; y++) //colunas
				for (int x = 0; x < numLinhas; x++) //linhas
					arqConfig >> mapa[c][y][x];

		arqConfig.close();
	}
}

void Jogo::finalizar()
{
	for (int c = 0; c < numCamadas; c++)
	{
		for (int l = 0; l < numLinhas; l++)
			delete[] mapa[c][l];
		delete[] mapa[c];
	}
	delete[] mapa;
	delete[] spriteTiles;
	delete[] nomeTiles;
	delete[] abacaxi;
	delete[] tile;
	uniFinalizar();
}

void Jogo::salvar()
{
	ofstream arqSave;

	arqSave.open("config_save.txt", ios::trunc);

	if (arqSave.is_open())
	{
		arqSave << numTiles << endl;

		for (int t = 0; t < numTiles; t++)
			arqSave << nomeTiles[t] << "\t" << caminho << numFrames << endl << tile[t].x << "\t" << tile[t].y;
			
		arqSave << endl << numColunas << numLinhas << numCamadas << endl;

		for (int c = 0; c < numCamadas; c++) //camadas
		{
			for (int y = 0; y < numColunas; y++) //colunas
			{
				for (int x = 0; x < numLinhas; x++) //linhas
				{
					arqSave << mapa[c][y][x];
					if (x + 1 < numColunas)
						arqSave << " ";
				}
				if (y + 1 < numLinhas)
					arqSave << endl;
			}
			if (c + 1 < numCamadas)
				arqSave << endl << endl;
		}

		arqSave << endl << ferrementaAtual;
	}
	else
	{
		fonte1.setString("*****Erro*****");
		fonte1.desenhar(500, 500);
	}
}

void Jogo::executar()
{

	if (gTeclado.soltou[TECLA_ESC] && gEventos.sair && telaAtual != tSair)
	{
		fonte1.setString("Tem certeza que quer sair?");
		fonte1.desenhar(500, 500);
	}
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual != tSair)
	{
		uniIniciarFrame();
		


		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tCreditos: telaCreditos();
			break;
		case tTutorial: telaTutorial();
			break;
		case tJogo: telaJogo();
			break;
		case tLoja: telaLoja();
			break;
		}
		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	if (!gMusica.estaTocando())
		gMusica.tocar("musicaAbacaxi", true);
	
	telas.setSpriteSheet("tMenu");
	telas.desenhar(512, 384);
	botoes[bComecar].setPos(512, 360);
	botoes[bAjuda].setPos(512, 420);
	botoes[bCreditos].setPos(512, 480);
	botoes[bSair].setPos(512, 540);

	botoes[bComecar].desenhar();
	botoes[bComecar].atualizar();
	if (botoes[bComecar].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musica", true);
		somBotao.tocar();
		telaAtual = tJogo;
	}

	botoes[bAjuda].desenhar();
	botoes[bAjuda].atualizar();
	if (botoes[bAjuda].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musicaTutorial", true);
		somBotao.tocar();
		telaAtual = tTutorial;
	}

	botoes[bCreditos].desenhar();
	botoes[bCreditos].atualizar();
	if (botoes[bCreditos].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musicaCreditos", true);
		somBotao.tocar();
		telaAtual = tCreditos;
	}

	botoes[bSair].desenhar();
	botoes[bSair].atualizar();
	if (botoes[bSair].estaClicado())
	{
		telaAtual = tSair;
	}
}

void Jogo::telaJogo()
{
	tempoDecorrido = gTempo.getTempoAteTickAtual(inicio);
	if (!cheatDev)
	{
		if (gTeclado.pressionou[TECLA_F1])
			cheatDev = true;
	}
	else
		if (gTeclado.pressionou[TECLA_F1])
			cheatDev = false;
	if (cheatDev)
	{
		gDebug.depurar("X tile: ", pTile.x);
		gDebug.depurar("Y tile: ", pTile.y);
		gDebug.depurar("ferramenta atual: ", ferrementaAtual);
		gDebug.depurar("sementes atual: ", loja.getSementes());
		gDebug.depurar("cortador atual: ", loja.getCortador());
		gDebug.depurar("abacaxis atual: ", loja.getAbacaxi());
		gDebug.depurar("tempo atual: ", (int)tempoDecorrido);
		gDebug.depurar("$ ", loja.getDinheiro());
		if (gTeclado.pressionou[TECLA_F11])
			loja.cheat();
	}

	const int altura = spriteTiles[0].getAltura(),//64
		largura = spriteTiles[0].getLargura();//64
	for (int c = 0; c < numCamadas; c++)
		for (int y = 0; y < numColunas; y++)
			for (int x = 0; x < numLinhas; x++)
			{
				if (mapa[c][y][x] != -1)
				{
					spriteTiles[mapa[c][y][x]].desenhar(largura / 2 + x * largura,
						altura / 2 + y * altura);
				}
			}
	for (int i = 0; i < numPlantado; i++)
	{
		if (mapa[1][(int)tile[i].y][(int)tile[i].x] == 2 || mapa[1][(int)tile[i].y][(int)tile[i].x] == 4 || mapa[1][(int)tile[i].y][(int)tile[i].x] == 5 || mapa[1][(int)tile[i].y][(int)tile[i].x] == 6 || mapa[1][(int)tile[i].y][(int)tile[i].x] == 7)
		{
			mapa[1][(int)tile[i].y][(int)tile[i].x] = abacaxi[i].crescer(tempoDecorrido);
		}
	}
	pTile.x = (int)(gMouse.x) / 64;
	pTile.y = (int)(gMouse.y) / 64;

	if (gMouse.pressionou[BOTAO_MOUSE_ESQ] && lojaAberta == false)
	{
		switch (ferrementaAtual)
		{
		case tRegador: if (mapa[0][(int)pTile.y][(int)pTile.x] == 0)
		{
			mapa[0][(int)pTile.y][(int)pTile.x] = ferrementaAtual;
			mapa[1][(int)pTile.y][(int)pTile.x] = ferrementaAtual;

		}	
		    break;
		case tSemente: if (mapa[0][(int)pTile.y][(int)pTile.x] == 3 && loja.getSementes() >= 1)
		{
			mapa[1][(int)pTile.y][(int)pTile.x] = ferrementaAtual;
			tile[numPlantado].x = pTile.x;
			tile[numPlantado].y = pTile.y;
			abacaxi[numPlantado].plantar(tempoDecorrido);
			loja.usarSementes();
			numPlantado++;
		}
			break;
		case tMao: if (mapa[1][(int)pTile.y][(int)pTile.x] == 6 || mapa[1][(int)pTile.y][(int)pTile.x] == 7)
		{
			mapa[0][(int)pTile.y][(int)pTile.x] = ferrementaAtual;
			if (mapa[1][(int)pTile.y][(int)pTile.x] != 7)
			{
				mapa[1][(int)pTile.y][(int)pTile.x] = ferrementaAtual;
				loja.colherAbacaxi();
				numPlantado--;
			}
			else
			{
				mapa[1][(int)pTile.y][(int)pTile.x] = ferrementaAtual;
				numPlantado--;
			}
		}
			break;
		case tPlantacao: if (mapa[0][(int)pTile.y][(int)pTile.x] == 1 && mapa[1][(int)pTile.y][(int)pTile.x] != 9 && loja.getCortador() >= 1)
		{
			mapa[0][(int)pTile.y][(int)pTile.x] = 0;
			loja.usarCortador();
		}
			break;
		}

		if (mapa[1][(int)pTile.y][(int)pTile.x] == 9 && loja.getAbacaxi() > 0)
		{
			loja.venderAbacaxi();
			loja.usarAbacaxi();
		}
	}
	for (int i = 0; i < 4; i++)
		icone[i].desenhar(70, 70 + (i * 90));

	gGraficos.desenharRetangulo(20, 40, 0, 180, 350,0,0,100,100,100, 100, true);

	fonte1.setString(to_string(loja.getCortador()));
	fonte1.desenhar(110, 250);
	fonte1.setString(to_string(loja.getSementes()));
	fonte1.desenhar(110, 340);
	fonte1.setString(to_string(loja.getAbacaxi()));
	fonte1.desenhar(110, 70);
	fonte1.setString(to_string((int)loja.getDinheiro()));
	fonte1.desenhar(110, 160);

	ferrementas[0].setSpriteSheet("regador");
	ferrementas[0].desenhar(408,680);

	ferrementas[1].setSpriteSheet("semente");
	ferrementas[1].desenhar(472, 680);

	ferrementas[1].setSpriteSheet("mao");
	ferrementas[1].desenhar(536, 680);

	ferrementas[1].setSpriteSheet("cortador");
	ferrementas[1].desenhar(600, 680);

	if (gTeclado.pressionou[TECLA_Q])
	{
		ferrementaAtual = tRegador;

	}


	if (gTeclado.pressionou[TECLA_W])
	{
		ferrementaAtual = tSemente;

	}

	if (gTeclado.pressionou[TECLA_E])
	{
		ferrementaAtual = tMao;
		
	}

	if (gTeclado.pressionou[TECLA_R])
	{
		ferrementaAtual = tPlantacao;

	}

	if (gTeclado.pressionou[TECLA_L])
	{
		telaAtual = tLoja;
	}

}

void Jogo::telaCreditos()
{
	telas.setSpriteSheet("tCreditos");
	telas.desenhar(512, 384);
	botoes[bVoltar].setPos(920, 720);
	botoes[bVoltar].desenhar();
	botoes[bVoltar].atualizar();
	if (botoes[bVoltar].estaClicado() && telaAtual == tCreditos)
	{
		gMusica.parar();
		gMusica.tocar("musicaAbacaxi", true);
		somBotao.tocar();
		telaAtual = tMenu;
	}
}

void Jogo::telaTutorial()
{
	telas.setSpriteSheet("tTutorial");
	telas.desenhar(512, 384);
	botoes[bVoltar].setPos(920, 720);
	botoes[bVoltar].desenhar();
	botoes[bVoltar].atualizar();
	if (botoes[bVoltar].estaClicado() && telaAtual == tTutorial)
	{
		gMusica.parar();
		gMusica.tocar("musicaAbacaxi", true);
		somBotao.tocar();
		telaAtual = tMenu;
	}
}

void Jogo::telaLoja()
{
	telas.setSpriteSheet("tLoja");
	telas.desenhar(512, 384);
	botoes[bCortador].setPos(370, 260);
	botoes[bCortador].desenhar();
	botoes[bCortador].atualizar();
	botoes[bSemente].setPos(370, 380);
	botoes[bSemente].desenhar();
	botoes[bSemente].atualizar();
	botoes[bAbacaxi].setPos(370, 480);
	botoes[bAbacaxi].desenhar();
	botoes[bAbacaxi].atualizar();
	if (botoes[bCortador].estaClicado() && telaAtual == tLoja)
		loja.comprarCortador();
	if (botoes[bSemente].estaClicado() && telaAtual == tLoja)
		loja.comprarSementes();
	if (botoes[bAbacaxi].estaClicado() && telaAtual == tLoja)
	{
		loja.venderAbacaxi();
		loja.usarAbacaxi();
	}


	if (gTeclado.pressionou[TECLA_L])
	{
		telaAtual = tJogo;
	}

}
