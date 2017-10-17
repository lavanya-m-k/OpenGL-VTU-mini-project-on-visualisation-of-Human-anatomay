#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fi 4
void desc();
int flag=0;
GLfloat v[][3]={{-35,30,-2.5},{-20,30,-2.5},{-20,40,-2.5},{-35,40,-2.5},{-35,30,2.5},{-20,30,2.5},{-20,40,2.5},{-35,40,2.5}};
GLfloat dx=0,dy=0,tx=0,ty=0,mx=0,my=0,rx=0,ry=0;
GLfloat a,b;
unsigned char keyf=0;
int strflag=0;

void drawstring(float x,float y,float z,const char *str)
{
unsigned int c;
glRasterPos3f(x,y,z);
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[c]);
}

void drawstring1(float x,float y,float z,const char *str)
{
unsigned int c;
glRasterPos3f(x,y,z);
if(strflag==0)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[c]);
if(strflag==1)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[c]);
if(strflag==2)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str[c]);
}


void drawline(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
glBegin(GL_LINES);
glVertex3f(x1,y1,0);
glVertex3f(x2,y2,0);
glEnd();
}

void drawcircle(GLfloat m, GLfloat n)
{
GLfloat i;
glBegin(GL_LINE_LOOP);
for(i=0;i<=2*3.14;i+=0.0005)
glVertex3f(m+cos(i)*3,n+sin(i)*3,0);
glEnd();
}

void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 drawstring(-15,40,0.0,"NIE INSTITUTE OF TECHNOLOGY");
 glColor3f(0.7,0,1);
 drawstring(-30,35,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(-15,30,0.0,"A MINI PROJECT ON ");
 glColor3f(1,0,0);
 drawstring(-25,20,0.0,"HUMAN DIGESTIVE AND RESPIRATORY SYSTEM");
 glColor3f(1,0.5,0);
 drawstring(-35,0,0.0,"BY:");
 glColor3f(0.5,0,0.5);
 drawstring(-35,-10,0.0,"LAVANYA M K (4NN14CS019)");
 strflag=0;
 drawstring(-35,-14,0.0,"6th Semester,CSE");
 glColor3f(1,0.5,0);
 drawstring(15,0,0.0,"GUIDE:");
 glColor3f(0.5,0.2,0.2);
 drawstring(15,-10,0.0,"PREMA N");
 strflag=0;
 drawstring(15,-14,0.0,"Assistant Professor,CSE");
 glColor3f(1,0.1,1);
 drawstring(-13,-35,0.0,"PRESS ENTER TO START");
 glFlush();
}

