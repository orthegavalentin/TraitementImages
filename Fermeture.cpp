/*
#include "ImageBase.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void Histo(ImageBase &inputImage,fstream &dataOutput);
void seuillage(ImageBase &imIn,ImageBase &imOut,int &seuil);
void Dilatation4(ImageBase &imIn,ImageBase &imOut);
void Erosion4(ImageBase &imIn,ImageBase &imOut);
bool inBound(ImageBase &imIn,int raw,int col );
int main(int argc, char **argv)

{
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

ImageBase imOutSeuil(imIn.getWidth(),imIn.getHeight(),imIn.getColor());
ImageBase imOutDilatation(imIn.getWidth(),imIn.getHeight(),imIn.getColor());
ImageBase imOutErosion(imIn.getWidth(),imIn.getHeight(),imIn.getColor());
int seuil=150;

seuillage(imIn,imOutSeuil,seuil);
//on enchaine une dilatation suivi d'une erosion

Dilatation4(imOutSeuil,imOutDilatation);
Erosion4(imOutDilatation,imOutErosion);
char* imgOuvert("09Fermeture4.pgm");
imOutSeuil.save(cNomImgOut);
imOutErosion.save(imgOuvert);

	return 0;

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




void Dilatation4(ImageBase &imIn,ImageBase &imOut){

for(int x = 0; x < imIn.getHeight(); ++x){
		for(int y = 0; y < imIn.getWidth(); ++y)
        {



                if((inBound(imIn,x-1,y)&&inBound(imIn,x+1,y)&&inBound(imIn,x,y+1)&&inBound(imIn,x,y-1))&&(imIn[x+1][y]==255||
                    imIn[x-1][y]==255||imIn[x][y+1]==255||imIn[x][y-1]==255||imIn[x][y]==255)){
                    imOut[x][y]=255;







            }else{

            imOut[x][y]=0;
            }


            }



        }








}
void Erosion4(ImageBase &imIn,ImageBase &imOut){

for(int x = 0; x < imIn.getHeight(); ++x)
		for(int y = 0; y < imIn.getWidth(); ++y)
        {
            {
                if(imIn[x][y]==255) {

                if(inBound(imIn,x-1,y)&&inBound(imIn,x+1,y)&&inBound(imIn,x,y+1)&&inBound(imIn,x,y-1)&&imIn[x+1][y]==255 &&
                    imIn[x-1][y]==255&&imIn[x][y+1]==255&&imIn[x][y-1]==255){
                    imOut[x][y]=255;





                }else{
                 imOut[x][y]=0;}
            }else{

            imOut[x][y]=0;


            }


            }



        }








}


bool inBound(ImageBase &imIn,int raw,int col ){

return(raw>=0&&raw<imIn.getWidth()&&col>=0&&col<imIn.getHeight());




}

*/


