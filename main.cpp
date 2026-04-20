#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>


//  HELPER FUNCTIONS

void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180;
        float x  = radius * cos(A);
        float y  = radius * sin(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180;
        float x  = radius * cos(A);
        float y  = radius * sin(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}


void sun()
{
    glPushMatrix();
    glColor3f(1,1,0);
    circle(300,650,35);
    glPopMatrix();
}


//  ROAD FUNCTION

void road()
{
    // Base Gray Color (sidewalk/curb)
    glColor3f(0.37f, 0.37f, 0.37f);
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    // Base white line
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    // Main Road
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    // Upper white line
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    // Upper gray color (upper curb)
    glColor3f(0.51f, 0.51f, 0.51f);
    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    // Road dash line
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x < 1000; x += 60)
    {
        glVertex2f(x,    102);
        glVertex2f(x+30, 102);
    }
    glEnd();
}


//  BUILDING FUNCTION

void building()
{
    /// 1st Building
    glColor3f(0.92f, 0.92f, 0.92f);
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // Windows
    glBegin(GL_QUADS);
    for(int x = 18; x < 80; x += 27)
    {
        for(int y = 500; y > 200; y -= 60)
        {
            glColor3f(1, 1, 1);
            glVertex2f(x-2,  y+7);
            glVertex2f(x+22, y+7);
            glVertex2f(x+22, y-20);
            glVertex2f(x-2,  y-20);

            glColor3f(0.52f, 0.78f, 0.96f);
            glVertex2f(x,    y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,    y-20);
        }
    }
    glEnd();

    // Window white border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    for(int y = 480; y > 200; y -= 60)
    {
        glVertex2f(5,   y);
        glVertex2f(105, y);
        glVertex2f(105, y-15);
        glVertex2f(5,   y-15);
    }
    glEnd();

    /// 2nd Building
    glBegin(GL_QUADS);
    glColor3f(0.90f, 0.80f, 0.69f);
    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    glColor3f(0.83f, 0.73f, 0.63f);
    glVertex2f(135, 200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135, 400);

    glColor3f(0.45f, 0.24f, 0.13f);
    glVertex2f(90,  400);
    glVertex2f(180, 400);
    glVertex2f(165, 425);
    glVertex2f(105, 425);
    glEnd();

    glColor3f(0.90f, 0.80f, 0.69f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(115, 400);
    glVertex2f(135, 425);
    glEnd();

    glColor3f(0.83f, 0.73f, 0.63f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(155, 400);
    glVertex2f(135, 425);
    glEnd();

    glColor3f(0.28f, 0.13f, 0.06f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(88,  400); glVertex2f(115, 400);
    glVertex2f(115, 398); glVertex2f(135, 427);
    glVertex2f(135, 427); glVertex2f(155, 400);
    glVertex2f(153, 400); glVertex2f(182, 400);
    glVertex2f(90,  340); glVertex2f(180, 340);
    glVertex2f(90,  280); glVertex2f(180, 280);
    glVertex2f(90,  220); glVertex2f(180, 220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.28f, 0.13f, 0.06f);
    for(int x = 100; x < 180; x += 45)
        for(int y = 385; y > 200; y -= 60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }

    glColor3f(0.67f, 0.77f, 0.89f);
    for(int x = 102; x < 180; x += 45)
        for(int y = 382; y > 200; y -= 60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+21, y);
            glVertex2f(x+21, y-25);
            glVertex2f(x,    y-25);
        }
    glEnd();

    glColor3f(0.28f, 0.13f, 0.06f);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 100; x < 180; x += 45)
        for(int y = 372; y > 200; y -= 60)
        {
            glVertex2f(x,      y);
            glVertex2f(x+25,   y);
            glVertex2f(x+12.5, y+10);
            glVertex2f(x+12.5, y);
        }
    glEnd();

    /// 3rd Building
    glColor3f(0.84f, 0.30f, 0.37f);
    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    glColor3f(0.90f, 0.45f, 0.50f);
    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    glColor3f(0.50f, 0.15f, 0.20f);
    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    glColor3f(0.50f, 0.15f, 0.20f);
    for(int y = 410; y > 200; y -= 70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    for(int x = 198; x < 280; x += 47)
        for(int y = 454; y > 220; y -= 70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    glEnd();

    glColor3f(0.36f, 0.54f, 0.66f);
    for(int x = 202; x < 280; x += 47)
        for(int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }

    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 198; x < 280; x += 47)
        for(int y = 454; y > 220; y -= 70)
        {
            glVertex2f(x+13, y);
            glVertex2f(x+13, y-32);
            glVertex2f(x,    y-13);
            glVertex2f(x+26, y-13);
            glVertex2f(x,    y-22);
            glVertex2f(x+26, y-22);
        }
    glEnd();

    /// 4th Building
    glColor3f(0.36f, 0.54f, 0.66f);
    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    glColor3f(1, 1, 1);
    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200); glVertex2f(320, 510);
    glVertex2f(340, 200); glVertex2f(340, 520);
    glVertex2f(360, 200); glVertex2f(360, 530);
    glVertex2f(380, 200); glVertex2f(380, 535);

    glColor3f(0.30f, 0.42f, 0.51f);
    for(int y = 455; y > 200; y -= 30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);
    glEnd();

    /// 5th Building
    glColor3f(0.96f, 0.96f, 0.96f);
    glBegin(GL_QUADS);
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    glVertex2f(440, 440);
    glVertex2f(530, 440);
    glVertex2f(530, 480);
    glVertex2f(440, 480);

    glVertex2f(450, 495);
    glVertex2f(520, 495);
    glVertex2f(520, 505);
    glVertex2f(450, 505);

    glVertex2f(460, 505);
    glVertex2f(510, 505);
    glVertex2f(510, 515);
    glVertex2f(460, 515);

    glVertex2f(470, 515);
    glVertex2f(500, 515);
    glVertex2f(500, 525);
    glVertex2f(470, 525);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(435, 495);
    glVertex2f(535, 495);
    glVertex2f(535, 480);
    glVertex2f(435, 480);
    glEnd();

    glColor3f(0.38f, 0.54f, 0.66f);
    glBegin(GL_QUADS);
    for(int x = 435; x < 550; x += 40)
    {
        glVertex2f(x,    200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x,    400);
    }
    for(int x = 450; x < 520; x += 20)
    {
        glVertex2f(x,    470);
        glVertex2f(x+11, 470);
        glVertex2f(x+11, 440);
        glVertex2f(x,    440);
    }
    glEnd();

    // Flag
    glColor3f(0.00f, 0.42f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(485, 555);
    glVertex2f(510, 555);
    glVertex2f(510, 540);
    glVertex2f(485, 540);
    glEnd();

    glColor3f(0.96f, 0.16f, 0.25f);
    circle(497.5f, 547.5f, 4);

    glColor3f(0.83f, 0.65f, 0.42f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(485, 525);
    glVertex2f(485, 555);
    glEnd();

    /// 6th Building
    glBegin(GL_QUADS);
    glColor3f(0.94f, 0.69f, 0.35f);
    glVertex2f(550, 200);
    glVertex2f(640, 200);
    glVertex2f(640, 400);
    glVertex2f(550, 400);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(550, 415);
    glVertex2f(640, 415);
    glVertex2f(640, 400);
    glVertex2f(550, 400);
    glEnd();

    glColor3f(0.94f, 0.69f, 0.35f);
    for(int x = 555; x < 640; x += 13)
        circle(x, 400, 7);

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(550, 290); glVertex2f(640, 290);
    glVertex2f(550, 350); glVertex2f(640, 350);
    glVertex2f(550, 230); glVertex2f(640, 230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    for(int x = 561; x < 640; x += 40)
        for(int y = 395; y > 200; y -= 60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }

    glColor3f(0.44f, 0.63f, 0.78f);
    for(int x = 561; x < 640; x += 40)
        for(int y = 395; y > 200; y -= 60)
        {
            glVertex2f(x+3,  y-3);
            glVertex2f(x+22, y-3);
            glVertex2f(x+22, y-27);
            glVertex2f(x+3,  y-27);
        }
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 561; x < 640; x += 40)
        for(int y = 385; y > 200; y -= 60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+22, y);
            glVertex2f(x+12, y);
            glVertex2f(x+12, y-20);
        }
    glEnd();

    /// 7th Building
    glColor3f(0.84f, 0.74f, 0.62f);
    glBegin(GL_QUADS);
    glVertex2f(640, 200);
    glVertex2f(720, 200);
    glVertex2f(720, 380);
    glVertex2f(640, 380);

    glColor3f(1, 1, 1);
    for(int y = 373; y > 200; y -= 30)
    {
        glVertex2f(647, y);
        glVertex2f(713, y);
        glVertex2f(713, y-21);
        glVertex2f(647, y-21);
    }

    glColor3f(0.52f, 0.78f, 0.96f);
    for(int y = 370; y > 200; y -= 30)
    {
        glVertex2f(650, y);
        glVertex2f(710, y);
        glVertex2f(710, y-15);
        glVertex2f(650, y-15);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 670; x < 710; x += 20)
        for(int y = 370; y > 200; y -= 30)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-15);
        }
    glEnd();

    /// 8th Building
    glColor3f(0.39f, 0.30f, 0.32f);
    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    for(int x = 759; x < 950; x += 150)
        for(int y = 400; y > 250; y -= 120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x,    y-40);
        }
    for(int x = 743; x < 950; x += 182)
    {
        glVertex2f(x,    340);
        glVertex2f(x+32, 340);
        glVertex2f(x+32, 300);
        glVertex2f(x,    300);
    }
    glEnd();

    glColor3f(0.44f, 0.65f, 0.80f);
    glBegin(GL_QUADS);
    for(int x = 763; x < 950; x += 150)
        for(int y = 397; y > 250; y -= 120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }
    for(int x = 747; x < 950; x += 182)
    {
        glVertex2f(x,    337);
        glVertex2f(x+24, 337);
        glVertex2f(x+24, 303);
        glVertex2f(x,    303);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x < 940; x += 150)
        for(int y = 400; y > 200; y -= 120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }
    for(int x = 759; x < 950; x += 182)
    {
        glVertex2f(x, 340);
        glVertex2f(x, 300);
    }
    glEnd();

    /// 9th Building
    glColor3f(0.51f, 0.73f, 0.75f);
    glBegin(GL_QUADS);
    glVertex2f(800, 200);
    glVertex2f(850, 200);
    glVertex2f(850, 480);
    glVertex2f(800, 480);

    glColor3f(0.47f, 0.67f, 0.69f);
    glVertex2f(850, 200);
    glVertex2f(900, 200);
    glVertex2f(900, 480);
    glVertex2f(850, 480);

    glColor3f(0.29f, 0.42f, 0.43f);
    glVertex2f(795, 490);
    glVertex2f(905, 490);
    glVertex2f(905, 475);
    glVertex2f(795, 475);

    glColor3f(0.29f, 0.42f, 0.43f);
    for(int y = 410; y > 200; y -= 70)
    {
        glVertex2f(800, y);
        glVertex2f(900, y);
        glVertex2f(900, y-10);
        glVertex2f(800, y-10);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    for(int x = 810; x < 900; x += 54)
        for(int y = 450; y > 220; y -= 70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-30);
            glVertex2f(x,    y-30);
        }
    glEnd();

    glColor3f(1, 1, 1);
    halfCircle(823, 450, 13); halfCircle(877, 450, 13);
    halfCircle(823, 380, 13); halfCircle(877, 380, 13);
    halfCircle(823, 310, 13); halfCircle(877, 310, 13);
    halfCircle(823, 240, 13); halfCircle(877, 240, 13);

    glColor3f(1, 0, 0);
    for(int x = 814; x < 900; x += 54)
        for(int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }

    glColor3f(1, 0, 0);
    halfCircle(823, 450, 9); halfCircle(877, 450, 9);
    halfCircle(823, 380, 9); halfCircle(877, 380, 9);
    halfCircle(823, 310, 9); halfCircle(877, 310, 9);
    halfCircle(823, 240, 9); halfCircle(877, 240, 9);

    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 823; x < 900; x += 54)
        for(int y = 460; y > 200; y -= 70)
        {
            glVertex2f(x,    y);
            glVertex2f(x,    y-40);
            glVertex2f(x-13, y-12);
            glVertex2f(x+13, y-12);
            glVertex2f(x-13, y-25);
            glVertex2f(x+13, y-25);
        }
    glEnd();
}


void circleM(int centerX, int centerY, int radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}


void cloud1()
{
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

//cloud-1
    circleM(50,650,15);
    circleM(70,660,15);
    circleM(90,650,15);
    circleM(110,645,15);
    circleM(70,640,15);
    circleM(90,640,15);

    glPopMatrix();

}


//cloud-2


void cloud2()
{
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(500,650,20);
    circleM(510,670,20);
    circleM(530,640,20);
    circleM(560,645,20);
    circleM(545,670,20);

    glPopMatrix();
}


//cloud-3

void cloud3()
{
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(700,650,20);
    circleM(710,670,20);
    circleM(730,650,15);
    circleM(755,645,15);
    circleM(745,670,20);
    circleM(770,670,15);

    glPopMatrix();

}




//  DISPLAY FUNCTION

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    building();
    road();
    cloud1();
    cloud2();
    cloud3();
    sun();

    glutSwapBuffers();
}

//  RESHAPE FUNCTION

void reshape(int w, int h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


//  MAIN FUNCTION

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Smart City Scenario");

    glClearColor(0.37f, 0.82f, 0.94f, 1.0f); // Sky blue background

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
