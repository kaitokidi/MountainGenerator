Uses sfml, execute de .exe to habe a map and feed the .mapa with this result to get it interpreted and pinted

g++ -c main.cpp;    g++ -o exe main.o ; g++ -c tilemap.cpp;    g++ -o mapa tilemap.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network; ./exe | ./mapa;

