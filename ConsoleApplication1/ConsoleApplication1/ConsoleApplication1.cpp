// OpenGL.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
/*

#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>
#include <vector>
#include <array>
#include <ctime>

using namespace std;
int antiHorario = 0, OffsetX = 0, OffsetY = 0;
float R = 0, G = 0, B = 1;
GLint V = 0, Ang = 0;
//GLint DesLoca = -100;

GLfloat angle, fAspect, Desloca;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;
char dir = 1;

//Redimensionamento
GLfloat ScaleX = 0, ScaleY = 0, ScaleZ = 0;
GLfloat eixoX = 0, eixoY = 0, eixoZ = 0;

void init(void) {
	// Três primeiros argumentos corresponde a valores normalizados de R, G e B. O último parâmetro
	// é o "alpha value" que é utilzado para "blend operations", ou seja, determinar a cor resultante de dois
	// objetos que se sobrepõem.
	glClearColor(1.0, 1.0, 1.0, 0);
	// Nesse primeiro programa, será mostrada uma linha em duas dimensões em tela. Para tanto,
	// é necessário "dizer" ao OpenGL como projetar nossa figura na tela, pois projetar uma figura bi-dimensional
	// é tratado pelo OpenGL como um caso especial de uma visualização tridimensional. Os dois próximos comandos
	// especificam que será utilizado uma projeção ortogonal (projeção de uma figura no espaço em um plano) para
	// mapear o conteudo de uma área bidimensional retangular para a tela, sendo que a coordenada "x" variará de 0 a 200
	// e a "y" de 0 a 150. Dessa forma, define-se a coordenada "lower left-corner" para 0 e 0 e a "upper right-corner"
	// para 200 e 150, respectivamente x e y.
	glMatrixMode(GL_PROJECTION);
	//midpoint
	//gluOrtho2D(-500, 500, -500, 500);
     gluOrtho2D(-800, 800, -800, 800);
	//translação
	//gluOrtho2D(0, 500, 0,500);


	

}


void caracol(void){

	glClear(GL_COLOR_BUFFER_BIT);
	
	GLdouble theta;
	GLuint regHex, wTamPad;
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0f);
	GLint k;
	wTamPad = 300;
	glBegin(GL_LINES);
	// Ver explicação em sala de aula sobre círculo trigonométrico e o porquê desse
	// for conseguir desenhar um hexagono regular
	for (k = 0; k < 150; k++) {
		theta = 6.2831853 * k / 150;
		glVertex2i(640, 340);
		glVertex2i(640 + wTamPad * cos(theta),
			340 + wTamPad * sin(theta));
		wTamPad -= 1;
	}
	glEnd();
	glFlush();

}




// Exercício da Aula 16 / 04 / 2020
//---Besenham Line:
void besenhamLine(void) {

	//Coordenadas
	glBegin(GL_LINES);
	//eixo x
	glVertex2i(-400, 0);
	glVertex2i(400, 0);

	//eixo y
	glVertex2i(0, -400);
	glVertex2i(0, 400);
	glEnd();

	glFlush();

	

	//Indice de variação
	int Ax, Ay;

	int XI = 0   , YI = 22;
	int XF = 350 , YF = 350;
	
	//Calculo do Indice de variação
	Ax = XF - XI;
	Ay = YF - YI;

	int p[350], y[350], x[350];
	y[0] = YI;
	x[0] = XI;
	p[0]= 2 * Ay - Ax;

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(x[0], y[0]);
	glEnd();
	glFlush;

	int k;

	for (k = 1; k <= XF - 1; k++) {

		if (p[k-1] < 0)
		{
			p[k] = p[k - 1] + 2 * Ay;
			y[k] = y[k - 1];
			x[k] = k;
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i(x[k], y[k]);
			glEnd();
			//glFlush;
		}
		else {
			p[k] = p[k - 1] + 2 * Ay - 2 * Ax;
			y[k] = y[k - 1] + 1 ;
			x[k] = k;
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i(x[k], y[k]);
			glEnd();
		//	glFlush;
		}
		glFlush;
		//Imprime resposta:
		cout << "x[" << k - 1 << "] = " << k - 1 << " | " << "y[" << k - 1 << "] = " << y[k - 1] << " | " << "p[" << k - 1 << "] = " << p[k - 1] << endl;


	}



	glFlush;

}






// Exercício da Aula 23 / 04 / 2020


void midPointCircunferencia(void) {


	//Coordenadas
	glBegin(GL_LINES);
	//eixo x
	glVertex2i(-500,0);
	glVertex2i(500, 0);

	//eixo y
	glVertex2i(0,-500);
	glVertex2i(0,500);
	glEnd();




	int x0 = 0;
	int raio = 400;
	int y[360];
	y[0] = raio;
	int p = 1 - raio;
	//glPointSize(10);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(x0, raio);
	glEnd();


	int pK[360];
	pK[0] = p;
	int k;
	for (k = 1; k <= 359; k++) {
		
		//Calcula Y[k] e pK[k]
		if (pK[k-1] < 0) {
			y[k] = y[k - 1];
			pK[k] = pK[k - 1]  + 2 * k + 1;
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i( k , y[k] );//( x, y )
			glVertex2i( y[k] , k );//( y, x )
			glVertex2i( k * -1 , y[k] ); //(- x, y )
			glVertex2i( y[k] * -1 , k ); //(- y, x )
			glVertex2i( y[k] * -1 , k * -1 ); //(- y, -x )
			glVertex2i( k * -1 , y[k] * -1 ); //(- x, -y  )
			glVertex2i(k , y[k] * -1 ); //( x, -y  )
			glVertex2i(y[k]  , k * -1); //( y, -x  )

			glEnd();
			glFlush();
		}
		else {
			y[k] = y[k - 1] - 1;
			pK[k] = pK[k - 1] + 2 * k + 1 - 2 * y[k] + 1;
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i(k, y[k]);//( x, y )
			glVertex2i(y[k], k);//( y, x )
			glVertex2i(k * -1, y[k]); //(- x, y )
			glVertex2i(y[k] * -1, k); //(- y, x )
			glVertex2i(y[k] * -1, k * -1); //(- y, -x )
			glVertex2i(k * -1, y[k] * -1); //(- x, -y  )
			glVertex2i(k, y[k] * -1); //( x, -y  )
			glVertex2i(y[k], k * -1); //( y, -x  )

			glEnd();
			glFlush();
		}

		

	   //Imprime resposta:
		cout << "x[" << k - 1 << "] = " << k - 1 << " | " << "y[" << k - 1 << "] = " << y[k - 1] << " | " << "p[" << k - 1 << "] = " << pK[k - 1] << endl;

		
		
	}


	
	
}


//Exercício da Aula 30 / 04 / 2020

void translacao(void) {

	//EXEMPLO 2: FONTE EXPLICAÇÃO DO POWER POINT - EXPLICA A MOVIMENTAÇÃO POR MEIO DO 
	// DESENHO DE UM PONTO ANTERIOR BRANCO
	//
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPointSize(50);
	// Cor preta
/*	glColor3f(0.0, 0.0, 1.0);
	// Ponto na posição (100,100)
	
	glBegin(GL_POINTS);
		glVertex2i(100, 100);
	glEnd();
	
	glFlush();
	glLoadIdentity;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(100, 100);
	glEnd();
	glFlush(); */
	
	// O novo ponto da posição (100,100) é deslocado 
	// 33 pixels na horizontal e 33 na vertical.
	//
	
	/*
	
	
	
	//começa a contar o tempo, em milissegundos;
	
	//Subindo ..........
	int k;
	for (k = 0; k <= 300; k =k+10) {
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(10, 10, 0);
		

		int x = clock();
		while (clock() - x <= 50) {
			glLoadIdentity;
			glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i(100, 100);
			glEnd();
			glFlush();
		}

		//glColor3f(1.0, 1.0, 1.0);
		int a = clock();//, tempo = clock();
		while (clock() - a <= 50) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POINTS);
			glVertex2i(100, 100);
			glEnd();
			glFlush();
		}
		
		
		
	}
	//Descendo ..........
	int j;
	for (j = 0; j <= 300; j = j + 10) {
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(-10, -10, 0);


		int x = clock();
		while (clock() - x <= 50) {
			glLoadIdentity;
			glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2i(100, 100);
			glEnd();
			glFlush();
		}

		//glColor3f(1.0, 1.0, 1.0);
		int a = clock();//, tempo = clock();
		while (clock() - a <= 50) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POINTS);
			glVertex2i(100, 100);
			glEnd();
			glFlush();
		}



	}

	
	


	
}


//Exercicio da Aula 12 / 05 / 2020

void DesenhaCasa() {
	glLineWidth(3);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(50, 100);
	glVertex2i(100, 150);
	glVertex2i(150, 100);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2i(50, 1);
	glVertex2i(50, 99);
	glVertex2i(150, 99);
	glVertex2i(150, 1);
	glEnd();
}



void DesenhaScale(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	DesenhaCasa();
	glScalef(eixoX, eixoY, eixoZ);
	DesenhaCasa();
	glFlush();

}

void Desenha(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotatef(Ang, 0.0, 0.0, 1.0);
	DesenhaCasa();
	
	
	glFlush();
	
	glutSwapBuffers();

	




}




// Aula - 19/05/2020

void lineSegment(void) {
	// glClearColor atrubui uma cor à janela, mas não coloca a janela na tela. Para tal, deve-se executar
	// o comando abaixo. O parâmetro GL_COLOR_BUFFER_BIT indica que os bits do "color buffer (refresh buffer)", devem 
	// ser setados para os valores indicados no comando glClearColor. Toda vez que a janela precisar ser
	// redesenhada, quando for redimensionada, por exemplo, o glClear deve ser executado. Se colocar
	// no procedimento "Init" isso não ocorrerá e, ao redimensionar da janela, ela ficará preta. Faça o teste!
	glClear(GL_COLOR_BUFFER_BIT);
	// Configura esquema de cor para os objetos que se que mostrar em tela. No exemplo abaixo, deseja-se 
	// setar a cor do objeto para verde escuro. o "f" indica que são valore de ponto flutuande ("float")
	//
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(R, G, B);
	//
	//Traça eixos X e Y
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, -400);
	glVertex2i(0, 400);
	glVertex2i(-400, 0);
	glVertex2i(400, 0);
	glEnd();

	//
	// EXEMPLO 1: ROTAÇÃO SEM SER NO CENTRO DO SISTEMA DE COORDENADAS
	//
	/*glRecti(50, 100, 200, 150); // Mostra retangulo azul
	glLoadIdentity(); // Reset current matrix to identity.

	glColor3f(0, 0, 1);
	glRotatef(90.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
	glRecti(50, 100, 200, 150); // Display red, rotated rectangle.

	glRotatef(90.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
	glRecti(50, 100, 200, 150); // Display red, rotated rectangle.*/
	//
	// EXEMPLO 2: ROTAÇÃO NO PONTO CENTRAL DO SISTEMA DE COORDENADAS
	//
	/*glColor3f(0,0,1);
	glRecti(0, 0, 150, 50); // Mostra retangulo azul
	glLoadIdentity(); // Reset current matrix to identity.
	glRotatef(90.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
	glColor3f(0, 1, 0);
	glRecti(0, 0, 150, 50); // Display red, rotated rectangle.
	glRotatef(90.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
	glColor3f(1, 0, 0);
	glRecti(0, 0, 150, 50); // Display red, rotated rectangle.*/
	//
	//
	// EXEMPLO 3: MOSTRA UM RETÂNGULO CIRCULANDO. ACELERA E DESACELERA COM
	// SETAS DO TECLADO
	/*
	glColor3f(R,G,B);
	glLoadIdentity(); // Reset current matrix to identity.
	glRotatef(Ang, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
	glRecti(0, 0, 50, 50); // Mostra retangulo azul
	//
	// Força a execução das funções OpenGL utlizadas no programa, que são armazenadas pelo SO em "buffers"
	// que se encontram em diferentes locais do sistema, dependnendo de como o OpenGL foi implementado.*/
	//
	// EXEMPLO 4: Mostra um "círculo de quadrados" caminhando em tempos
	// recorrentes.
	/*
	glLoadIdentity(); // Reset current matrix to identity.
	glColor3f(R, G, B);
	//glTranslated(DesLoca, DesLoca, 0.0f);
	glRecti(50, 100, 100, 150); // Mostra retangulo azul

	for (int i = 1; i < 12; i = i + 1) {
		glRotatef(30.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
		glRecti(50, 100, 100, 150); // Display red, rotated rectangle.
	}; 
	// Caso utilize um buffer de exibição, vide glutInitDisplayMode em 
	// main
	glFlush();
	// Caso utilize dois buffers de exibição, vide glutInitDisplayMode em 
	// main
	glutSwapBuffers();
}

void Teclado(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	};
};

void Anima(int value);

// Chamada quando uma tecla especial eh pressionada
void specialKey(int key, int x, int y) {
	switch (key) {
	
	case GLUT_KEY_HOME:

		antiHorario = -1;
		break;
	
	case GLUT_KEY_LEFT:
		V = V + 1;
		break;
	case GLUT_KEY_RIGHT:
		V = V - 1;
		if (V <= 0) { V = 1; };
		break;
	case GLUT_KEY_UP:
		
		antiHorario = 0;
		break;
	
	case GLUT_KEY_DOWN:
		antiHorario = 1;
		break;
	};
	cout << V << endl;
};

void mouseFunc(int button, int state, int x, int y) {

	srand(time(NULL));
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		B = (double)rand() / (double)RAND_MAX;
		R = (double)rand() / (double)RAND_MAX;
		G = (double)rand() / (double)RAND_MAX;
		glutPostRedisplay();
	};
}

void Anima(int value)
{
	//EXEMPLO 3 : O CODIGO ABAIXO É UTILIZADO NO EXEMPLO 3 
	if (antiHorario == 0) 
	{ 
		Ang = Ang + 10; 
		if (Ang == 360) { Ang = 0; }
	}
	else
	{
		if (antiHorario ==1)
		{
			Ang = Ang - 10;
			if (Ang <= 360) { Ang = 359; }
		}
		else
		{
			Ang = 0;
			V = 0;
		}
		
	}
	//if (Ang == 360) { Ang = 0; }
	glutPostRedisplay();
	cout <<"Velocidade: "<< V << "Angulo: " << Ang << endl;
	glutTimerFunc(V, Anima, 1);
	
	// EXEMPLO 4: O CODIGO ABAIXO É UTILIZADO NO EXEMPLO 4
	
	//DesLoca = DesLoca + 0.1;
	//if (DesLoca < 250) { glutTimerFunc(1000, Anima, 1); }
	//glutPostRedisplay();

}


//Aula 11 / 06 / 2020 - 3D

void Piramide3D() {
	// Base da pirâmide
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, 0, -1); //canto inf esquerdo tras.
	glVertex3f(-1, 0, 1); //canto inf esquerdo diant.
	glVertex3f(1, 0, 1); //canto inf direito  diant.
	glVertex3f(1, 0, -1); //canfo inf direito  tras.
	glEnd();
	// Face 1
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, 0, 1); //canto inf esquerdo diant.
	glVertex3f(1, 0, 1); //canto inf direito  diant.
	glVertex3f(0, 2, 0); //topo
	glEnd();
	// Face 2
	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, 1);  //canto inf direito  diant.
	glVertex3f(1, 0, -1);  //canfo inf direito  tras.
	glVertex3f(0, 2, 0);  //topo
	glEnd();
	// Face 3
	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, -1);  //canfo inf direito  tras.
	glVertex3f(-1, 0, -1);  //canto inf esquerdo tras.
	glVertex3f(0, 2, 0);  //topo
	glEnd();
	// Face 4
	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, -1);  //canfo inf direito  tras.
	glVertex3f(-1, 0, -1);  //canto inf esquerdo tras.
	glVertex3f(0, 2, 0);  //topo
	glEnd();

};


void cubo3D(){
	
	// Base do Cubo
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2, 0, -2); //
	glVertex3f(-2, 0, 2); //
	glVertex3f(2, 0, 2); //
	glVertex3f(2, 0, -2); //
	glEnd();

	// Topo do Cubo
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2, 2, -2); //
	glVertex3f(-2, 2, 2); //
	glVertex3f(2, 2, 2); //
	glVertex3f(2, 2, -2); //

	glEnd();

	// Face 1
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(2, 0, 2); //
	glVertex3f(2, 2, 2); //
	glVertex3f(-2, 2, 2); //
	glVertex3f(-2, 0, 2); //
	glEnd();

	// Face 2
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(2, 0, -2); //
	glVertex3f(2, 2, -2); //
	glVertex3f(2, 2, 2); //
	glVertex3f(2, 0, 2); //
	glEnd();

	// Face 3
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2, 0, -2); //
	glVertex3f(-2, 2, -2); //
	glVertex3f(2, 2, -2); //
	glVertex3f(2, 0, -2); //
	glEnd();

	// Face 4
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2, 0, 2); //
	glVertex3f(-2, 2, 2); //
	glVertex3f(-2, 2, -2); //
	glVertex3f(-2, 0, -2); //
	glEnd();

}

void Desenha3D(void){

// de fundo definida previamente
glClear(GL_COLOR_BUFFER_BIT);
// Salva o estado da matriz de transformação
// que foi sensibilização pela rotação do mouse
glPushMatrix();
// Reinicia a translação para mostrar os eixos
glTranslatef(0, 0, 0);
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINES);
glVertex3f(-15, 0, 0);
glVertex3f(15, 0, 0);
glVertex3f(0, 15, 0);
glVertex3f(0, -15, 0);
glVertex3f(0, 0, 15);
glVertex3f(0, 0, -15);
glEnd();
//
// Retira da pilha e retorna a matriz de transformação
// salva.
glPopMatrix();
//
// Exemplo 1: transformações
//
/*glColor3f(1.0f, 0.0f, 0.0f);
Piramide3D();
glTranslated(3.5, 0, 0);
//glRotated(90, 0, 0, 1);
glScaled(2,-2,2);
glColor3f(0.0f, 1.0f, 0.0f);
Piramide3D();*/
//
// Exemplo 2: movimentação figura
/*
glPushMatrix();
if (dir == 1) glTranslated(Desloca, Desloca , 0);
else if (dir == 2) glTranslated(0, 0, Desloca);
else glTranslated(0, Desloca, 0);
//Piramide3D();
cubo3D();
glPopMatrix();

//glutWireTeapot(2);
glFlush();
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX, -obsY, -obsZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	//
	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	// Angle - Especifica o ângulo de visualização, em graus, na direção Y. 
	// Quanto maior for o valor, maior será o campo de visão.
	// fAspect - É a proporção das coordenadas da figura na direção X. Define
	// proporção (razão) entre a altura e largura.
	// Terceiro parâmetro - distância do observador até o plano frontal
	// Quarto parâmetro - distância do observador até o plano traseiro
	//
	//gluPerspective(angle, fAspect, 0.1, 1200);
	//
	// A projeção ortogonal não altera o aspecto em função da 
	// posição do observador
	//
	glOrtho(-5, 5, -5, 5, -10, 10);
	PosicionaObservador();
}



// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	EspecificaParametrosVisualizacao();
}





// Função callback para tratar eventos de teclas especiais
void TeclasEspeciais3D(int tecla, int x, int y)
{
	switch (tecla)
	{
	case GLUT_KEY_HOME:
		if (angle >= 10)  angle -= 5;
		//rotX = 0;
		//rotY = 0;
		//obsX = obsY = 0;
		//obsZ = 5;
		//Desloca = 0;
		break;
	case GLUT_KEY_END:	if (angle <= 150) angle += 5;
		break;
	case GLUT_KEY_UP:
		fAspect = fAspect + 0.01;
		//dir = 3; // eixo Y
		Ang = Ang + 10;
		if (Ang == 360) { Ang = 0; }
		break;
	case GLUT_KEY_DOWN:
		fAspect = fAspect - 0.01;
		dir = 2; // eixo Y
		Ang = Ang - 10;
		if (Ang <= 0) { Ang = 359; };
		break;
	case GLUT_KEY_RIGHT:
		//dir = 1; // eixo X
		obsX = obsX + 0.1;
		obsY = obsY + 0.1;
		V = V + 1;
		break;
	case GLUT_KEY_LEFT:
		obsX = obsX - 0.1;
		obsY = obsY - 0.1;

		V = V - 1;
		if (V <= 0) { V = 1; };
		break;
	};
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}




// Função callback para eventos de botões do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		// Salva os parâmetros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

// Função callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	30.0
void GerenciaMovim(int x, int y)
{
	// Botão esquerdo ?
	if (bot == GLUT_LEFT_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ângulos
		rotY = rotY_ini - deltax / SENS_ROT;
		rotX = rotX_ini - deltay / SENS_ROT;
	}
	// Botão direito ?
	else if (bot == GLUT_RIGHT_BUTTON)
	{
		// Calcula diferença
		int deltaz = y_ini - y;
		// E modifica distância do observador
		obsZ = obsZ_ini + deltaz / SENS_OBS;
	}
	// Botão do meio ?
	else if (bot == GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posições
		obsX = obsX_ini + deltax / SENS_TRANSL;
		obsY = obsY_ini - deltay / SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Inicializa a variável que especifica o ângulo da projeção
	// perspectiva
	angle = 60;

	// Inicializa as variáveis usadas para alterar a posição do 
	// observador virtual
	rotX = 0;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 5;
	Desloca = 0;
}

/*
void Anima(int value)
{
	Desloca = Desloca + 0.1;
	glutTimerFunc(1000, Anima, 1);
	glutPostRedisplay();
}
*/




