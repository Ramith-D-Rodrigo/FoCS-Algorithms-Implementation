#include <iostream>
#include <map>
#include <vector>
using namespace std;

int RodCuttingProblem(map <int,int> price_of_piece, int size){
    vector <int> r;
    r.push_back(0);
    int price;
    for(int i = 1; i <= size; i++){
        price = 0;
        for(int j = 1; j <= i; j++){
            price = max(price, price_of_piece[j] + r[i-j]);
        }
        r[i] = price;
    }
    return r[size];
}

int main(){
    int size;
    map <int, int> arr;
    cout<<"Enter the size of the Rod: ";
    cin>>size;
    cout<<"Enter the prices"<<endl;
    for(int i = 1; i <= size; i++){
        cout<<"Price for the piece of size "<<i<<" : ";
        cin>>arr[i];
    }
    int max_price = RodCuttingProblem(arr, size);
    cout<<"Max Price: "<<max_price<<endl;
    return 0;
}