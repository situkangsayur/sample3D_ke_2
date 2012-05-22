#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

}

void display(void) {


	//warna
	/*	GLfloat warna_specular[] = { 0.0, 0.0, 1.0, 0.0 };
		GLfloat white_light[] = { 1.0, 1.0, 1.0, 0.0 };
		GLfloat blue_light[] = { 0.0, 0.0, 1.0, 0.0 };
		GLfloat lmodel_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
		//===


		GLfloat mat_shininess[] = { 50.0 };

		GLfloat light_position[] = { -9.0, 8.0, 10.0, 0.0 };

		GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };

		glMaterialfv(GL_FRONT, GL_SPECULAR, warna_specular);

		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
		glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

		glColorMaterial(GL_FRONT, GL_DIFFUSE);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glEnable(GL_COLOR_MATERIAL);

		glEnable(GL_DEPTH_TEST);*/

	//gluLookAt(0.0, 0.0, 2.0, 2.0, 4.0, -3.0, 0.0, 0.0, 0.0);
	/*glBegin(GL_POLYGON);
	 glVertex3d(50,20,-20); //A
	 glVertex3d(250,20,-20); //B
	 glVertex3d(250,20,-150); //C
	 glVertex3d(50,20,-150); //D
	 glVertex3d(50,20,-20); //A

	 glVertex3d(50,250,-20); //E
	 glVertex3d(250,250,-20); //F
	 glVertex3d(250,250,-150); //G
	 glVertex3d(50,250,-150); //H
	 glVertex3d(50,250,-20); //E

	 glEnd();*/

	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);


	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	/* clear the matrix */
	/* viewing transformation */
	gluLookAt(7.0, 5.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(0.0, 1.0, 1.0);
	glutWireCube(3);

	glPushMatrix();
	glScalef(0.5, 1.0, 0.4);
	glTranslatef(0.0, 0.0, -7.0);
	glutSolidSphere(3.0, 20.0, 16.0);

	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.3, 1.0, 1.0);
	//glutWireTorus(3.0,5.0,20,18);

	glPopMatrix();

	glColor3f(0.0, 1.0, 0.0);

	//glutWireTeapot(2);

	glPushMatrix();
	//glScalef(0.3,0.5, 3.0);
	//glTranslatef(0.0,0.0,3.0);

	glBegin(GL_LINE_LOOP);///begin

	glNormal3f(2.5, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);

	glVertex3f(-2.5, 0.0, 2.0);//A
	glVertex3f(2.5, 0.0, 2.0);//B
	glVertex3f(2.5, 0.0, -2.0);//C
	glVertex3f(-2.5, 0.0, -2.0);//D
	glVertex3f(-2.5, 0.0, 2.0);//E

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-2.5, -0.7, 2.0);//E
	glVertex3f(2.5, -0.7, 2.0);//F
	glVertex3f(2.5, -0.7, -2.0);//G
	glVertex3f(-2.5, -0.7, -2.0);//H
	glVertex3f(-2.5, -0.7, 2.0);//E
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(2.5, -0.7, 2.0);//F
	glVertex3f(2.5, 0.0, 2.0);//B
	glVertex3f(2.5, 0.0, -2.0);//C
	glVertex3f(2.5, -0.7, -2.0);//G
	glVertex3f(-2.5, -0.7, -2.0);//H
	glVertex3f(-2.5, 0.0, -2.0);//D


	glEnd();//end
	//glutWireTeapot(1.0);
	glPopMatrix();

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 25.0);
	//gluPerspective(5.0,2.0,7.0,5.0);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("new");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
