# Makefile for VideoPoker Game
# Run: make build, make run, make clean

SOURCES = Carta.java Mesa.java VerificarMaos.java Baralho.java VideoPoker.java
CLASSES = *.class
MAINCLASS = VideoPoker

.PHONY: all build run clean

all: build

build:
	javac $(SOURCES)

run: build
	java $(MAINCLASS)

clean:
	rm -f $(CLASSES)
