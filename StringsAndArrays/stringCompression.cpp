/*
Implement basic compression using counts of repeated characters
if result string is shorter than original
*/

#include <iostream>
#include <string>

using namespace std;

int newLength(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i+1] == s[i])
            continue;
        else
            count++;
    } 

    return count * 2;
}

string compression(string s){

    string newString ;

    if(newLength(s) >= s.size())
        return s;
    else {
        int count = 1;

        for(int i = 0; i < s.size(); i++){
            if(s[i+1] == s[i])
                count++;
            else {
                newString += s[i];// + a;
                newString += to_string(count);
                count = 1;
            }
        }

    }

    return newString ;
}

int main() {
    string s1 = "aaaaaaaaaaaaaabcccdeeee";
    cout << compression(s1) << endl;
    string s2 = "aabcccde";
    cout << compression(s2) << endl;

    return 0;
}
