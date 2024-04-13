class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for (int weight : weights) {
        high += weight;
    }
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int currentDays = 1;  // Start the first day
        int currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > mid) {
                // If adding this package exceeds the max capacity, we start a new day
                currentDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        if (currentDays > days) {
            // If it takes more days than we have, increase the capacity
            low = mid + 1;
        } else {
            // Otherwise, try a smaller capacity
            high = mid;
        }
    }

    return low;
    }
};