class TaskManager {
private:
    unordered_map<int, int> taskPri;
    unordered_map<int, int> taskUser;
    priority_queue<pair<int, int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            
            taskUser[taskId] = userId;
            taskPri[taskId] = priority;
            pq.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskUser[taskId] = userId;
        taskPri[taskId] = priority;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskPri[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskPri.erase(taskId);
        taskUser.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int taskId = top.second;
            
            if (taskPri.find(taskId) != taskPri.end() && taskPri[taskId] == top.first) {
                int userId = taskUser[taskId];
                taskUser.erase(taskId);
                taskPri.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};