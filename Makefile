CXX = g++
CXXFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

psychosis: src/characters.o src/main_menu.o src/main.o
	$(CXX) src/characters.o src/main_menu.o src/main.o -o psychosis $(CXXFLAGS)

src/main.o: src/main.cpp src/characters.h src/main_menu.h
	$(CXX) -c src/main.cpp -o src/main.o $(CXXFLAGS)

src/characters.o: src/characters.cpp src/characters.h
	$(CXX) -c src/characters.cpp -o src/characters.o $(CXXFLAGS)

src/main_menu.o: src/main_menu.cpp src/main_menu.h
	$(CXX) -c src/main_menu.cpp -o src/main_menu.o $(CXXFLAGS)

clean:
	rm ./psychosis
	rm ./src/main.o
	rm ./src/main_menu.o
	rm ./src/characters.o
