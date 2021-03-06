#include "../../comum.h"
#include "fase1.h"
#include "../../Player.h"

void createLevelOne(LevelOne *levelOne, Player *player){
	player->chances = 0;
	levelOne->portas = al_load_bitmap("./data/levels/fase1/circ_off.png");
	levelOne->circ1_on = al_load_bitmap("./data/levels/fase1/circ1_on.png");
	levelOne->circ2_on = al_load_bitmap("./data/levels/fase1/circ2_on.png");
	levelOne->circ3_on = al_load_bitmap("./data/levels/fase1/circ3_on.png");
	levelOne->circ4_on = al_load_bitmap("./data/levels/fase1/circ4_on.png");
	levelOne->circ5_on = al_load_bitmap("./data/levels/fase1/circ5_on.png");

	levelOne->circ1_off = al_load_bitmap("./data/levels/fase1/circ1_off.png");
	levelOne->circ2_off = al_load_bitmap("./data/levels/fase1/circ2_off.png");
	levelOne->circ3_off = al_load_bitmap("./data/levels/fase1/circ3_off.png");
}


void logicLevelOne(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player)
{
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 65 && player->state.y < 154))
	{
		player->chances++;
		if(*gateOne == false){
			*gateOne = true;
			printf("False para true\n");
		}
		else{
			*gateOne = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 155 && player->state.y < 238))
	{
		player->chances++;
		if(*gateTwo == false){
			*gateTwo = true;
			printf("False para true\n");
		}
		else{
			*gateTwo = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 254 && player->state.y < 338))
	{
		player->chances++;
		if(*gateThree == false){
			*gateThree = true;
			printf("False para true\n");
		}
		else{
			*gateThree = false;
			printf("True para false\n");
		}
	}
}

void drawLogicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne, bool *complete){
	if(gateOne)
	{
		levelOne->circ1 = levelOne->circ1_on;
	}
	else
	{
		levelOne->circ1 = levelOne->circ1_off;
	}
	if(gateTwo)
	{
		levelOne->circ2 = levelOne->circ2_on;
	}
	else
	{
		levelOne->circ2 = levelOne->circ2_off;
	}
	if(gateThree)
	{
		levelOne->circ3 = levelOne->circ3_on;
	}
	else
	{
		levelOne->circ3 = levelOne->circ3_off;

	}
	if(gateOne && gateTwo)
	{
		levelOne->circ4 = levelOne->circ4_on;
		levelOne->isOn[3] = true;
	}
	else
	{
		levelOne->isOn[3] = false;
	}
	if((gateOne && gateTwo) && gateThree)
	{
		levelOne->circ5 = levelOne->circ5_on;
		levelOne->isOn[4] = true;
		*complete = true;
	}
	else
	{
		levelOne->isOn[4] = false;
	}
	levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
	levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
}

void initDrawGatesLevelOne(LevelOne *levelOne){
	int i;

	for(i = 0; i < 5; i++){
		levelOne->isOn[i] = false;
	}
}

void drawLevelOne(LevelOne *levelOne){
	al_draw_bitmap(levelOne->portas, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ1, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ2, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ3, 0, 0 , 0);
	if(levelOne->isOn[3])al_draw_bitmap(levelOne->circ4, 0, 0 , 0);
	if(levelOne->isOn[4])al_draw_bitmap(levelOne->circ5, 0, 0 , 0);
}

void destroyLevelOne(LevelOne *levelOne){
	al_destroy_bitmap(levelOne->circ1_on);
	al_destroy_bitmap(levelOne->circ2_on);
	al_destroy_bitmap(levelOne->circ3_on);
	al_destroy_bitmap(levelOne->circ4_on);
	al_destroy_bitmap(levelOne->circ5_on);

	al_destroy_bitmap(levelOne->circ1_off);
	al_destroy_bitmap(levelOne->circ2_off);
	al_destroy_bitmap(levelOne->circ3_off);
}