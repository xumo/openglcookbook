#################################
# OpenGL con GLFW
# Autor: Rodrigo Torres
# Fecha: Lunes 20 de mayo de 2013
#################################

CC=g++ 

CFLAGS  = -m64

SOURCES=main.cpp  
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
#INCLUDES=  -I/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk/usr/X11/lib/GL
#LIBS=  -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -lGL -lGLU -lpthread /Developer/NVIDIA/CUDA-5.0/samples/common/lib/darwin/libGLEW.a


INCLUDES =-I/usr/local/include
LIBS =  -L/usr/local/lib  /usr/local/lib/libGLEW.a  -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo 

#Para usar GLFW 
LIBS += -lglfw3 
#Para SOIL
INCLUDES += -I/Users/rodrigo/Documents/Herramientas/SOIL/src
SOIL_OBJ = /Users/rodrigo/Documents/Herramientas/SOIL/obj/SOIL.o
SOIL_LIB = /Users/rodrigo/Documents/Herramientas/SOIL/lib/libSOIL.a
#Para glm
INCLUDES += -I/Users/rodrigo/Documents/Herramientas/glm-0.9.4.4


#all: $(SOURCES) $(EXECUTABLE) 

main: 
	$(CC) $(CFLAGS) -o main main_glfw.cpp $(INCLUDES) $(LIBS)

imageLoader: GLSLShader.o
	$(CC) $(CFLAGS) GLSLShader.o -o imageLoader imageLoader.cpp $(INCLUDES) $(LIBS) $(SOIL_LIB) 

rippleDeformer: GLSLShader.o
	$(CC) $(CFLAGS) GLSLShader.o -o rippleDeformer rippleDeformer.cpp $(INCLUDES) $(LIBS) $(SOIL_LIB) 

simpleTriangle: GLSLShader.o
	$(CC) $(CFLAGS) GLSLShader.o -o simpleTriangle simpleTriangle.cpp $(INCLUDES) $(LIBS) $(SOIL_LIB) 

GLSLShader.o:
	$(CC) $(CFLAGS) -c  GLSLShader.cpp $(INCLUDES) $(LIBS)



clean:
	/bin/rm -f *.o *.ii *~ $(TARGETS) 