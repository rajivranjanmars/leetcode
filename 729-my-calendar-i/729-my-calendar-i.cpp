class MyCalendar {
private:
    map<int,int> m;
public:
   bool canAdd(){//check for double-booking
       int count=0;
       for (auto entry: m){
           count+=entry.second;
           if(count>1) return false;
       }
       return true;
   }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if (canAdd()) return true;
        else{//restore the original values since we are not booking this room
            m[start]--;
            m[end]++;
            return false;
        }
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */