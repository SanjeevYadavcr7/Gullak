       int max_len = 0; 
        unordered_map<int, bool> numMap;

        for(int &i : nums) numMap[i] = true;
        
        for(int &i : nums) {
            // if prev num is not present means this is starting of seq.
            if(!numMap[i-1]) {
                int cnt = 0;
                while(numMap[i]) {
                    cnt++, i++;
                }
                max_len = max(max_len, cnt);
            } 
        }
        return max_len;
