class Solution
{
public:
    bool isAllDigits(const string &s)
    {
        return all_of(s.begin(), s.end(), ::isdigit);
    }

    bool isIPv4(string queryIP)
    {
        istringstream iss(queryIP);
        string curr = "";
        int cnt = 0;
        while (getline(iss, curr, '.'))
        {
            if (curr.empty() || (curr.size() > 3) || !isAllDigits(curr))
                return false;

            int no = stoi(curr);
            if ((no < 0) || (no > 255) || ((curr.size() > 1) && (curr[0] == '0')))
                return false;
            cnt++;
        }

        if (cnt == 4)
            return true;
        return false;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    bool isIPv6(string queryIP)
    {
        istringstream is(queryIP);
        int cnt = 0;
        string curr = "";
        vector<char> possible{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F'};
        while (getline(is, curr, ':'))
        {
            if (curr.empty() || (curr.size() > 4))
                return false;
            int i = 0, maxi = max(1, curr.size());
            for (; i < maxi; i++)
            {
                if (find(possible.begin(), possible.end(), curr[i]) == possible.end())
                    return false;
            }
            cnt++;
            if ((i < curr.size()) || (cnt > 8))
                return false;
        }
        if (cnt == 8)
            return true;
        return false;
    }

    string validIPAddress(string queryIP)
    {
        if (queryIP == "")
            return "Neither";
        if ((queryIP[0] == '.') || (queryIP[0] == ':') || (queryIP[queryIP.size() - 1] == '.') || (queryIP[queryIP.size() - 1] == ':'))
            return "Neither";

        if (queryIP.find('.') && isIPv4(queryIP))
            return "IPv4";
        if (queryIP.find(':') && isIPv6(queryIP))
            return "IPv6";
        return "Neither";
    }
};