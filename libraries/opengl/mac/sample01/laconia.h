/*
** laconia.h
*/

void lacSphere(GLdouble radius, char type);
void lacCube(GLdouble size, char type);
void lacBox(GLdouble xSize, GLdouble ySize, GLdouble zSize, char type);
void lacArm(GLdouble xSize, GLdouble ySize, GLdouble zSize, char type);
void lacTorus(GLdouble innerRadius, GLdouble outerRadius, char type);
void lacCylinder(GLdouble radius, GLdouble height, char type);
void lacIcosahedron(GLdouble radius, char type);
void lacOctahedron(GLdouble radius, char type);
void lacCone(GLdouble base, GLdouble height, char type);

/*
** ビューイングルーチン ( see IRIS GL polarview() )
*/
void polarView(GLdouble radius, GLdouble twist, GLdouble latitude, GLdouble longitude);

/*
** ビューイングルーチン ( see IRIS Performer pfChanView() )
*/
void pilotView(GLdouble xyz[3], GLdouble hpr[3]);

/*
** モデリングルーチン ( see IRIS Performer pfDCSCoord() )
*/
void xyzhpr(GLdouble xyz[3], GLdouble hpr[3]);

