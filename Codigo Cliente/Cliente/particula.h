
/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include <iostream>
#include "particulaIndividual.h"

class particula
{
public:
	particula();
	void setName(std::string nameParam);
	std::string getName();
	void setNumParticles(short int NumOfParticlesParam);
	short int getNumParticles();
	void setNumGrh(int NumGrhsParam);
	int getNumGrh();
	void setId(int idParam);
	int getId();
	void setX1(int x1Param);
	int getX1();
	void setY1(int y1Param);
	int getY1();
	void setX2(int x2Param);
	int getX2();
	void setY2(int y2Param);
	int getY2();
	void setAngle(int angleParam);
	int getAngle();
	void setVecX1(int vecx1Param);
	int getVecX1();
	void setVectX2(int vecx2Param);
	int getVectX2();
	void setVecY1(int vecy1Param);
	int getVecY1();
	void setVecY2(int vecy2Param);
	int getVecY2();
	void setLife1(int life1Param);
	int getLife1();
	void setLife2(int life2Param);
	int getLife2();
	void setFriction(int frictionParam);
	int getFriction();
	void setSpin(char spinParam);
	char getSpin();
	void setSpinSpeedL(short int spin_speedLParam);
	short int getSpinSpeedL();
	void setSpinSpeedH(short int spin_speedHParam);
	short int getSpinSpeedH();
	void setAlphaBlend(char AlphaBlendParam);
	char getAlphaBlend();
	void setGravity(char gravityParam);
	char getGravity();
	void setGravStregth(int grav_strengthParam);
	int getGravStregth();
	void setBounceStrength(int bounce_strengthParam);
	int getBounceStrength();
	void setXMove(int XMoveParam);
	int getXMove();
	void setYMove(int YMoveParam);
	int getYMove();
	void setMoveX1(int move_x1Param);
	int getMoveX1();
	void setMoveX2(int move_x2Param);
	int getMoveX2();
	void setMoveY1(int move_y1Param);
	int getMoveY1();
	void setMoveY2(int move_y2Param);
	int getMoveY2();
	void setGrhList(int* grh_listParam);
	int* getGrhLista();
	void setColorInt(unsigned char** colortintParam);
	unsigned char** getColorInt();
	void setSpeed(double speedParam);
	double getSpeed();
	void setLifeCounter(double life_counterParam);
	double getLifeCounter();
	void setGrhResize(bool grh_resizeParam);
	bool getGrhResize();
	void setGrhResizeX(short int grh_resizexParam);
	short int getGrhResizeX();
	void setGrhResizeY(short int grh_resizeyParam);
	short int getGrhResizeY();
	void dibujar(int indexParticulaIndividual);
	int getParticleGrhIndex(int indexParticulaIndividual);
	int getParticleX(int indexParticulaIndividual);
	int getParticleY(int indexParticulaIndividual);
	void setParticulasIndividuales();
	void setMovement(bool movementParam);
	particulaIndividual** particulasIndividuales;
	~particula();
private:
	std::string name;
	short int NumOfParticles;
	int NumGrhs;
	int id;
	int x1;
	int y1;
	int x2;
	int y2;
	int angle;
	int vecx1;
	int vecx2;
	int vecy1;
	int vecy2;
	int life1;
	int life2;
	int friction;
	char spin;
	short int spin_speedL;
	short int spin_speedH;
	char AlphaBlend;
	char gravity;
	int grav_strength;
	int bounce_strength;
	int XMove;
	int YMove;
	int move_x1;
	int move_x2;
	int move_y1;
	int move_y2;
	int* grh_list;
	unsigned char** colortint;
	double speed;
	double life_counter;
	bool grh_resize;
	short int grh_resizex;
	short int grh_resizey;
	bool movement;
};

