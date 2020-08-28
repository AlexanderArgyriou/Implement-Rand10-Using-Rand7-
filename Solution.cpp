// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// EV for random number of dice(6 faces) rolls = 1/6 * 1 + 1/6 * 2 + .... + 1/6 * 6
// EV = ∑P(Xi) × Xi.
class Solution 
{
    private:
        inline constexpr float calculateEV(float prob, int num) const noexcept
        {
            if(num == 1) return 1 / prob * 1;
            else return 1 / prob * num + calculateEV(prob, num - 1);
        }   // calculateEV

        int EV = calculateEV(7,7);  // max rand7() calls
        vector<int> v;
        int i = 0;
    public:
        inline Solution() noexcept
            : v(10 - EV)
        {
            for(int i = 1; i <= 10 - EV; i++)
                v[i-1] = i;
        }   // Constructor
    
        inline int rand10() noexcept
        {
            if(EV)  // EV random7() calls
            {
                EV--;
                v.push_back(rand7());
                return v[v.size() - 1];
            }   // if
            else
            {
                if (i > 9) i = 0;
                return v[i] + 10 - v[i] - i++;
            }   // else
        }   // rand10()
};
