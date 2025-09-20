
.PHONY:
	clean

clr: clr.c
	gcc -o clr clr.c -framework OpenGL -framework GLUT

draw: draw.c
	gcc -o draw draw.c -framework OpenGL -framework GLUT

reshape: reshape.c
	gcc -o reshape reshape.c -framework OpenGL -framework GLUT

single: single.c
	gcc -o single single.c -framework OpenGL -framework GLUT

double: double.c
	gcc -o double double.c -framework OpenGL -framework GLUT

primitive: primitive.c
	gcc -o primitive primitive.c -framework OpenGL -framework GLUT

stipple: stipple.c
	gcc -o stipple stipple.c -framework OpenGL -framework GLUT

projection: projection.c
	gcc -o projection projection.c -framework OpenGL -framework GLUT

projection.ORIG: projection.ORIG.c
	gcc -o projection.ORIG projection.ORIG.c -framework OpenGL -framework GLUT


clean:
	rm clr a.out draw reshape single double primitive stipple
