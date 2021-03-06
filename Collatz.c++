// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <cstring>
#include "Collatz.h"

using namespace std;

const int LEN = 1000;
int cache[LEN];

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}


//--------------
// Find next num
// Finds the next number in the sequence
//--------------

int findNextNum(int start){
    if(start % 2 == 0){
        return start / 2;
    } else {
        return (start * 3 + 1) / 2;
    }
}

//------
// Cache
// Caches all numbers with an index in the cache
//------
int cacheNums(int start){
    int steps = 1;
    if(start % 2 != 0){
        steps = 2;
    }
    if(start < 2){
	return 1;
    } else if(start < LEN && cache[start] != 0){
	return cache[start];
    } else if(start < LEN && cache[start] == 0) {
	cache[start] = cacheNums(findNextNum(start)) + steps; 
	return cache[start];
    } else {//if( start > len){
	return cacheNums(findNextNum(start)) + steps;
    }
    
}

//FOR TESTING
int getCache(int i){
    return cache[i];
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    if(i > j){
        int temp = i;
        i = j;
        j = temp;
    }
    assert (i >= 1);
    assert (j < 1000000);
    int steps = 1;
    int max = steps;
    for(int start = i; start <= j; start++) {
        //do calculations and caching
	steps = cacheNums(start);
        if(steps > max)
            max = steps;
    }
    assert (max > 0);
    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    memset(cache, 0, LEN);
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
