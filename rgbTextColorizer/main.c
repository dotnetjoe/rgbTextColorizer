//
//  main.c
//  rgbTextColorizer
//
//  Created by Adam Alston on 7/24/19.
//  Copyright © 2019 Adam Alston. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_LEN 16

void printer(int red, int green, int blue, int wl, char *word) {
    for(int i = 0; i < wl; i++) {
        red=((255/wl)*i);
        green=((255/wl)*i);
        blue=((255/wl)*i);
        int x = (int) red;
        int y = (int) green;
        int z = (int) blue;
        printf("{%d,%d,%d}%c",x,y,z,word[i]);
    }
}

int main () {
    char colorIn[MAX_LEN], colorOut[MAX_LEN], word[MAX_LEN];
    int colorLen, wordLen, r=0, g=0, b=0;
    double freq=.6;
    
    // get color and word input
    printf("Enter color\n");
    fgets(colorIn, MAX_LEN, stdin);
    printf("Enter word\n");
    fgets(word, MAX_LEN, stdin);
    
    // make color lowercase; add null terminator
    for(int i = 0; colorIn[i]; i++){
        colorOut[i] = tolower(colorIn[i]);
    }
    
    colorLen = strlen(colorOut) - 1;
    colorOut[colorLen] = '\0';
    wordLen = strlen(word) - 1;
    word[wordLen] = '\0';
    
    puts(colorIn);
    
    // change rgb pattern based on color input
    
        // red
    if (strcmp(colorOut, "red")==0) {
        r = 255;
        for(int i = 0; i < wordLen; i++) {
            g=((255/wordLen)*i);
            b=((255/wordLen)*i);
            int x = (int) g;
            int y = (int) b;
            printf("{%d,%d,%d}%c", r,x,y,word[i]);
        }
        // green
    } else if (strcmp(colorOut, "green")==0) {
        puts(colorOut);
        g = 255;
        for(int i = 0; i < wordLen; i++) {
            r=((255/wordLen)*i);
            b=((255/wordLen)*i);
            int x = (int) r;
            int y = (int) b;
            printf("{%d,%d,%d}%c",x,g,y,word[i]);
        }
        // blue
    } else if (strcmp(colorOut, "blue")==0) {
        b = 255;
        for(int i = 0; i < wordLen; i++) {
            r=((255/wordLen)*i);
            g=((255/wordLen)*i);
            int x = (int)r;
            int y = (int)g;
            printf("{%d,%d,%d}%c",x,y,b,word[i]);
        }
        // gray
    } else if (strcmp(colorOut, "gray")==0) {
        for(int i = 0; i < wordLen; i++) {
            r=((255/wordLen)*i);
            g=((255/wordLen)*i);
            b=((255/wordLen)*i);
            int x = (int)r;
            int y = (int)g;
            int z = (int)b;
            printf("{%d,%d,%d}%c",x,y,z,word[i]);
        }
        // rainbow
    } else if (strcmp(colorOut, "rainbow")==0) {
        for(int i = 0; i < wordLen; i++) {
            r= sin(freq*i) * 127 + 128;
            g= sin(freq*i+2) * 127 + 128;
            b= sin(freq*i + 4) * 127 + 128;
            printf("{%d,%d,%d}%c",r,g,b,word[i]);
        }
    } else {
        puts("Undefined Color");
    }
}
