//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int luna2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;
float sup = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	//glRotatef(90, 1.0, 0.0, 0.0);
	glPushMatrix();
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
		glutWireSphere(2.0,20,20);  //Draw Sun (radio,H,V);
	glPopMatrix();
	//Mercurio
	glPushMatrix();
		glRotatef(venus,0.0,1.0,0.0);
		glTranslatef(2.5,0.2,0.2);
		glRotatef(mercurio, 0.0, 1.0, 0.0);
		glColor3f(0.7,0.25,0.0);
		glutWireSphere(0.3,20,20);
	glPopMatrix();

	//Venus
	glPushMatrix();
	glRotatef(sol, 0.0, 0.0, 1.0);
	glTranslatef(3.7, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glColor3f(0.95, 0.64, 0.37);
	glutWireSphere(0.55, 20, 20);
	glPopMatrix();

	//Tierra
	glPushMatrix();
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(5.0, 0.2, 0.2);
	glPushMatrix();
		glRotatef(tierra, 0.0, 1.0, 0.0);
		glColor3f(0.0, 0.2, 1.0);
		glutWireSphere(0.4, 20, 20);
	glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 0.0, 1.0);
			glTranslatef(0.55, 0.2, 0.2);
			glRotatef(luna, 0.0, 0.0, 1.0);
			glColor3f(0.6, 0.6, 0.6);
			glutWireSphere(0.1, 20, 20);
		glPopMatrix();
	glPopMatrix();

	//Marte
	glPushMatrix();
	glRotatef(luna2, 1.0, 1.0, 0.0);
	glTranslatef(6.0, -5.0, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glColor3f(0.8, 0.0, 0.0);
	glutWireSphere(0.35, 20, 20);
	glPopMatrix();

	//Jupiter
	glPushMatrix();
	glRotatef(venus, 0.0, 1.0, 1.0);
	glTranslatef(7.7, 0.2, -2.0);
	glPushMatrix();
		glRotatef(venus, 0.0, 1.0, 0.0);
		glColor3f(0.25, 0.25, 0.25);
		glutWireSphere(1.0, 20, 20);
	glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 1.0);
			glTranslatef(1.5, 0.2, 0.2);
			glRotatef(luna, 0.0, 0.0, 1.0);
			glColor3f(0.7, 0.7, 0.7);
			glutWireSphere(0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glRotatef(luna, 0.0, 0.0, 1.0);
			glTranslatef(1.5, 0.2, 0.2);
			glRotatef(luna, 1.0, 0.0, 0.0);
			glColor3f(0.4, 0.4, 0.4);
			glutWireSphere(0.25, 20, 20);
		glPopMatrix();
	glPopMatrix();
	//Saturno
	glPushMatrix();
	glRotatef(tierra, 1.0, 0.0, 1.0);
	glTranslatef(-0.0, 9.6, 0.2);
	glPushMatrix();
		glRotatef(tierra, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 0.45);
		glutWireSphere(0.5, 20, 20);
	glPopMatrix();
		glPushMatrix();
		glColor3f(0.0,1.0,0.0);
		glutSolidTorus(0.11,0.7,15,10);
		glRotatef(90,1.0,0.0,0.0);
		glColor3f(0.0, 0.8, 0.4);
		glutSolidTorus(0.11, 0.7, 15, 10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(1.0, 0.2, 0.2);
			glRotatef(luna, 0.0, 0.0, 1.0);
			glColor3f(0.7, 0.7, 0.7);
			glutWireSphere(0.2, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glRotatef(luna, 0.0, 0.0, 1.0);
			glTranslatef(1.0, 0.2, 0.2);
			glRotatef(luna, 1.0, 0.0, 0.0);
			glColor3f(0.4, 0.4, 0.4);
			glutWireSphere(0.1, 20, 20);
		glPopMatrix();
	glPopMatrix();

	//Urano
	glPushMatrix();
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glTranslatef(11.0, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glColor3f(0.55, 0.55, 0.55);
	glutWireSphere(0.55, 20, 20);
	glPopMatrix();

	//Neptuno
	glPushMatrix();
	glRotatef(sol, 1.0, 1.0, 1.0);
	glTranslatef(12.2, -5.0, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glColor3f(0.0, 0.5, 1.0);
	glutWireSphere(0.45, 20, 20);
	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
		mercurio = (mercurio - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
		mercurio = (mercurio - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
		venus = (venus - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
		tierra = (tierra - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;

		luna = (luna - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
		luna2 = (luna2 - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		sup += 1.0;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		sup -= 1.0;
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}