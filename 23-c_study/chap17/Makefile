EXE=test
#OBJS=main.o sum.o
DEFINES=-DDEBUG
CFLAGS=-I./include $(DEFINES)
LDFLAGS=-lpthread

C_SRC = $(wildcard *.c)
#C_SRC = main.c sum.c 와 같다
OBJ = $(C_SRC:.c=.o)
#OBJ = main.o sum.o // .c파일을 .o로 바꿔주세요

all : $(EXE)
	echo completed!!!

$(EXE) : $(OBJ)
	gcc $(CFLAGS) -o $@ $^ $(LPFLAGS)

clean : 
	rm *.o
	rm test

good :
	echo good


