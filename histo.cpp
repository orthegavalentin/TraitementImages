/*#include "ImageBase.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void Histo(ImageBase &inputImage,fstream &dataOutput);
int main(int argc, char **argv)

{
	///////////////////////////////////////// Exemple d'un seuillage d'image
	char cNomImgLue[250];

	fstream output("lenaHisto.dat",fstream::out);
	if(output.is_open()){


	}

	if (argc != 2)
	{
		printf("Usage: ImageIn.pgm  \n");
		return 1;
	}
	sscanf (argv[1],"%s",cNomImgLue) ;
	string profileType(argv[2]);
	//sscanf (argv[2],"%s",profileType);

	int index=atoi(argv[3]);




	//ImageBase imIn, imOut;
	ImageBase imIn;
	imIn.load(cNomImgLue);


Histo(imIn,output);

	return 0;

}

void Histo(ImageBase &inputImage,fstream &dataOutput){

vector <int> occurences(256,0);


	for(int x = 0; x < inputImage.getHeight(); ++x)
		{for(int y = 0; y < inputImage.getWidth(); ++y)
		{

        int val =inputImage[x][y];
        occurences[val]++;



		}}
		for(int i=0; i<occurences.size();i++){

            dataOutput<<i<<" "<<occurences[i]<<endl;


		}
}
*/
