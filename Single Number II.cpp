typedef unsigned long long LL;
class Solution {
public:
    int singleNumber(int A[], int n) {
    	LL mask1, mask2;
    	for (int i = 0; i<32; i++){
    		mask1 = ((mask1<<2)|1);
    	}
    	mask2 = (mask1<<1);
    	LL a = 0, b = 0, c = 0;
    	for (int i = 0; i<n; i++){
    		LL na = (unsigned int)A[i];
    		LL od = (na & mask1);
    		LL ev = (na & mask2);
    		na = ((ev<<31) | od);
    
    		c = c + na;
    
    		a = (c & mask1);
    		b = (c & mask2);
    
    		LL z = (a^(b>>1));
    		LL x = (a&z);
    		LL y = (b&(z<<1));
    
    		c = (x | y);
    	}
    	return (int) (c|(c>>31));
    }
};
