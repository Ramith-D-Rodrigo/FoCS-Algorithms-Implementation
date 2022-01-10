#include <iostream>
using namespace std;

int LCS(string s, string t){
    int **arr = new int*[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = new int[t.size()]{0};
    }
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]){
                if(i == 0 || j == 0){
                    arr[i][j] = 1;
                }else{
                    arr[i][j] = arr[i - 1][j - 1] + 1;     
                }
            }else{
                if(i == 0 and j == 0){
                    arr[i][j] = 0;
                }
                else if(i == 0){
                    arr[i][j] = arr[i][j - 1];
                }
                else if(j == 0){
                    arr[i][j] = arr[i - 1][j];
                }
                else{
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
                
            }
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return arr[s.size()-1][t.size()-1]; 
}

int main(){
    string s1, s2;
    cout<<"Enter the long string: ";
    getline(cin, s1);
    cout<<"Enter the short string: ";
    getline(cin, s2);

    int k = LCS(s1, s2);
    cout<<"Longest substring is: "<<k<<endl;
}