#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
int ch=0;
void brick()
{
	glColor3f(0.501,0.18,0.121);
	glBegin(GL_POLYGON);
	 glVertex2f(200,750);
	 glVertex2f(200,800);
	 glVertex2f(300,800);
	 glVertex2f(300,750);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(200,800);
		glVertex2f(233.3,825);
		glVertex2f(333.3,825);
		glVertex2f(300,800);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(300,800);
		glVertex2f(333.3,825);
		glVertex2f(333.3,775);
		glVertex2f(300,750);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	
	glBegin(GL_LINES);
		glVertex2f(200,800);
		glVertex2f(300,800);
		glVertex2f(300,800);
		glVertex2f(333.3,825);
		glVertex2f(300,800);
		glVertex2f(300,750);
	glEnd();

	glFlush();
}

void ground()
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	 glVertex2f(100,190);
	 glVertex2f(810,190);
	 glEnd();
	 glFlush();
} 

void feather()
{
	//main feather line
	//glColor3f(0.176,0.43,0.21); //Leaf
	glColor3f(0.52,0.53,0.54); //Feather
	glBegin(GL_LINES);
	 glVertex2f(600,750);
	 glVertex2f(605,758);
	 glVertex2f(605,758);
	 glVertex2f(610,765);
	 glVertex2f(610,765);
	 glVertex2f(616,771);
	 glVertex2f(616,771);
	 glVertex2f(623,777);
	 glVertex2f(623,777);
	 glVertex2f(629,782);
	 glVertex2f(629,782);
	 glVertex2f(635,787);
	 glVertex2f(635,787);
	 glVertex2f(643,792);
	 glVertex2f(643,792);
	 glVertex2f(649,796);
	 glVertex2f(649,796);
	 glVertex2f(656,799);
	 glVertex2f(656,799); 
     glVertex2f(664,802.5);

	 glVertex2f(605,758); //1
	 glVertex2f(603,768);
     glVertex2f(605,758);
	 glVertex2f(621,762);
	 
	 glVertex2f(610,765);//2
	 glVertex2f(611,775);
	 glVertex2f(610,765);
	 glVertex2f(629,768);

	 glVertex2f(616,771); //3
	 glVertex2f(617,782.5);
	 glVertex2f(616,771);
	 glVertex2f(636,775.5);
	 
	 
	 glVertex2f(623,777); //4
	 glVertex2f(625,787);
	 glVertex2f(623,777);
	 glVertex2f(643,784);


	 glVertex2f(629,782); //5
	 glVertex2f(631,794);
	 glVertex2f(629,782);
	 glVertex2f(643,787);

	 glVertex2f(635,787); //6
	 glVertex2f(639,795.5);
	 glVertex2f(635,787);
	 glVertex2f(649,794);

	 glVertex2f(643,792); //7
	 glVertex2f(647,801);
	 glVertex2f(643,792);
	 glVertex2f(656,794);

	 glVertex2f(649,796); //8
	 glVertex2f(655,805);
	 glVertex2f(649,796);
	 glVertex2f(663,798);
	 
	 glVertex2f(656,799); //9
	 glVertex2f(663,806);
	 glVertex2f(656,799);
	 glVertex2f(666,805);

	glEnd();
	glFlush();
}
void prTNR24(int n,char s[],int x,int y)
{
  int k;
  glRasterPos2i(x,y);
  for(k=0;k<n;k++)
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
  glColor3f(1,1,1);
}
void prTNR10(int n,char s[],int x,int y)
{
  int k;
  glRasterPos2i(x,y);
  for(k=0;k<n;k++)
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[k]);
  glColor3f(1,1,1);
}
void display()
{
	int k;
	char free[24]="FREE FALL DEMONSTRATION";
	char cg[40]="Computer Graphics Project";
	char by[3] ="by";
	char ana[28]="Anagha Raghvendra Dudihalli";
	char ausn[11]="1JB14CS028";
	char pra[22]="Bonagiri Sri Pranathi";
	char pusn[11]="1JB14CS042";

	prTNR24(24,free,360,900);
	prTNR10(40,cg,400,600);
	prTNR10(3,by,470,550);
    prTNR10(28,ana,20,200);
	prTNR10(11,ausn,20,150);
	prTNR10(22,pra,800,200);
	prTNR10(11,pusn,800,150);
	
	if(ch==2)
	{ 
	 glClear(GL_COLOR_BUFFER_BIT);
     brick();
	 ground();
	 feather();
	}

	glFlush();
}

void myReshape(int w, int h)
{
	if(w>=h)
		glViewport(0,0,(GLsizei)h, (GLsizei)h);
	else
		glViewport(0,0,(GLsizei)w, (GLsizei)w);
}
void menu(int choice)
{
	switch(choice)
	{
	case 1: 
		break;
	case 2: ch=2;
		break;
	case 3:
		break;
	case 4: exit(0);
		break;
	}
	glutPostRedisplay();
}
void myinit()
{
	glutCreateMenu(menu);
	glutAddMenuEntry("Introduction",1);
	glutAddMenuEntry("With Air",2);
	glutAddMenuEntry("In Vacuum",3);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Free Fall");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}