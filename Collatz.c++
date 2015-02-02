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

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}


//------
// CACHE
//------
int cache(int[] cache, int start){
    if(start < 2){
	return 1;
    } else if(start < cache.length() && cache[start] == 0) {
	//FIND NEW START
	cache[start] = cache(cache, findNextNum(start)) + 1;
    } else if(start < cache.length() && cache[start] != 0){
	return cache[start];
    } else if( start > cache.length()){
	cache(cache, steps++, findNextNum(start));
    }
    
}

//--------------
// Find next num
//--------------

int findNextNum(int start){
    if(start % 2 == 0){
	return start / 2;
    } else {
        return start * 3 + 1;
    }
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
    int cache[j + 1];
    memset(cache, 0, j);
    int steps = 1;
    int max = steps;
    for(int start = i; start <= j; start++) {
        int k = start;
        steps = 1;
        //do calculations!
	steps = cache(cache, start);
        if(steps > max)
            max = steps;
    }
    assert (max > 0);
    return max;


}


/*
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
        int k = start;
        steps = 1;
        while(k > 1){
            if(k % 2 == 0){
                k = k / 2;
            } else {
                k = 3*k + 1;
            }
            steps++;
        }
        if(steps > max)
            max = steps;
    }
    assert (max > 0);
    return max;
}
*/

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
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
