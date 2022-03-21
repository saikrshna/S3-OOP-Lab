//
// Created by tproh on 25-01-2022.
//

#define MIN 100
#define MAX 200

#include <cstdio>

int main()
{
    for(int i=MIN-1; i++<MAX; printf("%d = (%o)8 = (%X)16\n", i, i, i));
    return 0;
}