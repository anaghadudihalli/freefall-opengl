#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

/* -- Variable declarations -- */
int ch = 1;   // Choice for the menu
int w = 600, h = 600;   //Width and height of the window
int pressed;


/* -- Function declarations -- */
void brick(int);   // Displaying Brick
void ground();   // Displaying ground
void feather(int);  // Displaying feather
void prTNR24(int n,char s[],int x,int y);   // Displaying text in Times new roman 24 size
void prTNR10(int n,char s[],int x,int y);	// Displaying text in Times new roman 10 size
void moveInVac();	// Move the objects in Vacuum
void moveInAir();	// Move the objects with Air Resistance
void display();
void myReshape(int w, int h);
void myKey(unsigned char key, int x, int y); 
void menu(int choice);
void myInit();



// Displaying brick
void brick(int y = 0) {	
 if(y <= 560) {
	glColor3f(0.501,0.18,0.121); // Brick color
	glBegin(GL_POLYGON);   // Front face
		glVertex2f(200,750 - y);
		glVertex2f(200,800 - y);
		glVertex2f(300,800 - y);
		glVertex2f(300,750 - y);
	glEnd();
	
	glBegin(GL_POLYGON);	// Top face
		glVertex2f(200,800 - y);
		glVertex2f(233.3,825 - y);
		glVertex2f(333.3,825 - y);
		glVertex2f(300,800 - y);
	glEnd();

	glBegin(GL_POLYGON);	// Side face
		glVertex2f(300,800 - y);
		glVertex2f(333.3,825 - y);
		glVertex2f(333.3,775 - y);
		glVertex2f(300,750 - y);
	glEnd();

	glColor3f(0.0,0.0,0.0);   // Brick Outline color
	glBegin(GL_LINES);	// Brick outline
		glVertex2f(200,800 - y);
		glVertex2f(300,800 - y);
		glVertex2f(300,800 - y);
		glVertex2f(333.3,825 - y);
		glVertex2f(300,800 - y);
		glVertex2f(300,750 - y);
	glEnd();
	glFlush();
 }
	else
		brick(560);
}


// Displaying ground
void ground() {
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(80,190);     
		glVertex2f(810,190);

		glColor3f(0,0.321,0.129);
		glVertex2f(100,190);	// #1 Grass
		glVertex2f(80,215);
		glVertex2f(100,190);
		glVertex2f(100,215);
		glVertex2f(100,190);
		glVertex2f(120,215);

		glVertex2f(200,190);	// #2 Grass	
		glVertex2f(180,215);
		glVertex2f(200,190);
		glVertex2f(200,215);
		glVertex2f(200,190);
		glVertex2f(220,215);

		glVertex2f(300,190);	// #3 Grass
		glVertex2f(280,215);
		glVertex2f(300,190);
		glVertex2f(300,215);
		glVertex2f(300,190);
		glVertex2f(320,215);

		glVertex2f(400,190);	// #4 Grass
		glVertex2f(380,215);
		glVertex2f(400,190);
		glVertex2f(400,215);
		glVertex2f(400,190);
		glVertex2f(420,215);

		glVertex2f(500,190);	// #5 Grass
		glVertex2f(480,215);
		glVertex2f(500,190);
		glVertex2f(500,215);
		glVertex2f(500,190);
		glVertex2f(520,215);

		glVertex2f(600,190);	// #6 Grass
		glVertex2f(580,215);
		glVertex2f(600,190);
		glVertex2f(600,215);
		glVertex2f(600,190);
		glVertex2f(620,215);

		glVertex2f(700,190);	// #7 Grass
		glVertex2f(680,215);
		glVertex2f(700,190);
		glVertex2f(700,215);
		glVertex2f(700,190);
		glVertex2f(720,215);

		glVertex2f(800,190);	// #8 Grass
		glVertex2f(780,215);
		glVertex2f(800,190);
		glVertex2f(800,215);
		glVertex2f(800,190);
		glVertex2f(820,215);
	glEnd();
	glFlush();
} 


