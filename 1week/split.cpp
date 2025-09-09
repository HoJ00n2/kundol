#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, const string delimter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimter);
    while(end != string::npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimter.size();
        end = input.find(delimter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main(){
    string s = "100,200,300,400";
    vector<string> ret;
    ret = split(s, ",");
    for(string ss : ret){
        cout << ss << " ";
    }

    return 0;
}