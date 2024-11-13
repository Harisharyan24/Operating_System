cc=gcc
first:
	$(cc) -c add.c differ.c product.c  
makearchieve:
	ar -crv cal.a add.o differ.o product.o
makeshared:
	$(cc) -o libarith.so add.o differ.o product.o -shared -fPIC
main:
	$(cc) -c calc.c
linkerstatic:
	$(cc) cal.a calc.o
linkerdynamic:
	$(cc) calc.o libarith.so
add:
	$(cc) -c add.c
differ:
	$(cc) -c differ.c
product:
	$(cc) -c product.c
clean:
	rm -rf *.i *.o *.s libarith.so a.out
# makelibrary:
# 	gcc -o libarith.so add.o differ.o product.o -shared -fPIC
# 	ar -crv libarith.a add.o differ.o product.o
