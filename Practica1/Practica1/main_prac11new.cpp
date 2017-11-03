//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//****** Alumno (s): Lorenzo Cruz Hector Eduardo *************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
//Variables de dibujo y manipulacion
bool an = true;
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0, giroBrazoIzq = 0, rotRodDer = 0, giroBrazoDer = 0;
float giroCabeza=0,giroCintura=0;
#define MAX_FRAMES 60
int i_max_steps = 500;
int i_curr_steps = 0;

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angCodo = 90.0;
float angMano = 0.0;
float angPulgar1 = 0;
float angPulgar2 = 0;
float angIndice1 = 0;
float angIndice2 = 0;
float angIndice3 = 0;
float angMedio1 = 0;
float angMedio2 = 0;
float angMedio3 = 0;
float angAnular1 = 0;
float angAnular2 = 0;
float angAnular3 = 0;
float angMeñique1 = 0;
float angMeñique2 = 0;
float angMeñique3 = 0;


typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float angPulgar1;
	float angPulgar2;
	float angIndice1;
	float angIndice2;
	float angIndice3;
	float angMedio1;
	float angMedio2;
	float angMedio3;
	float angAnular1;
	float angAnular2;
	float angAnular3;
	float angMeñique1;
	float angMeñique2;
	float angMeñique3;
	float angPulgar1Inc;
	float angPulgar2Inc;
	float angIndice1Inc;
	float angIndice2Inc;
	float angIndice3Inc;
	float angMedio1Inc;
	float angMedio2Inc;
	float angMedio3Inc;
	float angAnular1Inc;
	float angAnular2Inc;
	float angAnular3Inc;
	float angMeñique1Inc;
	float angMeñique2Inc;
	float angMeñique3Inc;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01


//NEW///////////////////////////7

CTexture textMesa;
CTexture textPata;
CTexture textWall;
CTexture textSilla;
CTexture textTecho;
CTexture textMarble;
CTexture textPiso;
CTexture textGlassWasser;
CTexture textBarrote;
CTexture textCuadro1;
CTexture textMarco;
CTexture textLibroCG;
CTexture textPB;
CTexture textPuerta;
CTexture textPuerta_princ;
CTexture textMarco_1;
CTexture textMarco_2;
CTexture textMarco_3;
CTexture textGrass;
CTexture textSky;
CTexture textLibrero;

//***ROSE****
CTexture textAlmohada;
CTexture textColcha;
CTexture textMaderaBuro;
CTexture textMaderaCama;
CTexture textLampara;
CTexture textLaptop;
CTexture textPantalla;
CTexture textTeclado;
CTexture textTouchPad;
CTexture textGW;

//CFiguras fig1;
//CFiguras fig5;
CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras asientoSilla;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;
//*****ROSE*****

CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;

float abrirPuerta = 0;
//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito


void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[0].angPulgar1=0;
	KeyFrame[0].angPulgar2 = 0;
	KeyFrame[0].angIndice1 = 0;
	KeyFrame[0].angIndice2 = 0;
	KeyFrame[0].angIndice3 = 0;
	KeyFrame[0].angMedio1 = 0;
	KeyFrame[0].angMedio2 = 0;
	KeyFrame[0].angMedio3 = 0;
	KeyFrame[0].angAnular1 = 0;
	KeyFrame[0].angAnular2 = 0;
	KeyFrame[0].angAnular3 = 0;
	KeyFrame[0].angMeñique1 = 0;
	KeyFrame[0].angMeñique2 = 0;
	KeyFrame[0].angMeñique3 = 0;
	FrameIndex++;
	KeyFrame[1].angPulgar1 = 0;
	KeyFrame[1].angPulgar2 = 0;
	KeyFrame[1].angIndice1 = 0;
	KeyFrame[1].angIndice2 = 0;
	KeyFrame[1].angIndice3 = 0;
	KeyFrame[1].angMedio1 = 0;
	KeyFrame[1].angMedio2 = 0;
	KeyFrame[1].angMedio3 = 0;
	KeyFrame[1].angAnular1 = 0;
	KeyFrame[1].angAnular2 = 0;
	KeyFrame[1].angAnular3 = 0;
	KeyFrame[1].angMeñique1 = 0;
	KeyFrame[1].angMeñique2 = 0;
	KeyFrame[1].angMeñique3 = 0;
	FrameIndex++;
	KeyFrame[2].angPulgar1 = -90.0;
	KeyFrame[2].angPulgar2 = -90.0;
	KeyFrame[2].angIndice1 = 60;
	KeyFrame[2].angIndice2 = 60;
	KeyFrame[2].angIndice3 = 60;
	KeyFrame[2].angMedio1 = 60;
	KeyFrame[2].angMedio2 = 60;
	KeyFrame[2].angMedio3 = 60;
	KeyFrame[2].angAnular1 = 60;
	KeyFrame[2].angAnular2 = 60;
	KeyFrame[2].angAnular3 = 60;
	KeyFrame[2].angMeñique1 = 60;
	KeyFrame[2].angMeñique2 = 60;
	KeyFrame[2].angMeñique3 = 60;
	FrameIndex++;
	KeyFrame[3].angPulgar1 = -90.0;
	KeyFrame[3].angPulgar2 = -90.0;
	KeyFrame[3].angIndice1 = 60;
	KeyFrame[3].angIndice2 = 60;
	KeyFrame[3].angIndice3 = 60;
	KeyFrame[3].angMedio1 = 60;
	KeyFrame[3].angMedio2 = 60;
	KeyFrame[3].angMedio3 = 60;
	KeyFrame[3].angAnular1 = 60;
	KeyFrame[3].angAnular2 = 60;
	KeyFrame[3].angAnular3 = 60;
	KeyFrame[3].angMeñique1 = 60;
	KeyFrame[3].angMeñique2 = 60;
	KeyFrame[3].angMeñique3 = 60;
	FrameIndex++;
	KeyFrame[4].angPulgar1 = 0;
	KeyFrame[4].angPulgar2 = 0;
	KeyFrame[4].angIndice1 = 0;
	KeyFrame[4].angIndice2 = 0;
	KeyFrame[4].angIndice3 = 0;
	KeyFrame[4].angMedio1 = 0;
	KeyFrame[4].angMedio2 = 0;
	KeyFrame[4].angMedio3 = 0;
	KeyFrame[4].angAnular1 = 0;
	KeyFrame[4].angAnular2 = 0;
	KeyFrame[4].angAnular3 = 0;
	KeyFrame[4].angMeñique1 = 0;
	KeyFrame[4].angMeñique2 = 0;
	KeyFrame[4].angMeñique3 = 0;
	FrameIndex++;
	KeyFrame[5].angPulgar1 = 0;
	KeyFrame[5].angPulgar2 = 0;
	KeyFrame[5].angIndice1 = 0;
	KeyFrame[5].angIndice2 = 0;
	KeyFrame[5].angIndice3 = 0;
	KeyFrame[5].angMedio1 = 0;
	KeyFrame[5].angMedio2 = 0;
	KeyFrame[5].angMedio3 = 0;
	KeyFrame[5].angAnular1 = 0;
	KeyFrame[5].angAnular2 = 0;
	KeyFrame[5].angAnular3 = 0;
	KeyFrame[5].angMeñique1 = 0;
	KeyFrame[5].angMeñique2 = 0;
	KeyFrame[5].angMeñique3 = 0;
	FrameIndex++;
	KeyFrame[6].angPulgar1 = -90.0;
	KeyFrame[6].angPulgar2 = -90.0;
	KeyFrame[6].angIndice1 = 0;
	KeyFrame[6].angIndice2 = 0;
	KeyFrame[6].angIndice3 = 0;
	KeyFrame[6].angMedio1 = 0;
	KeyFrame[6].angMedio2 = 0;
	KeyFrame[6].angMedio3 = 0;
	KeyFrame[6].angAnular1 = 60;
	KeyFrame[6].angAnular2 = 60;
	KeyFrame[6].angAnular3 = 60;
	KeyFrame[6].angMeñique1 = 60;
	KeyFrame[6].angMeñique2 = 60;
	KeyFrame[6].angMeñique3 = 60;
	FrameIndex++;
	KeyFrame[7].angPulgar1 = -90.0;
	KeyFrame[7].angPulgar2 = -90.0;
	KeyFrame[7].angIndice1 = 0;
	KeyFrame[7].angIndice2 = 0;
	KeyFrame[7].angIndice3 = 0;
	KeyFrame[7].angMedio1 = 0;
	KeyFrame[7].angMedio2 = 0;
	KeyFrame[7].angMedio3 = 0;
	KeyFrame[7].angAnular1 = 60;
	KeyFrame[7].angAnular2 = 60;
	KeyFrame[7].angAnular3 = 60;
	KeyFrame[7].angMeñique1 = 60;
	KeyFrame[7].angMeñique2 = 60;
	KeyFrame[7].angMeñique3 = 60;
	FrameIndex++;
	KeyFrame[8].angPulgar1 = 0.0;
	KeyFrame[8].angPulgar2 = 0.0;
	KeyFrame[8].angIndice1 = 60;
	KeyFrame[8].angIndice2 = 60;
	KeyFrame[8].angIndice3 = 60;
	KeyFrame[8].angMedio1 = 60;
	KeyFrame[8].angMedio2 = 60;
	KeyFrame[8].angMedio3 = 60;
	KeyFrame[8].angAnular1 = 60;
	KeyFrame[8].angAnular2 = 60;
	KeyFrame[8].angAnular3 = 60;
	KeyFrame[8].angMeñique1 = 60;
	KeyFrame[8].angMeñique2 = 60;
	KeyFrame[8].angMeñique3 = 60;
	FrameIndex++;
	KeyFrame[9].angPulgar1 = 0.0;
	KeyFrame[9].angPulgar2 = 0.0;
	KeyFrame[9].angIndice1 = 60;
	KeyFrame[9].angIndice2 = 60;
	KeyFrame[9].angIndice3 = 60;
	KeyFrame[9].angMedio1 = 60;
	KeyFrame[9].angMedio2 = 60;
	KeyFrame[9].angMedio3 = 60;
	KeyFrame[9].angAnular1 = 60;
	KeyFrame[9].angAnular2 = 60;
	KeyFrame[9].angAnular3 = 60;
	KeyFrame[9].angMeñique1 = 60;
	KeyFrame[9].angMeñique2 = 60;
	KeyFrame[9].angMeñique3 = 60;
}