#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>
#include <ctime>
#include <stdlib.h>
// TeaPot3D.c - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualização 
// de objetos 3D.
// Este código está baseado nos exemplos disponíveis no livro 
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

GLfloat angle, fAspect, Rot;
GLfloat Desloca;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;
int ex = 1, ey = 1, ez = 1;


// Função callback chamada para fazer o desenho


void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha o teapot com a cor corrente (wire-frame)
	glRotatef(0.0, 0.0, 0.0, 1.0);
	//glTranslatef(rotX, rotY, obsZ);
	glRotatef(angle, 0, rotY, 0);
	glScalef(ex, ey, ez);
	
	
	glutWireTeapot(50.0f);
	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angle = 45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.5, 500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	EspecificaParametrosVisualizacao();
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX, -obsY, -obsZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
}



void Anima(int value);

void Teclado(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	};
};



// Função callback para eventos de botões do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		// Salva os parâmetros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}





#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	30.0
void GerenciaMovim(int x, int y)
{
	// Botão esquerdo ?
	if (bot == GLUT_LEFT_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ângulos
		rotY = rotY_ini - deltax / SENS_ROT;
		rotX = rotX_ini - deltay / SENS_ROT;
	}
	// Botão direito ?
	else if (bot == GLUT_RIGHT_BUTTON)
	{
		// Calcula diferença
		int deltaz = y_ini - y;
		// E modifica distância do observador
		obsZ = obsZ_ini + deltaz / SENS_OBS;
	}
	// Botão do meio ?
	else if (bot == GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posições
		obsX = obsX_ini + deltax / SENS_TRANSL;
		obsY = obsY_ini - deltay / SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

void Anima(int value)
{

	int deltax = x_ini - 45;
	int deltay = y_ini - 45;
	int deltaz = obsZ_ini - 45;
	// E modifica ângulos
	rotY = rotY_ini - deltax / SENS_ROT;
	rotX = rotX_ini - deltay / SENS_ROT;
	obsZ = obsZ_ini + deltaz / SENS_OBS;
	glutPostRedisplay();
	
	glutTimerFunc(1000, Anima, 1);


	
}


// Programa Principal 

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(350, 300);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	
	// Registra a função callback para eventos de botões do mouse	
	glutMouseFunc(GerenciaMouse);

	// Registra a função callback para eventos de movimento do mouse	
	glutMotionFunc(GerenciaMovim);

	// Registra a função callback para tratamento das teclas normais 
	glutKeyboardFunc(Teclado);

	// Registra a função callback para tratamento das teclas especiais
	//glutSpecialFunc(TeclasEspeciais3D);

	glutTimerFunc(1000, Anima, 1);
	//glutTimerFunc(1000, Anima, 1);


	Inicializa();
	glutMainLoop();
}



//int main(int argc, char** argv)
//{
//	// Inicializa GLUT. Parâmetros são opcionais.
//	glutInit(&argc, argv);
//	// Configurar opções para mostrar a janela. No caso abaixo, optou-se pelo "single refresh buffer" - GLUT_SINGLE, 
//	// e queremos utilizar o sistema de cores RGB - GLUT_RGB. A "|" indica operação "OR". Contrapondo a "single refresh
//	// buffer", pode-se ter "double refresh buffer" para animações.
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	// Configura a posição inicial o "upper left-corner" da janela (acima e à esquerda)
//	glutInitWindowPosition(100, 100);
//	// Configura a largura, primeiro parâmetro, e a altura da janela. Após mostrar a janela na tela
//	// é possível reposicioná-la e redimensioná-la.
//	glutInitWindowSize(600, 600);
//	// Criar uma janela com um título
//	glutCreateWindow("Hello GL....!");
//
//
//	cout << "Informe os parametros de Redimensionamento (Scale):" << endl;
//	cout << "Informe o Eixo X:" << endl;
//	cin >> eixoX;
//	cout << "Informe o Eixo Y:" << endl;
//	cin >> eixoY;
//	cout << "Informe o fator Z:" << endl;
//	cin >> eixoZ;
//
//
//	//Executa rotinas de inicialização
//	init();
//	// o procedimento lineSegment será "passado" para a janela criada. O procedimento "lineSegment" é denominado
//	// de "display callback function" e esse procedimento é descrito com sendo "registrado" pela funcão
//	// "glutDisplayFunc" como a rotina que será chamada sempre que a janela precisar ser mostrada novamente. Isso pode
//		// ocorrer, por exemplo, se o usuário mover a janela. Nesse caso, "lineSegment" será novamente chamado.
//	//glutDisplayFunc(lineSegment);
////	glutDisplayFunc(funcoes);
//	
//	//glutDisplayFunc(caracol);
//	//glutDisplayFunc(estrela);
//	//glutDisplayFunc(besenhamLine);
//	//glutDisplayFunc(midPointCircunferencia);
//	//glutDisplayFunc(translacao);
//	glutDisplayFunc(DesenhaScale);
//	
//
//
//
//	//glutDisplayFunc(lineSegment);
//	//glutTimerFunc(V, Anima, 1);
//	// Registra a função callback para tratamento das teclas ASCII(Teclado);
//	//glutSpecialFunc(specialKey);
//	//glutMouseFunc(mouseFunc);
//
//	// Aula 3D
//
//	
//	// Especifica a posição inicial da janela GLUT
//	//glutInitWindowPosition(200, 200);
//
//	// Especifica o tamanho inicial em pixels da janela GLUT
//	//glutInitWindowSize(800, 800);
//
//	// Cria a janela passando como argumento o título da mesma
//	//glutCreateWindow("Desenho do wireframe de uma cubo");
//
//	// Registra a função callback de redesenho da janela de visualização
//	//glutDisplayFunc(Desenha3D);
//
//	// Registra a função callback de redimensionamento da janela de visualização
//	//glutReshapeFunc(AlteraTamanhoJanela);
//
//	// Registra a função callback para eventos de botões do mouse	
//	//glutMouseFunc(GerenciaMouse);
//
//	// Registra a função callback para eventos de movimento do mouse	
//	//glutMotionFunc(GerenciaMovim);
//
//	// Registra a função callback para tratamento das teclas normais 
//	glutKeyboardFunc(Teclado);
//
//	// Registra a função callback para tratamento das teclas especiais
//	//glutSpecialFunc(specialKey);
//
//	//glutTimerFunc(1000, Anima, 1);
//
//	// Chama a função responsável por fazer as inicializações 
//	//Inicializa();
//
//	
//
//
//	// Deve ser a última função de seu código. Mostra o gráfico inicial e coloca o programa em um loop que 
//	// avalia inputs do usuário, tipo uso do mouse ou do teclado. Nesse primeiro exemplo, não haverá interação,
//	// então o programa mostrará a figura até que a janela seja fechada.
//	glutMainLoop();
//
//	return 0;
//
//}