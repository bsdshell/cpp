all: 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o power2 power2.cpp 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o prime prime.cpp 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o Hello Hello.cpp Aron.cpp 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o GetMin GetMin.cpp 
	clang++ -g -v -std=c++11 -stdlib=libc++ -o OverlapInterval OverlapInterval.cpp 


