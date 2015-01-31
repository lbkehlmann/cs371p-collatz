// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <iostream>

using namespace std;


// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
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

//return 1;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);;
        collatz_print(w, i, j, v);
    }
}

// ----
// main
// ----

int main () {
    collatz_solve(cin, cout);
    return 0;
}






