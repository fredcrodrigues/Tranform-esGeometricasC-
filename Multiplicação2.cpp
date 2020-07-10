
#include<opencv2/opencv.hpp> //Biblioteca
#include<opencv2/imgproc.hpp>
#include<iostream>//Biblioteca padrao
#include<stdlib.h>
#include <locale.h> 

using namespace std;
using namespace cv; // defininido o nome dabivlioteca


Mat Rot(Mat image) {

	int lin = image.rows;
	int col = image.cols;


	Mat ImageRot(lin , col, image.type());

	int xR, yR , saidaR;

	for (int l = 0; l < col; l++) {

		for (int c = 0; c < lin; c++) {

			uchar saidaR = image.at<uchar>(l,c);  

			xR = l * cos(45) - c * sin(45);
			yR = l * sin(45) + c * cos(45);
			

			if((xR < lin) && (yR < col)) {

				ImageRot.at<uchar>(l, c) = saidaR;
			}

			
		}
	}
	return ImageRot;
}

Mat Transla(Mat image , int lin , int col) {
	

	Mat ImageTrans(lin, col, image.type());
	int x, y , saidaT;


		for (int l = 0; l < lin; l++) {
			for (int c = 0; c < col; c++) {

				saidaT = image.at<uchar>(l, c);
				

				x = l + 15;
				y = c + 15;
			
				if ((x < lin) && (y < col)) {
					ImageTrans.at<uchar>(x, y) = saidaT;
				}
			}
		}

		return ImageTrans;

}

Mat Esc(Mat image , int lin, int col) {


	Mat ImageSca(lin, col, image.type());
	int x, y, saidaE;


	for (int l = 0; l < lin; l++) {
		for (int c = 0; c < col; c++) {

			saidaE = image.at<uchar>(l, c);


			x = l * 2;
			y = c * 2;

			if ((x < lin) && (y < col)) {
				ImageSca.at<uchar>(x, y) = saidaE;
			}
		}
	}

	return ImageSca;



}

Mat EsP(Mat image , int lin, int col) {

	

	Mat ImageEsP(lin, col, image.type());
	int x, y, saidaEs;

	 

	/// eixo x reflexao

	for (int l = 0; l < lin; l++) {
		for (int c = 0; c < col; c++) {

			saidaEs = image.at<uchar>(l, c);

			ImageEsP.at<uchar>( (col - 1) - l , c ) = saidaEs;


			//x = (1 * l) + (0 * c);
			//y = (0*  l) + ( -1 * c);

			//if ((x < lin) && (y < col)) {
				//ImageEsP.at<uchar>(l, c) = saidaEs;
			//}
			
		}
	}

	return ImageEsP;



}

Mat Multiplicar(Mat image, Mat image2 , int lin , int col) {

	// OPERAÇÃO PIXEL A PXEL NA MULTIPLICAÇÃO
	
	int x, y, saidaM;

	Mat MatrizMul(image.rows, image.cols, image.type());
	

	for (int l = 0; l< lin; l++) {
		for (int c = 0; c < col; c++) {

			saidaM = image.at<uchar>(l, c) * image2.at<uchar>(l, c);

			if (saidaM > 255) {
				MatrizMul.at<uchar>(l, c) = 255;
			}
			
		}
	}
	return MatrizMul;
}

Mat somaP(Mat image , Mat image2 , int lin , int col) {


	int x, y, saidaSoma;

	Mat MatrizPond(lin, col, image.type());


	for (int l = 0; l < lin; l++) {
		for (int c = 0; c < col; c++) {

			x = image.at<uchar>(l, c);  
			y = image2.at<uchar>(l, c);  
			saidaSoma = (x * 2) + (y * 2) / 2; /// * pesos po imagens

			if (saidaSoma > 255) {
				MatrizPond.at<uchar>(l, c) = 255;
			}

		}
	}
	return MatrizPond;


}
Mat suB(Mat image, Mat image2 , int lin, int col) {



	int x, y, saidaSub;

	Mat MatrizSub(lin, col, image.type());


	for (int l = 0; l < lin; l++) {
		for (int c = 0; c < col; c++) {

			x = image.at<uchar>(l, c);

			y = image2.at<uchar>(l, c);

			saidaSub = x - y;

			if (saidaSub < 0 ) {

				MatrizSub.at<uchar>(l, c) = 0;
			}
			else {
					
				MatrizSub.at<uchar>(l, c) = saidaSub;
			}

		}
	}
	return MatrizSub;


}
int main()
{
	Mat image , image2 , ImageTrans , ImageRot , ImageE , ImageSub, ImageEs , ImageM , ImageSo; // , ImageTrans;
	

	image = imread("MARIO/Mario22.jpg" , cv::IMREAD_GRAYSCALE);
	image2 = imread("MARIO/Mario2.jpg" , cv::IMREAD_GRAYSCALE);

	int lin = image.rows;
	int col = image.cols;


	// ImageTrans = Transla(image , lin , col); // TRANSLAÇÃO

	//ImageRot = Rot(image  , lin , col);		// ROTAÇÃO
					
	//ImageE = Esc(image , lin , col);			// ESCALA

	//ImageEs = EsP(image  , lin , col);			// REFLEXAO

	// ImageM = Multiplicar(image, image2 , lin , col); /// OPERAÇÃO ARTIMETICA MULTIPLICAR
	// ImageSo = somaP(image , image2 , lin , col); ///OPERAÇÃO ARTMERICA SOMA 
	 ImageSub = suB(image, image2 , lin , col); /// operação subtração




	// imshow("Translação", ImageTrans);
	//imshow("Rotação", ImageRot);
	//imshow("Escala", ImageE);
	// imshow("Espe", ImageE);  // eixo X
	//imshow("MULTIPLICAÇÃO", ImageM);

	//imshow("SOMA PONDERADA", ImageSo);
	imshow("Subtração", ImageSub);
	waitKey(0);

	
	//imshow("Translação", ImageTrans);
	

}


