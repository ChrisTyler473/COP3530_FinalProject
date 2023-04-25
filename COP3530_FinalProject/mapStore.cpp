//
// Created by Chris Tyler on 4/24/23.
//
#include "mapStore.h"
#include<map>
#include <string>
#include <vector>
#include <iostream>
void mapStore ::insertGame(std::string console, std::string genre, bool multiplayer, std::string name, int year,
                           float price, float reviews, float length, std::string rating) {
    vertex add = vertex(name, year, price, reviews, length, rating);
    m[console][genre][multiplayer].push_back(add);
}

void mapStore ::searchAndPrintBestGame(std::string console, std::string genre, bool multiplayer, std::string rating,
                                       float length) {
    if(!(m[console][genre][multiplayer].empty())){
        cout << m[console][genre][multiplayer].size() << " games found" << endl;
    }
    else{
        cout << "No games found, try different search parameters" << endl;
    }
}