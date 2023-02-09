class Solution {

public:
    long long distinctNames(vector<string>& ideas) {

        unordered_map<char,unordered_set<string>> map;
        long long validNamesCount = 0;

        for(long long i=0; i < ideas.size(); i++)
            map[ideas[i][0]].insert((ideas[i]).substr(1));

        for(long long i = 0; i < map.size(); i++){

            if(map[i].size() == 0) continue;

            for(long long j = 0; j < map.size(); j++){
                
                if(map[j].size() == 0) continue;
 
                if(i == j) continue;
 
                long long samePairsCount = 0;
                for(auto i : map[i]){
                    if(map[j].count(i) > 0) samePairsCount++;
                }

                long long nonDupliWordsIn_i = map[i].size() - samePairsCount;
                long long nonDupliWordsIn_j = map[j].size() - samePairsCount;

 
                validNamesCount += nonDupliWordsIn_i * nonDupliWordsIn_j;
            }
        }

        return validNamesCount;
    }
};