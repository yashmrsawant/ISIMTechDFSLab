#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIM 10000

int getline(char* s, int limit) {
    int i = 0;
    char c;
    c = getc(stdin);
    for(i = 0 ; i < limit && !(c == EOF || c == '\n') ; ++i) {

        s[i] = c;
        c = getc(stdin);
    }
    s[i] = '\0';
    return i;
}
int findChar(char* s, char c) {
    int i = 1;
    for(; i < strlen(s) ; i ++) {
        if(s[i] == c)
            return i;
    }
    return -1;
}
int solveTest(char* s) {
    int len = strlen(s);
    int i;
    int distance = 0;
    char* s1;
    char* s2;
    char c = '\0';
    int pos;
    if(len % 2 == 0) {
        s1 = (char*)(malloc(sizeof(char) * (len / 2 + 1)));
        s2 = (char*)(malloc(sizeof(char) * (len / 2 + 1)));

        for(i = 0 ; i < len / 2; ++ i) {
            s1[i] = s[i];
            s2[i] = s[i + len / 2];

        }
        s1[i] = '\0';
        s2[i] = '\0';
        printf("%s\n", s1);
        printf("%s\n", s2);
        for(i = 0 ; i < len / 2; ++ i) {
            if(s1[i] == s2[i]) {
                continue;
            } else {
                pos = findChar(s1, s2[i]);
                if(pos > 0) {
                    c = s1[i];
                    s1[i] = s1[pos];
                    s1[pos] = c;
                } else {
                    break;
                }
            }
        }
        distance = len / 2 - i;
        return distance;
    }
    else {
        return -1;
    }
}

int main() {

    char* s = (char*)(malloc(sizeof(char) * LIM));
    int i = 0;
    //Replace
    int testCount = 0;
    scanf("%d", &testCount);

    for(i = 0 ; i < testCount ; i ++) {
        getline(s, LIM);
        printf("%d\n", solveTest(s));
    }
    return 0;
}
