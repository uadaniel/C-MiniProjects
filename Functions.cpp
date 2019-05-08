#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <math.h>
using namespace std;
/*
 * This challenge is about using a collection (list) of integers and allowing the user
to select options from a menu to perform operations on the list.
Your program should display a menu options to the user as follows:
P - Print numbers
A - Add a number
M - Display mean of the numbers
S - Display the smallest number
L - Display the largest number
Q - Quit
 * 
 * Additional functionality if you wish to extend this program.
- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!
 * */
 void printMenu();
 void printNumbers(vector<int>);
 double meanNumber(vector<int>);
 int minNumber(vector<int>);
 int maxNumber(vector<int>);
 void clearList(vector<int>&);
 void addNumber(vector<int>&);

int main(){
    std::cout<<"Section 9 Challenge"<<std::endl;
    cout<<"________________________________________"<<endl;
    char userInput;
    vector<int> listOfIntegers{1,2,3,4};
    
    while(true){
       printMenu();
       cin>>userInput;
       switch(toupper(userInput)) {
           case 'P'  :
           {
              printNumbers(listOfIntegers);
              break; //optional
           }
           case 'A'  :
           {
              addNumber(listOfIntegers);
              break; //optional
           }
           case 'M'  :
           {
              cout<<"Mean of the list is "<<meanNumber(listOfIntegers)<<endl;
              break; //optional
           }
           case 'S'  :
           {
              cout<<"Minimum number is "<<minNumber(listOfIntegers)<<endl;
              break; //optional
           }
           case 'L'  :
           {
              cout<<"Maximum number is "<<maxNumber(listOfIntegers)<<endl;
              break; //optional
           }
           case 'C' :
           {
               clearList(listOfIntegers);
               break;
           }
           case 'Q'  :
              break; //optional
           default : {
                cout<<"Your input is not valid, please try again with a valid one..."<<endl;
                break;
                }
    }
    if(userInput=='Q' || userInput=='q'){
           break;
    }
    else{
        continue;
    }
}
    cout<<"Program terminated. ";
    return 0;
}
 void printMenu(){
     cout<<"Please choose an option from the following menu"<<endl;
     cout<<"P - Print numbers"<<endl;
     cout<<"A - Add a number"<<endl;
     cout<<"M - Display mean of the numbers"<<endl;
     cout<<"S - Display the smallest number"<<endl;
     cout<<"L - Display the largest number"<<endl;
     cout<<"C - Clear the list"<<endl;
     cout<<"Q - Quit"<<endl;
 }
 void printNumbers(vector<int> inVector){
     for(auto i : inVector)
         cout<<i<<' ';
     cout<<endl;
 }
 double meanNumber(vector<int> inVector){
     double sum=0;
     for(auto i: inVector){
         sum+=i;
     }
     return sum/inVector.size();
 }
 int minNumber(vector<int>inVector){
     int min=pow(2,32)/2 - 1;
     for(auto i : inVector){
         if(i < min)
             min=i;
     }
     return min;
 }
 int maxNumber(vector<int>inVector){
     int max=0;
     for(auto i:inVector){
         if(i>max)
             max=i;
     }
     return max;
 }
 void clearList(vector<int> &inVector){
     inVector.clear();
     cout<<"List cleared!"<<endl;
 }
 void addNumber(vector<int> &inVector){
     int x;
     cout<<"Please provide the number you wish to add: ";
     cin>>x;
     inVector.push_back(x);
     cout<<"Number added!"<<endl;
 }