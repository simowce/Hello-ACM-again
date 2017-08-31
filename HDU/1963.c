/*
 * 1963.c
 * Copyright (C) 2017 simowce <simowce@simowce>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a)>(b)?(a):(b))
int dp[1000005];

int main()
{
    int n;

    scanf("%d", &n);
    while (n--) {
        int V, year, count;
        int w[11];
        int v[11];
        int i, j, k, t;
        scanf("%d%d%d", &V, &year, &count);
        for (i=0; i < count; i++) {
            scanf("%d%d", w+i, v+i);
            w[i] /= 1000;
        }
        for (i=0; i<year; i++) {
            t = V;
            V /= 1000;
            memset(dp, 0, sizeof(dp));
            for (j=0; j<count; j++) {
                for (k=w[j]; k<=V; k++) {
                    dp[k] = max(dp[k], dp[k-w[j]]+v[j]);
                }
            }
            V = t+dp[V];
        }

        printf("%d\n", V);
    }
}
