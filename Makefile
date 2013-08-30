all:
	g++ -o main main.cpp binaryTree.cpp -Wall -g
clean:
	rm main *~ -rf
