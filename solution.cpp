//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
         int fi=0,tn=0,tw=0,check=0;
    for(int i=0;i<bills.size();i++)
    {
        if(bills[i]==5)
        {
            fi++;
        }
        else if(bills[i]==10)
        {
            tn++;
            if(fi>=1)
            fi--;
            else if(fi<1)
            {
                check=1;
                break;
            }
        }
        else if(bills[i]==20)
        {
            tw++;
            if(fi>=1 && tn>=1)
            {fi--; tn--;}
            else if(fi>=3)
            fi=fi-3;
            else if((fi<3 && tn<1) || (fi<1 && tn<1) || fi<1 )
            {
                check=1;
                break;
            }
        }
    }
    if(check==0)
    return true;
    else 
    return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
