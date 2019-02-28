//
// Created by Shoto on 2/27/2019.
//

#include "MessageReceiveListenerImpl.h"
#include <stack>

char* MessageReceiveListenerImpl::on_msg_received(char *msg, int received_bytes_count) {
    std::stack<char>* stack = new std::stack<char>();
    for(int i = 0; i < received_bytes_count; i++) {
        char ch = msg[i];
        if(ch == '\0')
            break;

        if(is_not_bracket(ch))
            return (char*)&("Sequence is incorrect"[0]);

        if(is_open_bracket(ch)) {
            stack->push(ch);
            continue;
        }

        if(is_closing_bracket(ch)) {
            if(stack->empty())
                return (char*)&("Sequence is incorrect"[0]);

            char temp = stack->top();
            stack->pop();
            if(!char_is_opposite(temp, ch))
                return (char*)&("Sequence is incorrect"[0]);

            continue;
        }
    }

    if(!stack->empty())
        return (char*)&("Sequence is incorrect"[0]);

    return (char*)&("Sequence is correct"[0]);
}

bool MessageReceiveListenerImpl::char_is_opposite(char a, char b)  {
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}') ||
           (a == '<' && b == '>');
}

bool MessageReceiveListenerImpl::is_closing_bracket(char a) {
    return a == ')' || a == ']' || a == '}' || a == '>';
}

bool MessageReceiveListenerImpl::is_open_bracket(char a) {
    return a == '(' || a == '[' || a == '{' || a == '<';
}


bool MessageReceiveListenerImpl::is_not_bracket(char a){
    return !(is_closing_bracket(a) || is_open_bracket(a));
}