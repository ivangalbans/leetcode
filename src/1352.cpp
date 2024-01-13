// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers
{
private:
    vector<int> prefix;

public:
    ProductOfNumbers()
    {
        prefix = {1};
    }

    void add(int num)
    {
        if (num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k)
    {
        return k <= prefix.size() - 1 ? prefix.back() / prefix[prefix.size() - 1 - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */