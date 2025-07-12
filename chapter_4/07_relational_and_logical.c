#include <stdio.h>

main() {
    int lim = 10;
    char c, s[lim];

    for(int i = 0; i < lim-1 && (c = getchar()) != '\n' || c != EOF; i++) {
        s[i] = c;
    }

    // So over here i < lim-1 does not have parenthesis and is implicitly understood as i < (lim-1)
    // because relationals have loer precedence than arithmatic operators

    // Also expressions with && or || are interpreted left to right and as soon as falsehood or truth is determined
    // we exit the loop so that why lim-1 is checked first
    // also the precdence of && is greater than || and both are lesser than lower than relational and equality
    // so that why each condition does not require brackets like (i < lim-1) && ((c = getchar()) != '\n') && (c != EOF);

    // as (c = getchar()) need brances becuase assignment has lower precendece than equality
}