#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>

#define MAXN 16777217 //2^24 +1
#define N10 2047
#define INF 1 << 21

using namespace std;

int n;
int d[21][1 << 21] = {INF};
int dp[1 << 20][20];

vector<int> tmp_cost( 10 );
vector<vector<int>> cost ( 10, tmp_cost );
vector<int> way;

int find_way(int vert, int mask) {
    if (d[vert][mask] != INF)
        return d[vert][mask];
    for (int i = 0; i < n; i++) {
        if ((cost[vert][i] != -1) && (mask & (1 << i))) {
            //cout << ( mask & ( 1 << i ) ) << endl;
            int tmp_new = min( d[vert][mask], find_way( i, mask - ( 1 << i ) ) + cost[vert][i] );
            d[vert][mask] = tmp_new;
        }
    }
    return d[vert][mask];
}

int get_way() {
    int i = 0;
    int mask = ( 1 << n ) - 1;
    way.push_back( 0 );
    while (mask != 0) {
        for (int j = 0; j < n; j++) {
            if (( cost[i][j] != -1 ) && (mask & ( 1 << j )) && (d[i][mask] == d[j][mask - (1 << j)] + cost[i][j]) ) {
                way.push_back( j );
                i = j;
                mask -= 1 << j;
            }
        }
    }
    return 0;
}

int main( int argc, char *argv[] ) {

    if (argc > 1) {
        freopen( argv[1], "r", stdin );
        freopen( argv[2], "w", stdout );
    }
    else {
    
        freopen( "input.txt", "r", stdin );
        freopen( "output.txt", "w", stdout );
    }

    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= N10; j++) {
            d[i][j] = INF;
        }
    }
    d[0][0] = 0;
    //d[0][1] = 0;

    int ans = find_way( 0, ( 1 << n ) - 1 );
    //ans = d[0][( 1 << n ) - 1];
    get_way();
    cout << ans << endl;

    for (int i = 0; i < way.size(); i++) {
        cout << way[i] << " ";
    }

    //if (argc > 1)
    //    cout << "lah";


    /*for (int mask = 0; mask < ( 1 << n ); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = INF;
        }
    }

    dp[1][0] = 0; 

    for (int mask = 2; mask < ( 1 << n ); mask++) {
        for (int i = 0; i < n; i++) {
            if (( mask >> i ) & 1) {    
                int mask_without_i = mask ^ ( 1 << i );

                for (int j = 0; j < n; j++) {
                    if (j != i && ( ( mask >> j ) & 1 )) { 
                        dp[mask][i] = min( dp[mask][i], dp[mask_without_i][j] + cost[j][i] );
                    }
                }
            }
        }
    }

    int ans = INF;
    int mask_all = ( 1 << n ) - 1; 

    for (int i = 0; i < n; i++) {
        ans = min( ans, dp[mask_all][i] + cost[i][0]);
    }

    cout << ans << endl;*/

    //d[0][1] = 0;
    //d[1][1] = 0;
    //d[n-1][0] = 0;
    int a = 1;
    int b = (1 << 5) + 1;
    int c = a & b;
    return 0;

}