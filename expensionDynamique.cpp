/*
#include "ImageBase.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void Histo(ImageBase &inputImage,fstream &dataOutput,vector <int> &occurences);
void seuillage(ImageBase &imIn,ImageBase &imOut,int &seuil);
void Dilatation4(ImageBase &imIn,ImageBase &imOut);
void Erosion4(ImageBase &imIn,ImageBase &imOut);
void Specification(ImageBase &imgIn,ImageBase &imgOut);
void Difference(ImageBase &imageSeuil,ImageBase &imageDilater, ImageBase &imOut );
void SearchAlphaAndbeta(vector<int> &histo,int &alpha,int &beta);
bool inBound(ImageBase &imIn,int raw,int col );
int main(int argc, char **argv)

{

    fstream output("blackHisto.dat",fstream::out);
	char cNomImgLue[250],cNomImgOut[250];




	if (argc != 3)
	{
		printf("Usage: ImageIn.pgm ImageOut.pgm \n");
		return 1;
	}
	sscanf (argv[1],"%s",cNomImgLue) ;
	sscanf (argv[2],"%s",cNomImgOut) ;
	ImageBase imIn;
	imIn.load(cNomImgLue);
	ImageBase imOut(imIn.getWidth(),imIn.getHeight(),imIn.getColor());
Specification(imIn,imOut);
imOut.save(cNomImgOut);

}










void seuillage(ImageBase &imIn,ImageBase &imOut,int &seuil){

for(int x = 0; x < imIn.getHeight(); ++x)
		for(int y = 0; y < imIn.getWidth(); ++y)
		{
			if (imIn[x][y] < seuil)
				imOut[x][y] =255;
			else imOut[x][y] = 0;
		}


}


void Histo(ImageBase &inputImage,fstream &dataOutput,vector <int> &occurences){



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

void SearchAlphaAndbeta(vector<int> &histo,int &alpha,int &beta){


for(int i=0;i<histo.size();i++){

    if(histo[i]!=0){

        alpha=i;
        break;

    }




}

for(int j=255;j>=0;j--){

    if(histo[j]!=0){

        beta=j;
        break;

    }




}


}


void Specification(ImageBase &imgIn,ImageBase &imgOut){

vector<int> occurences(256,0);
 fstream output2("blackHistoExtended.dat",fstream::out);
 fstream output1("blackHisto.dat",fstream::out);

Histo(imgIn,output1,occurences);
int minn=0,maxx=0;

SearchAlphaAndbeta(occurences,minn,maxx);
int alpha = -((float)255.0 * minn) / (maxx-minn);
int beta = 255.0 / (maxx-minn);
cout<<"alpha = "<<alpha<<"beta ="<<beta<<endl;

for(int x = 0; x < imgIn.getHeight(); ++x)
		for(int y = 0; y < imgIn.getWidth(); ++y)
		{

		    {
		    imgOut[x][y]=alpha+imgIn[x][y]*beta;

		    }

		    }
		    vector<int> occurences1(256,0);


		Histo(imgOut,output2,occurences1);



		}



*/




