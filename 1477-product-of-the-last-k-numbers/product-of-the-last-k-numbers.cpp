class ProductOfNumbers {
public:

    vector<int> pre;

    int ind;
    int prod;
    int lastZero=-1;
    ProductOfNumbers() {
        pre.clear();
        lastZero=-1; 
        ind=0;
        prod=1; 
    }
    
    void add(int num) {
        
        
        if(!num)
        {
            lastZero=ind;
            pre.push_back(0);
            prod=1;

        }
        else
        {
            prod*=num;
            pre.push_back(prod);
        }
        ind++;
        
    }
    
    int getProduct(int k) {
        
        // for(auto it: pre) cout<<it<<" ";
        // cout<<endl;

        // cout<<"ind is "<<ind<<endl;
        int i=ind-k;

        if(lastZero >= i) return 0;
        else
        {
            if(i==0) return pre[ind-1];
            return pre[i-1] == 0 ? pre[ind-1] : pre[ind-1]/pre[i-1];
        }

        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

 // [3,2,4,0,2,5,4]
//  [3,6,24,0,2