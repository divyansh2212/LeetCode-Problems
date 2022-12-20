class Solution {
    
    void check(vector<vector<int>>& rooms, int vtx, vector<bool> &visited)
    {
        visited[vtx] = true;
        for(auto &child : rooms[vtx])
            if(!visited[child])
                check(rooms, child, visited);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        check(rooms, 0, visited);
        for(int i = 0; i < n; i++)
            if(visited[i] == false)
                return false;
                
        return true;
    }
};