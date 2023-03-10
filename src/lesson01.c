/*
=====================================================================
OpenGL Lesson 01:  Creating An First OpenGL Window with glut on Linux
=====================================================================

  Authors Name: Jeff Molofee ( NeHe )

  This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)

  If you've found this code useful, please let me know.

  Visit me at www.demonews.com/hosted/nehe
 (email Richard Campbell at ulmont@bellsouth.net)

  Disclaimer:

  This program may crash your system or run poorly depending on your
  hardware.  The program and code contained in this archive was scanned
  for virii and has passed all test before it was put online.  If you
  use this code in project of your own, send a shout out to the author!

=====================================================================
                NeHe Productions 1999-2004
=====================================================================
*/

 /*******************************************************************
 *  Project: $(project)
 *  Function : Main program
 ***************************************************************
 *  $Author: Jeff Molofee 2000 ( NeHe )
 *  $Name:  $
 ***************************************************************
 *
 *  Copyright NeHe Production
 *
 *******************************************************************/

/**         Comments manageable by Doxygen
*
*  Modified smoothly by Thierry DECHAIZE
*
*  Paradigm : obtain one source (only one !) compatible for multiple free C Compilers
*    and provide for all users an development environment on Linux (64 bits compatible),
*    the great Code::Blocks manager (version 20.03), and don't use glaux.lib or glaux.dll.
*
*	a) gcc 11.3.0 (32 and 64 bits) version officielle : commande pour l'installation sur Linux Mint
*       -> sudo apt-get install freeglut3 libglew-dev gcc g++ mesa-common-dev build-essential libglew2.2 libglm-dev binutils libc6 libc6-dev ; option -m32 to 32 bits ; no option to 64 bits
*	b) CLANG version 14.0.6 (32 et 64 bits), adoss?? aux environnements gcc : commande pour l'installation sur Linux Mint
*       -> sudo apt-get install llvm clang ; options pour la compilation et l'??dition de liens -> --target=i686-pc-linux-gnu (32 bits) --target=x86_64-pc-linux-gnu (64 bits)
*	c) Mingw 32 ou 64 bits version gcc version 10-win32 20220113 : commande pour l'installation sur Linux Mint
*        -> sudo apt-get install mingw64    (ATTENTION, il s'agit d'une cross g??n??ration : l'ex??cutable cr???? ne fonctionne que sur Windows !!!)
*
*  Date : 2022/12/28
*
* \file            lesson01.c
* \author          Jeff Molofee ( NeHe ) originely, adapted by Richard Campbell, and after by Thierry Dechaize
* \version         2.0.1.0
* \date            28 d??cembre 2022
* \brief           Ouvre une simple fen??tre Wayland on Linux et dessine un triangle muticolore en rotation avec OpenGL + glut.
* \details         Ce programme g??re plusieurs ??v??nements : le clic sur le bouton "Ferm??" de la fen??tre, la sortie par la touche ESC ou par les touches "q" ou "Q" [Quit]
* \details                                                  l'appui sur les touches "f" ou "F" qui active ou non le "Full Screen" en mode flip-flop.
*
*
*/

#include <GL/glut.h>  // Header File For The GLUT Library
#include <GL/glu.h>	  // Header File For The GLU Library
#include <GL/gl.h>	  // Header File For The OpenGL Library

#include <unistd.h>     // Header file for sleeping.

/* ascii code for the escape key */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

/* Indicator of Full Screen */
int nFullScreen=0;

/* The angle of rotation */
float theta = 0.0f;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */

/**	            This function initialize the basics characteristics of the scene with instructions OpenGL (background, depth, type of depth, reset of the projection matrix, ...)
*
* \brief      Fonction InitGL : fonction gerant les caract??ristiques de base de la sc??ne lorsque avec des instructions OpenGL (arri??re plan, profondeur, type de profondeur, ...)
* \details    En retour les deux param??tres des nouvelles valeurs de largeur et de hauteur de la fen??tre redimensionn??e.
* \param	  Width			    la largeur de la fen??tre lors de l'initialisation					*
* \param	  Height			la hauteur de la fen??tre lors de l'initialisation					*
* \return     void              aucun retour.
*
*/

void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */

/**	            This function manage the new dimension of the scene when resize of windows with instructions OpenGL
*
* \brief      Fonction ReSizeGLScene : fonction gerant les nouvelles dimensions de la sc??ne lorsque l'utilisateur agit sur un redimensionnement de la fen??tre
* \details    En retour les deux param??tres des nouvelles valeurs de largeur et de hauteur de la fen??tre redimensionn??e.
* \param	  Width			    la  nouvelle largeur de la fen??tre redimensionn??e					*
* \param	  Heigth			la  nouvelle hauteur de la fen??tre redimensionn??e					*
* \return     void              aucun retour.
*
*/

