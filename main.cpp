#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

//#define DEBUG(fmt, args...) {printf("\033[1;32[DBG] %s(%d) %s : "fmt"\033[m", __FUNCTION__, __LINE__, __TIME__, ##args);}

//#define debug_print(fmt, ...) \
//    do { fprintf(stderr, "[DBG] %s(%d) %s : " fmt,  __FUNCTION__, __LINE__, __TIME__, __VA_ARGS__);} while(0)

//#define TRACE(x) do{ debug_print x;} while(0)
//#define TRACE(x) do{ printf("[DBG] %s(%d) %s : ", __FUNCTION__, __LINE__, __TIME__); printf(x);} while(0)
//#define TRACE(fmt, ...) do{ printf("[DBG] %s(%d) %s : ", __FUNCTION__, __LINE__, __TIME__); printf(fmt, __VA_ARGS__);} while(0)
    
void c_recur(int k, int n, int m, vector<int> list, bool isInit)
{
    if(k-1 >=0) {
        printf("[DBG] %s(%d) %s : idx: %d\n", __FUNCTION__, __LINE__, __TIME__, k-1);
        list.push_back(k-1);
    }
    
    for (int i=k; i<=(m-n) && n>0; ++i)
    {
        printf("[DBG] %s(%d) %s : i: %d\n", __FUNCTION__, __LINE__, __TIME__, i);
        c_recur(i+1, n-1, m, list, false);
    }
    
    if (n==0 && !isInit) {
        for(int i=0; i<list.size(); ++i)
        {
            cout<<list[i]<<'\t';
        }
        cout<<endl;
    }
}
int main()
{
    int m=5, n=3;
    vector<int> list;
    c_recur(0, n, m, list, true);
    return 0;
}