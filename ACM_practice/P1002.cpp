

//
//  problem_1002.cpp
//  ACM_practice
//
//  Created by ming on 7/28/17.
//  Copyright © 2017 ___MingDu___. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX_N 4
#define EMPTY 0
#define WALL 1
#define TOWER 2

void read_map(char base[][MAX_N], int n)
{
    int i, j;
    char a;
    for(i=0; i < n; i++)
        for(j=0; j < n; j++)
        {
            cin>>a;
            if(a == '.')
                base[i][j] = EMPTY;
            else if(a == 'X')
                base[i][j] = WALL;
            else if(a == 'T')
                base[i][j] = TOWER;
        }
}

int  read_input(char base[][MAX_N])
{
    int n;
    cin>>n;
    read_map(base, n);
    
    return n;
}

void print_board(char base[][MAX_N], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<(int)base[i][j];
        cout<<endl;
    }
    
}

bool is_valid_position(char base[][MAX_N], int ic, int jc)
{
    int i,j;
    if(base[ic][jc] != EMPTY)
        return false;
    j = jc;
    for(i=ic-1; i>=0; i--)
    {//up
        if(base[i][j] == WALL)
            break;
        if(base[i][j] == TOWER)
            return false;
    }
    
    for(i=ic+1; i<MAX_N; i++)
    {//down
        if(base[i][j] == WALL)
            break;
        if(base[i][j] == TOWER)
            return false;
    }
    
    i = ic;
    for(j=jc-1; j>=0; j--)
    {//left
        if(base[i][j] == WALL)
            break;
        if(base[i][j] == TOWER)
            return false;
    }
    
    for(j=jc+1; j < MAX_N; j++)
    {//right
        if(base[i][j] == WALL)
            break;
        if(base[i][j] == TOWER)
            return false;
    }
    return true;
}

bool next_move(char base[][MAX_N], int ic, int jc, int & in, int & jn, int n)
{
    
    for(in=ic,jn=jc+1;jn < n; jn++)
        if(is_valid_position(base, in, jn))
            return true;
    
    for(in=ic+1; in < n; in++)
        for(jn=0; jn < n; jn++)
            if(is_valid_position(base, in, jn))
                return true;
    return false;
}


int find_max(char base[][MAX_N], int i, int j, int n)
{
    int next_i, next_j, ret;
    int max = 0;
    
    //print_board(base, n);
    
    if(!next_move(base, i, j, next_i, next_j, n))
        return 0;
    while(next_move(base, i, j, next_i, next_j, n))
    {
        base[next_i][next_j] = TOWER;
        ret = find_max(base, next_i, next_j, n);
        if(ret > max)
            max = ret;
        base[next_i][next_j] = EMPTY;
        i = next_i;
        j = next_j;
    }
    return max + 1;
}


int main()
{
    int n, ret, in=0, jn=-1;
    char base[MAX_N][MAX_N];
    
    
    //print_board(base, n);
    //cout<<"###########"<<endl;
    
    //while(next_move(base, in, jn, in, jn, n))
    //    cout<<in<<','<<jn<<endl;
    while((n = read_input(base)))
    {
        ret = find_max(base, 0, -1, n);
        cout<<ret<<endl;
    }
    return 0;
}
