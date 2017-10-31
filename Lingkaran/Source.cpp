// Algoritma lingkaran

#include<GL\freeglut.h>

// Prosedur
void init();
void display();
void lingkaran();

// Posisi pada window
int window_x;
int window_y;

// Ukuran pada window
int window_width = 500;
int window_height = 500;

// Judul pada window
char *judul_window = "Algoritma Lingkaran";

void main(int argc, char **argv)
{
	// Inisialisasi Graphic Library Utility Toolkit
	glutInit(&argc, argv);

	// Set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); // Set ukuran window 
	glutInitWindowPosition(window_x, window_y); // Set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // Set display RGB dan double buffer
	glutCreateWindow(judul_window);

	init(); // Menjalankan fungsi init
	glutDisplayFunc(display); // Set fungsi display
	glutMainLoop(); // Set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Set warna background 
	glColor3f(1.0, 1.0, 1.0); // Set warna titik
	glPointSize(2.0); // Set ukuran titik
	glMatrixMode(GL_PROJECTION); // Set mode matriks yang digunakan 
	glLoadIdentity(); // Load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // Set ukuran viewing window
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear color
	lingkaran(); // Menjalankan fungsi lingkaran
	glutSwapBuffers(); // Swap buffer 
}

void lingkaran()
{
	// Menentukan titik pusat dan jari-jari
	int r = 150, xc = 200, yc = 200, p, x_lingkaran = 0, y_lingkaran, i;
	
	// Menghitung p awal dan set nilai awal untuk x dan y
	p = 1 - r;
	y_lingkaran = r;

	glBegin(GL_POINTS); // Untuk mendeklarasikan titik awal

	for(i = x_lingkaran; i < y_lingkaran; i++)
	{
		if(p < 0) // Kondisi jika p lebih kecil dari 0
		{
			x_lingkaran = x_lingkaran + 1;
			y_lingkaran;
			p = p + 2 * x_lingkaran + 1;
		}
		else // Kondisi jika p lebih besar sama dengan 0
		{
			x_lingkaran = x_lingkaran + 1;
			y_lingkaran = y_lingkaran - 1;
			p = p + 2 * (x_lingkaran - y_lingkaran) + 1;
		}
		glVertex2i(xc + x_lingkaran, yc + y_lingkaran);
		glVertex2i(xc - x_lingkaran, yc + y_lingkaran);
		glVertex2i(xc + x_lingkaran, yc - y_lingkaran);
		glVertex2i(xc - x_lingkaran, yc - y_lingkaran);
		glVertex2i(xc + y_lingkaran, yc + x_lingkaran);
		glVertex2i(xc - y_lingkaran, yc + x_lingkaran);
		glVertex2i(xc + y_lingkaran, yc - x_lingkaran);
		glVertex2i(xc - y_lingkaran, yc - x_lingkaran);
	}
	glEnd();
	glFlush();
}
