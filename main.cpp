#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//There is a horse on a chess table.We input the number and coordinations of enemies.The program output is the number of potentialy killed enemies.
int main()
{
    int n, count = 0;
    bool error = false;
    pair<int, int> pos;
    vector<pair<int, int>> enemies;
    vector<pair<int, int>> places;
    pair<int, int> model;
    cout<<"--- Created by CodeFu ---"<<endl;
    cout<<"Enter horse coordinates: ";
    cin>>pos.first>>pos.second;
    for(int k=0; k<=1; k++) {
        if(pos.first > 8 || pos.second > 8) {
            error = true;
            cout<<"Error!";
            break;
        }
    }
    cout<<""<<endl;
    cout<<"Eneter number of enemies: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        cout<<"Enter enemy coordinates: ";
        cin>>model.first>>model.second;
        if(model.first > 8 || model.second > 8) {
            cout<<"Error!";
            error = true;
            break;
        } else {
        enemies.push_back({ model.first, model.second });
        }
    }
    places.push_back({ pos.first-1, pos.second+2 });
    places.push_back({ pos.first-2, pos.second+1 });
    places.push_back({ pos.first+1, pos.second+2 });
    places.push_back({ pos.first+2, pos.second+1 });
    places.push_back({ pos.first-1, pos.second-2 });
    places.push_back({ pos.first-2, pos.second-1 });
    places.push_back({ pos.first+1, pos.second-2 });
    places.push_back({ pos.first+2, pos.second-1 });
    for(int i=0; i<n; i++) {
        for(int j=0; j<8; j++) {
            if(error == false) {
            if(enemies.at(i) == places.at(j)) {
                count++;
            }
            }
        }
    }
    if(error == false) {
    cout<<""<<endl;
    cout<<"There are "<<count<<" killed enemies!";
    cout<<"There remain "<<n-count<<" enemies!";
    }
    return 0;
}
