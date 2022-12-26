// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation

class Solution {
public:
    int reinitializePermutation(int n) {
        int perm[n];
    for(int i=0;i<n;i++)
    {
        perm[i] = i;
    }
        
    int c = 0;
    while(1)
    {
        int f= 0;
        for(int i=0;i<n;i++)
        {
            if(perm[i]!=i)
                f=1;
        }
        if(f==0 && c!=0)
            break;

        int arr[n];
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                arr[i] = perm[i/2];
            }
            else
            {
                arr[i]= perm[n/2 + (i-1)/2];
            }
        }
        // out(arr);
        for(int i=0;i<n;i++)
        {
            perm[i] = arr[i];
        }
        c++;
    }
    return c;
    }
};