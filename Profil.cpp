/*#include "ImageBase.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char **argv)

{
	///////////////////////////////////////// Exemple d'un seuillage d'image
	char cNomImgLue[250];

	fstream output("profilBaboon.dat",fstream::out);
	if(output.is_open()){


	}

	if (argc != 4)
	{
		printf("Usage: ImageIn.pgm RaworColonne numero \n");
		return 1;
	}
	sscanf (argv[1],"%s",cNomImgLue) ;
	string profileType(argv[2]);
	//sscanf (argv[2],"%s",profileType);

	int index=atoi(argv[3]);




	//ImageBase imIn, imOut;
	ImageBase imIn;
	imIn.load(cNomImgLue);


if(profileType=="raw"){


	for(int x = 0; x < imIn.getWidth(); ++x){
            output << x<< " "<<(int) imIn[index][x]<<endl;


	}




}
if(profileType=="col"){


	for(int x = 0; x < imIn.getHeight(); ++x){
            output << x <<" "<<(int) imIn[x][index];


	}




}




	return 0;

}*/
