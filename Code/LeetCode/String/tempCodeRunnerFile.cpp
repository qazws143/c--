    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 0)
            return false;
        vector<int> next(s.size());
        int len = s.size();
        getNext(&next[0], s);
        if ((len - (% ((next.size() - 1) + 1))) == 0)
            return true;
        else
            return false;
    }