// Displaying feather
void feather(int y = 0) {	
	glColor3f(0.52,0.53,0.54);	// Feather
	glBegin(GL_LINES);  // Feather shaft
		 glVertex2f(600,750 - y);
		 glVertex2f(605,758 - y);
		 glVertex2f(605,758 - y);
		 glVertex2f(610,765 - y);
		 glVertex2f(610,765 - y);
		 glVertex2f(616,771 - y);
		 glVertex2f(616,771 - y);
		 glVertex2f(623,777 - y);
		 glVertex2f(623,777 - y);
		 glVertex2f(629,782 - y);
		 glVertex2f(629,782 - y);
		 glVertex2f(635,787 - y);
		 glVertex2f(635,787 - y);
		 glVertex2f(643,792 - y);
		 glVertex2f(643,792 - y);
		 glVertex2f(649,796 - y);
		 glVertex2f(649,796 - y);
		 glVertex2f(656,799 - y);
		 glVertex2f(656,799 - y); 
		 glVertex2f(664,802.5 - y);

		  
		 glVertex2f(605,758 - y); // #1
		 glVertex2f(603,768 - y);
		 glVertex2f(605,758 - y);
		 glVertex2f(621,762 - y);
	 
		 glVertex2f(610,765 - y); // #2
		 glVertex2f(611,775 - y);
		 glVertex2f(610,765 - y);
		 glVertex2f(629,768 - y);

		 glVertex2f(616,771 - y); // #3
		 glVertex2f(617,782.5 - y);
		 glVertex2f(616,771 - y);
		 glVertex2f(636,775.5 - y);
	 
		 glVertex2f(623,777 - y); // #4
		 glVertex2f(625,787 - y);
		 glVertex2f(623,777 - y);
		 glVertex2f(643,784 - y);

		 glVertex2f(629,782 - y); // #5
		 glVertex2f(631,794 - y);
		 glVertex2f(629,782 - y);
		 glVertex2f(643,787 - y);

		 glVertex2f(635,787 - y); // #6
		 glVertex2f(639,795.5 - y);
		 glVertex2f(635,787 - y);
		 glVertex2f(649,794 - y);

		 glVertex2f(643,792 - y); // #7
		 glVertex2f(647,801 - y);
		 glVertex2f(643,792 - y);
		 glVertex2f(656,794 - y);

		 glVertex2f(649,796 - y); // #8
		 glVertex2f(655,805 - y);
		 glVertex2f(649,796 - y);
		 glVertex2f(663,798 - y);
	 
		 glVertex2f(656,799 - y); // #9
		 glVertex2f(663,806 - y);
		 glVertex2f(656,799 - y);
		 glVertex2f(666,805 - y);
	glEnd();
	glFlush();
}


// Displaying text in Times New Roman 24 size
void prTNR24(int n,char s[],int x,int y) {	
	int k;
	glColor3f(1.0,1.0,1.0);
	glRasterPos2i(x,y);
	for(k = 0;k < n;k++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
	glColor3f(1,1,1);
}


// Displaying text in Times New Roman 10 size
void prTNR10(int n,char s[],int x,int y) {	
	int k;
	glColor3f(1.0,1.0,1.0);
	glRasterPos2i(x,y);
	for(k = 0;k < n;k++)
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[k]);
	glColor3f(1,1,1);
}


//Move the objects in Vacuum
void moveInVac() {
	int i;
	char vac[10] = "In Vacuum";
	for(i = 0; i < 570; i += 20) {
		glClear(GL_COLOR_BUFFER_BIT);
		brick(i);
		feather(i);
		prTNR24(10,vac,380,930);
		ground();
		_sleep(100);
	}
}


// Move the objects with Air Resistance
void moveInAir() {
	int i;
	char air[20] = "With Air Resistance";
	for(i = 0; i < 570; i += 10) {
		glClear(GL_COLOR_BUFFER_BIT);
		brick(2*i);
		feather(i);
		prTNR24(20,air,310,930);
		ground();
		_sleep(100);
	}  
}


