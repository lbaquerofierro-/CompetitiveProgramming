/*
Three types of edits can be performed in an string:
insert a character, remove a character, or replace a character.
Compare two strings and determine if they are 0 or 1 edits away
*/

#include <iostream>
#include <string>

using namespace std;

bool oneArray(string s1, string s2){

    int dif = 0; //differences counter

    //Remove and insert
    if((s1.size() == s2.size() + 1) || (s1.size() == s2.size() - 1)){
        for(int i = 0, j = 0; j < s2.size(); i++, j++){
            if(s1[i] == s2[j])
                continue;
            else {
                i++;
                dif++;
            }
        }
    }else if(s1.size() == s2.size()){ //Replace
        for(int i = 0; i < s2.size(); i++){
            if(s1[i] == s2[i])
                continue;
            else {
                dif++;
            }
        }
    }

    if(dif > 1) return false;
    else return true;
}

void print(bool res){
    if(res == true)
        cout << "True: Strings are 0 or 1 edit away";
    else
        cout << "False: Strings require more than 1 edit";
    cout << endl;
}

int main() {

    string s1, s2, s3, s4, s5, s6, s7, s8;
    bool r1, r2, r3, r4;
    s1 = "pale";
    s2 = "ple";

    s3 = "pales";
    s4 = "pale";

    s5 = "pale";
    s6 = "bale";

    s7 = "pale";
    s8 = "bae";

    print(oneArray(s1, s2));
    print(oneArray(s3, s4));
    print(oneArray(s5, s6));
    print(oneArray(s7, s8));



    return 0;
}
