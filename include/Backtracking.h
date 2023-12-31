#include <RegExp.h>

#if !defined(BACKTRACK)
#define BACKTRACK

#define BOOLSTACK_SIZE 512

typedef struct BackState {
    unsigned int index;
    unsigned int consumed;
    unsigned int stateIndex;
    unsigned short backTrackState;
} BackState;

typedef struct BackStack {
    unsigned int index;
    unsigned int max;
    struct BackState** states;
} BackStack;

BackStack* createBackStack();
void resetBackStack(BackStack* stack);
BackStack* pushBackStack(BackStack* back_stack, BoolState state, unsigned short backTrackState, unsigned int stateIndex);
BackState* popBackStack(BackStack* back_stack);
BackState* backtrack(BackStack* back_stack);

#endif