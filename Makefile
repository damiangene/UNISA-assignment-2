default: compile run
 
compile:
	g++ *.cpp -o main

run:
	./main

clean:
	@rm main