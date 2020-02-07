

#include "ImageBase.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
void Histo(ImageBase &inputImage,fstream &dataOutput,vector <int> &occurences);
void seuillage(ImageBase &imIn,ImageBase &imOut,int &seuil);
void Dilatation4(ImageBase &imIn,ImageBase &imOut);
void Erosion4(ImageBase &imIn,ImageBase &imOut);
void Expension(ImageBase &imgIn,ImageBase &imgOut);
void Difference(ImageBase &imageSeuil,ImageBase &imageDilater, ImageBase &imOut );
void SearchAlphaAndbeta(vector<int> &histo,int &alpha,int &beta);
bool inBound(ImageBase &imIn,int raw,int col );
void SeuillageExtrema(ImageBase &imgIn,ImageBase &imgOut,int &Smin,int &Smax);
int main(int argc, char **argv)

{





char cNomImgLue[250],cNomImgOut[250];
int SminRed=40,SmaxRed=220,SminBlue=45,SmaxBlue=215,SminGreen=50,SmaxGreen=210;


	if (argc != 3)
	{
		printf("Usage: ImageIn.pgm ImageOut.pgm \n");
		return 1;
	}
	sscanf (argv[1],"%s",cNomImgLue) ;
	sscanf (argv[2],"%s",cNomImgOut) ;
	ImageBase imIn,imgR,imgB,imgG,*R,*G,*B;
	imIn.load(cNomImgLue);
	ImageBase imOut(imIn.getWidth(),imIn.getHeight(),imIn.getColor());

	vector<int> occurencesRed(256,0);
	vector<int> occurencesBlue(256,0);
	vector<int> occurencesGreen(256,0);
	vector<int> occurencesRed1(256,0);
	vector<int> occurencesBlue1(256,0);
	vector<int> occurencesGreen1(256,0);
	vector<int> occurencesGreen11(256,0);
	fstream outputR("BaboonHistoRed.dat",fstream::out);
	fstream outputB("BaboonHistoBlue.dat",fstream::out);
	fstream outputG("BaboonHistoGreen.dat",fstream::out);
	fstream outputR1("BaboonHistoExtremaRed.dat",fstream::out);
	fstream outputB1("BaboonHistoExtremaBlue.dat",fstream::out);
	fstream outputG1("BaboonHistoExtremaGreen.dat",fstream::out);
	fstream outputG11("BaboonHistoExtremaGreencopy.dat",fstream::out);
R=(imIn.getPlan(imIn.PLAN_R));
imgR=(*R);
B=(imIn.getPlan(imIn.PLAN_B));
imgB=(*B);
G=(imIn.getPlan(imIn.PLAN_G));
imgG=(*G);
ImageBase imgRO(imgR.getWidth(),imgR.getHeight(),imgR.getColor());
ImageBase imgBO(imgB.getWidth(),imgB.getHeight(),imgB.getColor());
ImageBase imgGO(imgG.getWidth(),imgG.getHeight(),imgG.getColor());
ImageBase imgRO1(imgR.getWidth(),imgR.getHeight(),imgR.getColor());
ImageBase imgBO1(imgB.getWidth(),imgB.getHeight(),imgB.getColor());
ImageBase imgGO1(imgG.getWidth(),imgG.getHeight(),imgG.getColor());

cout<<"alpha"<<endl;
Histo(imgR,outputR,occurencesRed);
Histo(imgB,outputB,occurencesBlue);
Histo(imgG,outputG,occurencesGreen);

SeuillageExtrema(imgR,imgRO,SminRed,SmaxRed);
SeuillageExtrema(imgB,imgBO,SminBlue,SmaxBlue);
SeuillageExtrema(imgG,imgGO,SminGreen,SmaxGreen);

Histo(imgRO,outputR1,occurencesRed1);
Histo(imgBO,outputB1,occurencesBlue1);
Histo(imgGO,outputG1,occurencesGreen1);



Expension(imgGO,imgGO1);
Expension(imgRO,imgRO1);
Expension(imgBO,imgBO1);

Histo(imgGO1,outputG11,occurencesGreen11);
imOut.set_plan(imOut.PLAN_R,imgRO1);
imOut.set_plan(imOut.PLAN_B,imgBO1);
imOut.set_plan(imOut.PLAN_G,imgGO1);
cout<<"yoo"<<endl;

imOut.save(cNomImgOut);




}


void SeuillageExtrema(ImageBase &imgIn,ImageBase &imgOut,int &Smin,int &Smax){

for(int x = 0; x < imgIn.getHeight(); ++x)
		for(int y = 0; y < imgIn.getWidth(); ++y){
                {

            if(imgIn[x][y]<Smin){
                imgOut[x][y]=Smin;

            }else{
            if(imgIn[x][y]>Smax){
                imgOut[x][y]=Smax;
            }else{imgOut[x][y]=imgIn[x][y];}
            }




		}


}



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


void Expension(ImageBase &imgIn,ImageBase &imgOut){

vector<int> occurences(256,0);
 fstream output2("baboonHistoExtended.dat",fstream::out);
 fstream output1("baboonHisto.dat",fstream::out);

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
		    imgOut[x][y]=round(alpha+imgIn[x][y]*beta);

		    }

		    }
		   // vector<int> occurences1(256,0);


		//Histo(imgOut,output2,occurences1);



		}








