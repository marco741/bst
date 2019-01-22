obj=./Objfiles

$(obj)/bst.a: *.c *.h
	mkdir -p $(obj)
	gcc -c *.c
	mv *.o $(obj)
	ar -rc $@ $(obj)/*.o
	ranlib $@