config=`pkg-config --libs --static --cflags gl glu` -lglut

default:
	make clean 
	make work1.out
	make work2.out
	./work2.out
	
clean:
	rm -f *.out
work1.out:
	gcc work1.c $(config) -o work1.out
work2.out:
	gcc work2.c $(config) -o work2.out