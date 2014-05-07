CC=gcc
LIBCOMP=ranlib
LIBCOMPA=ar rc
LIBS=-lgc
EXECUTABLE=unic
SOURCES=main.c unic.c
OBJECTS=main.o
OBJECTSLIB=unic.o

all:
	$(CC) -c $(SOURCES)
	$(LIBCOMPA) lib$(EXECUTABLE).a $(OBJECTSLIB)
	$(LIBCOMP) lib$(EXECUTABLE).a
	make break
	$(CC) -fPIC -c $(SOURCES)
	$(CC) -shared -nostdlib -o $(EXECUTABLE).so $(OBJECTSLIB)	
	make break
	$(CC) -c $(SOURCES)
	$(CC) -O3 -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	make break
test:
	make clear
	$(CC) -c $(SOURCES)
	$(CC) -O3 -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	./$(EXECUTABLE)

clear:
	rm -rf *.o $(EXECUTABLE)

clearall:
	rm -rf *.o $(EXECUTABLE) lib$(EXECUTABLE).a $(EXECUTABLE).so 
break:
	rm -rf *.o
