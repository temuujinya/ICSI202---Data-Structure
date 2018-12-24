  #include <string>
  #include <stdio.h>
  #include<stdlib.h>
  #define MAX 100
// #include <iostream>

using namespace std;

  int bruteForce(char *search, char *pattern, int slen, int plen) {
        int i, j, k;

        for (i = 0; i <= slen - plen; i++) {
                for (j = 0, k = i; (search[k] == pattern[j]) &&
                        (j < plen); j++, k++);
                if (j == plen)
                        return j;
        }
        return -1;
  }

  int main() {
        char searchStr[MAX], pattern[MAX];
        int res;
        printf("String:");
        fgets(searchStr, MAX, stdin);
        printf("haih ug:");
        fgets(pattern, MAX, stdin);
        searchStr[strlen(searchStr) - 1] = '\0';
        pattern[strlen(pattern) - 1] = '\0';

        res = bruteForce(searchStr, pattern, strlen(searchStr), strlen(pattern));
        if (res == -1) {
                printf("bhgui\n");
        } else {
                printf("Oldson bairlal %d\n", res);
        }
        return 0;
  }

