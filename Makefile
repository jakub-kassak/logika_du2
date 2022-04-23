.PHONY: build_test run_test clean build run
OUT = ./bin/
SRC = ./src/
FLAGS = -Wall -ggdb


$(OUT)test:	$(SRC)testlp.cpp $(OUT)
	g++ $(FLAGS) -o $@ $< -I /usr/include/lpsolve/ -L /usr/lib/lp_solve -Wl,-rpath,/usr/lib/lp_solve -llpsolve55

$(OUT):
	mkdir $@

clean:
	rm -r $(OUT)


run_test: build_test
	@ $(OUT)test

build_test: $(OUT)test
	@# echo "build finnished"

$(OUT)cchi: $(SRC)cchi.cpp $(OUT)
	g++ $(FLAGS) -o $@ $< -I /usr/include/lpsolve/ -L /usr/lib/lp_solve -Wl,-rpath,/usr/lib/lp_solve -llpsolve55

run: build
	@ $(OUT)cchi

build: $(OUT)cchi
	@# echo "build finnished"