https://leetcode.com/problems/rectangle-overlap/description/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        pair<int, int> p1, p2, p3, p4;
        pair<int, int> p5, p6, p7, p8;
        if(rec1[0]<=rec1[2]) {
            p1 = {rec1[0], rec1[1]};
            p2 = {rec1[2], rec1[3]};
        } else {
            p2 = {rec1[0], rec1[1]};
            p1 = {rec1[2], rec1[3]};
        }
        if(rec2[0]<=rec2[2]) {
            p3 = {rec2[0], rec2[1]};
            p4 = {rec2[2], rec2[3]};
        } else {
            p4 = {rec2[0], rec2[1]};
            p3 = {rec2[2], rec2[3]};
        }
        if(p3.first>=p2.first || p4.first <= p1.first) {
            return false;
        }


        if(rec1[1]<=rec1[3]) {
            p5 = {rec1[0], rec1[1]};
            p6 = {rec1[2], rec1[3]};
        } else {
            p6 = {rec1[0], rec1[1]};
            p5 = {rec1[2], rec1[3]};
        }
        if(rec2[1]<=rec2[3]) {
            p7 = {rec2[0], rec2[1]};
            p8 = {rec2[2], rec2[3]};
        } else {
            p8 = {rec2[0], rec2[1]};
            p7 = {rec2[2], rec2[3]};
        }
        if(p7.second>=p6.second||p8.second<=p5.second) {
            return false;
        }

        return true;
    }
};
