#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void print_map(int map[10][10]);
void taxicap(int monster[2], int hero[2]);
void euclid(int monster[2], int hero[2]);
void cheby(int monster[2], int hero[2]);
int main(){
    srand(time(0));
    int map[10][10] = {0};
    int tree[2] = {rand() % 10, rand() % 10};
    int hero[2] = {5, 0};
    int monster[2] = {5, 2};
    
    cout << "Initial map:" << endl;
    print_map(map);
    map[tree[0]][tree[1]] = 1; 
    map[hero[0]][hero[1]] = 2;
    map[monster[0]][monster[1]] = 3;
    cout << "Map with tree hero and monster:" << endl;
    print_map(map);

    taxicap(monster,  hero);
    euclid(monster,  hero);
    cheby(monster,  hero);
}

void print_map(int map[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void taxicap(int monster[2], int hero[2]){
    int taxi = abs(monster[0] - hero[0]) + abs(monster[1] - hero[1]);
    cout << "taxicap = " << taxi << endl;
}

void euclid(int monster[2], int hero[2]){
    int euc = sqrt(pow(monster[0] - hero[0], 2) + pow(monster[1] - hero[1], 2));
    cout << "euclid = " << euc << endl;
}

void cheby(int monster[2], int hero[2]){
    int chebyshev = 0;
    if(abs(monster[0] - hero[0]) > abs(monster[1] - hero[1])){
        chebyshev = abs(monster[0] - hero[0]);
    }else{
        chebyshev = abs(monster[1] - hero[1]);
    }
    cout << "cheby = " << chebyshev << endl;
}
