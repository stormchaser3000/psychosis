psychosis:
	c++ src/main_menu.cpp src/main.cpp -o psychosis -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm ./psychosis