void resetElements( void )
{
	posX=KeyFrame[0].posX;
	posY=KeyFrame[0].posY;
	posZ=KeyFrame[0].posZ;

	angPulgar1 = KeyFrame[0].angPulgar1;
	angPulgar2 = KeyFrame[0].angPulgar2;
	angIndice1 = KeyFrame[0].angIndice1;
	angIndice2 = KeyFrame[0].angIndice2;
	angIndice3 = KeyFrame[0].angIndice3;
	angMedio1 = KeyFrame[0].angMedio1;
	angMedio2 = KeyFrame[0].angMedio2;
	angMedio3 = KeyFrame[0].angMedio3;
	angAnular1 = KeyFrame[0].angAnular1;
	angAnular2 = KeyFrame[0].angAnular2;
	angAnular3 = KeyFrame[0].angAnular3;
	angMeñique1 = KeyFrame[0].angMeñique1;
	angMeñique2 = KeyFrame[0].angMeñique2;
	angMeñique3 = KeyFrame[0].angMeñique2;

}

void interpolation ( void )
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;	
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;	
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	

	KeyFrame[playIndex].angPulgar1Inc = (KeyFrame[playIndex + 1].angPulgar1 - KeyFrame[playIndex].angPulgar1) / i_max_steps;	
	KeyFrame[playIndex].angPulgar2Inc = (KeyFrame[playIndex + 1].angPulgar2 - KeyFrame[playIndex].angPulgar2) / i_max_steps;
	KeyFrame[playIndex].angIndice1Inc = (KeyFrame[playIndex + 1].angIndice1 - KeyFrame[playIndex].angIndice1) / i_max_steps;
	KeyFrame[playIndex].angIndice2Inc = (KeyFrame[playIndex + 1].angIndice2 - KeyFrame[playIndex].angIndice2) / i_max_steps;
	KeyFrame[playIndex].angIndice3Inc = (KeyFrame[playIndex + 1].angIndice3 - KeyFrame[playIndex].angIndice3) / i_max_steps;
	KeyFrame[playIndex].angMedio1Inc = (KeyFrame[playIndex + 1].angMedio1 - KeyFrame[playIndex].angMedio1) / i_max_steps;
	KeyFrame[playIndex].angMedio2Inc = (KeyFrame[playIndex + 1].angMedio2 - KeyFrame[playIndex].angMedio2) / i_max_steps;
	KeyFrame[playIndex].angMedio3Inc = (KeyFrame[playIndex + 1].angMedio3 - KeyFrame[playIndex].angMedio3) / i_max_steps;
	KeyFrame[playIndex].angAnular1Inc = (KeyFrame[playIndex + 1].angAnular1 - KeyFrame[playIndex].angAnular1) / i_max_steps;
	KeyFrame[playIndex].angAnular2Inc = (KeyFrame[playIndex + 1].angAnular2 - KeyFrame[playIndex].angAnular2) / i_max_steps;
	KeyFrame[playIndex].angAnular3Inc = (KeyFrame[playIndex + 1].angAnular3 - KeyFrame[playIndex].angAnular3) / i_max_steps;
	KeyFrame[playIndex].angMeñique1Inc = (KeyFrame[playIndex + 1].angMeñique1 - KeyFrame[playIndex].angMeñique1) / i_max_steps;
	KeyFrame[playIndex].angMeñique2Inc = (KeyFrame[playIndex + 1].angMeñique2 - KeyFrame[playIndex].angMeñique2) / i_max_steps;
	KeyFrame[playIndex].angMeñique3Inc = (KeyFrame[playIndex + 1].angMeñique3 - KeyFrame[playIndex].angMeñique3) / i_max_steps;

}


