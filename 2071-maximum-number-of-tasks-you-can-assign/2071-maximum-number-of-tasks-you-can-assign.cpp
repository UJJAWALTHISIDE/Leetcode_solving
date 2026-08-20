class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0;
        int right = min(tasks.size(), workers.size());
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int usedPills = 0;
            // Take mid strongest workers
            multiset<int> workersFree(workers.end()-mid,workers.end());
            bool canAssign = true;
            // Check mid easiest tasks
            // Start from hardest task
            for (int i = mid - 1; i >= 0; i--) {
                int task = tasks[i];
                // Strongest worker
                auto worker = prev(workersFree.end());
                // Strongest worker can do the task
                if (*worker >= task) {
                    workersFree.erase(worker);
                }
                // Strongest worker cannot do it
                else {
                    // Find a worker who can do it with a pill
                    worker = workersFree.lower_bound(task - strength);
                    // No worker can do it even with a pill
                    if (worker == workersFree.end()) {
                        canAssign = false;
                        break;
                    }
                    usedPills++;
                    // We don't have enough pills
                    if (usedPills > pills) {
                        canAssign = false;
                        break;
                    }
                    // Use this worker
                    workersFree.erase(worker);
                }
            }
            // mid tasks are possible
            if (canAssign)
                left = mid;
            // mid tasks are not possible
            else
                right = mid - 1;
        }
        return left;
    }
};