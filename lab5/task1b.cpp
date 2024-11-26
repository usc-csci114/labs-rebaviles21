#include <iostream>
#include <string>
#include <stack>

using namespace std;

//prototype:
bool isBracket(char str);
bool openBracket(char str);
bool closeBracket(char str);
// #### Matching parenthesis/brackets:

bool isBracket(char str){
    if ((str == '{' || str == '}') || (str == '(' || str == ')') || (str == '<' || str == '>')|| (str == '[' || str == ']')) {
        return true;
    }
    return false;
}
bool openBracket(char bracket){
    if ((bracket == '{') || (bracket == '(') || (bracket == '<')|| (bracket == '[')) {
        return true;
    }
    return false;
}
bool closeBracket(char str){
    if((str == '}') || (str == ')') || (str == '>')|| (str == ']')) {
        return true;
    }
    return false;
}

// Stacks can also be used as part of the compiling process to check to see if expressions have correct syntax.
 //We can build a very simple version of this by checking to see if a sequence of open close parenthesis and/or 
 //brackets are nested correctly. For example `({<>[()]})` is correct, while `({<>[()}])` is not.
int main() {
    string str; 
    stack <char> bracketHolder;

    cout << " give input" << endl;
    cin >> str;

    for (int i = 0 ; i < str.size();i++) {
        //skip over the whitespace
        if(str[i] == ' ' || str[i] == '\t' ) {
            i++; //skip
        }
        bool isCharacter = isBracket(str[i]);
        if (isCharacter == false){
            cout << "One of the characters in your string are not considered valid." << endl;
            return 1;
        }
        char bracket = str[i];
        bool isOpen = openBracket(bracket);
        if (isOpen == true) { // if the character is an open bracket
            bracketHolder.push(bracket);
        } 
        bool isClosed = closeBracket(bracket); //if the character is a closed bracket
        if(isClosed == true) {
            if(bracketHolder.empty() == true) {
                cout << "Error" << bracket << "at position" << i << endl;
            }
            char topBracket = bracketHolder.top();
            /// it is a closed bracket and they match to the top of the stack (assumption)
            if(topBracket == '{' && str[i] == '}') {
                bracketHolder.pop();
            }
            else if(topBracket == '(' && str[i] == ')'){
                bracketHolder.pop();
            }
            else if(topBracket == '[' && str[i] == ']'){
                bracketHolder.pop();
            }
            else if(topBracket == '<' && str[i] == '>'){
                bracketHolder.pop();
            }
            else {// do not match
                cout<< " Error. Found " << str[i] <<  " at position " << i << "expecting" << topBracket << endl;
                if(topBracket == '}') {
                    str[i] = '{';
                }
                else if(topBracket == ']') {
                    str[i] = '[';
                } 
                else if(topBracket =='>') {
                    str[i] = '<';
                }
                else if(topBracket == ')'){
                    str[i] = '(';
                }
                bracketHolder.pop();
            }
        }
    }

    if(bracketHolder.empty() == false) {
        //mismatch occurs

        cout << "Error. Unmatched open parens/brackets." << endl;
        //replace the bracket
        bracketHolder.pop();

    }
    else{
        cout << "The string given had a matching bracket!! Good job" << endl;
    }
    return 0;
}



// Replace {bracket} with the paren/bracket you found, {index} with the 
//index of the error and {expected} with the bracket you were expecting to find (i.e the top of the stack). Make 
//sure to handle the case of finding a close paren/bracket when the stack is empty. In this case replace {expected} 
//with "any open".


// 2. If you finish scanning the string and the stack is not empty, your message should be "Error. Unmatched open parens/brackets."

