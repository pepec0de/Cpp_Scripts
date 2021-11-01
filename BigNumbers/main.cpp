#include "include/UINT1024.h"
#include <chrono>

/// long log -> max : 18,446,744,073,709,551,615

void sumar(UINT1024 op1, UINT1024 op2) {
    UINT1024 result = op1 + op2;
    cout << "error\n";
    cout << result.FastB2DConversion() << endl;
}

void restar(UINT1024 op1, UINT1024 op2) {

}

void multiplicar(UINT1024 op1, UINT1024 op2) {

}

void dividir(UINT1024 op1, UINT1024 op2) {

}

void numeros()
{
    cout << "Numero mas grande de c++ : 18,446,744,073,709,551,615" << endl;
    UINT1024 a;
    for (int i = 0; i < 1024; i++) {
        a.set(i);
    }
    cout << "Numero mas grande de la calculadora: " << a.FastB2DConversion() << endl;
}

int main() {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    UINT1024 a, b;
    //cout << b.FastB2DConversion() << endl;
    a.set(0); a.set(1); // 3
    // cout << a.num.to_string<char,std::string::traits_type,std::string::allocator_type>() << endl;

    std::chrono::_V2::system_clock::time_point t1 = high_resolution_clock::now();
    sumar(a, b);
    std::chrono::_V2::system_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;

    cout << "Tiempo = " << ms_double.count() << " ms\n";

    return 0;
}
