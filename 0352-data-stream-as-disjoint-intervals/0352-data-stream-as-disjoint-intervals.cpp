class SummaryRanges {
public:
    vector<bool> a;
    SummaryRanges() {
        a=vector<bool>(10001,0);
    }
    
    void addNum(int value) {
        a[value]=1;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int i=0;
        while(i<1e4){
          auto it=find(a.begin()+i,a.end(),1);
          auto it2=find(it,a.end(),0);
          if(it==a.end()) break;
          int st=it-a.begin();
          int en=(it2-a.begin())-1;
          ans.push_back({st,en});
          i=it2-a.begin();
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */