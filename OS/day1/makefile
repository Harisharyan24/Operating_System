cur=gcc
save:
	$(cur) -g -save-temps appln.c sum.c differ.c pro.c -o appln
main:
	$(cur) appln.c sum.c differ.c pro.c -o appln
sum: 
	$(cur) -c sum.c 
appln:
	$(cur) -c appln.c 
differ: 
	$(cur) -c differ.c 
pro:
	$(cur) -c pro.c 
all:
	make appln sum differ pro 
clean:
	rm -rf *.o appln