void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,7.0);
			glRotatef(90,1,0,0);
			glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,-7.0);
			glRotatef(90,1,0,0);
			//glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		fig7.prisma(2.0 ,2.0 ,1 ,text2.GLindex);

		glPushMatrix();//Cuello
			glTranslatef(0, 1.0, 0.0);
			glRotatef(giroCabeza, 1.0, 0.0, 0);
			fig7.cilindro(0.25, 0.25, 15, 0);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.0, 0);
				fig7.esfera(0.75, 15, 15, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(0.25, 0, 0);
				glRotatef(-45, 0, 1, 0); 
				glRotatef(giroBrazoDer, 0, 0, 1);
				glTranslatef(0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierdo <--
			glTranslatef(-1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(-0.25, 0, 0);
				glRotatef(45, 0, 1, 0); 
				glRotatef(25, 0, 0, 1);
				glRotatef(25, 1, 0, 0); 
				glRotatef(giroBrazoIzq,0,1,0);
				glTranslatef(-0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glColor3f(0, 0, 1);
			glTranslatef(0, -1.5, 0);
			glRotatef(giroCintura,0,1,0);
			fig7.prisma(1, 2, 1, 0);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.75, -0.5, 0);
				glRotatef(-15, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15+rotRodDer, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.75, -0.5, 0);
				glRotatef(-5, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15+rotRodIzq, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


		glPopMatrix();


		glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}



//NEW CASA//////////////////////////////////////

void dibujaLaptop(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(7.0,0.5,0.25);
				glScalef(14.0,1.0,0.5);
				 laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,11.5,0.25);
				glScalef(14.0,1.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

 		glPushMatrix();
				glTranslatef(0.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(13.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();
 	glPushMatrix();
				glTranslatef(7.0,6.0,0.125);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,6.0,0.375);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textPantalla.GLindex);
			glPopMatrix();

 		//teclado
			glPushMatrix();
				glTranslatef(7.0,-0.75,5.0);
				glScalef(14.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,0.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 			glPushMatrix();
				glTranslatef(7.0,-0.25,6.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(2.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(11.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,9.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(0.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(13.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		//teclas
			glPushMatrix();
				glTranslatef(7.0,-0.25,3.5);
				glScalef(12.0,0.5,5.0);
				laptop.prisma(1.0,1.0,1.0, textTeclado.GLindex);
			glPopMatrix();	

			//touchpad
			glPushMatrix();
				glTranslatef(7.0,-0.25,8.0);
				glScalef(4.0,0.5,2.0);
				laptop.tecla(1.0,1.0,1.0,textTouchPad.GLindex);
			glPopMatrix();	
 		glPopMatrix();
}


void mesa(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosMesa, GLfloat yPosMesa, GLfloat zPosMesa){
	//mesa	
		//tabla
		glPushMatrix();
			glScalef(xMadera, yMadera, zMadera);
			glTranslatef(xPosMesa, yPosMesa, zPosMesa);
			glPushMatrix();
				glScalef(10,.5,5);
				tablaMesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
			//patas
			glPopMatrix();
			glPushMatrix();
				glTranslatef(4, -2.75, 2);
				glScalef( .5,5,.5);
				pata1Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(0, 0, -8);
				pata2Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(-16, 0, 0);
				pata3Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(0, 0, 8);
				pata4Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
			glPopMatrix();
		glPopMatrix();

		return;
}

void silla(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosSilla, GLfloat yPosSilla, GLfloat zPosSilla){
	float numBarrotes = -2.9;
	glPushMatrix();
		//posicion y tamaño
		glScalef(xMadera, yMadera, zMadera);
		glTranslatef(xPosSilla, yPosSilla, zPosSilla);
		//figura
		glPushMatrix();
			glScalef(3,.5,3);
			asientoSilla.prisma (1.0, 1.0, 1.0, textSilla.GLindex);//1
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.35, -3.25,-1.35);
			glScalef( .3,6,.3);
			pata1Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(-9.0, 0, 0);
			pata2Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(0, 0, 9);
			pata3Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(9, 0, 0);
			pata4Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.45, 4.25, -1.45);
			glScalef( 0.1,8.0,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			for(int numBar = 1; numBar <= 10; numBar++){
				glTranslatef(numBarrotes,0,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,1,-1.45);
			glScalef( 2.3,0.1,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			//
			for(int numBar = 1; numBar <= 30; numBar++){
				glTranslatef(0,2,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			}
			glTranslatef(0,12,0);
			glScalef( 1.5,1,1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
		glPopMatrix();
	glPopMatrix();

	return;
}

void comedor(void){
	glPushMatrix();
			mesa(2,2,2,0,1,0);
	glPopMatrix();
	//SILLAS
	glPushMatrix();
		glTranslatef(0,0,-0.5);
		glRotatef(25, 0,1,0);
		glTranslatef(2,0,-0.5);
		silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
		//giramos con respecto Z
		glScalef(1,1,-1);
		glPushMatrix();				
		glPushMatrix();
			silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
	glPopMatrix();
		return;
}
void ropero(void){
			glPushMatrix();
				glTranslatef(-8,-20,50);
				fig5.prisma(50.0,1.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,35);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,65);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,57.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,42.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-45,50);
				fig5.prisma(0.5,6.0,31.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,5,50);
				fig5.prisma(0.5,6.0,31.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,50);
				fig5.prisma(0.5,6.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-30,50);
				fig5.prisma(0.5,6.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,39);
				fig5.prisma(0.5,6.0,7.5, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,61);
				fig5.prisma(0.5,6.0,7.5, textGW.GLindex);
			glPopMatrix();
}
void casa( void ){
//*****casa*****
	glPushMatrix(); //Creamos paredes
		glTranslatef(0,20,0);
		fig1.skybox2(60.0, 85.0, 85.0, textPata.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,50,0);
		techoCasa.prisma(1,90,90, textTecho.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-10,0);
		pisoCasa.prisma(1,85,85, textPiso.GLindex);
		//patio
		glTranslatef(0,-3,0);
		//pisoCasa.prisma(1,250,250, textGrass.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27.5,10,-42);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glTranslatef(30,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glTranslatef(15,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glPushMatrix();
			glTranslatef(15.5,0,0);
			pisoCasa.prisma(40,1,1, textMarco_1.GLindex);
			glTranslatef(9,0,0);
			pisoCasa.prisma(40,1,1, textMarco_2.GLindex);
			glTranslatef(-4.5,18.5,0);
			pisoCasa.prisma(2.5,8,1, textMarco_3.GLindex);
		glPopMatrix();
		//puerta
		glTranslatef(15,-1,0);
		glRotatef(abrirPuerta, 0,1,0);
		glTranslatef(5,-0.4,0);//eran 20 en x
		pisoCasa.prisma(37,8,1, textPuerta_princ.GLindex);
	glPopMatrix();
			
	//ventana 1
	glPushMatrix();
		glTranslatef(-34.5,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	// barrotes ventana
	glPushMatrix();
		glTranslatef(-42,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 2
	glPushMatrix();
		glTranslatef(-19,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(-11,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 3
	glPushMatrix();
		glTranslatef(-3,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(5,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 4
	glPushMatrix();
		glTranslatef(13,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(19.8,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();	
	//cierra ventana
	glPushMatrix();
		glTranslatef(31,38.5,-42);
		cubo.prisma(17,23,1, textPata.GLindex);
	glPopMatrix();
	return;
}

void cuadro(void){
	glPushMatrix();
		glScalef(1,1,-1);
		glTranslatef(-19,30,-42);
		cubo.prisma(16,15,.2, textCuadro1.GLindex);
		glTranslatef(0,0,-.05);
		//cubo.prisma(17,16,.05, textMarco.GLindex);
	glPopMatrix();
	return;
}
//****ROSE****
void dibujaCama (GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosCama, GLfloat yPosCama, GLfloat zPosCama)
{			
			glPushMatrix(); 
			glScalef(xMadera, yMadera, zMadera); //posicion y tamaño 
			glTranslatef(xPosCama, yPosCama, zPosCama); //figura 

			//dibujamos la cabecera
			glPushMatrix(); 
				glTranslatef(9.0,1.5,0.5);
				glScalef(18.0,3.0,1.0);  //Tamaño de cabecera
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(4.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(14.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,9.5,0.5);
				glScalef(18.0,1.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,5.0,0.5);
				glScalef(1.0,10.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//dibujamos la base de la cama
			glPushMatrix(); 
				glTranslatef(0.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,1.0,21.5);
				glScalef(18.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//colchon
			glPushMatrix(); 
				glTranslatef(9.0,3.5,11.0);
				glScalef(18.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			//almohada izquierda
			glPushMatrix(); 
				glTranslatef(4.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex);
			glPopMatrix();

			//almohada derecha
			glPushMatrix(); 
				glTranslatef(14.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex);
			glPopMatrix();


			//enfrente
			glPushMatrix(); 
				glTranslatef(9.0,6.5,21.5);
				glScalef(16.0,1.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,2.5,21.5);
				glScalef(16.0,5.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//patas
			glPushMatrix(); 
				glTranslatef(0.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();
			glPopMatrix();
}


void dibujaBuro(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(1.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,10.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			glPushMatrix();
				glTranslatef(8.0,6.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,1.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			//rellenos
			glPushMatrix();
				glTranslatef(13.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			//pared atras
			glPushMatrix();
				glTranslatef(8.0,6.5,1.5);
				glScalef(12.0,9.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			//base arriba
			glPushMatrix();
				glTranslatef(8.0,11.5,5.0);
				glScalef(16.0,1.0,10.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			//cajones
			glPushMatrix();
				glTranslatef(8.0,8.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,8.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();
		glPopMatrix();
}

void libros( void){
	glPushMatrix();
			glTranslatef(-1,-8,25);
			cubo.prisma(1,2,2, textLibroCG.GLindex);
		glPopMatrix();

		glPushMatrix();
			glRotatef(30, 0,1,0);
			glTranslatef(-10,-8,25);
			//cubo.prisma(.7,2,2, textPB.GLindex);
	glPopMatrix();
	return;
}
//END CASA////////////////////////////////////





GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();


	//NEW////////////////////////////////////////////

	textMesa.LoadBMP("casa/wood_5.bmp");
	textMesa.BuildGLTexture();
	textMesa.ReleaseImage();

	textPata.LoadBMP("casa/brick_3.bmp");
	textPata.BuildGLTexture();
	textPata.ReleaseImage();

	textWall.LoadBMP("casa/brick_2.bmp");
	textWall.BuildGLTexture();
	textWall.ReleaseImage();

	textSilla.LoadBMP("casa/madera.bmp");
	textSilla.BuildGLTexture();
	textSilla.ReleaseImage();
	
	textTecho.LoadBMP("casa/brick_3.bmp");
	textTecho.BuildGLTexture();
	textTecho.ReleaseImage();

	textMarble.LoadBMP("casa/marble_2.bmp");
	textMarble.BuildGLTexture();
	textMarble.ReleaseImage();

	textPiso.LoadBMP("casa/floor-parquet.bmp");
	textPiso.BuildGLTexture();
	textPiso.ReleaseImage();

	textGlassWasser.LoadBMP("casa/glass_2.bmp");
	textGlassWasser.BuildGLTexture();
	textGlassWasser.ReleaseImage();

	textBarrote.LoadBMP("casa/brickwall.bmp");
	textBarrote.BuildGLTexture();
	textBarrote.ReleaseImage();

	textCuadro1.LoadBMP("casa/cuadro_1.bmp");
	textCuadro1.BuildGLTexture();
	textCuadro1.ReleaseImage();

	textMarco.LoadBMP("casa/burned wood.bmp");
	textMarco.BuildGLTexture();
	textMarco.ReleaseImage();

	textLibroCG.LoadBMP("casa/gc_donald.bmp");
	textLibroCG.BuildGLTexture();
	textLibroCG.ReleaseImage();

	textPuerta.LoadBMP("casa/door_3.bmp");
	textPuerta.BuildGLTexture();
	textPuerta.ReleaseImage();

	textPuerta_princ.LoadBMP("casa/door_3_4_puerta.bmp");
	textPuerta_princ.BuildGLTexture();
	textPuerta_princ.ReleaseImage();

	textMarco_1.LoadBMP("casa/door_3_1_izq.bmp");
	textMarco_1.BuildGLTexture();
	textMarco_1.ReleaseImage();

	textMarco_2.LoadBMP("casa/door_3_2_der.bmp");
	textMarco_2.BuildGLTexture();
	textMarco_2.ReleaseImage();

	textMarco_3.LoadBMP("casa/door_3_3_cen.bmp");
	textMarco_3.BuildGLTexture();
	textMarco_3.ReleaseImage();

	textGrass.LoadBMP("casa/grass_2.bmp");
	textGrass.BuildGLTexture();
	textGrass.ReleaseImage();

	textSky.LoadBMP("casa/blue-sky-texture.bmp");
	textSky.BuildGLTexture();
	textSky.ReleaseImage();

	textLibrero.LoadBMP("casa/strata.bmp");
	textLibrero.BuildGLTexture();
	textLibrero.ReleaseImage();

	textGW.LoadBMP("casa/glass window.bmp");
	textGW.BuildGLTexture();
	textGW.ReleaseImage();
	
	//*****ROSE******
	textAlmohada.LoadBMP("casa/almohada.bmp");
	textAlmohada.BuildGLTexture();
	textAlmohada.ReleaseImage();

	textColcha.LoadBMP("casa/colcha.bmp");
	textColcha.BuildGLTexture();
	textColcha.ReleaseImage();

	textMaderaBuro.LoadBMP("casa/buro.bmp");
	textMaderaBuro.BuildGLTexture();
	textMaderaBuro.ReleaseImage();

	textMaderaCama.LoadBMP("casa/maderaCama.bmp");
	textMaderaCama.BuildGLTexture();
	textMaderaCama.ReleaseImage();

	textLampara.LoadBMP("casa/lampara.bmp");
	textLampara.BuildGLTexture();
	textLampara.ReleaseImage();

	textLaptop.LoadBMP("casa/laptop.bmp");
	textLaptop.BuildGLTexture();
	textLaptop.ReleaseImage();

	textPantalla.LoadBMP("casa/windows.bmp");
	textPantalla.BuildGLTexture();
	textPantalla.ReleaseImage();

	textTeclado.LoadBMP("casa/tecla.bmp");
	textTeclado.BuildGLTexture();
	textTeclado.ReleaseImage();

	textTouchPad.LoadBMP("casa/touchpad.bmp");
	textTouchPad.BuildGLTexture();
	textTouchPad.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].angPulgar1 = 0;
		KeyFrame[i].angPulgar2 = 0;
		KeyFrame[i].angIndice1 = 0;
		KeyFrame[i].angIndice2 = 0;
		KeyFrame[i].angIndice3 = 0;
		KeyFrame[i].angMedio1 = 0;
		KeyFrame[i].angMedio2 = 0;
		KeyFrame[i].angMedio3 = 0;
		KeyFrame[i].angAnular1 = 0;
		KeyFrame[i].angAnular2 = 0;
		KeyFrame[i].angAnular3 = 0;
		KeyFrame[i].angMeñique1 = 0;
		KeyFrame[i].angMeñique2 = 0;
		KeyFrame[i].angMeñique3 = 0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////
	

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	//gluLookAt(objCamera.mPos.x= 1.406547, objCamera.mPos.y = -1.000000, objCamera.mPos.z = -2.768619,
	
	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	glTranslatef(-1.1, 3.5f, 6.0);
	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	//Brazo detallado
	glPushMatrix();
	glRotatef(angHombro, 0.0, 0.0, 1.0);
	//hombro
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 1);
	prisma();
	glPopMatrix();
	//bicep
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();
	//codo
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angCodo, 0.0, 0.0, 1.0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	//Antebrazo
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angMano, 0.0, 0.0, 1.0);
	//Mano
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();
	//Pulgar

	glPushMatrix();
	glTranslatef(0.25, 0.0, 0.2);
	glRotatef(angPulgar1, 0.0, 0.0, 1.0);
	glTranslatef(0.1, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glScalef(0.2, 0.1, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.1, 0.0, 0.0);
	glRotatef(angPulgar2, 0.0, 0.0, 1.0);
	glTranslatef(0.1, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glScalef(0.2, 0.1, 0.5);
	prisma();
	glPopMatrix();
	//Indice
	glPushMatrix();
	glTranslatef(0.18, -0.25, 0.2);
	glRotatef(angIndice1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angIndice2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angIndice3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(1.0, 0.0, 0.4);
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	//Medio
	glPushMatrix();
	glTranslatef(0.07, -0.25, 0.2);
	glRotatef(angMedio1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glColor3f(0.2, 0.3, 1.0);
	glPushMatrix();
	glScalef(0.07, 0.3, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef(angMedio2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glColor3f(1.0, 0.4, 0.1);
	glPushMatrix();
	glScalef(0.07, 0.3, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef(angMedio3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glColor3f(1.0, 0.1, 0.4);
	glScalef(0.07, 0.3, 0.5);
	prisma();
	glPopMatrix();
	//Anular
	glPushMatrix();
	glTranslatef(-0.04, -0.25, 0.2);
	glRotatef(angAnular1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glColor3f(0.2, 0.3, 0.6);
	glPushMatrix();
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnular2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.8, 0.4, 0.3);
	glPushMatrix();
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnular3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glColor3f(0.0, 0.1, 0.4);
	glScalef(0.07, 0.2, 0.5);
	prisma();
	glPopMatrix();
	//Meñique
	glPushMatrix();
	glTranslatef(-0.15, -0.25, 0.2);
	glRotatef(angMeñique1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	glPushMatrix();
	glColor3f(0.2, 0.7, 0.6);
	glPushMatrix();
	glScalef(0.07, 0.1, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.05, 0.0);
	glRotatef(angMeñique2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	glColor3f(0.8, 0.4, 0.8);
	glPushMatrix();
	glScalef(0.07, 0.1, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0.0, -0.05, 0.0);
	glRotatef(angMeñique3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	glColor3f(0.5, 0.1, 0.4);
	glScalef(0.07, 0.1, 0.5);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
	// Swap The Buffers
}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	//Movimiento del monito
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			angPulgar1 += KeyFrame[playIndex].angPulgar1Inc;
			angPulgar2 += KeyFrame[playIndex].angPulgar2Inc;
			angIndice1 += KeyFrame[playIndex].angIndice1Inc;
			angIndice2 += KeyFrame[playIndex].angIndice2Inc;
			angIndice3 += KeyFrame[playIndex].angIndice3Inc;
			angMedio1 += KeyFrame[playIndex].angMedio1Inc;
			angMedio2 += KeyFrame[playIndex].angMedio2Inc;
			angMedio3 += KeyFrame[playIndex].angMedio3Inc;
			angAnular1 += KeyFrame[playIndex].angAnular1Inc;
			angAnular2 += KeyFrame[playIndex].angAnular2Inc;
			angAnular3 += KeyFrame[playIndex].angAnular3Inc;
			angMeñique1 += KeyFrame[playIndex].angMeñique1Inc;
			angMeñique2 += KeyFrame[playIndex].angMeñique2Inc;
			angMeñique3 += KeyFrame[playIndex].angMeñique3Inc;
			i_curr_steps++;
		}
		
	}


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			printf("%f      %f\n", objCamera.mPos.x, objCamera.mView.x);
			printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
			printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			printf("%f      %f\n", objCamera.mPos.x, objCamera.mView.x);
			printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
			printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			printf("%f      %f\n", objCamera.mPos.x, objCamera.mView.x);
			printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
			printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			printf("%f      %f\n", objCamera.mPos.x, objCamera.mView.x);
			printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
			printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
			break;

		/*case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;*/

		case 'l':						
		case 'L':
			if (an==true) {
				saveFrame();
				an = false;
			}
			if(play==false && (FrameIndex>1))
			{
				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			printf("%f \n", posX);
			break;

		case 'b':						
			rotRodIzq++;
			printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			rotRodIzq--;
			printf("%f \n", rotRodIzq);
			break;

		case 'p':						
			giroMonito++;
			break;

		case 'P':						
			giroMonito--;
			break;
		case 'm':
			giroBrazoIzq++;
			break;

		case 'M':
			giroBrazoIzq--;
			break;
		case 'z':
			giroBrazoDer++;
			break;

		case 'Z':
			giroBrazoDer--;
			break;
		case 'x':
			rotRodDer++;
			break;

		case 'X':
			rotRodDer--;
			break;
		case 'c':
			giroCabeza++;
			break;

		case 'C':
			giroCabeza--;
			break;
		case 'v':
			giroCintura++;
			break;

		case 'V':
			giroCintura--;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		printf("%f      %f\n", objCamera.mPos.x, objCamera.mView.x);
		printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
		printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		printf("%f      %f\n", objCamera.mPos.x,objCamera.mView.x);
		printf("%f      %f\n", objCamera.mPos.y, objCamera.mView.y);
		printf("%f      %f\n", objCamera.mPos.z, objCamera.mView.z);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}