void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */

/**	            This function generate the scene with injstructions OpenGL
*
* \brief      Fonction DrawGLScene : fonction generant l'affichage attendu avec des instructions OpenGL
* \details    Aucun param??tre dans ce cas de figure car tout est g??r?? directement ?? l'int??rieur de cette fonction d'affichage.
* \return     void              aucun retour.
*
*/

void DrawGLScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				    // Reset The View
    glTranslatef(0.0f,0.0f,-2.0f);		// Move Into The Screen 2.0

    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);               // Each set of 3 vertices form a triangle
      glColor3f(1.0f, 0.0f, 0.0f);      // Red
      glVertex3f(0.0f, 0.58f, 0.0f);     // Top
      glColor3f(0.0f, 1.0f, 0.0f);      // Green
      glVertex3f(0.58f,-0.42f, 0.0f);     // Bottom Left
      glColor3f(0.0f, 0.0f, 1.0f);      // Blue
      glVertex3f(-0.58f,-0.42f, 0.0f);    // Bottom Right
    glEnd();

    glPopMatrix();
    glFlush();  // Render now
    // since this is double buffered, swap the buffers to display what just got drawn.
    glutSwapBuffers();
    theta += 1.0f;
    usleep (1);

}

/* The function called whenever a key is pressed. */

/**	            This function inform caller with key pressed.
*
* \brief      Fonction keyPressed : fonction permettant de conna??tre quelle touche a ??t?? tap??e au clavier
* \details    Le premier paarm??tre en retour de cette fonction correspond ?? la touche pr??c??demment appuy??e.
* \param	  key			    la touche appuy??e 					*
* \param	  x             	une position x au niveau du clavier *
* \param	  y             	une position y au niveau du clavier *
* \return     void              aucun retour.
*
*/

void keyPressed(unsigned char key, int x, int y)
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key){

	//Mode plein ??cran : il suffit de taper au clavier sur la touche F majuscule ou f minuscule en mode flip-flop
		case 'f' :
		case 'F' :
			if (nFullScreen==0)
			{
				glutFullScreen();
				nFullScreen=1;
				break;
			}
			if (nFullScreen==1)
			{
		        glutReshapeWindow(640, 480);
				glutPositionWindow (0, 0);
				nFullScreen=0;
				break;
			}
	//Quitter
		case 'q' :
		case 'Q' :
		case 27  : // Touche ESC : il s'agit de sortir proprement de ce programme
            glutDestroyWindow(window);
			exit (0);
			break;

		default :
//			printf(" Touche: %c\n Souris a: %d %d \n",key,x,y);
			break;

	}

}

/* Main function : GLUT runs as a console application starting with program call main()  */

/**         Comments manageable by Doxygen
*
* \brief      Programme Main obligatoire pour les programmes sous Linux (OpenGL en mode console).
* \details    Programme principal de lancement de l'application qui appelle ensuite toutes les fonctions utiles OpenGL et surtout glut.
* \param      argc         le nombre de param??tres de la ligne de commande.
* \param      argv         un pointeur sur le tableau des diff??rents param??tres de la ligne de commande.
* \return     int          un entier permettant de conna??tre la statut du lancement du programme.
*
*/

