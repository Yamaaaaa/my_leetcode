class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(s[0]=='-'){
            std::reverse(++s.begin(),s.end());
        }else{
            std::reverse(s.begin(),s.end());
        }
        long long temp = stoll(s);
        if(temp > INT_MAX || temp<INT_MIN){
            return 0;
        }
        return temp;
    }
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
//Memory Usage: 8.3 MB, less than 98.18% of C++ online submissions for Reverse Integer.