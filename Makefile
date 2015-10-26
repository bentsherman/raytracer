INCS = Vector.h       \
       Image.h        \
       Entity.h       \
       Scene.h        \
       Window.h       \
       SceneObject.h  \
       Plane.h        \
       Sphere.h       \
       PointLight.h   

OBJS = Vector.o       \
       Image.o        \
       Entity.o       \
       Scene.o        \
       Window.o       \
       SceneObject.o  \
       Plane.o        \
       Sphere.o       \
       PointLight.o   \
       main.o

ray : ${OBJS}
	@echo
	@echo Linking $@
	g++ -g -Wall -lm -o $@ ${OBJS}

${OBJS} : ${INCS} Makefile

test :
	./ray myscene.txt output.ppm
	display output.ppm

clean :
	rm -f *.o ray core
