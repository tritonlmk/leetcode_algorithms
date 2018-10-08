//Implement strStr().

//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
class Solution {
    private:
        void buildKMPTable(const string & s, vector<int> &KMP_Table)
        {
            int sSize = s.size(), i=2, j=0;
            KMP_Table[0] = -1;
            if(sSize>1) KMP_Table[1] = 0;
            while(i<sSize)
            {
                if(s[i-1]==s[j]) KMP_Table[i++] = ++j;
                else if(j>0) j = KMP_Table[j];
                else KMP_Table[i++] = 0;
            }
        }
    public:
        int strStr(string haystack, string needle) {
            int start=0, i=0, hSize = haystack.size(), nSize = needle.size();
            if(hSize<nSize) return -1;
            if(!nSize) return 0;
            vector<int> KMP_Table(nSize, 0);
            buildKMPTable(needle, KMP_Table);
            while(start<=hSize-nSize)
            {
                if(haystack[start+i]==needle[i])
                {
                    if(++i == nSize) return start;
                }
                else
                {
                    start = start+i-KMP_Table[i];
                    i= i>0?KMP_Table[i]:0;    
                }
            }
            return -1;
        }
    };
