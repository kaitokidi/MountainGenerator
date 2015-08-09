#include <time.h>
#include <vector>
#include <iostream> 
#include <algorithm>

enum directions {
    dir_up, dir_down, dir_right, dir_left, dir_up_right, dir_down_left, dir_up_left, dir_down_right, dirqtty
};

const int maxX = 100;
const int maxY = 50;
const int maxHeight = 9;
const int numMountains = 7;

//                      N   S   E   W  NE   SW  NW SE  NONE
const float dirx[9] = { 0,  0,  1, -1,  1,  -1, -1, 1,   0};
const float diry[9] = {-1,  1,  0,  0, -1,   1, -1, 1,   0};

// const wchar heightChar[9] = {'X','@','0','O','6','*','º','o','·'};
// const char heightChar[10] = {'.','o','d','C','6','G','O','0','@','X'};
const char heightChar[10] = {' ','.','-',':',';','i','c','x','%','#'};
void drawMap(std::vector< std::vector < int> >& map){
// std::cout << "ini draw" << std::endl;
    std::cout << map[0].size() << " " << map.size() << std::endl;
    for(int i = 0 ; i < map.size(); ++i){
        for(int j = 0 ; j < map[0].size(); ++j){
           // std::cout << heightChar[map[i][j]];
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
// std::cout << "end draw" << std::endl;
}

bool shouldContinue(int height){
    return ( (std::rand()%height) < maxHeight-2);
}

bool shouldMantain(){
    return (std::rand()%3 <= 1);
}

void setHeight(std::vector< std::vector < int> >& map, int px, int py, int height){

    if( px >= 0 && 
        py >= 0 && 
        py < map.size() && 
        px < map[0].size()) {
            map[py][px] = height;
    }
    for(int i = 0; i < dirqtty; ++i){
        int nextX = px+dirx[i]; 
        int nextY = py+diry[i];
        if( nextX >= 0 && 
            nextY >= 0 && 
            nextY < map.size() && 
            nextX < map[0].size() &&
            map[nextY][nextX] < height){
          
            if(shouldContinue(height)){
                setHeight(map, nextX, nextY, height-1);
            }
            else if(shouldMantain()){
                setHeight(map, nextX, nextY, height);    
            }
        }
    }    
//      drawMap(map);
}

int main(int argc, char *argv[]){
    
    std::srand(time(0));
    char arg1, arg2;
    if(argc >= 3){
        arg1 = *(argv[1]);
        arg2 = *(argv[2]);
    }
   // else std::cout << "need the x and y of the map" << std::endl;
    
    int argv1, argv2;
    argv1 = maxY, 
    argv2 = maxX;
    
    //variable map
    std::vector< std::vector < int> > map( argv1, std::vector<int>(argv2, 0));
    
    for(int i = 0; i < numMountains; ++i){
        int posx = std::rand()%argv2;
        int posy = std::rand()%argv1;
    
        setHeight(map, posx, posy, maxHeight);
    }
    
    drawMap(map);
    
}