void display() {
	char press[17] = "Press S to start";
	if(ch == 1) {
		glClear(GL_COLOR_BUFFER_BIT);
		char free[24] = "FREE FALL DEMONSTRATION";
		char cg[40] = "Computer Graphics Project";
		char by[3] = "by";
		char ana[28] = "Anagha Raghvendra Dudihalli";
		char ausn[11] = "1JB14CS028";
		char pra[22] = "Bonagiri Sri Pranathi";
		char pusn[11] = "1JB14CS042";
		char minst[31] = "(Right click for more options)";

		glColor3f(1.0,1.0,1.0);
		prTNR24(24,free,340,900);
		prTNR10(31,minst,380,850);
		prTNR10(40,cg,400,600);
		prTNR10(3,by,550,550);
		prTNR10(28,ana,20,200);
		prTNR10(11,ausn,20,150);
		prTNR10(22,pra,800,200);
		prTNR10(11,pusn,800,150);

		glFlush();
	} else if(ch == 2) {
		glClear(GL_COLOR_BUFFER_BIT);
		
		char intro[13] = "INTRODUCTION";
		glColor3f(1.0,1.0,1.0);
		prTNR24(13,intro,800,840);
		
		char l1[138] = "In fourth-century BC Greece the philosopher Aristotle theorized that the speed at which an object falls is probably relative to its mass.";
		char l2[141] = "In other words, if two objects are the same size but one is heavier, the heavier one has greater density than the lighter object. Therefore,";
		char l3[138] = "when both objects are dropped from the same height and at the same time, the heavier object should hit the ground before the lighter one.";
		char l4[14] = "Is this true?";
		prTNR10(138,l1,100,700);
		prTNR10(141,l2,100,675);
		prTNR10(138,l3,100,650);
		prTNR10(14,l4,100,625);

		char l5[139] = "Some 1,800 years later, in late 16th-century Italy, scientist and mathematician Galileo Galilei questioned Aristotle's theories of falling";
		char l6[141] = "objects. Galileo performed an experiment from the top of the leaning tower of Pisa. He dropped two spheres of different weight and observed ";
		char l7[43] = "that both hit the ground at the same time.";
		prTNR10(139,l5,100,575);
		prTNR10(141,l6,100,550);
		prTNR10(43,l7,100,525);

		char l8[141] = "Galileo reasoned that when an object falls more slowly, it is due to air resistance.  An object moving solely under the influence of gravity";
		char l9[141] = "is said to be in free fall; near the surface of the Earth such an object falls at an acceleration of 9.8 metres per second squared. Hence in";
		char l10[78] = "a vacuum, two objects of different mass will hit the ground at the same time.";
		prTNR10(141,l8,100,475);
		prTNR10(141,l9,100,450);
		prTNR10(78,l10,100,425);

		glFlush();
	} else if (ch == 3) {
		int i, y = 825;
		char air[20] = "With Air Resistance";
		glClear(GL_COLOR_BUFFER_BIT);
		prTNR24(20,air,310,930);
		prTNR10(17,press,360,880);
		brick();
		ground();
		feather();
        if(pressed == 1) {
		   moveInAir();
		}
		glFlush();
		
	} else {
		int  i,y = 825;
		char vac[10]="In Vacuum";
		glClear(GL_COLOR_BUFFER_BIT);
		prTNR24(10,vac,380,930);
		prTNR10(17,press,360,880);
		brick();
		ground();
		feather();
		if(pressed == 1) {
		   moveInVac();
		}
	glFlush();
}
}


void myReshape(int w, int h) {
	
	(w >= h) ? glViewport(0,0,(GLsizei)h, (GLsizei)h) : glViewport(0,0,(GLsizei)w, (GLsizei)w);
}


//Keyboard function
void myKey(unsigned char key, int x, int y) {
	if(key == 's' || key == 'S') 
		pressed = 1;
	display();
}


void menu(int choice) {
	switch(choice) {
		case 1:
			ch = 1;
			break;
		case 2: 
			ch = 2;
			break;
		case 3:
			ch = 3;
			break;
		case 4: 
			ch = 4;
			break;
		case 5:
			exit(0);
			break;
	}	
	glutPostRedisplay();
}


void myInit() {
	glutCreateMenu(menu);
	glutAddMenuEntry("Start Screen",1);
	glutAddMenuEntry("Introduction",2);
	glutAddMenuEntry("With Air Resistance",3);
	glutAddMenuEntry("In Vacuum",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0.0,0.0,0.0,0.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}


void main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Free Fall Demonstration");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKey);
	myInit();
	glutMainLoop();
}
