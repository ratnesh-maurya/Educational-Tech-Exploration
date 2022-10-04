#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int target, vector<int> &prime){
    vector <bool> mark(target + 1, true);
    mark[0] = mark[1] = false;

    for (int i=2; i*i < target; i++){
        if (mark[i] == true){
            for (int j = i*i; j < target; j += i) mark[j] = false;
        }
    }
    for(int i=2; i<target; i++){
        if (mark[i] == true) prime.push_back(i);
    }
}

void segmentedSieve(int low, int high){
    int target = floor(sqrt(high)) + 1;
    vector<int> prime;
    simpleSieve(target, prime);

    int n = high - low;
    vector <bool> mark(n + 1, true);

    for (int i = 0; i < prime.size(); i++){
        int lowLim = floor(low / prime[i]) * prime[i];

        if (lowLim < low) lowLim += prime[i];

        for (int j = lowLim; j <= high; j += prime[i]) mark[j - low] = false;
    }

    for (int i = low; i <= high; i++){
        if (mark[i - low] == true) cout << i << " ";
    }
}

int main(){
    int low = 10, high = 50;
    segmentedSieve(low, high);
    return 0;
}