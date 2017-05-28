#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

/* -- Variable declarations -- */
int ch=1;   // Choice for the menu
int w=600, h=600;   //Width and height of the window


/* -- Function declarations -- */
void brick();   // Displaying Brick
void ground();   // Displaying ground
void feather();  // Displaying feather
void prTNR24(int n,char s[],int x,int y);   // Displaying text in Times new roman 24 size
void prTNR10(int n,char s[],int x,int y);	// Displaying text in Times new roman 10 size
void display();
void myReshape(int w, int h);
void menu(int choice);
void myinit();



// Displaying brick
void brick() {	
    glColor3f(0.501,0.18,0.121); // Brick color
	glBegin(GL_POLYGON);   // Front face
		glVertex2f(200,750);
		glVertex2f(200,800);
		glVertex2f(300,800);
		glVertex2f(300,750);
	glEnd();
	
	glBegin(GL_POLYGON);	// Top face
		glVertex2f(200,800);
		glVertex2f(233.3,825);
		glVertex2f(333.3,825);
		glVertex2f(300,800);
	glEnd();

	glBegin(GL_POLYGON);	// Side face
		glVertex2f(300,800);
		glVertex2f(333.3,825);
		glVertex2f(333.3,775);
		glVertex2f(300,750);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);	// Brick outline
		glVertex2f(200,800);
		glVertex2f(300,800);
		glVertex2f(300,800);
		glVertex2f(333.3,825);
		glVertex2f(300,800);
		glVertex2f(300,750);
	glEnd();
	glFlush();
}


void ground() {	// displaying ground
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(100,190);
		glVertex2f(810,190);
	glEnd();
	glFlush();
} 


// Displaying feather
void feather() {	
	//glColor3f(0.176,0.43,0.21);	//Leaf
	glColor3f(0.52,0.53,0.54);	//Feather
		
	glBegin(GL_LINES);  // feather shaft
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
	 
		 glVertex2f(610,765); //2
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


// Displaying text in Times New Roman 24 size
void prTNR24(int n,char s[],int x,int y) {	
	int k;
	glRasterPos2i(x,y);
	for(k=0;k<n;k++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
	glColor3f(1,1,1);
}


// Displaying text in Times New Roman 10 size
void prTNR10(int n,char s[],int x,int y) {	
	int k;
	glRasterPos2i(x,y);
	for(k=0;k<n;k++)
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[k]);
	glColor3f(1,1,1);
}


void display() {
	if(ch==1) {
		glClear(GL_COLOR_BUFFER_BIT);
		char free[24]="FREE FALL DEMONSTRATION";
		char cg[40]="Computer Graphics Project";
		char by[3] ="by";
		char ana[28]="Anagha Raghvendra Dudihalli";
		char ausn[11]="1JB14CS028";
		char pra[22]="Bonagiri Sri Pranathi";
		char pusn[11]="1JB14CS042";

		glColor3f(1.0,1.0,1.0);
		prTNR24(24,free,340,900);
		prTNR10(40,cg,400,600);
		prTNR10(3,by,550,550);
		prTNR10(28,ana,20,200);
		prTNR10(11,ausn,20,150);
		prTNR10(22,pra,800,200);
		prTNR10(11,pusn,800,150);
	}

	if(ch==2) {
		glClear(GL_COLOR_BUFFER_BIT);
		
		char intro[13]="INTRODUCTION";
		prTNR24(13,intro,800,840);
		
		char l1[138]="In fourth-century BC Greece the philosopher Aristotle theorized that the speed at which an object falls is probably relative to its mass.";
		char l2[141]="In other words, if two objects are the same size but one is heavier, the heavier one has greater density than the lighter object. Therefore,";
		char l3[138]="when both objects are dropped from the same height and at the same time, the heavier object should hit the ground before the lighter one.";
		char l4[14]="Is this true?";
		prTNR10(138,l1,100,700);
		prTNR10(141,l2,100,675);
		prTNR10(138,l3,100,650);
		prTNR10(14,l4,100,625);

		char l5[139]="Some 1,800 years later, in late 16th-century Italy, scientist and mathematician Galileo Galilei questioned Aristotle's theories of falling";
		char l6[141]="objects. Galileo performed an experiment from the top of the leaning tower of Pisa. He dropped two spheres of different weight and observed ";
		char l7[43]="that both hit the ground at the same time.";
		prTNR10(139,l5,100,575);
		prTNR10(141,l6,100,550);
		prTNR10(43,l7,100,525);

		char l8[141]="Galileo reasoned that when an object falls more slowly, it is due to air resistance.  An object moving solely under the influence of gravity";
		char l9[141]="is said to be in free fall; near the surface of the Earth such an object falls at an acceleration of 9.8 metres per second squared. Hence in";
		char l10[78]="a vacuum, two objects of different mass will hit the ground at the same time.";
		prTNR10(141,l8,100,475);
		prTNR10(141,l9,100,450);
		prTNR10(78,l10,100,425);

		glFlush();
	}

	if(ch==3) {
		glClear(GL_COLOR_BUFFER_BIT);
		brick();
		ground();
		feather();
	}

	if(ch==4) {
		glClear(GL_COLOR_BUFFER_BIT);
		brick();
		ground();
		feather();
	}
	glFlush();
}


void myReshape(int w, int h) {
	if(w>=h)
		glViewport(0,0,(GLsizei)h, (GLsizei)h);
	else
		glViewport(0,0,(GLsizei)w, (GLsizei)w);
}


void menu(int choice) {
	switch(choice) {
		case 1:
			ch=1;
			break;
		case 2: 
			ch=2;
			break;
		case 3:
			ch=3;
			break;
		case 4: 
			ch=4;
			break;
		case 5:
			exit(0);
			break;
	}	
	glutPostRedisplay();
}


void myinit() {
	glutCreateMenu(menu);
	glutAddMenuEntry("Start Screen",1);
	glutAddMenuEntry("Introduction",2);
	glutAddMenuEntry("With Air",3);
	glutAddMenuEntry("In Vacuum",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}


void main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Free Fall");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}