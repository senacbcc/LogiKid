/*
 * Contem as informações do sprite sheet
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct
{
	ALLEGRO_BITMAP *image;

	int x;
	int y;

	int posInSprite;
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
}Image;

typedef struct
{
	bool direita, esquerda;
	bool sobe, desce;
	bool idleE, idleD;
}State;

typedef struct
{
	int lgAND, lgOr, lgNAND, lgNOR;
	int lgNEG, lgXOR, lgXNOR;
}LogicGates;

typedef struct
{
	State state;
	Image image;
	LogicGates lGates;
}Player;

void CreatePlayer(Player *player, int hStartPosition, int wStartPosition);
void moveDireita(Player *player);
void moveEsquerda(Player *player);
void moveCima(Player *player);
void moveBaixo(Player *player);
void ProcessaMovimentoEsquerda(Player *player);
void ProcessaMovimentoDireita(Player *player);
void ProcessaMovimentoCima(Player *player);
void ProcessaMovimentoBaixo(Player *player);
void ValidaMovimento_CK_UP(Player *player);
void ValidaMovimento_TIMER(Player *player);
void ValidaMovimento(Player *player);