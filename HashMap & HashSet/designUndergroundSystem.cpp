// Source Code:

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInTime;
    unordered_map<string, pair<int, int>> checkoutTime;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string key = "";
        key += checkInTime[id].first + "-" + stationName;
        int travelTime = t - checkInTime[id].second;
        int travels = 0;
        if(checkoutTime.find(key) != checkoutTime.end()){
            travelTime += checkoutTime[key].first;
            travels = checkoutTime[key].second;
        }
        
        checkoutTime[key] = {travelTime, travels + 1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = "";
        key += startStation + "-" + endStation;
        return (double)checkoutTime[key].first/checkoutTime[key].second;
    }
};