#include <bits/stdc++.h>

using namespace std;

vector<string> my_numbers;

int diff_digits(string& a, string& b){
    int counter = 0;
    for(size_t i = 0; i < a.length(); i++){
        if(a[i] != b[i]) counter++;
    }
    return counter;
}

int main(){
    for(int i = 7; i < 1000; i += 7)
        my_numbers.push_back(to_string(i));
    int t, num;
    string n;
    cin >> t;
    while(t--){
        cin >> n;
        num = stoi(n);
        if(num % 7 == 0){
            cout << n << endl;
            continue;
        }
        int pos = 0;
        while(my_numbers[pos].size() != n.size()) pos++;


        int min_nums = 3;
        string best_num = "";
        for(int i = pos; i < my_numbers.size(); ++i){
            int d = diff_digits(my_numbers[i], n);
            if(d < min_nums){
                min_nums = d;
                best_num = my_numbers[i];
                if(d == 1) break;
            }
        }
        cout << best_num << endl;
    }
}