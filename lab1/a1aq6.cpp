#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace  std;
double distance(vector<int> & p1, vector<int> & p2  ){
    return sqrt(pow((p1[0] - p2[0]),2) + pow((p1[1] - p2[1]),2));
}

bool comparex(vector<int>&p1 , vector<int> &p2){
    return p1[0] < p2[0];
}
bool comparey(vector<int> &p1 , vector<int> &p2){
    return p1[1] < p2[1];
}

double min_strip_dis(vector<vector<int>> &nums,double d){
    double minD = d;

    sort(nums.begin(),nums.end(),comparey);

    for(int i=0;i<nums.size();i++){
        for(int j =i+1;j<nums.size() && (nums[j][1]-nums[i][1]) < minD;j++){
            minD = min(minD,distance(nums[i],nums[j]));
        } 
    }

    return minD;
}

double min_distance_til(vector<vector<int>> &nums, int low , int high ){
    if(high - low <=2){
        double min_dis = INT_MAX;
        for(int i = low; i < high;i++){
            for(int j = i+1;j<high;j++){
                min_dis = min(min_dis,distance(nums[i],nums[j]));
            }
        }
        return min_dis;
    }

    int mid = (high+low)/2;
    int midX = nums[mid][0];

    double min_left = min_distance_til(nums,low,mid);
    double min_right = min_distance_til(nums,mid,high);

    double min_dis = min(min_left,min_right);

    vector<vector<int>> strip;
    for(int i=low;i<high;i++){
        if(abs(midX-nums[i][0]) < min_dis){
            strip.push_back(nums[i]);
        }
    }

    double min_strip = min_strip_dis(strip,min_dis);

    return min(min_dis,min_strip);
}

double min_distance(vector<vector<int>> &nums){
    int n = nums.size();
    
    sort(nums.begin(),nums.end(),comparex);

    return min_distance_til(nums,0,n);
}

int main(){
    vector<vector<int>> points = {{9,3}, {2,6}, {15,3}, {5,1},{1,2}, {12,4}, {7,2}, {4,7}, {16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}};

    double res = min_distance(points);

cout << fixed << setprecision(6) << res << endl;

    return 0;
}