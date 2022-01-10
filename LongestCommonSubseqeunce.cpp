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
    system("clear");
    int k = LCS("My Name is Ramith", "Hi Ramith");
    cout<<k<<endl;
}