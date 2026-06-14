class Solution {
    bool ip4(string ip) {
        if(count(ip.begin(), ip.end(), '.') != 3) return false;
        
        stringstream ss(ip);
        string token;
        int segmentCount = 0;
        
        while(getline(ss, token, '.')) {
            segmentCount++;
            
            if(token.empty() || token.size() > 3) return false;
            
            for(char c : token) {
                if(!isdigit(c)) return false;
            }
            
            if(token.size() > 1 && token[0] == '0') return false;
            
            int num = stoi(token);
            if(num < 0 || num > 255) return false;
        }
        
        return segmentCount == 4;
    }

    bool ip6(string ip) {
        if(count(ip.begin(), ip.end(), ':') != 7) return false;
        
        stringstream ss(ip);
        string token;
        int segmentCount = 0;
        
        while(getline(ss, token, ':')){
            segmentCount++;
            
            if(token.empty() || token.size() > 4) return false;
            
            for(char c : token){
                if(!isxdigit(c)) return false;
            }
        }
        
        return segmentCount == 8;
    }
public:
    string validIPAddress(string queryIP) {
        if(ip4(queryIP)) return "IPv4";
        else if(ip6(queryIP)) return "IPv6";
        return "Neither";
    }
};