
all: prettyprint.o
	g++ $^ -o prettyprint.out
	echo "Done"

%.o : %.cpp
	g++ -c $< -o $@

