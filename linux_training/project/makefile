obj = Delete.o display.o hello.o menu.o Entry.o Insert.o Modify.o Statistics.o Sorting.o R_Sorting.o seek.o seek1.o seek2.o ret.o Save.o retreat.o Output.o main.o

Test:$(obj)
	$gcc -o Test $(obj)
Delete.o:Delete.c student.h
	$gcc -c Delete.c
display.o:display.c student.h
	$gcc -c display.c
hello.o:hello.c student.h
	$gcc -c hello.c
menu.o:menu.c student.h
	$gcc -c menu.c
Entry.o:Entry.c student.h
	$gcc -c Entry.c
Insert.o:Insert.c student.h
	$gcc -c Insert.c
Modify.o:Modify.c student.h
	$gcc -c Modify.c
Statistics.o:Statistics.c student.h
	$gcc -c Statistics.c
Sorting.o:Sorting.c student.h
	$gcc -c Sorting.c
R_Sorting.o:R_Sorting.c student.h
	$gcc -c R_Sorting.c
seek.o:seek.c student.h
	$gcc -c seek.c
seek1.o:seek1.c student.h
	$gcc -c seek1.c
seek2.o:seek2.c student.h
	$gcc -c seek2.c
ret.o:ret.c student.h
	$gcc -c ret.c
Save.o:Save.c student.h
	$gcc -c Save.c
retreat.o:retreat.c student.h
	$gcc -c retreat.c
Output.o:Output.c student.h
	$gcc -c Output.c
main.o:main.c student.h
	$gcc -c main.c
.PHONY:clear
clean:
	rm -rf *.o test
	@echo "clean done!"


