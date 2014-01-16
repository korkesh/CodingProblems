//
//  ReverseSentence.c
//  test
//
//  Created by Matthew Correia on 1/15/2014.
//  Copyright (c) 2014 a. All rights reserved.
//
#include "ReverseSentence.h"

#include <iostream>

using namespace std;

void reverseString(string &s, unsigned long start, unsigned long end) {
    auto stringLength = end - start;
    
    for (int i = 0; i < stringLength/2; i++) {
        char temp = s[(start + i)];
        char swap = s[(end - 1 - i)];
        
        s[(start + i)] = swap;
        s[(end - 1 - i)] = temp;
    }
}

void reverseWords(string &s) {
    auto stringLength = s.length();
    
    int start = 0;
    int end = 0;
    
    while (s[start] == ' ') {
        start++;
    }
    
    for (int i = start; i <= stringLength; i++) {
        if (s[i] == ' ' || (i == stringLength)) {
            end = i;
            reverseString(s, start, end);
            start = -1;
        }
        else if (start == -1 && s[i] != ' ') {
            start = i;
        }
    }
}

void reverseSentence() {
    string s = "my name is a b c";
    
    reverseString(s, 0, s.length());
    reverseWords(s);
    
    cout << s << endl;
}