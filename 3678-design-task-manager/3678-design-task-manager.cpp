struct CompareFunction {
    bool operator() (const vector<int> & a, const vector<int> & b) const {
        if (a[2] != b[2]) {
            return a[2]  < b[2];
        } else {
            return a[1] < b[1];
        }
    }
};
class TaskManager {
public:
    multiset<vector<int> , CompareFunction>ms ; 
    map<int,vector<int>> mp ; 
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks){
            ms.insert(task) ; 
            mp[task[1]] = task ;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId , taskId , priority} ; 
        ms.insert({userId , taskId , priority}) ; 
    }
    
    void edit(int taskId, int newPriority) {
        auto it = ms.find(mp[taskId]);
        if (it != ms.end()) {
            ms.extract(it); 
        }

        vector<int> oldTask = mp[taskId];
        int userId = oldTask[0];
        mp[taskId] = {userId, taskId, newPriority};
        ms.insert({userId, taskId, newPriority});
    }
        
    void rmv(int taskId) {
        vector<int> oldTask = mp[taskId] ; 
        ms.extract(oldTask) ; 
    }
    
    int execTop() {
        if (ms.empty()) return -1 ; 
        auto top = *ms.rbegin() ; 
        int userId = top[0] ; 
        ms.extract(top) ;
        return userId ; 
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */