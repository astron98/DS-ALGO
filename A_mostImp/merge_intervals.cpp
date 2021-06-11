class Solution {
public:
    static bool compareTo(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    struct elem {
        int st, ed;
        elem(int start, int end) {
            st = start;
            ed = end;
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareTo);

        stack<elem> str;
        elem temp(intervals[0][0], intervals[0][1]);
        str.push(temp);
        for (int i = 0; i < (int)intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (str.size() > 0) {
                temp = str.top();
                if (temp.ed >= start) {
                    if (temp.ed < end) {
                        str.pop();
                        temp.ed = end;
                        str.push(temp);
                    }
                }
                else {
                    temp.st = start;
                    temp.ed = end;
                    str.push(temp);
                }
            }
        }

        vector<vector<int>> res;
        while (!str.empty()) {
            elem t = str.top();
            str.pop();
            vector<int> x = {t.st, t.ed};
            res.push_back(x);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


/*testcases*/

/*
case 1:
input
[[1,4],[2,3]]

output
[[1,4]]

*/