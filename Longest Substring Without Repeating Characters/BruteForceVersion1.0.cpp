class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)return s.length();
        int locate[150] = {0};     //记录在当前子串中的字符的角标
        int max = 0;
        int begin = 1;  //起始位置
        int i=0;
        for(;i < s.length(); ++i){
            if(locate[s[i]]!=0 && locate[s[i]]>=begin){
                if(i + 1 - begin > max){
                    max = i + 1 - begin;
                }
                begin = locate[s[i]] + 1;
                locate[s[i]] = i+1;
            } else{
                locate[s[i]] = i + 1;
            }
        }
        if(i + 1 - begin > max){
            max = i + 1 - begin;
        }
        return max;
    }
};

//Runtime: 16 ms, faster than 92.30% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 9.1 MB, less than 99.78% of C++ online submissions for Longest Substring Without Repeating Characters.

//after adding a line of blank judge code between line 4 and line 5 -----  if(s[0] == 0) return 1; but it is a data bug actually
//Runtime: 12 ms, faster than 99.75% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 9.1 MB, less than 99.84% of C++ online submissions for Longest Substring Without Repeating Characters.