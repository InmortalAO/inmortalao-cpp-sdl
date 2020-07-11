/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "ini.h"


ini::ini()
{
	graficosIndex = new std::map<int, graficoData>();
}

void ini::cargarIndicesGraficos()
{
	short int grh;
	short int lgrh;
	short int frame;
	short int tempint;

	std::ifstream archivo("./Recursos/Init/graficos.ind", std::ios::in | std::ios::binary);
	
	archivo.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
	archivo.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
	archivo.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
	archivo.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
	archivo.read(reinterpret_cast<char *>(&tempint), sizeof(short int));

	archivo.read(reinterpret_cast<char *>(&grh), sizeof(short int));


	while (grh>0)
	{
	
		graficoData indexGrafico;

		archivo.read(reinterpret_cast<char *>(&indexGrafico.numframes), sizeof(short int));

		//Los frames contienen indexaciones de graficos ya hechas anteriormente
		//por lo tanto si tiene numFrames >1 significa que ya le fueron leidas las propiedades
		//anteriormente
		indexGrafico.frames = new short int[indexGrafico.numframes];

		if (indexGrafico.numframes > 1)
		{
			
			for (frame = 0; frame<indexGrafico.numframes; frame++)
			{
				archivo.read(reinterpret_cast<char *>(&indexGrafico.frames[frame]), sizeof(short int));
			}

			archivo.read(reinterpret_cast<char *>(&indexGrafico.speed), sizeof(short int));

			indexGrafico.pixelheight = (*graficosIndex)[indexGrafico.frames[0]].pixelheight;
			indexGrafico.pixelwidth = (*graficosIndex)[indexGrafico.frames[0]].pixelwidth;
			indexGrafico.tilewidth = (*graficosIndex)[indexGrafico.frames[0]].tilewidth;
			indexGrafico.tileheight = (*graficosIndex)[indexGrafico.frames[0]].tileheight;
		}
		else
		{
			archivo.read(reinterpret_cast<char *>(&indexGrafico.filenum), sizeof(short int));
			archivo.read(reinterpret_cast<char *>(&indexGrafico.sx), sizeof(short int));
			archivo.read(reinterpret_cast<char *>(&indexGrafico.sy), sizeof(short int));
			archivo.read(reinterpret_cast<char *>(&indexGrafico.pixelwidth), sizeof(short int));
			archivo.read(reinterpret_cast<char *>(&indexGrafico.pixelheight), sizeof(short int));
			
			indexGrafico.tilewidth = indexGrafico.pixelwidth / 32.0;
			indexGrafico.tileheight = indexGrafico.pixelheight / 32.0;

			indexGrafico.frames[0] = grh;
		}

		(*graficosIndex)[grh] = indexGrafico;
		
		lgrh = grh;
		archivo.read(reinterpret_cast<char *>(&grh), sizeof(short int));
		if (lgrh == grh){
			grh = 0;
		}
		
	}
	archivo.close();
}

int ini::getNumeroArchivo(int index)
{
	return (*graficosIndex)[index].filenum;
}

int ini::getXindex(int index)
{
	return (*graficosIndex)[index].sx;
}

int ini::getYindex(int index)
{
	return (*graficosIndex)[index].sy;
}

int ini::getHindex(int index)
{
	return (*graficosIndex)[index].pixelheight;
}

int ini::getWindex(int index)
{
	return (*graficosIndex)[index].pixelwidth;
}

int ini::getTileW(int index)
{
	return (*graficosIndex)[index].tilewidth;
}

int ini::getTileH(int index)
{
	return (*graficosIndex)[index].tileheight;
}

int ini::getFrameCount(int index)
{
	return (*graficosIndex)[index].numframes;
}

int ini::getIndexFrame(int index,int frame)
{
	return (*graficosIndex)[index].frames[frame];
}

int ini::getGrhSpeed(int index)
{
	return (*graficosIndex)[index].speed;
}


ini::~ini()
{
}
