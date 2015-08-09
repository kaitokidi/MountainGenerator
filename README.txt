g++ -c main.cpp;    g++ -o exe main.o ; g++ -c tilemap.cpp;    g++ -o mapa tilemap.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network; ./exe | ./mapa;

