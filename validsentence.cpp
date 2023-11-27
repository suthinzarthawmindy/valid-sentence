#include <iostream>
#include <string>
using namespace std;
//String has no period characters other than the last character.
bool hasPeriodCharacter(string sentence){
    bool flag= true;
    for (int i=0; i<(sentence.length()-1);i++){
        if (sentence[i]=='.'){
            flag =false;
            break;
        }
        else
        {
            flag= true;
        }
    }
    return flag;
}
//function that check items in the dedicated array.
bool inMembership(string test_array, int size,char character){
    bool flag= false;
    for (int i=0; i<size;i++){
        if(test_array[i]==character){
            flag =true;
            break;
        }
        else
        {
            flag= false;
        }
    }
    return flag;
}

//String ends with one of the following sentence termination characters: ".", "?", "!"
bool endWithTerminationCharacter(string sentence){
    bool flag= true;
        if(sentence[sentence.length()-1]=='.'|| sentence[sentence.length()-1]=='?'||sentence[sentence.length()-1]=='!'){
           flag= true;
        }
        else{
            flag= false;
        }
    return flag;
}
//Numbers below 13 are spelled out (”one”, “two”, "three”, etc…).
bool isNumberBelow(string sentence){
    string s= "123456789";
    bool flag= true;
    for(int i=0; i<sentence.length();i++){
        if (inMembership(s,s.length(),sentence[i])){
            if (inMembership(s,s.length(),sentence[i+1])){
                if (stoi(sentence.substr(i,2))<13){
                    flag= false;
                    break;
                }
                else{
                    flag= true;
                }
            }
        }
    }
    return flag;
}
//String has an even number of quotation marks.
bool hasEvenQuotationNumber(string sentence) {
    bool flag = true;
    int count = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '"') {
            count++;
        }
    }
    if (count % 2 == 0) {
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}
//function to check if the sentence is valid or not (including capital letter function)
bool isValidSentence(string sentence){
    bool flag= false;
    if(isupper(sentence[0]) && endWithTerminationCharacter(sentence) && hasPeriodCharacter(sentence) &&
            isNumberBelow(sentence) && hasEvenQuotationNumber(sentence)){
        flag = true;
    }
    else{
        flag= false;
    }
    return flag;
}

int main(){
    string sentence;
    cout<<"Please enter a sentence: "<<endl;
    getline(cin,sentence);
    if(isValidSentence(sentence)){
        cout<< "This sentence is valid."<<endl;
    }
    else{
        cout<<"This sentence is not valid."<<endl;
    }
    return 0;
}
