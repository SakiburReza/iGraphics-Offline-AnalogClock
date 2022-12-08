#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
int x = 300, y = 300, r = 20;
double x1=250,ut=250,x2=250,y2=350,m=6;
double x1m=250,y1m=250,x2m=250,y2m=330,n=1;
double x1h=250,y1h=250,x2h=250,y2h=310,o=1;
int mode=0,h,mi,s;
int a,b,d;
char hr[3],minu[3],se[3];

static int c=1;
static int i=0;
void roth()
{
    if(mode) o=b*.5+30*a;
    x2h=250+60*sin(o*3.1416/180);
    y2h=250+60*cos(o*3.1416/180);

    if(!mode)o=o+.008333;
}

void rotamin()
{
    if(mode) n=+b*6;

    x2m=250+80*sin(n*3.1416/180);
    y2m=250+80*cos(n*3.1416/180);

    if(!mode) n=n+.1;
}
void rotation()
{
    if(mode) m=d*6;

    x2=250+100*sin(m*3.1416/180);
    y2=250+100*cos(m*3.1416/180);

    if(!mode) m+=6;
}

/*
	function iDraw() is called again and again by the system.

	*/
void iDraw() {
	//place your drawing codes here
	iClear();


	iSetColor(250,0,100);
	iCircle(250,250,100);
	iText(250,340,"12");
	iText(250,152,"6");
	iText(150,245,"9");
	iText(340,250,"3");
	iText(300,327,"1");
	iText(298,165.4,"5");
    iText(327,298,"2");
	iText(331,200,"4");
	iText(200,327,"11");
	iText(198,165.4,"7");
    iText(160.4,294,"10");
	iText(163.4,196,"8");
	iSetColor(255,252,252);
    iLine(x1,ut,x2,y2);
    iSetColor(150,220,150);
    iLine(x1m,y1m,x2m,y2m);
    iSetColor(255,255,0);
    iLine(x1h,y1h,x2h,y2h);
    iSetColor(252,252,252);
    iRectangle(50,400,220,50);
    iSetColor(0,255,0);
    iText(60,420,"Set Time:   H   M   S");
    iSetColor(255,0,0);
   if(mode) iText(140,420,hr);
   if(mode) iText(170,420,minu);
   if(mode) iText(200,420,se);
   iSetColor(100,0,255);
   iText(30,480,"Click in the box to set time");
   iText(30,70,"Click outside the box to start clock");

	/*iLine(250,250,350,250);
	iLine(250,250,350,250);*/






}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		if(mx>=50&&mx<=220&&my>=400&&my<=450) mode=1;
		else {
                c=1;
        i=0;
                mode=0;
        hr[0]=0;hr[1]=0;
    minu[0]=0;minu[1]=0;
    se[0]=0;se[1]=0;

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

	}
}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {

	if(mode){
	if (key == 'q') {

		exit(0);
	}


	else{
       if(c==1||c==2){
       hr[i] = key;
       c++;
       i++;
       if(c==3){
           hr[i]=0;
          a=atoi(hr);

            i=0;
       }
       }

       else if(c==3||c==4){


        minu[i]=key;
        c++;
        i++;
     if(c==5){
        minu[i]=0;
        b=atoi(minu);

        i=0;
     }
       }
       else if(c==5||c==6){

        se[i]=key;
        c++;
        i++;
        if(c==7){
           se[i]=0;
           d=atoi(se);

        }

       }

	}
}



        //printf("%c\n",key);
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	iSetTimer(1000,rotation);
	iSetTimer(1000,rotamin);
	iSetTimer(1000,roth);
	iInitialize(500, 500, "Clock");

	return 0;
}
