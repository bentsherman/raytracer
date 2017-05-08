CXX = g++
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

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

ray: ${OBJS}
	$(CXX) -o $@ ${OBJS}

clean:
	rm -f *.o ray
