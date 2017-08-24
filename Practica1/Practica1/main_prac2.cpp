//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//GL_LINES   Dibuja lineas
	//GL_LINES_LOOP  Une todos los vertices
	//GL_TRIANGLES Dibuja triangulos, pide tercias de coordenadas
	//GL_POINTS  Hace puntos
	//GL_POLYGON  Crea poligonos acepta n numero de vertices
	//glColor3f(0.0, 0.0, 0.0);  SIRVE PARA MODIFICAR EL COLOR
	glPointSize(10.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	//glVertex3f(1.0,1.0,-1.2);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, 9.0, -1.2);
	//glColor3f(0.0, 0.0, 1.0);
	glVertex3f(9.0, 9.0, -1.2);
	//glColor3f(0.0, 1.0, 0.0);
	glVertex3f(9.0, 8.0, -1.2);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(3.0, 8.0, -1.2);
	/*glColor3f(1.0, 0.5, 1.0);
	glVertex3f(3.0, 3.0, -1.2);
	glColor3f(0.2, 0.0, 0.6);
	glVertex3f(9.0, 3.0, -1.2);
	glColor3f(0.7, 0.2, 1.0);
	glVertex3f(9.0, 1.0, -1.2);*/
	glEnd();
	glPointSize(10.0);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.2);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, 9.0, -1.2);
	//glColor3f(0.0, 0.0, 1.0);
	//glVertex3f(9.0, 9.0, -1.2);
	//glColor3f(0.0, 1.0, 0.0);
	//glVertex3f(9.0, 7.0, -1.2);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(3.0, 8.0, -1.2);
	//glColor3f(1.0, 0.5, 1.0);
	glVertex3f(3.0, 2.0, -1.2);
	//glColor3f(0.2, 0.0, 0.6);
	//glVertex3f(9.0, 3.0, -1.2);
	//glColor3f(0.7, 0.2, 1.0);
	//glVertex3f(9.0, 1.0, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, -1.2);
	//glColor3f(1.0, 1.0, 0.0);
	//glVertex3f(1.0, 9.0, -1.2);
	//glColor3f(0.0, 0.0, 1.0);
	//glVertex3f(9.0, 9.0, -1.2);
	//glColor3f(0.0, 1.0, 0.0);
	//glVertex3f(9.0, 7.0, -1.2);
	//glColor3f(1.0, 0.0, 1.0);
	//glVertex3f(3.0, 7.0, -1.2);
	//glColor3f(1.0, 0.5, 1.0);
	glVertex3f(3.0, 2.0, -1.2);
	//glColor3f(0.2, 0.0, 0.6);
	glVertex3f(9.0, 2.0, -1.2);
	//glColor3f(0.7, 0.2, 1.0);
	glVertex3f(9.0, 1.0, -1.2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.2);
	glVertex3f(-9.0, 1.0, -1.2);
	glVertex3f(-9.0, 9.0, -1.2);
	glVertex3f(-7.0, 9.0, -1.2);
	glVertex3f(-7.0, 2.0, -1.2);
	glVertex3f(-1.0, 2.0, -1.2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-11.0, 1.0, -1.2);
	glVertex3f(-19.0, 1.0, -1.2);
	glVertex3f(-19.0, 9.0, -1.2);
	glVertex3f(-11.0, 9.0, -1.2);
	glVertex3f(-11.0, 8.0, -1.2);
	glVertex3f(-17.0, 8.0, -1.2);
	glVertex3f(-17.0, 5.5, -1.2);
	glVertex3f(-13.0, 5.5, -1.2);
	glVertex3f(-13.0, 4.5, -1.2);
	glVertex3f(-17.0, 4.5, -1.2);
	glVertex3f(-17.0, 2.0, -1.2);
	glVertex3f(-11.0, 2.0, -1.2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-21.0, 1.0, -1.2);
	glVertex3f(-23.0, 1.0, -1.2);
	glVertex3f(-23.0, 4.5, -1.2);
	glVertex3f(-27.0, 4.5, -1.2);
	glVertex3f(-27.0, 1.0, -1.2);
	glVertex3f(-29.0, 1.0, -1.2);
	glVertex3f(-29.0, 9.0, -1.2);
	glVertex3f(-27.0, 9.0, -1.2);
	glVertex3f(-27.0, 5.5, -1.2);
	glVertex3f(-23.0, 5.5, -1.2);
	glVertex3f(-23.0, 9.0, -1.2);
	glVertex3f(-21.0, 9.0, -1.2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-10.0, -1.0, -1.2);
	glVertex3f(-8.0, -3.0, -1.2);
	glVertex3f(-4.0, -3.0, -1.2);
	glVertex3f(-7.0, -4.5, -1.2);
	glVertex3f(-4.5, -7.0, -1.2);
	glVertex3f(-10.0, -5.5, -1.2);
	glVertex3f(-15.5, -7.0, -1.2);
	glVertex3f(-13.0, -4.5, -1.2);
	glVertex3f(-16.0, -3.0, -1.2);
	glVertex3f(-12.0, -3.0, -1.2);
	glEnd();

	glFlush();
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

	// Ortogonal
	glOrtho(-30,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

