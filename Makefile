CC := gcc
CFLAGS :=  -Wall -Werror -Wextra -std=c++17

OS = $(shell uname)
ifeq ($(OS), Linux)
	LEAK_CHECK = valgrind --tool=memcheck --leak-check=yes
else
	LEAK_CHECK = CK_FORK=no leaks --atExit --
endif
SRC := $(wildcard prj.lab/s21_*.cc)
TEST_SRC := $(wildcard prj.test/*.cc)

all: clean s21_matrix_oop.a test

s21_matrix_oop.o: prj.lab/s21_matrix_oop.h
		$(CC) $(CFLAGS) -c $(SRC)

s21_matrix_oop.a: s21_matrix_oop.o
		ar rcs libs21_matrix_oop.a s21_matrix_oop.o
		ranlib libs21_matrix_oop.a
		cp libs21_matrix_oop.a s21_matrix_oop.a

test:
		rm -rf test_exec
		mkdir test_exec
		cd test_exec && cmake .. && make && cd prj.test/bin && ./test_matrix

check:
	clang-format -i prj.*/*.cc prj.*/*.h
	make test
	cd test_exec/prj.test/bin && $(LEAK_CHECK) ./test_matrix

clean:
	rm -rf test *.a *.o *.gcno *.gcda *.info test_output gcov_report report test_exec
