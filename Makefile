sort_colors.o: sort_colors.cpp
	g++ -std=c++11 $^ -o $@

strtsr.o: strtsr.cpp
	g++ -std=c++11 $^ -o $@

mostfrequentnumber.o: mostfrequentnumber.cpp
	g++ -std=c++11 mostfrequentnumber.cpp -o mostfrequentnumber.o

LCA_BST.o: LCA_BST.cpp
	g++ -std=c++11 $^ -o $@
	
firstoccurenceBS.o: firstoccurenceBS.cpp
	g++ -std=c++11 $^ -o $@

wordbreak.o: wordbreak.cpp
	g++ -std=c++11 $^ -o $@


clean: *.o
	rm $^

.PHONY: clean
