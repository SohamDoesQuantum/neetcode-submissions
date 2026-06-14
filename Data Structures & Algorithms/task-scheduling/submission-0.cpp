class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. Count frequencies
        vector<int> freq(26, 0);
        for(char task: tasks){
            freq[task - 'A']++;
        }

        // 2. Max-Heap to always execute the highest-frequency task available
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        // 3. Cooldown queue stores pairs of {remaining_frequency, available_time}
        queue<pair<int, int>> cooldown; 
        
        int time = 0; // Tracks the CPU cycles

        // Keep running until all tasks are executed and no tasks are cooling down
        while(!pq.empty() || !cooldown.empty()) {
            time++; // Move to the next CPU cycle

            if(!pq.empty()) {
                int rem_freq = pq.top() - 1; // Execute the most frequent task
                pq.pop();

                // If the task still needs to run in the future, put it in cooldown
                if(rem_freq > 0) {
                    // It will be available again at current time + n
                    cooldown.push({rem_freq, time + n});
                }
            } else {
                // If pq is empty, the CPU is currently "Idle"
            }

            // Check if any task has finished its cooldown period
            if(!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};