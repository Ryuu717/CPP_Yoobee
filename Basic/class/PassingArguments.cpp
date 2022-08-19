#include <iostream>
using namespace std;

class Alpha { 
    int a; 
public: 
    Alpha(int x) { 
        a = x; 
        cout << "Alpha constructed\n"; 
    } 
    void showAlpha() { 
        cout << "Alpha:" << a << "\n";
    } 
} ; 

class Beta { 
    int b; 
public: 
    Beta(int y) { 
        b = y; 
        cout << "Beta constructed\n"; 
    } 
    void showBeta() { 
        cout << "Beta:" << b << "\n"; 
    } 
} ; 

class Gamma : public Alpha, public Beta {
    int g; 
public: Gamma(int x, int y, int z): Alpha(x),Beta(y) {  //passing arguments
    g = z; 
    cout << "Gamma constructed\n"; 
    }
    
    void showGamma() {
        cout << "Gamma:" << g << "\n"; 
    }
};


int main(){
    Gamma g1(10, 20, 30);
    g1.showAlpha();
    g1.showBeta();
    g1.showGamma();
}