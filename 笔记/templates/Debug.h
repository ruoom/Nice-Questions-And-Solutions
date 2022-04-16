#pragma once
#include<bits/stdc++.h>
using namespace std;

string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true; string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) res += ", "; first = false; res += to_string(v[i]);
    }res += "}"; return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); }
    return res;
}
template <typename A>
string to_string(A v) {
    string res; stringstream ss;
    ss << v;
    ss >> res; return res;
}
template <typename A>
string to_string(vector<A> v) {
    bool first = true; string res = "{"; for (const auto& x : v) {
        if (!first) res += ", "; first = false; res += to_string(x);
    }res += "}"; return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    //cout << " " << H; debug_out(T...);
    cout << " " << to_string(H); debug_out(T...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


//-------------------------------------------------------------------------------------