int main(int argc, char **argv)
{
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */

/**	            This Code initialize the context of windows on Wayland with glut.
*
* \brief      Appel de la fonction glutInit : fonction Glut d'initialisation
* \details    En entr??e de cette fonction, les param??tres de la ligne de commande.
* \param	  argc			    le nombre de param??tres mis ?? disposition			*
* \param	  argv              Hle tableau des diff??rents param??tres mis ?? disposition *
* \return     int               un integer.
*
*/

  glutInit(&argc, argv);

  /* Select type of Display mode:
     Double buffer
     RGBA color
     Alpha components supported
     Depth buffer */

/**	            This Code initialize le mode d'affichage d??fini avec une fonction glut.
*
* \brief      Appel de la fonction glutInitDisplayMode(: fonction Glut initialisant le mode d'affichage.
* \details    En entr??e de cette fonction, des param??tres s??par??s par des "ou logique".
* \param	  const         une succession deparam??tres s??par??s par des "ou logique".
* \return     void          aucun retour de fonction.
*
*/

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

  /* get a 640 x 480 window */

/**	            This Code initialize the dimensions (width & height) of the window into screen.
*
* \brief      Appel de la fonction glutInitWindowSize : fonction Glut initialisant la position de la fen??tre dans l'??cran.
* \details    En entr??e de cette fonction, les deux param??tres X et Y correspondant ?? la taille de la fen??tre dans l'??cran (deux dimensions)
* \param	  X			    la largeur de la fen??tre en x
* \param	  Y			    la hauteur de la fen??tre en y
* \return     void          aucun retour de fonction.
*
*/

  glutInitWindowSize(640, 480);

  /* the window starts at the upper left corner of the screen */

/**	            This Code initialize the position of the window into screen.
*
* \brief      Appel de la fonction glutInitWindowPosition : fonction Glut initialisant la position de la fen??tre dans l'??cran.
* \details    En entr??e de cette fonction, les deux param??tres X et Y de positionnement de la fen??tre dans l'??cran (deux dimensions)
* \param	  X			    le positionnement de la fen??tre en x
* \param	  Y			    le positionnement de la fen??tre en y
* \return     void          aucun retour de fonction.
*
*/

  glutInitWindowPosition(0, 0);

  /* Open a window */

/**	            This Code create windows on Wayland with glut.
*
* \brief      Appel de la fonction glutCreateWindow : fonction Glut cr??ant une fen??tre.
* \details    En entr??e de cette fonction, l'identification de la fen??tre (.id. son nom).
* \param	  tittle			le nom de la fen??tre
* \return     int               l'identifiant entier de la fen??tre cr??ee.
*
*/

  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... First Window - NeHe '99");

  /* Register the function to do all our OpenGL drawing. */

/**	            This Code rely the internal function DrawGLScene at the display function of glut.
*
* \brief      Appel de la fonction glutDisplayFunc : fonction Glut permettant d'activer la fonction interne d'affichage.
* \details    En entr??e de cette fonction, l'adresse de la fonction interne appell??e .
* \param	  &function			l'adresse de la fonction interne d'affichage.
* \return     void              aucun retour de fonction.
*
*/

  glutDisplayFunc(&DrawGLScene);

/**	            This Code rely the internal function DrawGLScene at the idle function of glut.
*
* \brief      Appel de la fonction glutIdleFunc : fonction d'attente de Glut permettant d'activer la fonction interne d'affichage.
* \details    En entr??e de cette fonction, l'adresse de la fonction interne appell??e.
* \param	  &function			l'adresse de la fonction interne d'affichage.
* \return     void              aucun retour de fonction.
*
*/

  /* Even if there are no events, redraw our gl scene. */

  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */

/**	            This Code rely the internal function ResizeGLScene at the reshape function of glut.
*
* \brief      Appel de la fonction glutReshapeFunc : fonction Glut permettant d'activer la fonction interne de changement des dimensions d'affichage.
* \details    En entr??e de cette fonction, l'adresse de la fonction interne appell??e.
* \param	  &function			l'adresse de la fonction interne traitant des changements de dimension de l'affichage.
* \return     void              aucun retour de fonction.
*
*/

  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */

/**	            This Code give pressed key used by this program.
*
* \brief      Appel de la fonction glutKeyboardFunc : fonction Glut permettant de recup??rer la touche appuy??e.
* \details    En entr??e de cette fonction, l'adresse de la touche appuy??e.
* \param	  &key			l'adresse de la touche appuy??e sur le clavier.
* \return     void          aucun retour de fonction.
*
*/

  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */

/**	            This Code initialize les param??tres d'affichage OpenGL.
*
* \brief      Appel de la fonction InitGL : fonction d'initialisation dde la taille de la fen??tre d'affichage OpenGL (la m??me que celle de glut).
* \details    En entr??e de cette fonction, les deux param??tres X et Y correspondant ?? la taille de la fen??tre OpenGL dans l'??cran (deux dimensions)
* \param	  X			    la largeur de la fen??tre en x
* \param	  Y			    la hauteur de la fen??tre en y
* \return     void          aucun retour de fonction.
*
*/

  InitGL(640, 480);

  /* Start Event Processing Engine */

/**	            This Code run the permanently wait loop of events.
*
* \brief      Appel de la fonction glutMainLoop : fonction lancant la boucle d'attente des ??v??nements sous glut.
* \details    Aucun param??tre en entr??e ni en sortie.
* \return     void          aucun retour de fonction.
*
*/

  glutMainLoop();

  return 1;
}

