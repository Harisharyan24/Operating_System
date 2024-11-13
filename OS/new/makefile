g=gcc
hh:mklib cal
	$(g) calc.o calc.so -o cal
cal:calc.c
	$(g) -c calc.c
add:add.c
	$(g) -c add.c
dif:differ.c
	$(g) -c differ.c
pr:product.c
	$(g) -c product.c
mklib: add dif pr 
	ar -crv calc.a add.o differ.o product.o 
	$(g) -o calc.so add.o differ.o product.o -shared -fPIC
