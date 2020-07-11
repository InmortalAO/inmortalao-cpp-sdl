/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "cabezas.h"


cabezas::cabezas()
{
	Cabezas = new std::map<int, headdata>();
}

void cabezas::cargar()
{
	short int numheads;
	short int tempint;

	std::ifstream fentrada("./Recursos/Init/cabezas.ind", std::ios::in | std::ios::binary);
	//la cabecera 
	fentrada.seekg(255 + 4 + 4);
	fentrada.read(reinterpret_cast<char *>(&numheads), sizeof(short int));

	headdata tempHead;

	for (int i = 0; i<numheads; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempHead.head[NORTH].grhindex =  tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempHead.head[EAST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempHead.head[SOUTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempHead.head[WEST].grhindex = tempint;

		(*Cabezas)[i] = tempHead;
	}
	fentrada.close();
}

cabezas::~cabezas()
{
}
