#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, pair<string, string>> pa {
    {{"Ab", "minor"}, {"G#", "minor"}}, 
    {{"A", "minor"}, {"UNIQUE", "minor"}}, 
    {{"A#", "minor"}, {"Bb", "minor"}}, 
    {{"Bb", "minor"}, {"A#", "minor"}}, 
    {{"B", "minor"}, {"UNIQUE", "minor"}}, 
    {{"C", "minor"}, {"UNIQUE", "minor"}}, 
    {{"C#", "minor"}, {"Db", "minor"}}, 
    {{"Db", "minor"}, {"C#", "minor"}}, 
    {{"D", "minor"}, {"UNIQUE", "minor"}}, 
    {{"D#", "minor"}, {"Eb", "minor"}}, 
    {{"E", "minor"}, {"UNIQUE", "minor"}}, 
    {{"Eb", "minor"}, {"D#", "minor"}}, 
    {{"F", "minor"}, {"UNIQUE", "minor"}},
    {{"F#", "minor"}, {"Gb", "minor"}}, 
    {{"Gb", "minor"}, {"F#", "minor"}}, 
    {{"G", "minor"}, {"UNIQUE", "minor"}}, 
    {{"G#", "minor"}, {"Ab", "minor"}}, 
    {{"Ab", "major"}, {"G#", "major"}}, 
    {{"A", "major"}, {"UNIQUE", "major"}}, 
    {{"A#", "major"}, {"Bb", "major"}}, 
    {{"Bb", "major"}, {"A#", "major"}}, 
    {{"B", "major"}, {"UNIQUE", "major"}}, 
    {{"C", "major"}, {"UNIQUE", "major"}}, 
    {{"C#", "major"}, {"Db", "major"}}, 
    {{"Db", "major"}, {"C#", "major"}}, 
    {{"D", "major"}, {"UNIQUE", "major"}}, 
    {{"D#", "major"}, {"Eb", "major"}}, 
    {{"E", "major"}, {"UNIQUE", "major"}}, 
    {{"Eb", "major"}, {"D#", "major"}}, 
    {{"F", "major"}, {"UNIQUE", "major"}},
    {{"F#", "major"}, {"Gb", "major"}}, 
    {{"Gb", "major"}, {"F#", "major"}}, 
    {{"G", "major"}, {"UNIQUE", "major"}}, 
    {{"G#", "major"}, {"Ab", "major"}}
};

int main() {
    char a[5], b[10];
    int i = 1;

    while (scanf("%s %s", &a, &b) != EOF) {
        if (pa[{a, b}].first == "UNIQUE") {
            printf("Case %d: UNIQUE\n", i);
        } else {
            printf("Case %d: %s %s\n", i, pa[{a, b}].first.c_str(), pa[{a, b}].second.c_str());
        }

        i++;
    }

    return 0;
}