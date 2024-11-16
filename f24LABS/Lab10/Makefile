default : build run
	@# default when just "make" is to run both the build and run targets 
	@# ie command "make" and command "make build run" are the same now
	@echo "Compiling and running program:"

build : main.cpp utility.cpp 
	@# compiles the source files into an executable file named exefile
	@# -o allows exe file to be named rather than default a.out name
	@echo "Compiling source files into executable called 'exefile'"
	g++ -Wall main.cpp utility.cpp -o exefile


run : exefile
	@# runs the executable, so depends on the executable (build has to 
	@# have run before run target can run)
	@echo "Running compiled executable"
	./exefile

clean :
	@# removes the executable file. will get error if exefile is not there 
	@# (build was not run or clean was run twice in a row)
	@echo "Removing executable file"
	rm exefile

