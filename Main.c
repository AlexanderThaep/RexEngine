#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <RegExp.h>

int main(int argc, char** args) {
    char* regex = "(limb)|(and)|(ing)";
    // char* regex = ".[a-z]*";
    // char* testex = "However, this implementation seeks to allow for the minimum that any user familiar with RegEx would appreciate. There are few special features and even fewer guarantees of efficiency or function. Yet, it's a little novelty project that I hope to incorporate into a larger Language Parser and, eventually, compiler.";
    char* testex = "a limbless cold-blooded vertebrate animal with gills and fins and living wholly in water: the sea is thick with fish.";

    RE** parseStack = parse(regex, strlen(regex));
    debug(parseStack, 0);

    BoolState stateTest = test(parseStack, testex, strlen(testex));
    printf("Truth: %d\n", stateTest.match);
    printf("Consumed: %d\n", stateTest.consumed);
    match(parseStack, testex, strlen(testex));

    return 0;
}