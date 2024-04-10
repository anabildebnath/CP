        set<long long> s;
        for (int i = 0; i < k; i++)
        {
            s.insert(v1[i]);
            s.insert(v2[i]);
        }
        bool nigga = true;
        long long nigger = 1;

        for (auto i=s.begin();i!=s.end();i++)
        {
            if (*i != nigger)
            {
                nigga = false;
                break;
            }
            else
            {
                ++nigger;
            }
            if (nigger > k)
            {
                break;
            }
        }