void body()
{
GLfloat i,x,y;
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex3f(x=0+cos(1)*7,y=35+sin(1)*7,0);
for(i=1;i<=3.81;i+=0.05)
glVertex3f(0+cos(i)*7,36.3+sin(i)*7,0);
glVertex3f(-7,35,0);
glVertex3f(-6,27,0);
glEnd();
//face
glColor3ub(255,191,128);
glBegin(GL_POLYGON);
glVertex3f(x,y,0);
glVertex3f(x,y-5,0);
glVertex3f(x,y-5.5,0);
glVertex3f(x,y-6,0);
glVertex3f(x+1.5,y-9,0);
glVertex3f(x,y-9,0);
glVertex3f(x,y-11,0);
glVertex3f(x-0.5,y-12,0);
glVertex3f(x-0.5,y-13,0);
glVertex3f(x-1,y-14,0);
glVertex3f(x-3,y-16,0);
glVertex3f(x-6,y-16,0);
glVertex3f(-6,27,0);
glVertex3f(-5,30,0);
glVertex3f(-4,32.5,0);
glVertex3f(-3.7,35,0);
//glVertex3f(-3.5,37,0);
//glVertex3f(-3,36,0);
glVertex3f(-2,35,0);
glEnd();
glBegin(GL_POLYGON);//neck
glVertex3f(1,27,0);
glVertex3f(-4,27,0);
glVertex3f(-4,22,0);
glVertex3f(1,22,0);
glEnd();
glBegin(GL_POLYGON);
for(i=3.14;i>(3.14/2.0);i-=0.05)
glVertex3f(-9+cos(i)*5,15+sin(i)*7,0);
glVertex3f(-9,22,0);
glVertex3f(5,22,0);
for(i=(3.14/2.0);i>0;i-=0.05)
glVertex3f(5+cos(i)*7,15+sin(i)*7,0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(-9,15.1,0);
glVertex3f(7,15.1,0);
glVertex3f(6,0,0);
glVertex3f(-8,0,0);
glEnd();
glBegin(GL_POLYGON);//left hand
glVertex3f(-13.99,15.011,0);
glVertex3f(-9,15.011,0);
glVertex3f(-10,2.011,0);
glVertex3f(-13.59,2.011,0);
glEnd();
glBegin(GL_POLYGON);//Right hand
glVertex3f(12,15.011,0);
glVertex3f(6.7,15.011,0);
glVertex3f(8,1.011,0);
glVertex3f(11.5,1.011,0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(6,0,0);
glVertex3f(-8,0,0);
glVertex3f(-9,-18,0);
glVertex3f(7,-18,0);
glEnd();
dx=x-1;dy=y-11;
a=x;b=y;
}


GLfloat aa,bb;
void digesdraw()
{
GLfloat i;
body();
glLineWidth(15);
glColor3ub(255,100,50);
glBegin(GL_LINE_STRIP);
glVertex3f(a,b-11,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(2+cos(i)*3.5,26+sin(i)*3.5,0);//oesophagus1
glVertex3f(-1.5,27,0);
glVertex3f(-1.5,4.5,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(a,b-11,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(2.5+cos(i)*3.5,26.2+sin(i)*3.5,0);//oesophagus2
glVertex3f(-1.2,25,0);
glVertex3f(-1.2,4,0);
glEnd();
glBegin(GL_POLYGON);//stomach upper
for(i=(5*3.14/2.0);i>=(3*3.14/2);i-=0.005)
glVertex3f(aa=(1+cos(i)*4),bb=(0+sin(i)*4),0);
glVertex3f(-1.5,5,0);
glEnd();
glBegin(GL_POLYGON);//stomach lower
glVertex3f(aa,bb,0);
for(i=(3.14/2);i<(3*3.14/2);i+=0.005)
glVertex3f(0+cos(i)*2.5,-2+sin(i)*2.5,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-2.5,-2,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(aa=-1.4+cos(i)*3,bb=-4.5+sin(i)*3,0);
for(i=(3.14/2.0);i<=3.0;i+=0.0005)
glVertex3f(-1.3+cos(i)*3,-5+sin(i)*3,0);
//glVertex3f(-3,-3.2,0);
//glVertex3f(-3,-3.5,0);
glEnd();
double freq=0.3,amp=4.5;
glBegin(GL_LINE_STRIP);
glVertex3f(aa,bb,0);
glVertex3f(aa,bb-3,0);
glEnd();
glBegin(GL_LINE_STRIP);//small interestine
for(i=-5;i>=-14;i-=0.005)
glVertex3f((amp*sin(2*3.14*freq*i)),i,0);
glEnd();

glColor3f(0,0,0);//border
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(41,51,0);
glVertex3f(-41,51,0);
glVertex3f(-41,-21,0);
glVertex3f(41,-21,0);
glEnd();
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex3f(40,50,0);
glVertex3f(-40,50,0);
glVertex3f(-40,-20,0);
glVertex3f(40,-20,0);
glEnd();
strflag=1;
glColor3ub(0, 207, 119);
drawstring1(-20,-30,0,"HUMAN DIGESTIVE SYSTEM");
strflag=0;
glColor3f(0,0,0);
//drawline(a+1,b-9,a+5.6,b-9);
//drawstring1(a+6,b-9,0,"Nose");
drawline(a,b-12,a+6.5,b-12);
drawstring1(a+7,b-12,0,"Mouth");
drawline(-10,28,-1,28);
drawstring1(-16,28,0,"Pharynx");
drawline(-12,22,-1.5,22);
drawstring1(-20,22,0,"Oesophagus");
drawline(10,0,3,0);
drawstring1(10.5,0,0,"Stomach");
drawline(-14,-2,-2,-2);
drawstring1(-22,-2,0,"Duodenum");

//glLoadIdentity();
}


void liver()
{
GLfloat i;
glColor3ub(200,100,50);//liver
glBegin(GL_POLYGON);
glVertex3f(-1.2,4,0);
glVertex3f(-1.5,5,0);
glVertex3f(-1,6,0);
for(i=(3.14/2.0);i<=3.5;i+=0.005)
glVertex3f(0+cos(i)*6,0+sin(i)*7,0);
glEnd();
glLineWidth(1);
strflag=0;
glColor3f(0,0,0);
drawline(-15,4,-4,4);
drawstring1(-20,4,0,"Liver");
}
void largeinstes()
{
glLineWidth(15);
GLfloat i;
glColor3ub(240,150,50);//large interstine
glBegin(GL_LINE_LOOP);
glVertex3f(-1,-17.5,0);
glVertex3f(-1,-15,0);
glVertex3f(4,-15,0);
glVertex3f(4,-6,0);
glVertex3f(-5.3,-6,0);
glVertex3f(-5.3,-14,0);
glVertex3f(-2,-13,0);
glVertex3f(-2,-14,0);
glVertex3f(-6,-14,0);
glVertex3f(-6,-5,0);
glVertex3f(4.7,-5,0);
glVertex3f(4.7,-16,0);
glVertex3f(3,-16,0);
glVertex3f(1,-16,0);
glVertex3f(-1,-16,0);
glEnd();
glLineWidth(1);
strflag=0;
glColor3f(0,0,0);
drawline(-14,-7,-5,-7);
drawstring1(-24,-7,0,"Large intestine");
drawline(9.5,-9,1,-9);
drawstring1(10,-9,0,"Small intestine");
drawline(9.5,-15,-1,-15);
drawstring1(10,-15,0,"Rectum");
drawline(9.5,-17.5,-1,-17.5);
drawstring1(10,-17.5,0,"Anus");

}
int countd=0;

void food()
{
glPointSize(5);//food
glColor3ub(20,190,50);
//glColor3f(0,0,0);
glBegin(GL_POINTS);
glVertex3f(0.9,27,0);
glEnd();
glBegin(GL_POINTS);
glVertex3f(0.65,27.2,0);
glEnd();
}

void foodp()
{
glPointSize(3);//food
glColor3ub(20,190,50);
//glColor3f(0,0,0);
glBegin(GL_POINTS);
glVertex3f(-4.4,6.5,0);
glVertex3f(-3.9,6.5,0);
glVertex3f(-4.1,7.2,0);
glEnd();
}


void digest()
{
GLfloat i,dy=-1;
digesdraw();
glPushMatrix();
//glColor3f(1.0,1.0,0.0);
glTranslatef(dx+tx,dy+ty,0.0);
food();
glPopMatrix();
glPushMatrix();
glTranslatef(dx+mx,dy+my,0.0);
foodp();
glPopMatrix();
liver();
largeinstes();
if(countd==1)
{
glColor3ub(115, 183, 0);
glLineWidth(3);
drawline(a+9,b-9,a+9.5,b-10);
drawline(a+9,b-9,a+9.5,b-8);
drawline(a+9,b-9,a+13,b-9);
drawstring(a+14,b-9,0,"Food");
}
glutSwapBuffers();
}

//for(i=(3.14/2.0);i<=3.0;i+=0.0005)
//glVertex3f(-1.3+cos(i)*3,-5+sin(i)*3
GLfloat theta1=5*3.14/2.0,theta=3.14/2.0,theta2=3.14/2.0;
void animate()
{
if(flag==1)
{
if(tx<20 && ty<20 && theta<=3.14)
{
tx=-1.2+cos(theta)*3.5;
ty=sin(theta)*3.5;
countd=1;
//food
theta+=0.005;
}
if(theta>=3.14 && ty>=-20.5)
{
ty=ty-0.01;
countd=0;
}

if(theta>=3.14 && theta1>= 3*3.14/2.0 && ty<=-20.5 && ty>=-30)
{
mx=-1.5+cos(theta1)*4;
my=-4.8+sin(theta1)*4;
theta1-=0.005;

}

else if(theta1<= 3*3.14/2.0 && my<=-5.79 && my>=-11 && theta2<=3.0)
{
mx=mx-0.01;
my=my-0.01;

//theta2+=0.005;
}
glutPostRedisplay();
}
}

void descDigest()
{
//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3ub(253, 123, 119);//border
glBegin(GL_LINE_LOOP);
glVertex3f(47,50,0);
glVertex3f(-45,50,0);
glVertex3f(-45,-40,0);
glVertex3f(47,-40,0);
glEnd();
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(48,51,0);
glVertex3f(-46,51,0);
glVertex3f(-46,-41,0);
glVertex3f(48,-41,0);
glEnd();

glColor3f(0.7,0,1);
strflag=1;
drawstring1(-20,45,0.0,"Human Digestive System");
glColor3ub(255, 159, 0);
drawstring(-35,30,0.0,"Here are the major stages of the Digestive system:");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,25,0.0,"1. Chewing");
glColor3f(0,0,0);
strflag=0;
drawstring1(-24,25,0.0,"is the first stage of the digestive system. When you chew your food it breaks up big pieces ");
drawstring1(-26,22.5,0.0,"into little pieces that are easier to digest and swallow.Also, the saliva is more than just water."); 
drawstring1(-26,20,0.0," It has special enzymes in it that start to breakdown starchy food while chewing.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,17,0.0,"2. Swallowing");
strflag=0;
glColor3f(0,0,0);
drawstring1(-17,17,0.0,"may seem like a simple process to us. But food doesn't just fall down our throats ");
drawstring1(-26,14.5,0.0,"into the stomach.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,9,0.0,"3. Stomach");
strflag=0;
glColor3f(0,0,0);
drawstring1(-21,9,0.0,"The next stage is the stomach. Food hangs out in the stomach for around four hours. ");
drawstring1(-26,6.5,0.0,"While the food sits there, more enzymes go to work on it, breaking down things like proteins ");
drawstring1(-26,4,0.0,"that our bodies can use. The stomach kills a lot of bad bacteria as well, so we don't get sick.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,-2,0.0,"4. Small Intestine");
strflag=0;
glColor3f(0,0,0);
drawstring1(-15,-2,0.0,"The first part of the small intestine works with juices from the liver and pancreas");
drawstring1(-26,-5,0.0," to continue to break down our food. The second part is where the food gets absorbed from the");
drawstring1(-26,-7.5,0.0,"intestine and into our body through the blood.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,-14,0.0,"5. Large Intestine");
strflag=0;
glColor3f(0,0,0);
drawstring1(-15,-14,0.0,"The last stage is the large intestine. Any food that the body doesn't need or can't");
drawstring1(-26,-17,0.0," use is sent to the large intestine and later leaves the body as waste. ");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,-24,0.0,"6. The Liver and Pancreas");
strflag=0;
glColor3f(0,0,0);
drawstring1(-6,-24,0.0,"The liver and pancreas do a lot to help the digestive system along.");
drawstring1(-26,-26.5,0.0,"Both work with the small intestine. The liver provides bile that helps break up fat into");
drawstring1(-26,-29,0.0," smaller bits. The pancreas provides additional enzymes to help digest all sorts of food. ");

/*
2. Swallowing - Swallowing may seem like a simple process to us. But food doesn't just fall down our throats into our stomach. First, our tongue helps to push food into the back of our throat. Then there are special throat muscles that force the food down into a long tube that leads to our stomach, called the esophagus. The food doesn't just fall down the pipe, muscles push the food along until it gets to our stomach. At the same time all this is going on, a flap blocks off our windpipe making sure food doesn't go the wrong way. We call this "going down the wrong pipe" and it can make us choke. This flap is called the epiglottis and, fortunately for us, it works automatically.

3. Stomach - The next stage is the stomach. Food hangs out in the stomach for around four hours. While the food sits there, more enzymes go to work on it, breaking down things like proteins that our bodies can use. The stomach kills a lot of bad bacteria as well, so we don't get sick. 4. Small Intestine - The first part of the small intestine works with juices from the liver and pancreas to continue to break down our food. The second part is where the food gets absorbed from the intestine and into our body through the blood. 
5. Large Intestine - The last stage is the large intestine. Any food that the body doesn't need or can't use is sent to the large intestine and later leaves the body as waste. 
The Liver and Pancreas -The liver and pancreas do a lot to help the digestive system along. Both work with the small intestine. The liver  The pancreas provides additional enzymes to help digest all sorts of food. The liver also processes the digested food from your blood before it gets sent to various places in your body to be used.

*/
}

GLfloat vrx,vlx,vry,vly;
void resdraw()
{
GLfloat i;
body();
glLineWidth(15);
glColor3ub(255,100,50);
glBegin(GL_LINE_STRIP);
glVertex3f(a+1,b-9,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(2.5+cos(i)*3.5,28+sin(i)*3.5,0);//oesophagus1
glVertex3f(-1.2,27,0);
glVertex3f(-1.2,15,0);
glColor3ub(255,230,230);
glVertex3f(-1.2,20,0);
glVertex3f(-1.2,10,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-1.2,10,0);
glVertex3f(-3,6.5,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-1.2,10,0);
glVertex3f(2,6.5,0);
glEnd();
glColor3ub(230,200,200);
drawline(-1.2,19,-1.2,18.7);
drawline(-1.2,18,-1.2,17.7);
drawline(-1.2,17,-1.2,16.7);
drawline(-1.2,16,-1.2,15.7);
drawline(-1.2,15,-1.2,14.7);
drawline(-1.2,14,-1.2,13.7);
drawline(-1.2,13,-1.2,12.7);
drawline(-1.2,12,-1.2,11.7);
drawline(-1.2,11,-1.2,10.7);
glColor3f(0,0,0);
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(41,51,0);
glVertex3f(-41,51,0);
glVertex3f(-41,-21,0);
glVertex3f(41,-21,0);
glEnd();
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex3f(40,50,0);
glVertex3f(-40,50,0);
glVertex3f(-40,-20,0);
glVertex3f(40,-20,0);
glEnd();
strflag=1;
glColor3ub(187, 42, 44);
drawstring1(-20,-30,0,"HUMAN RESPIRATORY SYSTEM");
strflag=0;
glColor3f(0,0,0);
glLineWidth(1);
drawline(a+1,b-9,a+4.8,b-9);
drawstring1(a+5,b-9,0,"Nose");
drawline(a,b-12,a+6.5,b-12);
drawstring1(a+7,b-12,0,"Mouth");
drawline(-14,18,-1.5,18);
drawstring1(-19,18,0,"Trachea");
drawline(-10,22,-1.5,22);
drawstring1(-16,22,0,"Larynx");
drawline(-10,28,-1.5,28);
drawstring1(-16,28,0,"Pharynx");
drawline(-15,10,-4,10);
drawstring1(-19,10,0,"Lung");
drawline(-1,14.9,10,14.9);
drawstring1(11,14.9,0,"Rings of Cartilage");
drawline(-1,5,10,5);
drawstring1(11,5,0,"Space occupied by heart");
}

void leftlung()
{
GLfloat i;
glColor3ub(250,105,30);
glBegin(GL_POLYGON);//left lung
glVertex3f(-2,5,0);
for(i=(3.14/2.0);i<=3.5;i+=0.005)
glVertex3f(vlx=-2+cos(i)*(rx+5),vly=8+sin(i)*(ry+6),0);
glVertex3f(vlx+1,vly-4.5,0);
glEnd();
}
void rightlung()
{
GLfloat i;
glColor3ub(250,105,30);
glBegin(GL_POLYGON);//right lung
glVertex3f(0,5,0);
for(i=(3.14/2.0);i>=-0.4;i-=0.005)
glVertex3f(vrx=0+cos(i)*(rx+5),vry=8+sin(i)*(ry+6),0);
glVertex3f(vrx-1,vry-4.5,0);
glEnd();
}

int count=0;
void respiration()
{
//GLfloat ry=-5;
resdraw();
glPushMatrix();
glTranslatef(-rx,ry,0.0);
leftlung();
glPopMatrix();
glPushMatrix();
glTranslatef(rx,ry,0.0);
rightlung();
glPopMatrix();
if(count==1)
{
glColor3f(1,0.8,0);
glLineWidth(3);
drawline(a+9,b-9,a+9.5,b-10);
drawline(a+9,b-9,a+9.5,b-8);
drawline(a+9,b-9,a+13,b-9);
drawstring(a+14,b-9,0,"Inhale");
}
else if(count==0)
{
glColor3f(1,0.5,0);
glLineWidth(3);
drawline(a+13,b-9,a+12.5,b-10);
drawline(a+13,b-9,a+12.5,b-8);
drawline(a+9,b-9,a+13,b-9);
drawstring(a+14,b-9,0,"Exhale");
}
glutPostRedisplay();
}

void animate1()
{
if(flag==2)
{
if(rx<=1 && ry<=0.7)
{
rx+=0.001;
ry+=0.001;
if(rx>=0.6)count=0;
else count=1;
}
else
{
rx=0;ry=0;
count=0;
}
}
glutPostRedisplay();
}

void descResp()
{
glColor3ub(253, 123, 119);//border
glBegin(GL_LINE_LOOP);
glVertex3f(47,50,0);
glVertex3f(-45,50,0);
glVertex3f(-45,-40,0);
glVertex3f(47,-40,0);
glEnd();
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(48,51,0);
glVertex3f(-46,51,0);
glVertex3f(-46,-41,0);
glVertex3f(48,-41,0);
glEnd();

glColor3f(0.7,0,1);
strflag=1;
drawstring1(-20,45,0.0,"Human Respiratory System");
drawstring(-35,30,0.0,"Here are the major stages of the Respiratory system:");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,25,0.0,"1. Breathing In");
glColor3f(0,0,0);
strflag=0;
drawstring1(-18,25,0.0,"We breathe in using a muscle called the diaphragm. It flattens out making our lungs");
drawstring1(-26,22.5,0.0,"expand and fill with air. When we breathe in,air gets a forced through our nose or mouth,"); 
drawstring1(-26,20,0.0," down our windpipe, and into bronchi tubes in our lungs.These bronchi tubes branch out and ");
drawstring1(-26,17.5,0.0,"get smaller and smaller,like the roots or branches of tree.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,12,0.0,"2. Alveoli");
strflag=0;
glColor3f(0,0,0);
drawstring1(-22,12,0.0,"At the end of the smallest branches of bronchi are tiny air sacs called alvoeoli.");
drawstring1(-26,9.5,0.0,"These air sacs have a very thin,one cell thick wall that allows oxygen to be passed to ");
drawstring1(-26,7,0.0,"red blood cells as they are passing.There are hundreds of millions of alveoli.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,1,0.0,"3. Breathing Out");
strflag=0;
glColor3f(0,0,0);
drawstring1(-17,1,0.0,"The alevoli don't just pass oxygen to our blood,they also help to clean out ");
drawstring1(-26,-1.5,0.0,"carbon dioxide.When we need to breathe the carbon dioxide out of our lungs the diaphragm ");
drawstring1(-26,-4,0.0,"bows up and pushes the air back out,getting rid of carbon dioxide.This makes room for ");
drawstring1(-26,-6.5,0.0,"fresh air with new oxygen to come back on our next breath.");
}

void excredraw()
{
GLfloat i;
body();
glLineWidth(3.2);
//glColor3ub(255,222,63);
glColor3ub(155,100,13);
glBegin(GL_LINE_STRIP);//
for(i=(3.14/2.0);i>=0.6;i-=0.005)
glVertex3f(-3.5+cos(i)*2.5,-8+sin(i)*3,0);
glVertex3f(-1.5,-16,0);
glEnd();


glBegin(GL_LINE_STRIP);//
for(i=(3.14/2.0);i<=2.6;i+=0.005)
glVertex3f(1.5+cos(i)*2.5,-8+sin(i)*3,0);
glVertex3f(-0.5,-16,0);
glEnd();

glColor3ub(255,100,63);
glBegin(GL_POLYGON);
for(i=0;i<=3.14;i+=0.005)
glVertex3f(-1+cos(i)*2,-15.7+sin(i)*2,0);
glVertex3f(-1,-18,0);
glEnd();

glColor3ub(245,133,63);
glBegin(GL_POLYGON);//left kidney
for(i=(3.14/2.0);i<=(3*3.14/2.0);i+=0.005)
glVertex3f(-3.5+cos(i)*2.5,-5+sin(i)*3,0);
for(i=(3*3.14/2.0);i<=(5*3.14/2.0);i+=0.005)
glVertex3f(-3.5+cos(i)*1.5,-3.5+sin(i)*1.5,0);
for(i=(3*3.14/2.0);i<=(5*3.14/2.0);i+=0.005)
glVertex3f(-3.5+cos(i)*1.5,-6.5+sin(i)*1.5,0);
glEnd();
glBegin(GL_POLYGON);//right
for(i=(3.14/2.0);i<=(3*3.14/2.0);i+=0.005)
glVertex3f(1.5+cos(i)*1.5,-3.5+sin(i)*1.5,0);
for(i=(3*3.14/2.0);i<=(5*3.14/2.0);i+=0.005)
glVertex3f(1.5+cos(i)*2.5,-5+sin(i)*3,0);
for(i=(3.14/2.0);i<=(3*3.14/2.0);i+=0.005)
glVertex3f(1.5+cos(i)*1.5,-6.5+sin(i)*1.5,0);
glEnd();
strflag=0;
glColor3f(0,0,0);
glLineWidth(1);
drawline(3,-6,9.5,-3.5);
drawline(-4,-6,9.5,-3.5);
drawstring1(10,-3.55,0,"Kidneys");
drawline(-7,-13.0,-1.4,-13.0);
drawstring1(-11.5,-13,0,"Ureter");
drawline(-1.5,-15,10,-15);
drawstring1(11,-15,0,"Bladder");
drawline(9.5,-17.5,-1,-17.5);
drawstring1(10,-17.5,0,"Urethra");
glColor3f(0,0,0);
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(41,51,0);
glVertex3f(-41,51,0);
glVertex3f(-41,-21,0);
glVertex3f(41,-21,0);
glEnd();
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex3f(40,50,0);
glVertex3f(-40,50,0);
glVertex3f(-40,-20,0);
glVertex3f(40,-20,0);
glEnd();
strflag=1;
glColor3ub(142, 133, 60);
drawstring1(-20,-30,0,"HUMAN EXCRETORY SYSTEM");
}


void excretion()
{
excredraw();
glutPostRedisplay();
}


void excretDesc()
{
glColor3ub(253, 123, 119);//border
glBegin(GL_LINE_LOOP);
glVertex3f(47,50,0);
glVertex3f(-45,50,0);
glVertex3f(-45,-40,0);
glVertex3f(47,-40,0);
glEnd();
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(48,51,0);
glVertex3f(-46,51,0);
glVertex3f(-46,-41,0);
glVertex3f(48,-41,0);
glEnd();

glColor3f(0.7,0,1);
strflag=1;
drawstring1(-20,45,0.0,"Human Excretory System");
drawstring(-35,30,0.0,"Here are the major parts of the Excretory system:");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,25,0.0,"1. Kidneys");
glColor3f(0,0,0);
strflag=0;
drawstring1(-18,25,0.0,"Kidneys are blood filters.they are responsible for removing waste from our blood ");
drawstring1(-26,22.5,0.0,"and extra water that our body doesn't need. We have two kidneys.They're shaped like large beans"); 
drawstring1(-26,20,0.0,"and sit toward our back, near the bottom of body travels through the kidneys to get cleaned.");
strflag=2;
glColor3ub(0, 207, 119);
drawstring1(-35,12,0.0,"2. Ureters and Bladder");
strflag=0;
glColor3f(0,0,0);
drawstring1(-18,12,0.0,"the waste water filtered by our kidneys becomes urine. Urine leaves the kidneys through two ");
drawstring1(-26,9.5,0.0,"tubes called ureters. The ureters' job is to transport urine from the kidneys to the bladder, which is ");
drawstring1(-26,7,0.0,"the temporary storage organfor urine.");
}

void passive(int x,int y)
{

if(x>=450 && x>=490 && y>=150 && y<=170)
{
glutSetCursor(GLUT_CURSOR_INFO);
drawline(a+1,b-9,a+5.6,b-9);
drawstring1(a+6,b-9,0,"nose");
}
glutPostRedisplay();
}

void mydisplay(void)
{
glViewport(10,-50,980,700);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 if(flag==0)
  frontscreen ();
 if(flag==1)
 {
  digest();
  glutIdleFunc(animate); 
 }
 if(flag==2)
  respiration();
 if(flag==3)
  excretion();
 if(flag==4)
  desc();
glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
 
 if(flag==0 && key==13) //Ascii of 'enter' key is 13
    flag=1;
 if(key=='d')
  keyf=key;
 if(key=='D')
  keyf=key;
 if(key=='r')
  keyf=key;
 if(key=='R')
  keyf=key;
 if(key=='e')
  keyf=key;
 if(key=='E')
  keyf=key;
 if(key=='Q' || key=='q' || key==27)
  exit(0);

mydisplay();
}
 void desc()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(17, 40, 60);//border
glBegin(GL_LINE_LOOP);
glVertex3f(47,50,0);
glVertex3f(-45,50,0);
glVertex3f(-45,-40,0);
glVertex3f(47,-40,0);
glEnd();
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(48,51,0);
glVertex3f(-46,51,0);
glVertex3f(-46,-41,0);
glVertex3f(48,-41,0);
glEnd();
glColor3ub(58, 62, 73);
strflag=1;
drawstring1(-25,45,0.0,"HUMAN ANATOMY AND PHYSIOLOGY");

glColor3ub(159, 34, 70);
drawstring(-37,30,0.0," The human body is the entire structure of a human being. It is composed");
drawstring(-37,26,0.0,"of many different types of cells that together create tissues and subse-"); 
drawstring(-37,22,0.0,"quently organ systems. They ensure homeostasis and the viability of the ");
drawstring(-37,18,0.0,"human body.");
drawstring(-37,13,0.0," It comprises a head, neck, trunk (which includes the thorax and abdomen)");
drawstring(-37,9,0.0,"arms and hands, legs and feet.");
drawstring(-37,4,0.0," The study of the human body involves anatomy, physiology, histology and");
drawstring(-37,0,0.0,"embryology. The body varies anatomically in known ways.Physiology focus-");
drawstring(-37,-4,0.0,"-es on the systems and organs of the human body and their functions. Many");
drawstring(-37,-8,0.0,"systems and mechanisms interact in order to maintain homeostasis, with safe");
drawstring(-37,-12,0.0,"levels of substances such as sugar and oxygen in the blood.");
strflag=2;
glColor3ub(159, 176, 167);
drawstring1(-35,-20,0.0,"Enter key 'd' or 'D' to see brief description on Digestive system");
drawstring1(-36.2,-25,0.0,"Enter key 'r' or 'R' to see brief description on Respiratory system");
drawstring1(-35,-30,0.0,"Enter key 'e' or 'E' to see brief description on Exretory system");
drawstring1(-24,-35,0.0,"Enter 'ESC' or 'q' or 'Q' to exit");
if(keyf=='d' || keyf=='D')
{
glClear(GL_COLOR_BUFFER_BIT);
descDigest();
glutIdleFunc(descDigest);
}
if(keyf=='r' || keyf=='R')
{
glClear(GL_COLOR_BUFFER_BIT);
descResp();
glutIdleFunc(descResp);
}
if(keyf=='e' || keyf=='E')
{
glClear(GL_COLOR_BUFFER_BIT);
excretDesc();
glutIdleFunc(excretDesc);
}

//glutPostRedisplay();
}


void mymenu(int id)
{
switch(id)
{
case 1: frontscreen();
break;
case 2:flag=1;
glutIdleFunc(animate);
//glutPassiveMotionFunc(passive);
tx=0;ty=0;theta=3.14/2.0;theta1=5*3.14/2.0;theta2=3.14/2.0;mx=0;my=0;
break;
case 3: flag=2;
glutIdleFunc(animate1);
rx=0;ry=0;
break;
case 4: flag=3;
glutIdleFunc(excretion);
break;
case 5: flag=4;
  desc();
  glutIdleFunc(desc);
  glutKeyboardFunc(myKeyboardFunc);
  keyf=0;
break;
case 6:exit(0);
}
}




void init()
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glOrtho(-60,60,-60,60,-60,60);
}



int main(int argc,char **argv)
{
glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB/*|GLUT_DEPTH*/);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("Human Anatomy");
init();

glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboardFunc);
glutCreateMenu(mymenu);
glutAddMenuEntry("Digestive system",2);
glutAddMenuEntry("Respiratory system",3);
glutAddMenuEntry("Excretory system",4);
glutAddMenuEntry("Description",5);
glutAddMenuEntry("EXIT",6);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutKeyboardFunc(myKeyboardFunc);
;
glutMainLoop();
return 0;
}




