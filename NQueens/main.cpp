//
//  main.cpp
//  NQueens
//
//  Created by Mohamed Radhi ZOUAOUI on 22/04/2015.
//  Copyright (c) 2015 Mohamed Radhi ZOUAOUI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if(n==0) return {};
        if(n==1) return {generateRowConfigs(1)};
        vector<string> sol(0);
        vector< vector<string> > allSol(0);
        vector<string> S = generateRowConfigs(n);
        findSolution(n, n, sol, allSol, S);
        return allSol;
    }
    
    int findQ(const string& s)
    {
        for(int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'Q') return i;
        }
        return -1;
    }
    
    vector<string> generateRowConfigs(int n)
    {
        vector<string> configs;
        string s(n,'.');
        for (int i = 0; i<n; ++i) {
            string q = s;
            q[i] = 'Q';
            configs.push_back(q);
        }
        return configs;
    }
    
    bool isOK(int n, const vector<string>& s)
    {
        if(s.size()<2) return true;
        if(s.size()>n) return false;
        for(int i = 0; i < s.size()-1; ++i)
        {
            int j = (int)s.size() - 1;
            if((abs((findQ(s[i])-findQ(s[j])))==0)||(abs(findQ(s[i])-findQ(s[j])))==abs(i-j)) return false;
            
        }
        return true;
    }
    
    bool accept(int n, const vector<string>& s)
    {
        if(s.size()==n) return isOK(n,s);
        return false;
    }
    
    void findSolution(int n, int idx, vector<string> &sol, vector<vector<string>> &allSol, const vector<string>& S) {
        if((!isOK(n,sol))||(idx<0)) return;
        else
        {
            if(accept(n,sol))
            {
                allSol.push_back(sol);
            }
        }
        for(int i=0; i<n; i++) {
            if(sol.size()<n) {
                sol.push_back(S[i]);
                findSolution(n, idx-1, sol, allSol, S);
                sol.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution S;
    int n = 13;
    clock_t t;
    t = clock();
    vector< vector<string> > v = S.solveNQueens(n);
    t = clock() - t;
    for(int i = 0; i< v.size();++i)
    {
        cout<<endl;
        for(int j = 0; j < n; ++j)
        {
            cout<<v[i][j]<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Il y avait : "<<v.size()<<" solutions!" <<endl;
    cout<<"Execution time is : "<<((float)t)/CLOCKS_PER_SEC<<" seconds!"<<endl;
    
    return 0;
}
