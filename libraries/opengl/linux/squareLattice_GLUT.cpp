/*
GLUT�F�����i�q�i2D�J���[�}�b�v�j
*/

#include <math.h>
#include <GL/glut.h>

int WindowPositionX = 200;  //��������E�B���h�E�ʒu��X���W
int WindowPositionY = 100;  //��������E�B���h�E�ʒu��Y���W
int WindowWidth  = 512;     //��������E�B���h�E�̕�
int WindowHeight = 512;     //��������E�B���h�E�̍���
char WindowTitle[] = "���E�̎n�܂�";	//�E�B���h�E�̃^�C�g��

//----------------------------------------------------
// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
//----------------------------------------------------
void initialize(void);
void display(void);
void idle(void);
void draw(void);
//----------------------------------------------------
// ���C���֐�
//----------------------------------------------------
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);                                     //���̏�����
	glutInitWindowPosition(WindowPositionX, WindowPositionY);  //�E�B���h�E�̈ʒu�̎w��
	glutInitWindowSize(WindowWidth, WindowHeight);             //�E�B���h�E�T�C�Y�̎w��
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);              //�f�B�X�v���C���[�h�̎w��
	glutCreateWindow(WindowTitle);                             //�E�B���h�E�̍쐬
	glutDisplayFunc(display);                                  //�`�掞�ɌĂяo�����֐����w�肷��i�֐����Fdisplay�j
	glutIdleFunc(idle);                                        //�v���O�����A�C�h����Ԏ��ɌĂяo�����֐�
	initialize();                                              //�����ݒ�̊֐����Ăяo��
	glutMainLoop();
	return 0;
}
//----------------------------------------------------
// �����ݒ�̊֐�
//----------------------------------------------------
void initialize(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //�w�i�F
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�gluPerspactive(th, w/h, near, far);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(
		   0.0,  0.0, 186.0,  // ���_�̈ʒux,y,z;
		   0.0,  0.0, 0.0,    // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
		   0.0,  1.0, 0.0);   // ���E�̏�����̃x�N�g��x,y,z
}
//--------------------------------------------------------
// �A�C�h�����ɌĂяo�����֐�
//--------------------------------------------------------
void idle()
{
	glutPostRedisplay(); //glutDisplayFunc()���P����s����
}
//----------------------------------------------------
// �`��̊֐�
//----------------------------------------------------
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //�o�b�t�@�̏���

	draw();

	glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)�Ń_�u���o�b�t�@�����O�𗘗p��
}
void draw()
{
	//�����i�q�̃T�C�Y
	int tate = 100, yoko = 100;
	int vertexNumber = yoko * tate ;
	int indexNumber  = 2 * (yoko-1) * (tate-1);

	GLfloat (*vertices)[3] = new GLfloat[vertexNumber][3];
	GLfloat (*colors)[4]   = new GLfloat[vertexNumber][4];
	GLuint  (*indices)[3]  = new GLuint[indexNumber][3];
	int k=0; 
	for (int i = 0; i < tate; i++) {
		for (int j = 0; j < yoko; j++) {
			//���_�z��̐ݒ�
			vertices[k][0] = i;
			vertices[k][1] = j;
			vertices[k][2] = 0.0;

			GLfloat x = GLfloat(i - tate / 2) / tate;
			GLfloat y = GLfloat(j - yoko / 2) / yoko;
			GLfloat f = exp(-10.0*(x * x + y * y));//�K�E�X���z
			//�J���[�z��̐ݒ�
			colors[k][0] = f;
			colors[k][1] = f;
			colors[k][2] = f;
			colors[k][3] = 1.0;
			k++;
		}
	}

	k=0;
	for (int i = 0; i < tate - 1; i++) {
		for (int j = 0; j < yoko - 1; j++) {
			indices[k][0] =yoko * i + j;             //�O�p�`�P�̒��_�P
			indices[k][1] =yoko * i + (j + 1);       //�O�p�`�P�̒��_�Q
			indices[k][2] =yoko * (i + 1) + (j + 1); //�O�p�`�P�̒��_�R
			k++;
			indices[k][0] =yoko * i + j;             //�O�p�`�Q�̒��_�P
			indices[k][1] =yoko * (i + 1) + j;       //�O�p�`�Q�̒��_�Q
			indices[k][2] =yoko * (i + 1) + (j + 1); //�O�p�`�Q�̒��_�R
			k++;
		}
	}

	glPushMatrix();
		glTranslatef( -yoko/2+0.5, -tate/2+0.5, 0.0);     //���s�ړ�
		glRotatef(0.0 , 0.0, 0.0, 1.0);  //��]
		//�l�p�`�̕`��
		glBegin(GL_TRIANGLES);//GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES
			for(int i=0; i<indexNumber; i++){
				for(int j=0; j<3; j++){
					int k = indices[i][j];
					glColor4fv(colors[k]);
					glVertex3fv(vertices[k]); 
				}
			}
		glEnd();
	glPopMatrix();
}

