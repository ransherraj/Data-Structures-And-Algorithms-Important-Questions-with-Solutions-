class OrderedStream {
public:
    
    vector<string> stream;
    int i = 0;
    OrderedStream(int n) {
        stream.resize(n);
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        vector<string> ans;
        while(i < stream.size()  && stream[i] != ""){
            ans.push_back(stream[i++]);
        }
        return ans;
    }
};
