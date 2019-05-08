#include <iostream>
#include <string>
using namespace std;

int main(){
    string inputString;
    cout<<"Please input a string:"<<endl;
    getline(cin, inputString);
    cout<<endl<<"Pyramid string:"<<endl;
    
    for(size_t i{0};i<inputString.length();i++){
        
        cout<<string(inputString.length()-i,' ');

        for(size_t j{0};j<=i;j++){
            cout<<inputString[j];
        }
        if(i!=0){
            for(int k{i-1};k>=0;k--){
                cout<<inputString[k];
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}