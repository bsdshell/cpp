all: 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o  MergeSortedList MergeSortedList.cpp Aron.cpp
	clang++ -g -v -std=c++11 -stdlib=libc++ -o  DataStructure  DataStructure.cpp 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o  DecimalBinary DecimalBinary.cpp  Aron.cpp
