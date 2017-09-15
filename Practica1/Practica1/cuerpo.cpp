//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//****** Alumno (s):Lorenzo Cruz Hector Eduardo **************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transY = -0.0f;
float transX = -0.0f;
float rotY = 0.0;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angCodo = 0.0;
float angMano = 0.0;
float angPulgar1 = 0.0;
float angPulgar2 = 0.0;
float angIndice1 = 0.0;
float angIndice2 = 0.0;
float angIndice3 = 0.0;
float angMedio1 = 0.0;
float angMedio2 = 0.0;
float angMedio3 = 0.0;
float angAnular1 = 0.0;
float angAnular2 = 0.0;
float angAnular3 = 0.0;
float angMenique1 = 0.0;
float angMenique2 = 0.0;
float angMenique3 = 0.0;




void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		
		//Poner Código Aquí.
	//MODELADO GEOMETRICO
	glTranslatef(0.0, 0.0, transZ);
	glTranslatef(transX,transY, 0.0);
	glRotatef(rotY,0.0,1.0,0.0);

	glPushMatrix();
	//(0,0,0)
		//cabeza
		glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//cuello
		glPushMatrix();
			glTranslated(0.0,-0.75,0.0);
			glScalef(0.5,0.5,1.0);
			glColor3f(0.0,1.0,0.0);
			prisma();
		glPopMatrix();
		//torso
		glPushMatrix();
			glTranslatef(0.0,-2.5,0.0);
			glScalef(3.0, 3.0, 1.0);
			glColor3f(0.0,0.0,1.0);
			prisma();
		glPopMatrix();
		//brazo derecho
		glPushMatrix();
		glTranslatef(-3.0,-1.5,0.0);
		glScalef(3.0,1.0,1.0);
		glColor3f(1.0,0.0,1.0);
		prisma();
		glPopMatrix();
		//brazo izquierdo
		//glPushMatrix();
		/*glTranslatef(3.0, -1.5, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();*/
		//hombro
		glPushMatrix();
		glTranslatef(1.75, -1.5, 0.0);
		glRotatef(90,0.0,0.0,1.0);
		glRotatef(angHombro, 0.0, 0.0, 1.0);
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
		glRotatef(-angPulgar1, 0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.0, 0.0);
		glColor3f(0.0, 1.0, 1.0);
		glPushMatrix();
		glScalef(0.2, 0.1, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.1, 0.0, 0.0);
		glRotatef(-angPulgar2, 0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.0, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(0.2, 0.1, 0.5);
		prisma();
		glPopMatrix();
		//Indice
		glPushMatrix();
		glTranslatef(0.18, -0.25, 0.2);
		glRotatef(-angIndice1, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glPushMatrix();
		glColor3f(0.0, 1.0, 1.0);
		glPushMatrix();
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.1, 0.0);
		glRotatef(-angIndice2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glPushMatrix();
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.1, 0.0);
		glRotatef(-angIndice3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glColor3f(1.0, 0.0, 0.4);
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		//Medio
		glPushMatrix();
		glTranslatef(0.07, -0.25, 0.2);
		glRotatef(-angMedio1, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.15, 0.0);
		glPushMatrix();
		glColor3f(0.2, 0.3, 1.0);
		glPushMatrix();
		glScalef(0.07, 0.3, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.15, 0.0);
		glRotatef(-angMedio2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.15, 0.0);
		glColor3f(1.0, 0.4, 0.1);
		glPushMatrix();
		glScalef(0.07, 0.3, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.15, 0.0);
		glRotatef(-angMedio3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.15, 0.0);
		glColor3f(1.0, 0.1, 0.4);
		glScalef(0.07, 0.3, 0.5);
		prisma();
		glPopMatrix();
		//Anular
		glPushMatrix();
		glTranslatef(-0.04, -0.25, 0.2);
		glRotatef(-angAnular1, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glPushMatrix();
		glColor3f(0.2, 0.3, 0.6);
		glPushMatrix();
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.1, 0.0);
		glRotatef(-angAnular2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glColor3f(0.8, 0.4, 0.3);
		glPushMatrix();
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.1, 0.0);
		glRotatef(-angAnular3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.1, 0.0);
		glColor3f(0.0, 0.1, 0.4);
		glScalef(0.07, 0.2, 0.5);
		prisma();
		glPopMatrix();
		//Meñique
		glPushMatrix();
		glTranslatef(-0.15, -0.25, 0.2);
		glRotatef(-angMenique1, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.05, 0.0);
		glPushMatrix();
		glColor3f(0.2, 0.7, 0.6);
		glPushMatrix();
		glScalef(0.07, 0.1, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.05, 0.0);
		glRotatef(-angMenique2, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.05, 0.0);
		glColor3f(0.8, 0.4, 0.8);
		glPushMatrix();
		glScalef(0.07, 0.1, 0.5);
		prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.05, 0.0);
		glRotatef(-angMenique3, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.05, 0.0);
		glColor3f(0.5, 0.1, 0.4);
		glScalef(0.07, 0.1, 0.5);
		prisma();
		glPopMatrix();
		glPopMatrix();
		//mano derecha
		/*glPushMatrix();
		glTranslatef(5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 1.0, 0.0);
		prisma();
		glPopMatrix();*/
		//mano izquierda
		glPushMatrix();
		glTranslatef(-5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 1.0, 0.0);
		prisma();
		glPopMatrix();
		//pierna derecha
		glPushMatrix();
		glTranslatef(-1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 0.5, 0.5);
		prisma();
		glPopMatrix();
		//pierna izquierda
		glPushMatrix();
		glTranslatef(1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 0.5, 0.5);
		prisma();
		glPopMatrix();
		//pierna derecha
		glPushMatrix();
		glTranslatef(-1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 0.5, 0.5);
		prisma();
		glPopMatrix();
		//pie derecho
		glPushMatrix();
		glTranslatef(-2.0, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.5, 1.0);
		prisma();
		glPopMatrix();
		//pie izquierdo
		glPushMatrix();
		glTranslatef(2.0, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.5, 1.0);
		prisma();
		glPopMatrix();


	glPopMatrix();
	
  glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 't':
			if (angHombro<=90)
			{
				angHombro += 1.0f;
			}
			break;
		case 'T':
			if (angHombro>=-90)
			{
				angHombro -= 1.0f;
			}
			break;
		case 'y':
			if (angCodo<=150)
			{
				angCodo += 1.0f;
			}
			break;
		case 'Y':
			if (angCodo>=0)
			{
				angCodo -= 1.0f;
			}
			break;
		case 'u':
			if (angMano <=50)
			{
				angMano += 1.0f;
			}
			break;
		case 'U':
			if (angMano >= -70)
			{
				angMano -= 1.0f;
			}
			break;
		case 'i':
			if (angMenique1>=0)
			{
				angMenique1 -= 1.0f;
			}
			break;
		case 'I':
			if (angMenique1<=90)
			{
				angMenique1 += 1.0f;
			}
			break;
		case 'o':
			if (angMenique2 >= 0)
			{
				angMenique2 -= 1.0f;
			}
			break;
		case 'O':
			if (angMenique2 <= 90)
			{
				angMenique2 += 1.0f;
			}
			break;
		case 'p':
			if (angMenique3 >=0)
			{
				angMenique3 -= 1.0f;
			}
			break;
		case 'P':
			if (angMenique3 <= 90)
			{
				angMenique3 += 1.0f;
			}
			break;
		case 'k':
		case 'K':
			if (angPulgar1 >= 0)
			{
				angPulgar1 -= 1.0f;
			}
			break;
		case 'l':
		case 'L':
			if (angPulgar1 <= 90)
			{
				angPulgar1 += 1.0f;
			}
			break;
		case 'm':
			if (angPulgar2 >= 0)
			{
				angPulgar2 -= 1.0f;
			}
			break;
		case 'M':
			if (angPulgar2 <= 90)
			{
				angPulgar2 += 1.0f;
			}
			angPulgar2 -= 1.0f;
			break;
		case 'z':
			if (angIndice1 >= 0)
			{
				angIndice1 -= 1.0f;
			}
			break;
		case 'Z':
			if (angIndice1 <= 90)
			{
				angIndice1 += 1.0f;
			}
			break;
		case 'x':
			if (angIndice2 >= 0)
			{
				angIndice2 -= 1.0f;
			}
			break;
		case 'X':
			if (angIndice2 <= 90)
			{
				angIndice2 += 1.0f;
			}
			break;
		case 'c':
			if (angIndice3 >= 0)
			{
				angIndice3 -= 1.0f;
			}
			break;
		case 'C':
			if (angIndice3 <= 90)
			{
				angIndice3 += 1.0f;
			}
			break;
		case 'v':
			if (angMedio1 >= 0)
			{
				angMedio1 -= 1.0f;
			}
			break;
		case 'V':
			if (angMedio1 <= 90)
			{
				angMedio1 += 1.0f;
			}
			break;
		case 'b':
			if (angMedio2 >= 0)
			{
				angMedio2 -= 1.0f;
			}
			break;
		case 'B':
			if (angMedio2 <= 90)
			{
				angMedio2 += 1.0f;
			}
			break;
		case 'n':
			if (angMedio3 >= 0)
			{
				angMedio3 -= 1.0f;
			}
			break;
		case 'N':
			if (angMedio3 <= 90)
			{
				angMedio3 += 1.0f;
			}
			break;
		case 'f':
			if (angAnular1 >= 0)
			{
				angAnular1 -= 1.0f;
			}
			break;
		case 'F':
			if (angAnular1 <= 90)
			{
				angAnular1 += 1.0f;
			}
			break;
		case 'g':
			if (angAnular2 >= 0)
			{
				angAnular2 -= 1.0f;
			}
			break;
		case 'G':
			if (angAnular2 <= 90)
			{
				angAnular2 += 1.0f;
			}
			break;
		case 'h':
			if (angAnular3 >= 0)
			{
				angAnular3 -= 1.0f;
			}
			break;
		case 'H':
			if (angAnular3 <= 90)
			{
				angAnular3 += 1.0f;
			}
			break;
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			rotY += 1.0f;
			break;
		case 'd':
		case 'D':
			rotY -= 1.0f;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		transY += 0.3;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		transY -= 0.3;
		break;
	case GLUT_KEY_LEFT:
		transX += 0.3;
		break;
	case GLUT_KEY_RIGHT:
		transX -= 0.3;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
