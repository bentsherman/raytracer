.SUFFIXES:
.SUFFIXES: .c .cpp .o

CC = g++
CXXFLAGS = -g -Wall

OBJS=Vector.o       \
     Image.o        \
     Entity.o       \
     Scene.o        \
     Window.o       \
     SceneObject.o  \
     Plane.o        \
     Sphere.o       \
     PointLight.o   \
     main.o

all: ray

${OBJS}: Vector.h       \
         Image.h        \
         Entity.h       \
         Scene.h        \
         Window.h       \
         SceneObject.h  \
         Plane.h        \
         Sphere.h       \
         PointLight.h   \
         Makefile

ray: ${OBJS}
	g++ -o $@ ${OBJS}

test:
	./ray scene1.txt output.ppm

clean:
	rm -f *.o ray core