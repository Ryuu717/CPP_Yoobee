#include <iostream>
using namespace std;

class TestClass
{
    int num;

public:
    //+記号をオーバーロード
    TestClass operator +(TestClass r)
    {
        TestClass tc;
        tc.num = this->num + r.num;
        return tc;
    }
    // //-記号をオーバーロード
    // TestClass operator -(TestClass r)
    // {
    //     TestClass tc;
    //     tc.num = this->num - r.num;
    //     return tc;
    // }

    TestClass(int x = 0) { num = x; }
    int get() { return num; }
    // void set(int x) { num = x; }
};

int main(){
    TestClass tc1(1), tc2(2);
    TestClass tc3 = tc1 + tc2;
    cout << tc3.get();

    return 0;
}