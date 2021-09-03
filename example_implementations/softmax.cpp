#include <iostream>
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace std;


vector<float> softmax_unstable(const vector<float> &x) 
{
    float sum = 0;
    vector<float> result;
    result.resize(x.size());

    for (size_t i = 0; i < x.size(); i++) 
    {
        sum += exp(x[i]);
        cout << exp(x[i]) <<endl;
    }
    cout << sum << endl;
    for (size_t j = 0; j < x.size(); j++) 
    {
        result[j] = exp(x[j]) / sum;
    }
    return result;
}


vector<float> softmax_stable(const vector<float> &x) 
{
    float sum = 0;
    vector<float> result;
    result.resize(x.size());
    float max = *max_element(x.begin(), x.end());

    for (size_t i = 0; i < x.size(); i++) 
    {
        sum += exp(x[i] - max);
    }
    for (size_t j = 0; j < x.size(); j++) 
    {
        result[j] = exp(x[j] - max) / sum;
    }
    return result;
}

int main() {
    vector<float> x{10.0, 100.0, 1000.0};
    vector<float> y{-1000.0, -10000.0, -1000000.0};

    vector<float> result_unstable_x = softmax_unstable(x);
    cout << "Unstable softmax given x: " << endl;
    for (const auto &i : result_unstable_x) {
        cout << i << endl;
    }
    vector<float> result_stable_x = softmax_stable(x);
    cout << "Stable softmax given x: " << endl;
    for (const auto &i : result_stable_x) {
        cout << i << endl;
    }

    vector<float> result_unstable_y = softmax_unstable(y);
    cout << "Unstable softmax given y: " << endl;
    for (const auto &i : result_unstable_y) {
        cout << i << endl;
    }
    vector<float> result_stable_y = softmax_stable(y);
    cout << "Stable softmax given y: " << endl;
    for (const auto &i : result_stable_y) {
        cout << i << endl;
    }
}
