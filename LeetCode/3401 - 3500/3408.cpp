// 3408. Design Task Manager


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


// Solution 1: Using Hash Map and Min-Heap (set)
// Time Complexity: O(Q log Q) where Q is the number of queries
// Space Complexity: O(Q)
// Custom comparator for pair<int,int>
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first)
            return a.second > b.second;  // sort by second if first is same
        return a.first > b.first;        // otherwise sort by first
    }
};

class TaskManager {
public:
    unordered_map<int,int> taskToUser;
    unordered_map<int,int> taskToPriority;
    set<pair<int,int>, cmp> taskPriorityHeap;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task: tasks){
            int userId = task[0], taskId = task[1], priority = task[2];
            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
            taskPriorityHeap.insert({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        taskPriorityHeap.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int prevPriority = taskToPriority[taskId];
        taskToPriority[taskId] = newPriority;
        taskPriorityHeap.erase({prevPriority, taskId});
        taskPriorityHeap.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        int priority = taskToPriority[taskId];
        taskPriorityHeap.erase({priority, taskId});
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        if(taskPriorityHeap.empty()) return -1;
        auto [priority, taskId] = *taskPriorityHeap.begin();
        int userId = taskToUser[taskId];
        taskPriorityHeap.erase({priority, taskId});
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
        return userId;
    }
};

// Solution 2: Using Hash Map and Priority Queue
// Time Complexity: O(Q log Q) where Q is the number of queries
// Space Complexity: O(Q)
// A struct to hold all information about a task.
struct Task {
    int userId;
    int taskId;
    int priority;

    bool operator!=(const Task& other) const {
        return userId != other.userId || 
               taskId != other.taskId || 
               priority != other.priority;
    }
};

// Custom comparator to define the order in the max-heap.
// 1. Higher priority comes first.
// 2. If priorities are equal, higher taskId comes first.
struct TaskComparator {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority == b.priority) {
            return a.taskId < b.taskId;
        }
        return a.priority < b.priority;
    }
};

class TaskManager {
private:
    // A max-heap to efficiently find the highest priority task.
    priority_queue<Task, vector<Task>, TaskComparator> taskHeap;

    // A hash map to store the most current version of a task's details
    // for fast O(1) lookups by taskId.
    unordered_map<int, Task> taskDetails;

public:
    // Initializes the manager with a set of tasks.
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    // Adds a new task to the system.
    void add(int userId, int taskId, int priority) {
        Task newTask = {userId, taskId, priority};
        taskHeap.push(newTask);
        taskDetails[taskId] = newTask;
    }

    // Updates an existing task's priority.
    void edit(int taskId, int newPriority) {
        // Get the userId from the details map.
        int userId = taskDetails[taskId].userId;
        // Create the updated task and add it to the heap.
        // The old version is now a "zombie" left in the heap.
        Task updatedTask = {userId, taskId, newPriority};
        taskHeap.push(updatedTask);
        // Update the details map to reflect the new priority.
        taskDetails[taskId] = updatedTask;
    }

    // Removes a task by erasing it from the details map.
    // The actual task object remains in the heap as a "zombie".
    void rmv(int taskId) {
        taskDetails.erase(taskId);
    }

    // Finds, executes, and removes the top task.
    int execTop() {
        // Clean up "zombie" tasks from the top of the heap.
        while (!taskHeap.empty()) {
            Task topTask = taskHeap.top();

            // A task is a zombie if:
            // 1. It's not in our details map (was removed by rmv).
            // 2. Its priority in the heap doesn't match the current official
            //    priority in the map (it's an old version from an edit).
            if (!taskDetails.count(topTask.taskId) || 
                 taskDetails[topTask.taskId].priority != topTask.priority) {
                taskHeap.pop(); // Discard zombie and check the next one.
                continue;
            }

            // If we reach here, we've found the valid top task.
            int userIdToReturn = topTask.userId;
            
            // Execute the task by removing it from the system.
            taskHeap.pop();
            taskDetails.erase(topTask.taskId);
            
            return userIdToReturn;
        }

        // Return -1 if no valid tasks are left.
        return -1;
    }
};
