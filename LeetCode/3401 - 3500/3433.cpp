// 3433. Count Mentions Per User

// Solution 1: Using Sorting, Priority Queue, and Intelligent String Parsing
// Time Complexity: O(m log m + m) where m is number of events
// Space Complexity: O(n + m) where n is number of users and m is number of events
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA == timeB) {
                // "OFFLINE" > "MESSAGE", so a[0] > b[0] puts OFFLINE first
                return a[0] > b[0];
            }
            return timeA < timeB;
        });

        vector<int> mentions(numberOfUsers, 0);
        unordered_set<int> online;
        // Min-heap: {returnTime, userId}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> backOnline;

        for (int i = 0; i < numberOfUsers; i++)
            online.insert(i);

        for (auto& event : events) {
            string eventType = event[0];
            int timeStamp = stoi(event[1]);
            while (!backOnline.empty() && backOnline.top().first <= timeStamp) {
                online.insert(backOnline.top().second);
                backOnline.pop();
            }

            if (eventType == "MESSAGE") {
                string mentions_string = event[2];
                if (mentions_string == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                } else if (mentions_string == "HERE") {
                    for (auto& it : online)
                        mentions[it]++;
                } else {
                    // Parse "id<number>" tokens
                    size_t pos = 0;
                    while ((pos = mentions_string.find("id", pos)) != std::string::npos) {
                        pos += 2;
                        int value;
                        auto res = std::from_chars(
                            &mentions_string[pos], 
                            &mentions_string[pos] + (mentions_string.size() - pos), 
                            value
                        );

                        if (res.ec == std::errc()) {
                            mentions[value]++;
                            pos = res.ptr - mentions_string.data();
                        } else {
                            break;
                        }
                    }
                }
            } else { // OFFLINE event
                int userId = stoi(event[2]);
                online.erase(userId);
                backOnline.push({timeStamp + 60, userId});
            }
        }
        return mentions;
    }
};