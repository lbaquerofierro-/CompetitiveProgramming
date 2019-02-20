/* Determine if all the characters of a given string are unique */

#include <iostream>
#include <map>

using namespace std;


/* Using a map from characters to dummy int value */

bool isUnique(char *s){
    int val;

    map<char, int> m;
    map<char, int>::iterator it;

    for(int i = 0; s[i] != '\0'; i++){
        val = 0;

        it = m.find(s[i]);
        if(it == m.end()){
            m.insert(pair<char, int>(s[i], val));
        }else{
            return false;
        }

    }

    return true;
}

/* Using an array to represent ASCII characters */

bool isUniqueASCIIarray(char *s){
    bool arr[128] = {false};
    int val;


    for(int i = 0; s[i] != '\0'; i++){

        if(arr[s[i]] == true) {
            return false;
        }else {
            arr[s[i]] = true;
        }
    }
    return true;
}

int main() {

    char s[] = "eabcd";
    if (isUnique(s) == true)
        cout << "No duplicates: UNIQUE";
    else
        cout << "Duplicates: NOT UNIQUE";

    cout << endl;


    if (isUniqueASCIIarray(s) == true)
        cout << "No duplicates: UNIQUE";
    else
        cout << "Duplicates: NOT UNIQUE";

    return 0;
}
